/* 
 * File:   keypress.h
 * Author: user
 *
 * Created on 25 ??????? 2018, 22:33
 */

#ifndef KEYPRESS_H
#define	KEYPRESS_H

#define BUTTON1 RA0
#define BUTTON2 RA1

#define MIN_SHORT 1
#define MAX_SHORT 10
#define MIN_LONG 9
#define MAX_LONG 20
#define MIN_VERY_LONG 19


char state1;
char state_count1;
char state2;
char state_count2;

void short_press(unsigned char);
void long_press(unsigned char);
void very_long_press(unsigned char);
void read_keypress(); 




/* init RA0 button*/
#define init_keypress()\
    TRISA = 0b00000011;

#endif	/* KEYPRESS_H */

