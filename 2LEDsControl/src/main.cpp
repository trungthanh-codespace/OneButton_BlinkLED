#include <Arduino.h>
#include "LED.h"
#include <OneButton.h>

LED led1(LED1_PIN, LED1_ACT);
LED led2(LED2_PIN, LED2_ACT);


void btnPush();
void btnHold();
void switchBTN();
OneButton button(BTN_PIN, !BTN_ACT);
int state = 0;

void setup()
{
    led1.off();
    led2.off();
    button.attachClick(btnPush);
    button.attachDoubleClick(switchBTN);
    button.attachLongPressStart(btnHold);
}

void loop()
{
    if (state == 0) {
      led1.loop();
      button.tick();
    }
    if (state == 1) {
      led2.loop();
      button.tick();
    }
}

void btnPush()
{
    if (state == 0) {
      led1.flip();
    }
    if (state == 1) {
      led2.flip();
    }
}

void btnHold()
{
    if (state == 0) {
      led1.blink(200);
    }
    if (state == 1) {
      led2.blink(200);
    }
}

void switchBTN()
{
    state = (state + 1) % 2;
}