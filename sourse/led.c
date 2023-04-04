#include "head.h"

unsigned P0_DAT = 0xff;

void LED_config(unsigned char led_adr,unsigned led_dat)
{
	if(led_dat == 0)
		P0_DAT |= 0x01 <<(led_adr - 1);
	else 
		P0_DAT &= ~(0x01 <<(led_adr - 1));
	
	P0 = P0_DAT;
}

void LED_F()
{
	LED_config(1,0);
	LED_config(2,0);
	LED_config(3,0);
	LED_config(4,0);
	LED_config(5,0);
	LED_config(6,0);
	LED_config(7,0);
	LED_config(8,0);
}