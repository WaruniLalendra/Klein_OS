
#include "framebuffer.h"
#include "serial.h"
#include "memory_segments.h"


    
void kmain(){

    char msg[] = "KleinOS";
   
    segments_install_gdt();
    serial_write(0x3F8, msg, sizeof(msg));
    fb_write(msg, sizeof(msg));
    
}
