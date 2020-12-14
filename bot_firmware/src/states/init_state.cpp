
#include "main.h"
#include "states.h"
#include "events.h"


// ----------------------------------------------------------------------
//      INIT STATE
// ----------------------------------------------------------------------

void init_state_handler()
{

    machine.set_state(idle_state_handler);

}
