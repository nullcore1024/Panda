
// @Name   : main.c 
//
// @Author : Yukang Chen (moorekang@gmail.com)
// @Date   : 2012-01-03 17:33:50
//
// @Brief  : The kernel entry point

#include <asm.h>
#include <cpu.h>
#include <screen.h>
#include <string.h>
#include <page.h>
#include <kheap.h>
#include <test.h>

void kmain()
{
    init_video();
    puts("booting Panda OS ...\n");
    gdt_init();
    idt_init();
    timer_init(1);
    kb_init();
    page_init( 0x1000000 * 2 );//32 MB

#if 0
    int k;
    for(k=0; k<10; k++) {
        u32 *ptr = (u32*)kmalloc(sizeof(u32));
        printk("ptr: %x\n", ptr);
        *ptr = 0xA;
        printk("value: %x\n", (*ptr));
        char* cp = (char*)kmalloc(sizeof(char));
        *cp = 'c';
        printk("value: %c\n", (*cp));
    }
#endif
    
    
    int initial = 1;
    while(1){
        if(initial) {
            puts("running\n");
            initial = 0;
        }
    }
}
