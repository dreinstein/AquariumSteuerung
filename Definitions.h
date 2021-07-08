#ifndef _DEFINITIONS
#define _DEFINITIONS

#include "Arduino.h"

// ARDUINO IN/OUT     PIN       Serial     Function
#define RELAIS2       9     /// 6          LIGHT
#define RELAIS3       12    /// 7          PUMP
#define RELAIS4       11    /// 8          HEATER ,
#define TEMPSENSOR    8	                 //TempSensor
#define SERVICEBUTTON 7                  // Pump, Heater
#define ONOFFBUTTON   6                  //Pump, Heater (same as light is now controlled by juwel control																													v     hight: Pump, TempSensor, Light out //IN

// Relais1 light
// Relais2 pump
// Relais3 heater

// interface serial
// 1 - 5V
// 5 - Ground
// 6,7,8 datas, see above


// LCD positions
#define CURSERPOSTEMPSTRING  0
#define CURSERPOSTEMPVALUE   8
#define CURSERPOSCSTRING     14
#define MAXSEC				 59
#define DISPLAYTOGGLETIME    20
#define TEMP_RESOLUTION      12

#define WATERTEMPERATUR_VALIDMAXVALUE  40
#define WATERTEMPERATUR_VALIDMINVALUE  10

// active and inavtive settings, can be changed for relais high active or low acive
#define ACTIVE          HIGH
#define INACTIVE        LOW

// value for actualising display  and light calculation 
#define REFRESHVARIABLE_MAX   80000
#define TOGGLE_TIME_DISPLAY   200
#define DELAYTIME_BASE		  		200
#define ACTUALISE_LIGHT_MULTiPLIER  20
#define ACTUALISE_TIME_MULTIPLIER   800
#define ACTUALISE_PUMP_MULTIPLIER   2000
#define ACTUALISE_REMOTE_MULTIPLIER 8000
#define ACTUALISE_NTC_MULTIPLIER    8000

// macro calculate when to actualise
#define TO_ACTUALISE(REFRESH,MULTIPLIER) (!((REFRESH*DELAYTIME_BASE)%MULTIPLIER))

#endif
