/*	Author: dsale010
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

#include <stdlib.h>

#define A PINA
#define B PINB
#define C PINC
#define MAX_KG 140
#define MAX_KG_DIFF 80

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00;    PORTA = 0xFF;
    DDRB = 0x00;    PORTB = 0xFF;
    DDRC = 0x00;    PORTC = 0xFF;
    DDRD = 0xFF;    PORTD = 0x00;
    
    /* Insert your solution below */
    while (1) {
        unsigned char outtie = 0;
        unsigned short sum = 0;
        short diff = 0;
        
        sum = A + B + C;
        diff =abs(C - A);
        
        if (sum >= MAX_KG){
            outtie = (outtie | 0x01);
        }
        
        if (diff >= MAX_KG_DIFF)
            outtie = (outtie | 0x02);
            
        outtie |= (sum & 0xFC);
       
    }
    
    return 1;
}
