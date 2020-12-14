
#include "main.h"
#include "states.h"
#include "events.h"

void watering_state_handler()
{
    
        machine.set_state(idle_state_handler);
}