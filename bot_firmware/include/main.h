#ifndef MAIN_H
#define MAIN_H

// Core Files
#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <EEPROM.h>
#include "FSM.h"                // Custom State Machine Class
#include "Atmega328p_Timers.h"  // Custom functions to interact with the chip's timers

// Ext libraries (used in current app, added from the platformio.ini file)
#include <Adafruit_GFX.h>
#include <HX711_ADC.h>
#include <Adafruit_ST7789.h>    // Includes Adafruit_GFX.h

// App Specific Files

// ----------------------------------------------------------------------
//      GLOBAL
// Global variables, declared extern here to be accessed by states source files
// ----------------------------------------------------------------------

#define DEBUG_LED_PIN (13)

extern FSM machine;

extern bool refreshFlag;
extern bool valuesRefreshFlag;



#endif // MAIN_H