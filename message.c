#define FOSC 16000000UL 
#define BAUD 9600
#define MYUBRR (FOSC / 16 / BAUD - 1)



#include <avr/io.h>

void UART_Init(unsigned int ubrr);
uint8_t UART_Receive();
void UART_Transmit(uint8_t);

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

  UCSR0C &= ~(1 << USBS0);
//framing
//
  UCSR0C &= ~(1 << UCSZ01 | 1 << UCSZ00);
  UCSR0B &= ~(1 << UCSZ02);
  UCSR0C |= (1 << UCSZ01 | 1 << UCSZ00);


  //enabling transmitter and receiver
  UCSR0B = (1 << RXEN0); 
  UCSR0B |= (1 << TXEN0);
  


  

  return;
}


uint8_t UART_Receive()
{
  while((UCSR0A & (1 << RXC0)));

  return UDR0;


}

void UART_Transmit(uint8_t data)
{

  
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

// // 1. Fixed macro syntax and set clock speed for ATmega2560 (typically 16 MHz)
// #define FOSC 16000000UL 
// #define BAUD 9600
// #define MYUBRR (FOSC / 16 / BAUD - 1)
//
// // Function prototype
// void USART0_Init(unsigned int ubrr);
//
// int main(void) {
//     // Initialize USART0
//     USART0_Init(MYUBRR);
//
//     while (1) {
//         // Main loop
//     }
//
//     return 0;
// }
//
// void USART0_Init(unsigned int ubrr) {
//     /* Set baud rate (USART0 uses UBRR0H and UBRR0L) */
//     UBRR0H = (unsigned char)(ubrr >> 8);
//     UBRR0L = (unsigned char)ubrr;
//
//     /* Enable receiver and transmitter */
//     UCSR0B = (1 << RXEN0) | (1 << TXEN0);
//
//     /* Set frame format: 8 data bits, 2 stop bits */
//     // Note: ATmega2560 register requires setting the URSEL bit equivalent logic
//     // via UCSZ01 and UCSZ00 for 8-bit mode (3 << UCSZ00 sets both UCSZ01 and UCSZ00)
//     UCSR0C = (1 << USBS0) | (3 << UCSZ00);
// }
