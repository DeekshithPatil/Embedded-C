#include<lpc17xx.h>

void delay(unsigned long int x)
{
	unsigned long int di;
	for(di=0;di<x;di++)
	{
	}
}

int main()
{
	unsigned int val;
	
	SystemInit();
	LPC_SC->PCONP=0x00009000;
	LPC_PINCON->PINSEL3=0xC0000000;
	LPC_ADC->ADCR=0x00210220;
	
	LPC_GPIO0->FIOMASK2=0xD0;
	LPC_GPIO0->FIODIR2=0x20;
	
	while(1)
	{
		while((LPC_ADC->ADSTAT&0x00000020)!=0x00000020)
		{
		}
		val=(LPC_ADC->ADDR5>>4)&0x0FFF;
		if(val<0x5FF)
		{
			LPC_GPIO0->FIOCLR2=0x20;
		}
		else
		{
			LPC_GPIO0->FIOSET2=0x20;
		}
	}
}
