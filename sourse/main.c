#include "head.h"




void main()
{
//	P0 = 0x00;
//	P2 = 0xA0;
//	P2 = 0x80;
//	P0 = 0xFF;
//	P2 = 0x00;
	
	
	Write_ds1302_config();
	EA = 1;
	Timer0Init();
	EA = 0;
	
	while(1)
	{
		ds18b20_config();
		Read_ds1302_config();
		refer_key();
		menu_key();
		
	}
}