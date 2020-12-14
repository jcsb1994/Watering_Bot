#ifndef FSM_H
#define FSM_H

#include "UI.h"


class FSM
{
private:
    /* data */
    UI myUI;
    events incoming_UI_event;
    void (*state_handler)();

public:
    FSM();
    ~FSM();

    events poll_ui();

    void handle_state();
    void set_state(void state(void)) {state_handler = state; }
};


#endif