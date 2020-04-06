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

int main()
{ unsigned char i;
	unsigned char val1[]="Hello world 1";
	unsigned char val2[]="Hello world 2";
	SystemInit();
	LPC_SC->PCONP=0x00000008;
	uart_init();
	
	for(i=0;i<=15;i++)
	{
	LPC_UART0->THR=val1[i];
	while((LPC_UART0->LSR&0x20)!=0x20)
	{}
	}	
	LPC_UART0->THR='\n';
	while((LPC_UART0->LSR&0x20)!=0x20)
	{}
	for(i=0;i<=15;i++)
	{
	LPC_UART0->THR=val2[i];
	while((LPC_UART0->LSR&0x20)!=0x20)
	{}
	}	
}

/*int main()
{ unsigned char val,i;
	unsigned char arr[50];
	unsigned char val1[]="Hello world ";
	SystemInit();
	LPC_SC->PCONP=0x00000008;
	uart_init();
		i=0;
	while(1)
	{
		while((LPC_UART0->LSR&0x01)!=0x01)
		{}
		val=LPC_UART0->RBR;
		arr[i]=val;
			if(val==0x0D)
				break;
		LPC_UART0->THR=val;
		while((LPC_UART0->LSR&0x20)!=0x20)
		{}
		i++;
	}
		LPC_UART0->THR='\n';
		while((LPC_UART0->LSR&0x20)!=0x20)
			{}
	if(arr[4]=='v')
	{
		for(i=0;i<=10;i++)
		{
			LPC_UART0->THR=val1[i];
			while((LPC_UART0->LSR&0x20)!=0x20)
			{}
		}	
	}
}*/