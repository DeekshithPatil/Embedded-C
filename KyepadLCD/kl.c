#include<lpc17xx.h>

void delay(unsigned long int x)
{
	unsigned long int di;
	for(di=0;di<x;di++)
	{
	}
}

void lcdwrt(unsigned char ch)
{
	LPC_GPIO2->FIOPIN0=ch;
	LPC_GPIO1->FIOSET1=0x04;
	delay(0x500);
	LPC_GPIO1->FIOCLR1=0x04;
	delay(0x500);
}

int main()
{ int i;
	unsigned char cmd[]={0x38,0x0E,0x06,0x01,0x80};
	unsigned char rowloc,colloc;
	unsigned char val[4][4]={'1','2','3','A','4','5','6','B','7','8','9','C','E','0','F','D'};
	
	SystemInit();
	LPC_SC->PCONP=0x00008000;
	LPC_GPIO2->FIOMASK0=0x00;
	LPC_GPIO2->FIODIR0=0xFF;
	LPC_GPIO1->FIOMASK=0xF0FFF8FF;
	LPC_GPIO1->FIODIR=0x0F0007FF;
	LPC_GPIO0->FIOMASK=0xFFFFFF0F;
	LPC_GPIO0->FIODIR=0x000000F0;
	
	LPC_GPIO1->FIOCLR1=0x03;
	for(i=0;i<5;i++)
	{
		lcdwrt(cmd[i]);
	}
	LPC_GPIO1->FIOSET1=0x03;
	
	while(1)
	{
		LPC_GPIO1->FIOPIN3=0x00;
		do 
		{
			colloc=LPC_GPIO0->FIOPIN0&0xF0;
		}while(colloc==0xF0);
	  
		while(1)
		{
			LPC_GPIO1->FIOPIN3=0x0E;
			colloc=LPC_GPIO0->FIOPIN0&0xF0;
			if(colloc!=0xF0)
			{
				rowloc=0;
				break;
			}
			LPC_GPIO1->FIOPIN3=0x0D;
			colloc=LPC_GPIO0->FIOPIN0&0xF0;
			if(colloc!=0xF0)
			{
				rowloc=1;
				break;
			}
			LPC_GPIO1->FIOPIN3=0x0B;
			colloc=LPC_GPIO0->FIOPIN0&0xF0;
			if(colloc!=0xF0)
			{
				rowloc=2;
				break;
			}
			LPC_GPIO1->FIOPIN3=0x07;
			colloc=LPC_GPIO0->FIOPIN0&0xF0;
			if(colloc!=0xF0)
			{
				rowloc=3;
				break;
			}
		}
		LPC_GPIO1->FIOCLR1=0x03;
		lcdwrt(0x80);
		LPC_GPIO1->FIOSET1=0x03;
		
		if(colloc==0xE0)
		{
			lcdwrt(val[rowloc][0]);
		}
		else if(colloc==0xD0)
		{
			lcdwrt(val[rowloc][1]);
		}
		else if(colloc==0xB0)
		{
			lcdwrt(val[rowloc][2]);
		}
		else if(colloc==0x70)
		{
			lcdwrt(val[rowloc][3]);
		}
	}
}
		
			
			
				
	
	
			
	
	

