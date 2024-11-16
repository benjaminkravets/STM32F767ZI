MEMORY
{
    SRAM (rwx): ORIGIN = 0x20000000, LENGTH = 512K
    FLASH_BOOT (rx): ORIGIN = 0x08000000, LENGTH = 32K
}

SECTIONS
{
    .isr_vector :
    {
        _sisr_vector = .;
        KEEP(*(.isr_vector)) /*keep, even if not reference in the section. will be "called by hardware" */
    } > FLASH_BOOT

    .text :
    {
        . = ALIGN(4); /*ALIGN inserts padding bytes until the current location is aligned*/

        *(.text)
        *(.text.*)
        *(.rodata)
        *(.rodata.*)
        KEEP(*(.init)) /* initialization code run before main */
        KEEP(*(.fini)) /* executed after main returns */
        *(.eh_frame)
        *(.ARM.exidx) /* contains informaiton for unwinding the stack */


        . = ALIGN(4);
        _etext = .; /*of type uintptr_t which is architecture word size*/
    } > FLASH_BOOT

    _sidata = LOADADDR(.data); /*LOADADDR returns the load address of the named section */

    .data :
    {
        . = ALIGN(4);
        _sdata = .;

        *(.data)
        *(.data.*)

        KEEP(*(.init_array)) /*array of function pointers that is called at program start*/
        KEEP(*(.fini_array)) /*array of function pointers that is called at program end*/

        . = ALIGN(4);
        _edata = .;
    } >SRAM AT> FLASH_BOOT /*here, SRAM is the virtual memory address and the FLASH_BOOT is the load memory address */

    .bss :
    {
        . = ALIGN(4);
        _sbss = .;
        __bss_start__ = _sbss;  /*neexed by _mainCRTStartup*/

        *(.bss)
        *(.bss.*)

        . = ALIGN(4);
        _ebss = .;
        __bss_end__ = _ebss; /*needed by _mainCRTStartup */
    } > SRAM
}