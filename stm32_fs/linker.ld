MEMORY
{
    SRAM (rwx): ORIGIN = 0x20000000, LENGTH = 512K
    FLASH (rx): ORIGIN = 0x08000000, LENGTH = 2048K
}

SECTIONS
{
    .isr_vector :
    {
        KEEP(*(.isr_vector)) /*keep, even if not reference in the section. will be "called by hardware" */
    } > FLASH

    .text :
    {
        . = ALIGN(4); /*ALIGN inserts padding bytes until the current location is aligned*/

        *(.text)
        *(.text.*)
        *(.rodata)
        *(.rodata.*)
        KEEP(*(.init))
        KEEP(*(.fini))
        *(.eh_frame)
        *(.ARM.exidx)


        . = ALIGN(4);
        _etext = .; /*of type uintptr_t which is architecture word size*/
    } > FLASH

    _sidata = LOADADDR(.data);

    .data :
    {
        . = ALIGN(4);
        _sdata = .;

        *(.data)
        *(.data.*)

        KEEP(*(.init_array))
        KEEP(*(.fini_array))

        . = ALIGN(4);
        _edata = .;
    } >SRAM AT> FLASH /*here, SRAM is the virtual memory address and the FLASH is the load memory address */

    .bss :
    {
        . = ALIGN(4);
        _sbss = .;
        __bss_start__ = _sbss;

        *(.bss)
        *(.bss.*)

        . = ALIGN(4);
        _ebss = .;
        __bss_end__ = _ebss;
    } > SRAM
}