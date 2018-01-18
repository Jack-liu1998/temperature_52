#include "warning.h"


void Check(int temp)
{
	if(temp>=highest_temp)
	{
	   ET0=1;
	   TR0=1;
	}
	else
	{
	  ET0=0;
	   TR0=0;
	}
}
void biz_init()
{
	TMOD=0x00;
	TH0=225;
	TL0=24;//1ms一次中断
	EA=1;
}
void T0_time() interrupt 1
{		
	TH0=225;
	TL0=24;//重装初值
	buz=~buz;	
}