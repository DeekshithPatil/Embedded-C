#include<lpc17xx.h>

void delay(unsigned long int x)
{
	unsigned long int di;
	for(di=0;di<x;di++)
	{
	}
}

/*int main() //clockwise
{
	unsigned char arr[]={0x88,0x44,0x22,0x11};
	unsigned char i;
	SystemInit();
	LPC_SC->PCONP=0x00008000;
	LPC_GPIO1->FIOMASK=0xFFFC3FFF;
	LPC_GPIO1->FIODIR=0x0003C000;
	while(1)
	{
		for(i=0;i<4;i++)
		{
			LPC_GPIO1->FIOPIN=(arr[i]<<14);
			delay(99000);
		}
	}
}*/

/*int main() //Anticlockwise
{
	unsigned char arr[]={0x11,0x22,0x44,0x88};
	unsigned char i;
	SystemInit();
	LPC_SC->PCONP=0x00008000;
	LPC_GPIO1->FIOMASK=0xFFFC3FFF;
	LPC_GPIO1->FIODIR=0x0003C000;
	while(1)
	{
		for(i=0;i<4;i++)
		{
			LPC_GPIO1->FIOPIN=(arr[i]<<14);
			delay(150000);
		}
	}
}*/

int main()
{
	unsigned char arr1[]={0x88,0x44,0x22,0x11};
	unsigned char arr2[]={0x11,0x22,0x44,0x88};
	unsigned char i,val;
	SystemInit();
	LPC_SC->PCONP=0x00008000;
	LPC_GPIO1->FIOMASK=0xFFFC3FFF;
	LPC_GPIO1->FIODIR=0x0003C000;
	LPC_GPIO0->FIOMASK3=0xF7;
	LPC_GPIO0->FIODIR3=0x00;
	while(1)
	{
		val=(LPC_GPIO0->FIOPIN3&0x08)>>3;
		if(val==0x01)
		{
			for(i=0;i<4;i++)
			{
				LPC_GPIO1->FIOPIN=(arr1[i]<<14);
				delay(99000);
			}
		}
		else
		{
			for(i=0;i<4;i++)
			{
				LPC_GPIO1->FIOPIN=(arr2[i]<<14);
				delay(99000);
			}
		}	
	}
}
