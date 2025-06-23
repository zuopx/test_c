ENTRY(nomain)

SECTIONS
{
    . = 0x0000000000400000 + SIZEOF_HEADERS;
    tinytext : {*(.text) *(.data) *(.rodata)}    
    /DISCARD/ : {*(.comment) *(.eh_frame)}
}