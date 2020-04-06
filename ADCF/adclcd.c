#include<lpc17xx.h>

void delay (unsigned long int x)
{
	unsigned long int di;
	for(di=0;di<x;di++)
	{
	}
}

void lcdwrt(unsigned char ch)
{
	LPC_GPIO2->FIOPIN0=ch;
	LPC_GPIO1->FIOSET1=0x04;
	delay(0x500);
	LPC_GPIO1->FIOCLR1=0x04;
	delay(0x500);
}

int main()
{
	unsigned char cmd[]={0x38,0x0E,0x06,0x01,0x80};
	unsigned int val;
	unsigned int y[4],a,i;
	
	SystemInit();
	LPC_SC->PCONP=0x00009008;
	LPC_PINCON->PINSEL3=0xC0000000;
	LPC_ADC->ADCR=0x00210220;
	
	LPC_GPIO2->FIOMASK0=0x00;
	LPC_GPIO2->FIODIR0=0xFF;
	LPC_GPIO1->FIOMASK1=0xF8;
	LPC_GPIO1->FIODIR1=0x0F;
	
	LPC_GPIO1->FIOCLR1=0x03;
	for(i=0;i<5;i++)
	{
		lcdwrt(cmd[i]);
	}
	
	while(1)
	{
		LPC_GPIO1->FIOCLR1=0x03;
		lcdwrt(0x01);
		lcdwrt(0x06);
		lcdwrt(0x80);
		LPC_GPIO1->FIOSET1=0x01;
		
		while((LPC_ADC->ADSTAT&0x00000020)!=0x00000020)
		{
		}
		val=(LPC_ADC->ADDR5>>4)&0x0FFF;
		val=val/12.4;
		
		a=val;
		for(i=0;i<3;i++)
		{
			y[i]=a%10;
			a=a/10;
		}
		y[i]=a;
		for(i=0;i<4;i++)
		{
			y[i]=y[i]+30;
		}
		lcdwrt(y[3]);
		delay(0x500);
		lcdwrt(y[2]);
		delay(0x500);
		lcdwrt('.');
		delay(0x500);
		lcdwrt(y[1]);
		delay(0x500);
		lcdwrt(y[0]);
		delay(0x500);
	}
	
}

