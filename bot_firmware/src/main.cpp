

#include "main.h"
#include "states.h"
#include "events.h"
/*
TO IMPLEMENT
- add init tare as an init fct
- add timer for printing in live mode
- add logo
- change list menu to show ++ values (as a list)
- correct bug timer
- correct why peak starts printing nonstop after reaching max time once
*/

struct tact_link tact_links[TACT_NB]{{2, nothing, nothing, nothing},
                                     {3, nothing, nothing, nothing},
                                     {4, nothing, nothing, nothing}};

#define WATER_LVL_ANALOG_PIN (A4)
#define MOTOR_GATE_PIN (5)

bool refreshFlag = false;
bool valuesRefreshFlag = false;

void setup()
{
    Serial.begin(9600);
    pinMode(DEBUG_LED_PIN, OUTPUT);
    pinMode(MOTOR_GATE_PIN, OUTPUT);
    pinMode(WATER_LVL_ANALOG_PIN, INPUT);
}

FSM machine;

void loop()
{
    machine.handle_state();
}
