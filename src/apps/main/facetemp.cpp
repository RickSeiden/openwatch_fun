// include your face.h file
#include "./apps/main/facetemp.h"
// #define GIF_BG

#include <RtcDS3231.h>
#include <Wire.h>
#include <gfx_util.h>
#include <osw_app.h>
#include <osw_hal.h>
#include <time.h>

#include "RtcDateTime.h"
#include "osw_ui_util.h"
#include "config.h"

// you must give this variable a unique name across the entire system
RtcDS3231<TwoWire> faceRTC(Wire);

// ESP32 complains if not included
#if defined(ARDUINO_ARCH_ESP32)
#include <inttypes.h>
#endif

#ifdef GIF_BG
#include "./apps/_experiments/gif_player.h"
#endif

#include "bma400_defs.h"

// you must give this function a unique name across the entire system
// this is where you write code to draw your face

void drawYourWatch(OswHal* hal, Graphics2D* gfx2d) {
  // get the time and put it into these variables
  uint32_t second = 0;
  uint32_t minute = 0;
  uint32_t hour = 0;
  hal->getLocalTime(&hour, &minute, &second);

  // get the date and put it into these variables
  // uncomment if you want to use them
  //uint8_t currentMonth = faceRTC.GetDateTime().Month();
  //uint8_t currentDay = faceRTC.GetDateTime().Day();
  //uint16_t currentYear = faceRTC.GetDateTime().Year();

  // get the steps
  // uncomment if you want to use them
  //uint32_t steps = hal->getStepCount();

  // you can use print2Digits to pad a number less than 10 to a two digit 9->09
  // and then print it to the canvas

  // print2Digits(hal, hour);

  /*
    This example shows printing the current time to the watch face

  */

  //set the curor location centered top to bottom and left to right
  hal->getCanvas()->setTextSize(4);
  hal->getCanvas()->setCursor((DISP_W -defaultFontXOffset(8, 4))/2, (DISP_H - defaultFontYOffset(1, 4)) / 2);

  //print the time
  print2Digits(hal, hour);
  hal->getCanvas()->print(":");
  print2Digits(hal, minute);
  hal->getCanvas()->print(":");
  print2Digits(hal, second);
}

void OswAppFacetemp::setup(OswHal* hal) {
#ifdef GIF_BG
  bgGif->setup(hal);
#endif
}

void OswAppFacetemp::loop(OswHal* hal) {
  static long loopCount = 0;
  // static long lastDraw = 0;
  loopCount++;

#ifdef GIF_BG
  // if (millis() - 1000 > lastDraw) {
  bgGif->loop(hal);
  // lastDraw = millis();
  // }
#else
  hal->getCanvas()->getGraphics2D()->fill(rgb565(0, 0, 0));
#endif

  drawYourWatch(hal, hal->getCanvas()->getGraphics2D());

  hal->requestFlush();
}

void OswAppFacetemp::stop(OswHal* hal) {
  // hal->disableDisplayBuffer();

#ifdef GIF_BG
  bgGif->stop(hal);
#endif
}
