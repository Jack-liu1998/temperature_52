
#include "LCD1602.h"
#include "ad-read.h"
#include "warning.h"

BYTE code dis1 []={"Temperature"};

main()
{
	BYTE i;
	int ad;
	double temp_f,V;
	biz_init();
	lcd_init();	
	delay (10);	
	while(1)
	{
		lcd_wcmd (0x01);   //清屏
		lcd_pos (0);	   //第一行输出temperature
 	 i=0;
  	while (dis1 [i]!='\0')
   {
     lcd_wdat (dis1 [i]);
	 delay(1);
     i++;	
   } 
		ad=read1543(0x00);
		V=ad*4.96/1024.0;
		temp_f=640.5*V-80.62+65;//640.5*V-80.62为仿真出的线性拟合值，65为实际修正值相当于实际温度加6.5
		Out(temp_f);//输出第二行测量温度值
		Check(temp_f/10);//超温报警功能	
		delay(200);//200ms延时
	}
}
