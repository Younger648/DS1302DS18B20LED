#include "head.h"




void Timer0Init()		//1����@12.000MHz
{

	TMOD &= 0xF0;		//���ö�ʱ��ģʽ
	TMOD |= 0x01;		//���ö�ʱ��ģʽ
	
	
	TL0 = 0x66;		//���ö�ʱ��ʼֵ
	TH0 = 0xFC;		//���ö�ʱ��ʼֵ
	
	TF0 = 0;		//���TF0��־
	
	EA = 1;
	ET0 = 1;
	TR0 = 1;		//��ʱ��0��ʼ��ʱ

	
	
}




void ServiceTimer0() interrupt 1
{
	
	static unsigned char i = 0;
	static unsigned char i_flag = 0;
	P0 = 0xff;
	TL0 = 0x66;		//���ö�ʱ��ʼֵ
	TH0 = 0xFC;		//���ö�ʱ��ʼֵ
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