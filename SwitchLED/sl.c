#include<lpc17xx.h>

int main() 
{
	unsigned char val;
	SystemInit();
	LPC_SC->PCONP=0x00008000;
	LPC_GPIO0->FIOMASK3=0xF7;
	LPC_GPIO0->FIODIR3=0x00;
	LPC_GPIO0->FIOMASK2=0xDF;
	LPC_GPIO0->FIODIR2=0x20;
	while(1)
	{
		val=(LPC_GPIO0->FIOPIN3&0x08)>>3;
		if(val==0x01)
		{
			LPC_GPIO0->FIOSET2=0x20;
		}
		else
		{
			LPC_GPIO0->FIOCLR2=0x20;
		}
	}
}
