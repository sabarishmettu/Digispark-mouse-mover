/*
 * Digispark HID Mouse Mover
 * --------------------------
 * Moves the mouse cursor randomly to prevent
 * the computer from going to sleep or activating
 * the screensaver.
 *
 * No clicks — cursor movement only.
 * Appears as a generic HID mouse to the host PC.
 *
 * Board:   Digispark (Default - 16.5mhz)
 * Library: DigiMouse
 */

#include "DigiMouse.h"

// ---- Settings ----
#define MOVE_INTERVAL  2000   // ms between movements
#define MOVE_RANGE     20     // max pixels per move (+/-)
// ------------------

void setup() {
  DigiMouse.begin();
}

void loop() {
  DigiMouse.delay(MOVE_INTERVAL);

  // Pseudo-random movement using millis()
  int moveX = (int8_t)(millis() % (MOVE_RANGE * 2 + 1)) - MOVE_RANGE;
  int moveY = (int8_t)((millis() / (MOVE_RANGE * 2 + 1)) % (MOVE_RANGE * 2 + 1)) - MOVE_RANGE;

  DigiMouse.moveX(moveX);
  DigiMouse.delay(50);
  DigiMouse.moveY(moveY);

  DigiMouse.update();
}
