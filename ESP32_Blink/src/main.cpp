#include <Arduino.h>
#include "LED.h"
#include <OneButton.h>

LED led(LED_PIN, LED_ACT);

void btnPush();
void btnx2Push();
OneButton button(BTN_PIN, !BTN_ACT);

void setup()
{
    led.off();
    button.attachClick(btnPush);
    button.attachDoubleClick(btnx2Push);
}

void loop()
{
    led.loop();
    button.tick();
}

void btnPush()
{
    led.flip();
}

void btnx2Push()
{
    led.blink(200);
}