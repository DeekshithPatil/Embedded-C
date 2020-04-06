#include<lpc17xx.h>
#include<math.h>
void delay(unsigned long int x)
{
	unsigned long int di;
	for(di=0;di<x;di++)
	{
	}
}


	
	
/*int main() //Square wave
{ int i;
	LPC_SC->PCONP=0x20000000;
	LPC_PINCON->PINSEL1=0x00200000;
	
	while(1)
	{
		i=0x3FF;
		LPC_DAC->DACR=(i<<6);
		delay(0x50);
		i=0x000;
		LPC_DAC->DACR=(i<<6);
		delay(0x50);
	}
}*/

/*int main() //Traingular wave
{ int i;
	LPC_SC->PCONP=0x20000000;
	LPC_PINCON->PINSEL1=0x00200000;
	
	while(1)
	{
		for(i=0;i<0x3FF;i++)
		{
			LPC_DAC->DACR=(i<<6);
			delay(0x50);
		}
		for(i=0x3FF;i>0;i--)
		{
			LPC_DAC->DACR=(i<<6);
			delay(0x50);
		}
	}
}*/
/*int main() //Sawtooth wave
{ int i;
	LPC_SC->PCONP=0x20000000;
	LPC_PINCON->PINSEL1=0x00200000;
	
	while(1)
	{
		for(i=0;i<0x3FF;i++)
		{
			LPC_DAC->DACR=(i<<6);
			delay(0x50);
		}
	}
}*/

/*int main() //Staircase wave
{ int i;
	LPC_SC->PCONP=0x20000000;
	LPC_PINCON->PINSEL1=0x00200000;
	
	while(1)
	{
		for(i=0;i<=0x3FF;i=i+0xFF)
		{
			LPC_DAC->DACR=(i<<6);
			delay(0x50);
		}
	}
}*/

int main() //Sine wave
{ 	
	float j;
	LPC_SC->PCONP=0x20000000;
	LPC_PINCON->PINSEL1=0x00200000;
	while(1)
	{
		for(j=0;j<(2*3.14);(j=j+0.01))
		{
		LPC_DAC->DACR=((unsigned long int)(0x1ff*(sin(j)+1)))<<6;		
		
		}
		LPC_DAC->DACR=(0x1FF)<<6;
		delay(0x30000);
	}
}


		
		