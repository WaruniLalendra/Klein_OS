#include "io.h"
#include "framebuffer.h"
#include "serial.h"
#include "memory_segments.h"
#include "keyboard.h"
#include "interrupts.h"
#include "multiboot.h"
#include "paging.h"




    
void kmain(multiboot_info_t *mbinfo){

    //char msg[] = "Welcome to KleinOS";
    //unsigned char scancode,ascii;
    //char asciicode[1];

    module_t* modules = (module_t*) mbinfo->mods_addr;       
    unsigned int address_of_module = modules->mod_start; 

    typedef void (*call_module_t)(void);
    call_module_t start_program = (call_module_t) address_of_module;
    start_program();
   
    segments_install_gdt();
    interrupts_install_idt();
    init_paging();
    /* test page fault 	
    unsigned int *ptr = (unsigned int*)0xA0000000;
    unsigned int do_page_fault = *ptr;*/

    //serial_write(msg, sizeof(msg));
    //fb_write(msg, sizeof(msg));

    //scancode = keyboard_read_scan_code();
    //ascii = keyboard_scan_code_to_ascii(scancode);
    //asciicode[0] = ascii;
    //serial_write(asciicode, sizeof(asciicode));
}
