#include <xc.h>
#include <pic16f648a.h>
#include <stdio.h>
#include <stdlib.h>

char state = 0;
char state_count = 0;

void short_press(){
    //printf(" ===== Short press %d =====\r\n", state_count );
    RA1 = !RA1;
};

void long_press(){
    //printf(" ===== long press %d ======\r\n", state_count );
    RA2 = !RA2;
};

void very_long_press(){
    //printf(" ==== Very long press %d ====\r\n", state_count );
    RA3 = !RA3;
};

void read_keypress() {
    if ( RA0 == 0 ) {  
            if( state == 0 ) {  
                state = 1; 
                state_count = 1; 
            } else { 
                state_count ++; 
            }; 
        } else { 
            if( state == 1 ){ 
                if (state_count > 1 && state_count < 10 ) short_press(); 
                if (state_count > 9 && state_count < 20) long_press(); 
                if (state_count > 19 ) very_long_press(); 
                state = 0; 
                state_count = 0; 
            };
        };
};