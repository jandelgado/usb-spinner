// USB spinner firmware.
//
// Announces itself as an USB mouse device. Reads the encoder and reports value
// as horizontal mouse movements. Attached buttons are mapped to mouse buttons.
//
// https://github.com/jandelgado/usb-spinner
//
// (c) copyright 2020 Jan Delgado
//
#include <Arduino.h>
#include <Mouse.h>      // https://github.com/arduino-libraries/Mouse
#include <Button.h>     // https://github.com/madleech/Button
#include <Encoder.h>    // https://github.com/PaulStoffregen/Encoder


// pins 0 and 1 have interrupt support on the pro micro
constexpr auto ENCODER0 = 1;
constexpr auto ENCODER1 = 0;
constexpr auto BUTTON1  = 2;
constexpr auto BUTTON2  = 3;

Encoder spinner(ENCODER0, ENCODER1);
Button button1(BUTTON1);
Button button2(BUTTON2);

void setup() {
    Mouse.begin();
    button1.begin();
    button2.begin();
}

void loop() {
  static int pos = 0;

  auto newPos = spinner.read();
  if (pos != newPos) {
    const auto offset = newPos - pos;
    pos = newPos;
    Mouse.move(offset, 0, 0);
  }

  if (button1.pressed()) {
    Mouse.press(MOUSE_LEFT);
  }
  if (button1.released()) {
    Mouse.release(MOUSE_LEFT);
  }
  if (button2.pressed()) {
    Mouse.press(MOUSE_RIGHT);
  }
  if (button2.released()) {
    Mouse.release(MOUSE_RIGHT);
  }
}


