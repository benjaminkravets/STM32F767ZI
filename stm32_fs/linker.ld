MEMORY
{
    SRAM (xrw): ORIGIN = 0x20000000, LENGTH = 512K
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
        . = ALIGN(4);

        *(.text)
        *(.rodata)

        . = ALIGN(4);
        _etext = .;
    } > FLASH

    .data :
    {
        . = ALIGN(4);
        _sdata = .;

        *(.data)

        . = ALIGN(4);
        _edata = .;
    } > SRAM AT>FLASH /*here, SRAM is the virtual memory address and the FLASH is the load memory address

    .bss :
    {
        . = ALIGN(4);
        _sbss = .;

        *(.bss)

        . = ALIGN(4)
        _ebss = .;
    } > SRAM
}