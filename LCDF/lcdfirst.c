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
	delay(0x99000);
	LPC_GPIO1->FIOCLR1=0x04;
	delay(0x99000);
}

/*int main() //On First line
{ unsigned char cmd[]={0x38,0x0E,0x06,0x01,0x80};
	unsigned char str1[]="Hello";
	unsigned char i;
	SystemInit();
	LPC_SC->PCONP=0x00008000;
	LPC_GPIO1->FIOMASK1=0xF8;
	LPC_GPIO1->FIODIR1=0x07;
	LPC_GPIO2->FIOMASK0=0x00;
	LPC_GPIO2->FIODIR0=0xFF;

	LPC_GPIO1->FIOCLR1=0x03;
	for(i=0;i<5;i++)
	{
		lcdwrt(cmd[i]);
	}
	LPC_GPIO1->FIOSET1=0x01;
	for(i=0;str1[i]!='\0';i++)
	{
		lcdwrt(str1[i]);
	}
}*/

/*int main() //Display on second line
{ unsigned char cmd[]={0x38,0x0E,0x06,0x01,0xC0};
	unsigned char str1[]="Hello";
	unsigned char i;
	SystemInit();
	LPC_SC->PCONP=0x00008000;
	LPC_GPIO1->FIOMASK1=0xF8;
	LPC_GPIO1->FIODIR1=0x07;
	LPC_GPIO2->FIOMASK0=0x00;
	LPC_GPIO2->FIODIR0=0xFF;

	LPC_GPIO1->FIOCLR1=0x03;
	for(i=0;i<5;i++)
	{
		lcdwrt(cmd[i]);
	}
	LPC_GPIO1->FIOSET1=0x01;
	for(i=0;str1[i]!='\0';i++)
	{
		lcdwrt(str1[i]);
	}
}*/

int main()
{
	unsigned char cmd[]={0x38,0x0E,0x06,0x01,0xC0};
	unsigned char str1[]="ON";
	unsigned char str2[]="OFF";
	unsigned char i,val;
	SystemInit();
	LPC_SC->PCONP=0x00008000;
	LPC_GPIO1->FIOMASK1=0xF8;
	LPC_GPIO1->FIODIR1=0x07;
	LPC_GPIO2->FIOMASK0=0x00;
	LPC_GPIO2->FIODIR0=0xFF;
	LPC_GPIO0->FIOMASK3=0xF7;
	LPC_GPIO0->FIODIR3=0x00;

	LPC_GPIO1->FIOCLR1=0x03;
	for(i=0;i<5;i++)
	{
		lcdwrt(cmd[i]);
	}
	LPC_GPIO1->FIOSET1=0x01;
	while(1)
	{
		val=(LPC_GPIO0->FIOPIN3&0x08)>>3;
		if(val==0x01)
		{
			for(i=0;str1[i]!='\0';i++)
			{
				lcdwrt(str1[i]);
			}
		}
		else
		{
			for(i=0;str2[i]!='\0';i++)
			{
				lcdwrt(str2[i]);
			}
		}
	}
}


