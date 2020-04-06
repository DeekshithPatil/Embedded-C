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
	LPC_GPIO2->FIOPIN0=ch;   //Writing the data
	LPC_GPIO1->FIOSET1=0x04; //EN=1
	delay(0x5000);
	LPC_GPIO1->FIOCLR1=0x04; //EN=0
	delay(0x5000);
}

int main()
{
	unsigned char cmd[]={0x38,0x0E,0x06,0x01,0x80};
	unsigned char val[4][4]={'1','2','3','A','4','5','6','B','7','8','9','C','E','0','F','D'};
	unsigned char i,rowloc,colloc;
	SystemInit();
	LPC_SC->PCONP=0x00008000;
	LPC_GPIO2->FIOMASK0=0x00;
	LPC_GPIO2->FIODIR0=0xFF;
	LPC_GPIO1->FIOMASK=0xF0FFF8FF;
	LPC_GPIO1->FIODIR=0x0F000700;
	LPC_GPIO0->FIOMASK0=0x0F;
	LPC_GPIO0->FIODIR0=0x00;
	
	LPC_GPIO1->FIOCLR1=0x03; 
	for(i=0;i<5;i++)
	{
		lcdwrt(cmd[i]);
	}
	
	while(1)
	{
		LPC_GPIO1->FIOCLR3=0x0F;
		do
		{
			colloc=LPC_GPIO0->FIOPIN0&0xF0;
		}while(colloc==0xF0);
		while(1)
		{
			LPC_GPIO1->FIOCLR3=0x0E; //1110
			colloc=(LPC_GPIO0->FIOPIN0&0xF0);
			if(colloc!=0xF0)
			{
				rowloc=0;
				break;
			}
			LPC_GPIO1->FIOCLR3=0x0D; //1101
			colloc=(LPC_GPIO0->FIOPIN0&0xF0);
			if(colloc!=0xF0)
			{
				rowloc=1;
				break;
			}
			LPC_GPIO1->FIOCLR3=0x0B; //1011
			colloc=(LPC_GPIO0->FIOPIN0&0xF0);
			if(colloc!=0xF0)
			{
				rowloc=2;
				break;
			}
			LPC_GPIO1->FIOCLR3=0x07; //0111
			colloc=(LPC_GPIO0->FIOPIN0&0xF0);
			if(colloc!=0xF0)
			{
				rowloc=3;
				break;
			}
		}
		LPC_GPIO1->FIOCLR1=0x03;
		lcdwrt(0x80);
		LPC_GPIO1->FIOCLR1=0x01;
		
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

	
