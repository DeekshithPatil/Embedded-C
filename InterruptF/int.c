#include<lpc17xx.h>
unsigned int i;
void delay(unsigned long int x)
{
	unsigned long int di;
	for(di=0;di<x;di++)
	{
	}
}

void EINT1_IRQHandler(void)
{
	NVIC_DisableIRQ(EINT1_IRQn);
	for(i=0;i<10;i++)
	{
		LPC_GPIO1->FIOSET3=0x10;
		delay(0x50000);
		LPC_GPIO1->FIOCLR3=0x10;
		delay(0x50000);
	}
	LPC_SC->EXTINT=0x00000002;
	NVIC_EnableIRQ(EINT1_IRQn);
	
}

int main()
{
	SystemInit();
	LPC_SC->PCONP=0x00008000;
	LPC_PINCON->PINSEL4=0x00400000;
	LPC_GPIO1->FIOMASK3=0xEF;
	LPC_GPIO1->FIODIR3=0x10;
	
	LPC_SC->EXTMODE=0x00000020;
	LPC_SC->EXTPOLAR=0x00000000;
	
	NVIC_EnableIRQ(EINT1_IRQn);
	while(1)
	{
	}
}

