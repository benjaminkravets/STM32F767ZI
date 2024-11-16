
MEMORY
{
    SRAM (rwx): ORIGIN = 0x20000000, LENGTH = 512K
    FLASH_BOOT (rx): ORIGIN = 0x08000000, LENGTH = 32K
    FLASH_APP (rx): ORIGIN = 0x08008000, LENGTH = 2016K
}

__flash_boot_start__ = ORIGIN(FLASH_BOOT);
__flash_boot_size__ = LENGTH(FLASH_BOOT);
__flash_app_start__ = ORIGIN(FLASH_APP);
__flash_app_size__ = LENGTH(FLASH_APP);

SECTIONS
{
    .isr_vector :
    {
        _sisr_vector = .;
        KEEP(*(.isr_vector)) /*keep, even if not reference in the section. will be "called by hardware" */
    } > FLASH_APP

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
    } > FLASH_APP

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
    } >SRAM AT> FLASH_APP /*here, SRAM is the virtual memory address and the FLASH_APP is the load memory address */

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