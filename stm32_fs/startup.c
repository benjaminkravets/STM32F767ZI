#define SRAM_START (0x20000000U)
#define SRAM_SIZE (512U * 1024U)
#define SRAM_END (SRAM_START + SRAM_SIZE)
#define STACK_POINTER_INIT_ADDRESS (SRAM_END)

#include <stdint.h>
#define ISR_VECTOR_SIZE_WORDS 126

extern uint32_t _etext, _sdata, _edata, _sbss, _ebss;

//https://developer.arm.com/documentation/dui0646/c/The-Cortex-M7-Processor/Exception-model/Exception-types

void default_handler(void); //catches unexpected interrupts or exceptions- will be called if another interrupt is not implemented

void reset_handler(void); //called at boot. https://developer.arm.com/documentation/dui0056/d/handling-processor-exceptions/reset-handlers
void nmi_handler(void) __attribute__((weak, alias("default_handler"))); //non maskable interrupt. highest priority other than reset
void hard_fault_handler(void) __attribute__((weak, alias("default_handler"))); //error during exception processing, or an exception can't be managed by another exception mechanism
void mem_manage_handler(void) __attribute__((weak, alias("default_handler"))); //memory protection fault (especially unprivileged access as defined by MPU)
void bus_fault_handler(void) __attribute__((weak, alias("default_handler"))); //fault related to instruction/data memory transaction. may be error on memory system bus.
void usage_fault_handler(void) __attribute__((weak, alias("default_handler"))); //fault from instruction execution
void svcall_handler(void) __attribute__((weak, alias("default_handler"))); // called when supvisor call (SVC) instruction is called (used by apps to access OS kernel functions/device drivers)
void debug_monitor_handler(void) __attribute__((weak, alias("default_handler")));
void pendsv_handler(void) __attribute__((weak, alias("default_handler"))); //interrupt-driven request for system=level service
void systick_handler(void) __attribute__((weak, alias("default_handler"))); //occurs when system timer reaches 0, but can be triggered by software. used as a system tick in OS environment

//section attribute places this array in the isr_vector sections
uint32_t isr_vector[ISR_VECTOR_SIZE_WORDS] __attribute__((section(".isr_vector"))) = {
    (uint32_t)STACK_POINTER_INIT_ADDRESS, //will be copied to r13
    (uint32_t)&reset_handler,
    (uint32_t)&nmi_handler,
    (uint32_t)&hard_fault_handler,
    (uint32_t)&mem_manage_handler,
    (uint32_t)&bus_fault_handler,
    (uint32_t)&usage_fault_handler,
    0,
    0,
    0,
    0,
    (uint32_t)&svcall_handler,
    (uint32_t)&debug_monitor_handler,
    0,
    (uint32_t)&pendsv_handler,
    (uint32_t)&systick_handler,

};

void default_handler(void) //waits in busy loop (common out-of-box implementation, should be changed)
{
    while (1);
}

void main(void);

void reset_handler(void)
{
    // copy .data from whereever it ended up in FLASH to SRAM
    uint32_t data_size = (uint32_t)&_edata - (uint32_t)&_sdata;
    uint32_t *flash_data = (uint32_t *)&_etext;
    uint32_t *sram_data = (uint32_t *)&_sdata;

    for (uint32_t i = 0; i < data_size; i++)
    {
        sram_data[i] = flash_data[i];
    }

    // zero fill .bss section in SRAM
    uint32_t bss_size = (uint32_t)&_ebss - (uint32_t)&_sbss;
    uint32_t *bss = (uint32_t *)&_sbss;

    for (uint32_t i = 0; i < bss_size; i++)
    {
        bss[i] = 0;
    }

    main();
}
//compile  arm-none-eabi-gcc main.c startup.c -T linker.ld -o blink.elf -mcpu=cortex-m7 -mthumb -nostdlib
//to bin    arm-none-eabi-objcopy  -O binary blink.elf "blink.bin"