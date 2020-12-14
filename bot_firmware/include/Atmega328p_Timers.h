#ifndef ATMEGA328P_TIMERS_H
#define ATMEGA328P_TIMERS_H

#include <Arduino.h>

#define WDT_CONFIG 0
#define TIMER_ONE_CONFIG 1


/*##################################################
            WDT
##################################################*/

#if WDT_CONFIG

extern volatile uint8_t wdt_counter;

/***************************************************************************
 * WDT_setup function
 * This function sets the appropriate registers for WDT to be turned on.
 ***************************************************************************/

void WDT_setup();

#endif

/*##################################################
            TIMER1
##################################################*/
#if TIMER_ONE_CONFIG

void timer1_setup();

void timer0_setup();

/***************************************************************************
 * timer1_setup function
 * This function sets the appropriate registers for WDT to be turned on.
 ***************************************************************************/

#endif

#endif // ATMEGA328P_TIMERS_H