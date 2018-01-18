#ifndef _AD_READ_H_
#define _AD_READ_H_

#include <reg52.h>

#define uchar unsigned char

#define uint unsigned int

#define ulong unsigned long
sbit SD0 = P1^0;	//输出数据

sbit CS = P1^2;	//片选

sbit CLK = P1^3;	//时钟

sbit DIN = P1^1; //输入数据

sbit EOC=P1^4;	//转换结束


//chunnle0-10均为16 bits、MSB first、unipolar

uint read1543(uchar addr);
#endif