
#include "main.h"
#include "states.h"
#include "events.h"

void measuring_state_handler()
{

    switch (machine.poll_ui())
    {
    case events::nothing:
    default:
        break;
    }
    
    machine.set_state(idle_state_handler);
}