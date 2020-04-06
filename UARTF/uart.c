#include<lpc17xx.h>

void uart_init()
{
	LPC_PINCON->PINSEL0=0x00000050;
	LPC_UART0->LCR=0x83;
	LPC_UART0->DLL=0x75;
	LPC_UART0->DLM=0x00;
	LPC_UART0->FDR=0x10;
	LPC_UART0->LCR=0x03;
}

/*int main() //5th character program
{
	unsigned char str1[50];
	unsigned char str2[]="Valid";
	unsigned char str3[]="Invalid";
	unsigned char i=0;
	SystemInit();
	
	LPC_SC->PCONP=0x00000008;
	uart_init();
	
	while(1)
	{
		
		while((LPC_UART0->LSR&0x01)!=0x01)
		{
		}
		str1[i]=LPC_UART0->RBR;
		
		if(str1[i]==0x0D)
		{
			break;
		}
		LPC_UART0->THR=str1[i];
		while((LPC_UART0->LSR&0x20)!=0x20)
		{
		}
	i++;
	}
	if(str1[4]=='v')
	{
	for(i=0;str2[i]!='\0';i++)
	{
		LPC_UART0->THR=str2[i];
		while((LPC_UART0->LSR&0x20)!=0x20)
		{
		}
	}
	}
	else
	{
	for(i=0;str3[i]!='\0';i++)
	{
		LPC_UART0->THR=str3[i];
		while((LPC_UART0->LSR&0x20)!=0x20)
		{
		}
	}
	}
	
}*/

/*int main() //Transmit two strings in different lines
{
	unsigned char str1[]="Valid";
	unsigned char str2[]="Invalid";
	unsigned char i=0;
	SystemInit();
	
	LPC_SC->PCONP=0x00000008;
	uart_init();
	for(i=0;str1[i]!='\0';i++)
	{
		LPC_UART0->THR=str1[i];
		while((LPC_UART0->LSR&0x20)!=0x20)
		{
		}
	}
	LPC_UART0->THR='\n'; //Note that it is '/n' and not 0x0D
	while((LPC_UART0->LSR&0x20)!=0x20)
	{
	}
	for(i=0;str2[i]!='\0';i++)
	{
		LPC_UART0->THR=str2[i];
		while((LPC_UART0->LSR&0x20)!=0x20)
		{
		}
	}
}*/

int main()
{
	unsigned char val;
	
	SystemInit();
	LPC_SC->PCONP=0x00008008;
	uart_init();
	LPC_GPIO0->FIOMASK3=0xEF;
	LPC_GPIO0->FIODIR3=0x10;
	
	while(1)
	{
		while((LPC_UART0->LSR&0x01)!=0x01)
		{
		}
		val=LPC_UART0->RBR;
		LPC_UART0->THR=val;
		while((LPC_UART0->LSR&0x20)!=0x20)
		{
		}
		if(val=='1')
		{
			LPC_GPIO0->FIOSET3=0x10;
		}
	}
}


	
