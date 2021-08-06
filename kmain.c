
#include "framebuffer.h"
#include "serial.h"


    
void kmain(){

    char msg[] = "KleinOS";
   
    
    serial_write(0x3F8, msg, 7);
    fb_write(msg, 7);
    
}
