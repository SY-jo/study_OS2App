ENTRY(vector_start)
SECTIONS
{
    . = 0x0;


    .text :
    {
        *(vector_start)
        *(.text .rodata)
        
    }
    .data :
    {
        *(.data)
    }
    .bss :
    {
        *(.bss)
    }
    .note.gnu.build-id :
	{
		*(.note.gnu.build-id)
	}
}