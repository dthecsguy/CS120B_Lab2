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

#define inputs PINA
unsigned char outtie = 0;

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00;    PORTA = 0xFF;
    DDRC = 0xFF;    PORTC = 0x00;
    
    /* Insert your solution below */
    while (1) {
        unsigned char cnt = 0, i = 0;
        unsigned char temp = inputs;
        
        while (i < 4){
            if (temp & 0x01){
                cnt++;
            }
            
            i++;
            temp = temp >> 1;
        }
        
        outtie = (cnt == 4) ? (cnt & 0x0F) | 0x80 : (cnt & 0x0F) | 0x00;
    }
    
    return 1;
}
