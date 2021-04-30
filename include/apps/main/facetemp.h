#ifndef OSW_APP_FACETEMP_H
#define OSW_APP_FACETEMP_H

#include <osw_hal.h>

#include "osw_app.h"

class OswAppFacetemp : public OswApp {
 public:
  OswAppFacetemp(void){};
  void setup(OswHal* hal);
  void loop(OswHal* hal);
  void stop(OswHal* hal);
  ~OswAppFacetemp(){};

 private:
};

#endif