# openwatch_fun
Some extra files I've added to my openwatch

Note that this is not a branch or fork of the openwatch project.  These are files that I've added to my openwatch that I thought others might find helpful or usefull.

## Watch face template
  * src/apps/main/facetemp.cpp
  * include/apps/main/facetemp.h
  * A template for watch faces that already fetches the time, date and steps in the loop

## Watch face changer
  * src/apps/main/face_off.cpp
  * include/apps/main/face_off.h
  * An app to put into main.cpp as your watch face
  * Configure face_off.cpp with your selected watch faces the same way you would configure main.cpp with applications
  * Button 2 (lower left) switches between faces
  * Last displayed face stored in TTGO's "external" flash memory
  * Memory only read when the app starts, and only written to if app changes with a different face than when it started--it does not write to the memory on change to avoid wear on the flash memory
