#include<lpc17xx.h>

void delay(unsigned long int x)
{
	unsigned long int di;
	for(di=0;di<x;di++)
	{
	}
}

int main()
{ int i,val,j,n=5;
	int arr1[]={0x00020000,0x00010000,0x00008000,0x00004000}; //For clockwise direction
	int arr2[]={0x00004000,0x00008000,0x00010000,0x00020000};
	SystemInit();
	LPC_SC->PCONP=0x00008000;
	LPC_GPIO1->FIOMASK=0xFFFC3FFF;
	LPC_GPIO1->FIODIR=0x0003C000;
	
	for(i=0;i<(50*n);i++)
	{
		for(j=0;j<4;j++)
		{
			val=arr2[j];
			LPC_GPIO1->FIOPIN=arr2[j];
		}
	}
	
}