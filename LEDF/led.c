#include<LPC17xx.h>
void delay (unsigned long int x)
{
	unsigned long int di;
	for(di=0;di<x;di++)
	{
	}
}

/*int main() //Blink an LED
{
	
	SystemInit();
	LPC_SC->PCONP=0x00008000;
	LPC_GPIO1->FIOMASK3=0xEF;//P1.28 is unmasked
	LPC_GPIO1->FIODIR3=0x10;
	while(1)
	{
		LPC_GPIO1->FIOSET3=0x10;
		delay(0x50000);
		LPC_GPIO1->FIOCLR3=0x10;
		delay(0x50000);
	}
	
	
}*/

/*int main() //Blink an LED for N times
{
	char i,N=50;
	SystemInit();
	LPC_SC->PCONP=0x00008000;
	LPC_GPIO1->FIOMASK3=0xEF;//P1.28 is unmasked
	LPC_GPIO1->FIODIR3=0x10;
	for(i=0;i<N;i++)
	{
		LPC_GPIO1->FIOSET3=0x10;
		delay(0x50000);
		LPC_GPIO1->FIOCLR3=0x10;
		delay(0x50000);
	}

	
}*/

/*int main() //Array of LEDs to be blinked at P0.8,9,10,11
{
	//char i,N=50;
	SystemInit();
	LPC_SC->PCONP=0x00008000;
	LPC_GPIO0->FIOMASK1=0xF0;//P0.8,9,10,11 is unmasked
	LPC_GPIO0->FIODIR1=0x0F;
	while(1)
	{
		LPC_GPIO0->FIOSET1=0x0f;
		delay(0x50000);
		LPC_GPIO0->FIOCLR1=0x0f;
		delay(0x50000);
	}

	
}*/

/*int main() //Decimal Counter
{ unsigned char i;
	SystemInit();
	LPC_SC->PCONP=0x00008000;
	LPC_GPIO0->FIOMASK1=0xF0;
	LPC_GPIO0->FIODIR1=0x0F;
	while(1)
	{
		for(i=0;i<10;i++)
		{
			LPC_GPIO0->FIOPIN1=i;
			delay(0x50000);
		}
	}
}*/

int main() //Ring and Twisted Ring couter
{ 
	unsigned char ring[]={0x08,0x04,0x02,0x01};
	unsigned char tring[]={0x00,0x08,0x0C,0x0E,0xF,0x07,0x03,0x01};
	unsigned char i;
	SystemInit();
	LPC_SC->PCONP=0x00008000;
	LPC_GPIO0->FIOMASK1=0xF0;
	LPC_GPIO0->FIODIR1=0x0F;
	while(1)
	{
		for(i=0;i<4;i++)
		{
			LPC_GPIO0->FIOPIN1=ring[i];
			delay(0x99000);
		}
		for(i=0;i<8;i++)
		{
			LPC_GPIO0->FIOPIN1=tring[i];
			delay(0x99000);
		}
	}
}

	
