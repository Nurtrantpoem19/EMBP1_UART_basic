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


  unsigned char temp;
  while(1)
  {
    temp = UART_Receive();
    UART_Transmit(temp);

  }


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
  while(!(UCSR0A & (1 << RXC0)));

  return UDR0;


}

void UART_Transmit(uint8_t data)
{

  while(!(UCSR0A & ( 1 << UDRE0)));

  UDR0 = data;
  return;

  
}



