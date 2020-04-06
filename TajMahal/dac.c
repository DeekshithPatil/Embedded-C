#include<LPC17XX.H>
#include<math.h>
void delay(unsigned int y)
{
	unsigned int x;
	for(x=0;x<y;x++)
	{}
}
void main()
{	
	unsigned int i,v;
	SystemInit();
	LPC_PINCON->PINSEL1=0X00200000;
	while(1)
	{
		LPC_DAC->DACR=(0X0000<<6);
		delay(0x500);
		
		LPC_DAC->DACR=(0X01FF<<6);
		delay(0x500);
		
		for(i=0;i<51;i++)
		{
			v=(0x1FF + 0x1FF*sin(i*3.1414/180));
			LPC_DAC->DACR=(v<<6);
		}
		
		for(i=v;i<0x400;i++)
		{
			LPC_DAC->DACR=(i<<6);
		}
		
		for(i=0x3ff;i>=v;i--)
		{
			LPC_DAC->DACR=(i<<6);
		}
			
		for(i=50;i>0;i--)
		{
			v=(0x1FF + 0x1FF*sin(i*3.1414/180));
			LPC_DAC->DACR=(v<<6);
		}
		
		LPC_DAC->DACR=(0X01FF<<6);
		delay(0x900);
	}
}