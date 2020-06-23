/*
 * thread.c
 */

#include "thread.h"

#include "devices/device.h"

void thread_led(void *arg)
{
  /* initialize the led index */
  thread_led_bss->ledIndex = 0;
  while(1)
  {
    /* sleep 500ms */
    ostSleep(thread_led_data->delay);
    /* toggle the led */
    ostDevControl(DEV_LED, LED_TOGGLE, thread_led_bss->ledIndex, 0);
    /* move to next led */
    thread_led_bss->ledIndex = (thread_led_bss->ledIndex + 1) % 4;
  }
  return;
}
