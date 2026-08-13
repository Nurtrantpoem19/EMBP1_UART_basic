#define FOSC 16000000UL 
#define BAUD 9600
#define MYUBRR (FOSC / 16 / BAUD - 1)



#include <avr/io.h>

void UART_Init(unsigned int ubrr);


int main(void)
{
	UART_Init(MYUBRR);

}


void UART_Init(unsigned int ubrr) 
{
  UBRR0H = (unsigned char)(ubrr >> 8);
  UBRR0L = (unsigned char)ubrr;
  
  UCSR0C &= ~(1 << UMSEL00 | 1 << UMSEL01);
  
  UCSR0C &= ~(1 << UPM01 | 1 << UPM00);
  UCSR0C |= (1 << UPM01);



  

  return;
}

// #define FOSC 1843200// Clock Speed
// #define BAUD 9600
// #define (MYUBRR FOSC/16/BAUD-1)
// void main( void )
// {...
// USART_Init ( MYUBRR );
// ...} // main
// void USART_Init( unsigned int ubrr){
// /* Set baud rate */
// UBRRH = (unsigned char)(ubrr>>8);
// UBRRL = (unsigned char)ubrr;
// /* Enable receiver and transmitter */
// UCSRB = (1<<RXEN)|(1<<TXEN);
// /* Set frame format: 8data, 2stop bit */
// UCSRC = (1<<USBS)|(3<<UCSZ0);
// } // USART_Init
//
// #include <avr/io.h>

	}
