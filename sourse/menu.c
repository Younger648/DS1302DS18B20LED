#include "head.h"


unsigned char Scon = 1;



void Delay5ms()		//@12.000MHz
{
	unsigned char i, j;

	i = 59;
	j = 90;
	do
	{
		while (--j);
	} while (--i);
}


void menu()
{
	if(Scon == 1)
	ds18b20_show();
	else if(Scon == 2)
	ds1302_show();
	else if(Scon == 3)
	refer_show();
}









void menu_key()
{
	key(1);
	if(C4 == 0)
	{
		Delay5ms();
		if(C4 == 0)
		{
			Scon ++;
			if(Scon == 4)
				{
					Scon = 1;
				}
		}
		while(C4 == 0);
	}
		
}



