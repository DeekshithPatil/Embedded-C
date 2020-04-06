#include<lpc17xx.h>

void delay(unsigned long int x)
{
	unsigned long int di;
	for(di=0;di<x;di++)
	{
	}
}

/*int main() //Buzzer connected at P0.21
{
	SystemInit();
	LPC_SC->PCONP=0x00008000;
	LPC_GPIO0->FIOMASK2=0xDF;
	LPC_GPIO0->FIODIR2=0x20;
	
	while(1)
	{
		LPC_GPIO0->FIOSET2=0x20;
		delay(0x99000);
		LPC_GPIO0->FIOCLR2=0x20;
		delay(0x99000);
	}
}*/

int main() //Relay connected at P0.22
{
	SystemInit();
	LPC_SC->PCONP=0x00008000;
	LPC_GPIO0->FIOMASK2=0xBF;
	LPC_GPIO0->FIODIR2=0x40;
	
	while(1)
	{
		LPC_GPIO0->FIOSET2=0x40;
		delay(0x99000);
		LPC_GPIO0->FIOCLR2=0x40;
		delay(0x99000);
	}
}
