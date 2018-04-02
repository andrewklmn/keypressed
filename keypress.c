#include <xc.h>
#include <pic16f648a.h>
#include <stdio.h>
#include <stdlib.h>

#include "keypress.h"

char state1 = 0;
char state_count1 = 0;
char state2 = 0;
char state_count2 = 0;

void short_press(unsigned char key){
    //printf(" ===== Short press %d =====\r\n", state_count );
    if(key==1) RA2 = 1;
    if(key==2) RA2 = 0;
};

void long_press(unsigned char key){
    //printf(" ===== long press %d ======\r\n", state_count );
    if(key==1) RA3 = 1;
    if(key==2) RA3 = 0;
};

void very_long_press(unsigned char key){
    //printf(" ==== Very long press %d ====\r\n", state_count );
    if(key==1) RA4 = 1;
    if(key==2) RA4 = 0;    
};

void read_keypress() {
    if ( BUTTON1 == 0 ) {  
        if( state1 == 0 ) {  
            state1 = 1; 
            state_count1 = 1; 
        } else { 
            state_count1 ++; 
        }; 
    } else { 
        if( state1 == 1 ){ 
            if (state_count1 > MIN_SHORT && state_count1 < MAX_SHORT ) short_press(1); 
            if (state_count1 > MIN_LONG && state_count1 < MAX_LONG) long_press(1); 
            if (state_count1 > MIN_VERY_LONG ) very_long_press(1); 
            state1 = 0; 
            state_count1 = 0; 
        };
    };
    if ( BUTTON2 == 0 ) {  
        if( state2 == 0 ) {  
            state2 = 1; 
            state_count2 = 1; 
        } else { 
            state_count2 ++; 
        }; 
    } else { 
        if( state2 == 1 ){ 
            if (state_count2 > MIN_SHORT && state_count2 < MAX_SHORT ) short_press(2); 
            if (state_count2 > MIN_LONG && state_count2 < MAX_LONG) long_press(2); 
            if (state_count2 > MIN_VERY_LONG ) very_long_press(2); 
            state2 = 0; 
            state_count2 = 0; 
        };
    };
};