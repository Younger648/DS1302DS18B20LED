#include "head.h"




void Timer0Init()		//1����@12.000MHz
{

	TMOD &= 0xF0;		//���ö�ʱ��ģʽ
	TMOD |= 0x01;		//���ö�ʱ��ģʽ
	
	
	TL0 = 0x18;		//���ö�ʱ��ʼֵ
	TH0 = 0xFC;		//���ö�ʱ��ʼֵ
	
	TF0 = 0;		//���TF0��־
	
	
	ET0 = 1;
	TR0 = 1;		//��ʱ��0��ʼ��ʱ

	
	
}



void ServiceTimer0() interrupt 1
{
	
	

	
	
	TL0 = 0x18;		//���ö�ʱ��ʼֵ
	TH0 = 0xFC;		//���ö�ʱ��ʼֵ
  P0 = 0xff;


	
	LED_temp();
	menu();
	jidianqi_a();

}

