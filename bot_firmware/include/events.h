#ifndef EVENTS_H
#define EVENTS_H

enum events
{
    nothing,    // Value 0 when no events are incoming
    increment,  // goes to next saved value
    decrement,  // goes to previous saved value
    saveToEEPROM,
    tare,
    switchReadingMode,
    switchMenuPage // toggle saved readings or live readings
};

#endif // EVENTS_H