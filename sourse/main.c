#include "head.h"




void main()
{
	Write_ds1302_config();
	Timer0Init();
	
	while(1)
	{
		ds18b20_config();
		Read_ds1302_config();
		
		menu_key();
		
	}
}