#include "UI.h"

UI::UI()
{
    for (int i = 0; i < TACT_NB; i++)
    {
        myTacts[i] = tact(tact_links[i].pin);
    }
}

UI::~UI()
{
}

void UI::poll_tacts()
{

    for (int i = 0; i < TACT_NB; i++)
    {
        int currentState;
        if (myTacts[i].getPin())
        {
            currentState = myTacts[i].poll();
        }
        switch (currentState)
        {
        case SHORT_EFFECT_REQUIRED:
            m_incoming_event = tact_links[i].short_press;
            break;

        case RELEASE_EFFECT_REQUIRED:
            m_incoming_event = tact_links[i].release_press;
            break;

        case LONG_EFFECT_REQUIRED:
            m_incoming_event = tact_links[i].long_press;
            break;

        default:
            break;
        }

    }
}


