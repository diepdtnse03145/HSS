#ifndef HSSSENSOR_H_INCLUDED
#define HSSSENSOR_H_INCLUDED

#include "HSSConstant.h"

extern int pirValue;
extern int switchValue;
extern int bellValue;


extern void readPirValue();
extern void readDoorBellValue();
extern void readSwitchValue();
extern void updateSensorValue();

#endif // HSSSENSOR_H_INCLUDED
