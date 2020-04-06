#include<lpc17xx.h>

void delay(unsigned long int x)
{
	unsigned long int di;
	for(di=0;di<x;di++)
	{
	}
}

/*int main() //Decimal counter
{
	unsigned char arr[]={0x3F,0x06,0x5B,0x4f,0x66,0x6D,0x7D,0x07,0x7f, 0X6f};
	unsigned char val1,val2,i,j;
	SystemInit();
	LPC_SC->PCONP=0x00008000;
	LPC_GPIO0->FIOMASKH=0xFC7F;
	LPC_GPIO0->FIODIRH=0x0380;
	LPC_GPIO0->FIOCLRH=0x0380;
	
	for(i=0;i<10;i++)
	{
		val1=arr[i];
		LPC_GPIO0->FIOCLR3=0x01; // S clock low
		for(j=0;j<8;j++)
		{
			LPC_GPIO0->FIOCLR2=0x80; //SR clock low
			val2=val1&0x80; //Most significant bit
			val1=val1<<1;
			if(val2==0x80)
			{
				LPC_GPIO0->FIOSET3=0x02;
			}
			else
			{
				LPC_GPIO0->FIOCLR3=0x02;
			}
			LPC_GPIO0->FIOSET2=0x80; //SR clock as High
		}
		LPC_GPIO0->FIOSET3=0x01; // S clock as High
		// Display for One value completed;
		delay(0x50000);
	}
}*/

int main() //Decimal Up down counter
{
	unsigned char arr[]={0x3F,0x06,0x5B,0x4f,0x66,0x6D,0x7D,0x07,0x7f, 0X6f,0x7f,0x07,0x7D,0x6D,0x66,0x4F,0x5B,0x06,0x3F};
	unsigned char val1,val2,i,j;
	SystemInit();
	LPC_SC->PCONP=0x00008000;
	LPC_GPIO0->FIOMASKH=0xFC7F;
	LPC_GPIO0->FIODIRH=0x0380;
	LPC_GPIO0->FIOCLRH=0x0380;
	
	for(i=0;i<19;i++)
	{
		val1=arr[i];
		LPC_GPIO0->FIOCLR3=0x01; // S clock low
		for(j=0;j<8;j++)
		{
			LPC_GPIO0->FIOCLR2=0x80; //SR clock low
			val2=val1&0x80; //Most significant bit
			val1=val1<<1;
			if(val2==0x80)
			{
				LPC_GPIO0->FIOSET3=0x02;
			}
			else
			{
				LPC_GPIO0->FIOCLR3=0x02;
			}
			LPC_GPIO0->FIOSET2=0x80; //SR clock as High
		}
		LPC_GPIO0->FIOSET3=0x01; // S clock as High
		// Display for One value completed;
		delay(0x50000);
	}
}
