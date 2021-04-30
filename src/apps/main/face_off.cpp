#include <Arduino.h>
#include <Wire.h>
#include <config.h>
#include <osw_app.h>
#include <osw_hal.h>
#include <osw_pins.h>
#include <Preferences.h>


// #include "./apps/_experiments/runtime_test.h"
#include "./apps/main/watchface.h"
#include "./apps/main/facetemp.h"
#include "./apps/main/rickface.h"
#include "./apps/main/face_off.h"


#define PREF_NAME "face_off"
#define PREF_SPACE "face_off_count"

// HINT: NUM_FACE must match the number of faces below!

#define NUM_FACES 2

uint8_t facePtr = 0;
uint8_t startPtr=0;

Preferences prefs;
OswApp *faceApps[] = {
    new OswAppRickface(),
    new OswAppWatchface()
};

void OswAppFaceOff::setup(OswHal* hal) {
  faceApps[facePtr]->setup(hal);
  prefs.begin(PREF_SPACE,false);
  facePtr=prefs.getUInt(PREF_NAME);
  startPtr=facePtr;
}

void OswAppFaceOff::loop(OswHal* hal) {
 
   // handle click to switch
  if (hal->btn2Down()) {
    // switch face
    Serial.print("button click facePtr before=");
    Serial.print(facePtr);
    faceApps[facePtr]->stop(hal);
    facePtr++;
    facePtr %= NUM_FACES;
    Serial.print(" facePtr after=");
    Serial.print(facePtr);
    faceApps[facePtr]->setup(hal);
  }

  faceApps[facePtr]->loop(hal);
 
}

void OswAppFaceOff::stop(OswHal* hal){
  //only write the current pointer if it has changed from the original
  if (startPtr!=facePtr){
    prefs.putUInt(PREF_NAME,facePtr);
  }
  prefs.end();
  faceApps[facePtr]->stop(hal);
}
