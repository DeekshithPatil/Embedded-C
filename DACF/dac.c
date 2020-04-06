#include<lpc17xx.h>
#include<math.h>

void delay(unsigned long int x)
{
	unsigned long int di;
	
	for(di=0;di<x;di++)
	{
	}
}

/*int main() //SquareWave
{
	int i; // i has to be of the type int
	SystemInit();
	LPC_SC->PCONP=0x20000000;  //29th BIt for power
	LPC_PINCON->PINSEL1=0x00200000; //P0.26 as 2nd alternate funtion
	while(1)
	{
		i=0x3FF;
		LPC_DAC->DACR=i<<6;
		delay(0x50000);
		i=0x000;
		LPC_DAC->DACR=i<<6;
		delay(0x50000);
	}
} */

/*int main() //Triangular
{
	int i; // variable for holding the value
	
	SystemInit();
	LPC_SC->PCONP=0x20000000; //29th bit for power
	LPC_PINCON->PINSEL1=0x00200000; //P0.26 as second alternate function
	
	while(1)
	{
		for(i=0;i<0x3FF;i++)
		{
			LPC_DAC->DACR=i<<6; //For increasing half
		}
		for(i=0x3FF;i>=0;i--)
		{
			LPC_DAC->DACR=i<<6; //For reducing half
		}
	}
}*/

/*int main() //Ramp
{
	int i;
	SystemInit();
	LPC_SC->PCONP=0x20000000; //29th bit 
	LPC_PINCON->PINSEL1=0x00200000; //P 0.26 as second alternate function
	while(1)
	{
		for(i=0;i<0x3FF;i++)
		{
			LPC_DAC->DACR=i<<6; //Aout is from 6th bit
		}
	}
}*/

/*int main() //Staircase
{
	int i;
	
	SystemInit();
	LPC_SC->PCONP=0x20000000; //29th bit
	LPC_PINCON->PINSEL10=0x00200000; //P0.26 as 2nd alternate function
	i=0;
	while(1)
	{
		LPC_DAC->DACR=i<<6;
		delay(0x5000);
		i=i+0x0FF;
		if(i>0x3FF)
		{
			i=0;
		}
	}
}*/

/*int main() //Full Sine wave
{
	float i;
	
	SystemInit();
	LPC_SC->PCONP=0x20000000; //29th bit
	LPC_PINCON->PINSEL10=0x00200000; //P0.26 as 2ns alt fn
	
	while(1)
	{
		for(i=0;i<(2*3.14);i=i+0.01)
		{
			LPC_DAC->DACR=((unsigned long int)(0x1FF*(sin(i)+1)))<<6; //include math and note that there implicit type conversion to unsigned long int
			//Imp Note: There is a braces afetr 0x1FF. as it multiplies with sin(i)+1 and 
			//not just with sin. if the bracess is not there then it geneates only half wave
		}
	}
}*/

/*int main() //Full Wave Rectifier
{
	float i;
	
	SystemInit();
	LPC_SC->PCONP=0x20000000;
	LPC_PINCON->PINSEL1=0x00200000;
	
	while(1)
	{
		for(i=0;i<3.14;i=i+0.01)
		{
			LPC_DAC->DACR=((unsigned long int)(0x1FF*sin(i)+1))<<6;
		}
	}
}*/

/*int main() //Half Wave Rectifier
{
	float i;
	
	SystemInit();
	LPC_SC->PCONP=0x20000000;
	LPC_PINCON->PINSEL1=0x00200000;
	
	while(1)
	{
		for(i=0;i<3.14;i=i+0.01)
		{
			LPC_DAC->DACR=((unsigned long int)(0x1FF*sin(i)+1))<<6;
		}
		i=0x1ff;
		delay(0x50000);
	}
}*/

/*int main() // Sine followed by tri
{
	float i;
	int j;
	
	SystemInit();
	LPC_SC->PCONP=0x20000000; //29th bit
	LPC_PINCON->PINSEL10=0x00200000; //P0.26 as 2nd alt fn
	
	while(1)
	{
			for(i=0;i<(2*3.14);i=i+0.01)
		{
			LPC_DAC->DACR=((unsigned long int)(0x1FF*(sin(i)+1)))<<6; //include math and note that there implicit type conversion to unsigned long int
		}
		
		for(j=0x1FF;j<=0x3FF;j++)
		{
			LPC_DAC->DACR=j<<6;
			delay(0x50);
		}
		for(j=0x3FF;j>=0x00;j--)
		{
			LPC_DAC->DACR=j<<6;
			delay(0x50);
		}
		for(j=0;j<=0x1FF;j++)
		{
			LPC_DAC->DACR=j<<6;
			delay(0x50);
		}
	}
}*/
