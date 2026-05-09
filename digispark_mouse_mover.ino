/*
 * Digispark HID Mouse Mover — Smooth Infinity Shape
 * --------------------------------------------------
 * Moves the mouse cursor in a smooth infinity (∞) shape
 * to prevent the computer from sleeping or activating
 * the screensaver.
 *
 * No clicks — cursor movement only.
 * Appears as a generic HID mouse to the host PC.
 * Uses sub-pixel accumulation for real mouse smoothness.
 *
 * Board:   Digispark (Default - 16.5mhz)
 * Library: DigiMouse
 */

#include "DigiMouse.h"

// ---- Settings ----
#define STEPS        200    // more steps = smoother
#define RADIUS       10     // size of infinity shape (pixels)
#define STEP_DELAY   15     // ms per step (lower = faster)
// ------------------

float prevX = 0;
float prevY = 0;
float accumX = 0;  // sub-pixel accumulator
float accumY = 0;

void setup() {
  DigiMouse.begin();
  DigiMouse.delay(2000);
}

void loop() {
  for (int i = 0; i < STEPS; i++) {
    float t = (2.0 * 3.14159265 * i) / STEPS;

    // Lemniscate of Bernoulli (infinity shape)
    float denom = 1 + sin(t) * sin(t);
    float x = RADIUS * cos(t) / denom;
    float y = RADIUS * sin(t) * cos(t) / denom;

    // Accumulate fractional movements (sub-pixel smoothness)
    accumX += (x - prevX);
    accumY += (y - prevY);

    // Only send whole pixel movements
    int moveX = (int)accumX;
    int moveY = (int)accumY;

    // Keep the leftover fraction for next step
    accumX -= moveX;
    accumY -= moveY;

    if (moveX != 0 || moveY != 0) {
      DigiMouse.moveX(moveX);
      DigiMouse.moveY(moveY);
      DigiMouse.update();
    }

    DigiMouse.delay(STEP_DELAY);

    prevX = x;
    prevY = y;
  }
}
