/*	Author: dsale010
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 
    I dont understand how to represent the sum because the highest sum can be 765 which would
    need 10 bit. Only taking the highest six would not yield a number within 3. 
    
    I noticed with numbers that arent extreme we can represent the sum as highest 6 bits give or take 3.
 
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

#include <stdlib.h>

#define A (PINA & 0xFF)
#define B (PINB & 0xFF)
#define C (PINC & 0xFF)
#define MAX_KG 140
#define MAX_KG_DIFF 80

int main(void){
    /* Insert DDR and PORT initializations */
    DDRA = 0x00;    PORTA = 0xFF;
    DDRB = 0x00;    PORTB = 0xFF;
    DDRC = 0x00;    PORTC = 0xFF;
    DDRD = 0xFF;    PORTD = 0x00;
        
    /* Insert your solution below */
    while(1){
        unsigned char outtie = 0;
        unsigned char sum = 0;
        unsigned char diff = 0;
        
        sum = A + B + C;
        diff = abs(C - A);
        
        if (sum >= MAX_KG){
            outtie = (outtie | 0x01);
        }
        
        if (diff >= MAX_KG_DIFF)
            outtie = (outtie | 0x02);
            
        outtie = outtie | (sum & 0xFC);
        
        PORTD = outtie;
    }
    
    return 1;
}
