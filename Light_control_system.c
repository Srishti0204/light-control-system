#include<avr/io.h>
#define F_CPU 16000000UL
#include<util/delay.h>
#define lcd PORTD
#include<my_library/lcd.h>

void main()
{
	DDRB=0b11111111;
	DDRA=0b11111100;
	DDRD=0b11111111;
	lcd_init();
	lcd_command(0x80);
	lcd_string("IN:     OUT:     ");
	lcd_command(0xc0);
	lcd_string("CURRENT:");
	int in=0,out=0,current=0;	
	while(1)
	{
		if((PINA&0x01)==0x01)
		{
			while(PINA&0x01)
			{
				//goto l1;
			}
			in++;
			lcd_command(0x85);
			number_infinity(in);
		}
		if((PINA&0x02)==0x02)
		{
			while(PINA&0x02)
			{
				//goto l0;
			}
			out++;
			lcd_command(0x8F);
			number_infinity(out);
		}
		current=in-out;
		lcd_command(0xCF);
		number_infinity(current);
		if(current>0) {PORTB=0b00000001;}

		else 
		PORTB=0b00000000;

	}
}
