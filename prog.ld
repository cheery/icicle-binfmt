OUTPUT_FORMAT("binary")
SECTIONS
{
    .boot : {
        QUAD(0x00656c636963692e)
        QUAD(ABSOLUTE(load))
        QUAD(binsize)
    }
    .text : { *(.text) }
    .data : { *(.data) }
    .bss  : { *(.bss) }
    binsize = .;
}
