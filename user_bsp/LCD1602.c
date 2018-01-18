#include "LCD1602.h"


void delay (int m)
{
 unsigned char i,j;
 for (i=0;i<m;i++)
 for (j=0;j<253;j++);
}

 BOOL lcd_bz()
{
  BOOL result;
  rs=0;           // 读忙信号
  rw=1;
  ep=1;
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  result = (BOOL)(P2&0x80);
  ep=0;
  return result;
}

void lcd_wcmd (BYTE cmd)
{
  while (lcd_bz());
  rs=0;
  rw=0;
  ep=0;
  _nop_();
  _nop_();
  P2=cmd ;
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  ep=1;
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  ep=0;
}

void lcd_pos (BYTE pos)
{
  lcd_wcmd (pos|0x80);
}

void lcd_wdat (BYTE dat)
{
   while (lcd_bz());
  rs=1;
  rw=0;
  ep=0;
  _nop_();
  _nop_();
  P2=dat ;
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  ep=1;
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  ep=0;
}

void lcd_init ()
{
  lcd_wcmd (0x38);
  delay (1);
  lcd_wcmd (0x0c);
  delay (1);
  lcd_wcmd (0x06);
  delay (1);
  lcd_wcmd (0x01);
  delay (1);
}


 void Out(int num)
{
int i;
	char number[13];
	number[12]='\0';//xx.x Celsius
	number[11]='s';
	number[10]='u';
	number[9]='i';
	number[8]='s';
	number[7]='l';
	number[6]='e';
	number[5]='C';
	number[4]=' ';
	number[3]=num%10+'0';
	number[2]='.';
	number[1]=(num/10)%10+'0';
	number[0]=num/100+'0';
	lcd_pos (0x40);		  //第二行输出温度具体数据
  i=0;
  while (number[i]!='\0')//输出
   {
     lcd_wdat (number[i]);
 	 delay(1);
     i++;	
   } 
}