/* 
 * File:   keypress.h
 * Author: user
 *
 * Created on 25 ??????? 2018, 22:33
 */

#ifndef KEYPRESS_H
#define	KEYPRESS_H

char state;
char state_count;

void short_press();
void long_press();
void very_long_press();
void read_keypress(); 


/* init RA0 button*/
#define init_keypress()\
    TRISA = 0b00000001;     

#endif	/* KEYPRESS_H */

