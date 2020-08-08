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

#define inputs (PINA & 0x0F)
unsigned char outtie = 0;

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00;    PORTA = 0xFF;
    DDRC = 0xFF;    PORTC = 0x00;
    
    unsigned char cnt = 0, i = 0;
    unsigned char temp = inputs;
    
    /* Insert your solution below */
    while (1) {
        while (i < 4){
            if ((temp & 0x01) == 1)
               cnt++;
            
            temp = temp >> 1;
            i++;
        }
        
        PORTC = cnt;
    }
    return 1;
}
