#include "LPC13xx.h"
#include "delay.h"

#define GPIO3DIR    *(volatile uint32_t *)0x50038000
#define GPIO3DATA   *(volatile uint32_t *)0x50033FFC
static void init (void) {
    // LED_0 is PIO3_0
        GPIO3DIR |= (1 << 0); // Selectively set bit to 1, marking GPIO3 as output. If to 0, it would be input. 1 << 0 = 001
};
static void led_off (void) {
// GPIO3DATA |= 0x00000001;
    GPIO3DATA |= 1 << 0;   // set PIO3_0 pin to 1, disabling the led 
}
static void led_on (void) {
// LED is lit when writing 0 to it.
// So you invert the one value and then c
    GPIO3DATA &= ~(1 << 0); // Sets the first bit to zero, 1 << 0 = 001

}

int main (void)
{
    init();
	while (1) {
        led_on();
        delay_ms(500);
        led_off();
	}
}
