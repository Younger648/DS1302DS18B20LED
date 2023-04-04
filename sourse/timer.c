#include "head.h"




void Timer0Init()		//1毫秒@12.000MHz
{

	TMOD &= 0xF0;		//设置定时器模式
	TMOD |= 0x01;		//设置定时器模式
	
	
	TL0 = 0x66;		//设置定时初始值
	TH0 = 0xFC;		//设置定时初始值
	
	TF0 = 0;		//清除TF0标志
	
	EA = 1;
	ET0 = 1;
	TR0 = 1;		//定时器0开始计时

	
	
}




void ServiceTimer0() interrupt 1
{
	
	static unsigned char i = 0;
	static unsigned char i_flag = 0;
	P0 = 0xff;
	TL0 = 0x66;		//设置定时初始值
	TH0 = 0xFC;		//设置定时初始值
	HC138(4);
	
	
		if(temper / 10 > refer)
	{
		i ++;
		if(i == 100)
		{
			i = 0;
			i_flag = ~i_flag;
			if(i_flag)
				LED_config(1,0);
			else
				LED_config(1,1);
		}
	}
	
	
	
	menu();

}