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