#include <avr/io.h>

void UART_Init(void);
int main(void)
{
	UART_Init();

}
	void UART_Init(void)
	{
		UCSR0C | (1 << UMSEL01);

		return;


	}
