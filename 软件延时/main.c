#include <ny8.h>

void delay_ms(unsigned int count);

#define LED_HIGH PORTB &= 0xF7;
#define LED_LOW PORTB |= 0x08;

void main(void)
{
	// clockConfig();

	IOSTB = 0; // set PortA as output mode
	unsigned int delayNum = 1000;

	while (1)
	{
		// LED = off
		LED_LOW;
		delay_ms(delayNum);
		LED_HIGH;
		delay_ms(delayNum);
		CLRWDT();
	}
}

/*
主频为 4 MHz 时
1.  一个 nop 一个周期 需要 1um， 一个周期是 4 个时钟周期
2. 一个 while(i--) 需要 14.05um （i 是 unsigned int 类型）
**/
void delay_ms(unsigned int count)
{
	unsigned int i = count;
	while (i--)
	{
		unsigned int j = 70;
		while (j--)
			;
		NOP();
		NOP();
	}
}
