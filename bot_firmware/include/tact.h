#ifndef TACT_H
#define TACT_H

#include <Arduino.h>
#include "events.h"

/*##################################################
            MACROS
##################################################*/

#define TACT_NB 3
#define LONG_PRESS_DELAY (400)
#define BUTTON_ACTIVE_STATE_CONFIG 0
// Debounce macros
#define DEBOUNCED 1
#define NOT_DEBOUNCED 0
#define DEBOUNCE_TIME 0.3
#define SAMPLE_FREQUENCY 6
#define MAXIMUM (SAMPLE_FREQUENCY*DEBOUNCE_TIME)
// Polling macros
#define SHORT_EFFECT_REQUIRED 1
#define RELEASE_EFFECT_REQUIRED 2
#define LONG_EFFECT_REQUIRED 3

/*##################################################
            DECLARATION
##################################################*/

struct input_shift_register
{
    bool not_used;
    int data;
    int *ptr_to_data;
};


//#######################################################################//
// tact_link struct
//      used to link the events to different types of inputs from the tact.
//      tact_links object is defined in main
//#######################################################################//

struct tact_link
{
    int pin;

    events short_press;
    events release_press;
    events long_press;
    tact_link(int pin,
        events short_press_event = nothing,
        events release_press_event = nothing,
        events long_press_event = nothing) : pin(pin),
        short_press(short_press_event),
        release_press(release_press_event),
        long_press(long_press_event) {}
};

extern struct tact_link tact_links[TACT_NB];

//#######################################################################//
// tact class
//      manages tactile buttons
//#######################################################################//

class tact
{

private:
    int pin;
    static int mCount;  // counts how many tacts are created
    unsigned int mID;   // sets a specific ID for each tact in order of creation

    short state = 0;    // carries the current state after polling

    bool input_shift_used;
    input_shift_register *input_shift_ptr;

    // Debounce variables
    volatile unsigned int input = 1; // Current state of the tact switch
    volatile unsigned int integrator;
    volatile bool now_debounced_input = 1; // Output of the algorithm
    volatile bool last_debounced_input = 1;

    unsigned long long_press_counter = 0;
    bool long_effect_done = 0;
    bool is_pressed = false;    // Keeps track of which button is pressed during poll (useful when simultaneousButtonPressesConfig)





public:
    tact() {};
    tact(int assigned_pin);                              // Constructor
    tact(int assigned_pin, input_shift_register &shift); // Overloaded constructor for tacts linked to a shift register chip

    void debounce();

    int poll();

    static int *pressOutput;

    void setPin(int assigned_pin)
    {
        tact::pin = assigned_pin;
    }

    int getPin() {
        return tact::pin;
    }

};

#endif // Header guard