#include "ad-read.h"
/*double myRead()
{
	int V1;
	double V;
	//float om;
	int i;
	for(i=0;i<2;i++)
	{
	 V1=ad2543work(0);
	}
	 //V=V1*((double)(5/4096.));
	 
	 //om=((R1*R6*5-(R1+R2)*R5*V)*R3)/((R1+R2)*R6*5-5*R1*R6+(R1+R2)*R5*V);
	 return V1;
} */
/*******************************实现延时************************************/

void mdelay(uint T) //实现延时

{

uint j;

for(j=0;j<T;j++);

}

/***************************TLC1543驱动部分*********************************/

uint read1543(uchar addr)

{

uint Data_Out=0;

uchar k;

uchar i;

uchar j;

CLK=0;

CS=0;

for (i=0;i<4;i++)

{

DIN=(bit)(addr&0x08);

CLK=1;

CLK=0;

addr<<=1;

}

for (j=0;j<6;j++) //填充6 个CLOCK

{

CLK=1;

CLK=0;

}

CS=1;

mdelay(25);

CS=0; //等待AD 转换

mdelay(25);

for(k=0;k<10;k++)

{

SD0 = 1;

CLK = 0;

Data_Out<<=1;

if(SD0)

{

Data_Out += 1;

}

CLK = 1;

}

return(Data_Out);

}

 