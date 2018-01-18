
#ifndef LCD_CHAR_1602_2005_4_9
#define LCD_CHAR_1602_2005_4_9

#include <intrins.h>
#include <reg52.h>
typedef unsigned char BYTE;
typedef unsigned int WORD;
typedef bit BOOL;

sbit rs=P0^7;
sbit rw=P0^6;
sbit ep=P0^5;

void Out(int num);
void lcd_wcmd (BYTE cmd);
void lcd_pos (BYTE pos);
void lcd_init ();
void delay (int m);
void lcd_wdat (BYTE dat);

#endif
