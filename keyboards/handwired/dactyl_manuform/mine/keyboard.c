#include "keyboard.h"
#include "config.h"

void matrix_init_kb(void) {
	matrix_init_user();
};

void led_set_user(uint8_t usb_led) {
    if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {
        writePinHigh(LED_CAPS_LOCK_PIN);
    } else {
        writePinLow(LED_CAPS_LOCK_PIN);
    }
}
