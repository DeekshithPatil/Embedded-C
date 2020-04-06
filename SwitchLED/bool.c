#include<lpc17xx.h>

int main()
{
	unsigned char val1,val2;
	SystemInit();
	LPC_SC->PCONP=0x00008000;
	LPC_GPIO0->FIOMASKH=0xE7DF;
	LPC_GPIO0->FIODIRH=0x0020;
	while(1)
	{
		val1=(LPC_GPIO0->FIOPIN3&0x10)>>4;
		val2=(LPC_GPIO0->FIOPIN3&0x08)>>3;
		if(val1&&val2)
		{
			LPC_GPIO0->FIOSET2=0x20;
		}
		else
		{
			LPC_GPIO0->FIOCLR2=0x20;
		}
	}
}
