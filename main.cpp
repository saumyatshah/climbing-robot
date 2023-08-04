/*
 * child_robot.cpp
 *
 * Created: 20-07-2019 17:16:09
 * Author : Saumya
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include "GPIO.h"
#include "lcd.h"
#include <avr/delay.h>
#include <avr/interrupt.h>
#define rs PORTC7
#define en PORTC5
#define db4 PORTC3
#define db5 PORTC2
#define db6 PORTC4
#define db7 PORTC6

#define open 1
#define close 0

void l_motor_down(){
	PORTA|=1<<3;
	PORTA&=~(1<<2);
}
void r_motor_down(){
	PORTA|=1<<6;
	PORTA&=~(1<<7);
}
void r_motor_up(){
	PORTA|=1<<7;
	PORTA&=~(1<<6);
}
void motor_up(){
	PORTA|=1<<2;
	PORTA&=~(1<<3);
	PORTA|=1<<7;
	PORTA&=~(1<<6);

}
void motor_down(){
	PORTA|=1<<3;
	PORTA&=~(1<<2);
	PORTA|=1<<6;
	PORTA&=~(1<<7);

}
void piston(int x){                            ///hooks              1 is piston retracted             red in 3
if(x==1){
	PORTB|=1<<2;
	PORTB|=(1<<3);
}
if(x==0){
	 	PORTB&=~(1<<2);
	 	PORTB&=~(1<<3);

}
}
void piston_push(int x){    ///      need to push  the bot    0 is piston retracted      black in  7
	if (x==1)
	{
		PORTB|=(1<<4);
		PORTB|=(1<<7);
	}
	if (x==0)
	{
		PORTB&=~(1<<4);
		PORTB&=~(1<<7);
		
	}
}   //
ISR(INT0_vect){     //this func takes the motor up and all the pistons go to their actual position
	
	motor_up();
	
	waitms(850);
	piston(0);
	piston_push(0);
	PORTA|=0xFF;
	while(1);
}


int main(void)
{
	DDRA|=0xFF;
	DDRB|=0xFF;
	DDRD=0X00;
	PORTD=0XFF;
    ConfigLcd(rs,en,db4,db5,db6,db7);
	GICR =1<<INT0;
	MCUCR=1<<ISC01 | 1<<ISC00 ;
	sei();
	 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// ff
 

     
	    motor_down();
	    waitms(650);
	    piston(1);
	    motor_down();
	    waitms(750);
		PORTA=0xFF;
		piston(0);
		motor_up();
		waitms(850);
		PORTD|=0xFF;
		 motor_down();
		 waitms(650);
		 piston(1);
		 motor_down();
		 waitms(750);
		 PORTA=0xFF;
		 piston(0);
		 motor_up();
		 waitms(850);
		 PORTD|=0xFF;
	
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
piston(1);
motor_down();
waitms(1200);
PORTD=0xFF;
//	waitms(1000);
piston(0);
//	waitms(1000);
motor_up();
waitms(850);
PORTD|=0xFF;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
*/
motor_down();
waitms(200);
piston(1);
motor_down();
waitms(1000);
PORTD=0xFF;
piston(0);
motor_up();
waitms(850);
PORTD|=0xFF;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	       motor_down();
	       waitms(200);
	       piston(1);
	       motor_down();
	       waitms(1000);
	       PORTD=0xFF;
	//       waitms(1000);
		   piston(0);
	        piston_push(1);
		   //piston_push(0);
	      waitms(2000);
	       //	piston(0);
	       motor_up();
	       waitms(800);
	       waitms(40);
		   PORTD|=0xFF;
		   motor_down();
		   waitms(200);
		   piston(1);
		   motor_down();
		   waitms(1000);
		   PORTD=0xFF;
	
	
	
*/
while(1);
}

