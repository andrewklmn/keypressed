/*
 * File:   main.c
 * Author: user
 *
 * Created on 25 ??????? 2018, 16:38
 */


#define _XTAL_FREQ 4000000      // ???????? ??????? 


// CONFIG
#pragma config FOSC = INTOSCCLK // Oscillator Selection bits (INTOSC oscillator: CLKOUT function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON       // RA5/MCLR/VPP Pin Function Select bit (RA5/MCLR/VPP pin function is MCLR)
#pragma config BOREN = OFF      // Brown-out Detect Enable bit (BOD disabled)
#pragma config LVP = ON         // Low-Voltage Programming Enable bit (RB4/PGM pin has PGM function, low-voltage programming enabled)
#pragma config CPD = OFF        // Data EE Memory Code Protection bit (Data memory code protection off)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)


#include <xc.h>
#include <pic16f648a.h>
#include <stdio.h>
#include <stdlib.h>
#include "usart.h"
#include "keypress.h"

unsigned int i = 0;

void main(void) {
    
    init_comms();   // ????? UART
    init_keypress();// ????? ??????
    
    while ( 1 ) {
        read_keypress(); // ????????? ??????
        i++;
        __delay_ms(100);
    };

    return;
}
