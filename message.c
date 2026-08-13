#define FOSC 16000000UL 
#define BAUD 9600
#define MYUBRR (FOSC / 16 / BAUD - 1)



#include <avr/io.h>

void UART_Init(unsigned int ubrr);


int main(void)
{
	UART_Init(MYUBRR);

}



	}
