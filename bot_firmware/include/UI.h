#ifndef UI_H
#define UI_H

#include "tact.h"



class UI
{
private:

    tact myTacts[TACT_NB];
    // int m_tacts_states[TACT_NB];
    events m_incoming_event = nothing;

public:
    UI(/* args */);
    ~UI();

    void poll_tacts();

    events release_ui_event()
    {
        if (m_incoming_event)
        {

            Serial.println("FSM event");
            Serial.println(m_incoming_event);

            events event = m_incoming_event;
            m_incoming_event = nothing;
            return event;
        }
        else
            return nothing;
    }
};




#endif