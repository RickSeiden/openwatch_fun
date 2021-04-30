#ifndef OSW_APP_FACE_OFF_H
#define OSW_APP_FACE_OFF_H

#include <osw_hal.h>

#include "osw_app.h"

class OswAppFaceOff : public OswApp {
 public:
  OswAppFaceOff(void){};
  void setup(OswHal* hal);
  void loop(OswHal* hal);
  void stop(OswHal* hal);
  ~OswAppFaceOff(){};

 private:
};

#endif