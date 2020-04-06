#include<lpc17xx.h>

void delay(unsigned long int x)
{
	unsigned long int di;
	for(di=0;di<x;di++)
	{
	}
}

/*int main() clockwise and anti-clockwise
{
	
	SystemInit();
	LPC_SC->PCONP=0x00008000;
	LPC_GPIO1->FIOMASK=0xFFFFFFEC;
	LPC_GPIO1->FIODIR=0x00000013;
	
	while(1)
	{
		LPC_GPIO1->FIOPIN=0x00000012; //for clockwise
		delay(0x50000);
		LPC_GPIO1->FIOPIN=0x00000003; //for anti-clockwise
		delay(0x50000);
	}
} */

int main() //direction based on switch
{ unsigned char val;
	SystemInit();
	LPC_SC->PCONP=0x00008000;
	LPC_GPIO1->FIOMASK=0xFFFFFFEC;
	LPC_GPIO1->FIODIR=0x00000013;
	LPC_GPIO0->FIOMASK=0xF7FFFFFF;
	LPC_GPIO0->FIODIR=0x00000000;
	
	while(1)
	{
		val=((LPC_GPIO0->FIOPIN3&0x08)>>3);
		if(val==0x00)
		{
			LPC_GPIO1->FIOPIN=0x00000012; //for clockwise
			//delay(0x50000);
		}
		else if(val==0x01)
		{
			LPC_GPIO1->FIOPIN=0x00000003; //for anti-clockwise
			//delay(0x50000);
		}
	}
}	
		

