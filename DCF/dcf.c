#include<lpc17xx.h>

void delay(unsigned long int x)
{
	unsigned long int di;
	for(di=0;di<x;di++)
	{
	}
}

/*int main() //Singled side rotation
{
	SystemInit();
	LPC_SC->PCONP=0x00008000;
	LPC_GPIO1->FIOMASK0=0xEC;
	LPC_GPIO1->FIODIR0=0x13;
	
	while(1)
	{
		LPC_GPIO1->FIOPIN=0x03;
		delay(0x50000);
		LPC_GPIO1->FIOPIN=0x02;
		delay(0x50000);
	}
}*/

int main()
{ unsigned char val;
	SystemInit();
	LPC_SC->PCONP=0x00008000;
	LPC_GPIO1->FIOMASK0=0xEC;
	LPC_GPIO1->FIODIR0=0x13;
	LPC_GPIO1->FIOMASK3=0xF7;
	LPC_GPIO1->FIODIR3=0x00;
	
	while(1)
	{
		val=(LPC_GPIO0->FIOPIN3&0x08);
		if(val==0x08)
		{
			LPC_GPIO1->FIOPIN0=0x03;
			delay(85000);
			LPC_GPIO1->FIOPIN0=0x02;
			delay(15000);
		}
		else
		{
			LPC_GPIO1->FIOPIN0=0x03;
			delay(35000);
			LPC_GPIO1->FIOPIN0=0x02;
			delay(65000);
		}
	}
}


