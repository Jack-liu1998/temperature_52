#ifndef _ALLEN_H_
#define _ALLEN_H_
#include<reg52.h>

sbit buz=P3^6;//蜂鸣器管脚

#define highest_temp 30//30  0C报警
void Check(int temp);//参数为测量温度
void biz_init();
#endif