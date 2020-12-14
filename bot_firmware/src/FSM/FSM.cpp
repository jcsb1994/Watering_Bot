#include "FSM.h"


void init_state_handler();

FSM::FSM()
{
    myUI = UI();
    state_handler = init_state_handler;
}

FSM::~FSM()
{
}

events FSM::poll_ui()
{
    // poll all UI user inputs (tacts, encoders, etc.)
    myUI.poll_tacts();

    // get an event from any of the polled input widgets
    incoming_UI_event = myUI.release_ui_event();


    if (incoming_UI_event)
    {
        Serial.print("FSM event");
        Serial.println(incoming_UI_event);
    }

    return incoming_UI_event;
}

/*
Sensor_events FSM::poll_sensors()
    whatever sensor->read();
    incoming
 */

void FSM::handle_state()
{
    state_handler();
}