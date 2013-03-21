#include <bcm2835.h>
#include <sched.h>
#include <sys/mman.h>
#include <stdio.h>
#include <stdlib.h>

//TODO: set pins properly, according to the version of your board: 
// http://www.airspayce.com/mikem/bcm2835/bcm2835_8h_source.html
// https://projects.drogon.net/raspberry-pi/wiringpi/pins/
#define PIN_TEMP RPI_GPIO_P1_13
#define PIN_LIGHT RPI_GPIO_P1_12
#define PIN_LED RPI_V2_GPIO_P1_11

void init();

uint8_t readTemp();
uint8_t readLight();
uint8_t read(uint8_t pin);

void turnOnLED();
void turnOffLED();


int main() {

    if (!bcm2835_init())
        return 1;

	init();
	
	int i = 0;	
	for(i = 0; i < 10; i++) {//10 temperature and light read, with LED blinking. Should take around 10 seconds
		turnOnLED();
	
/*		printf("Reading temperature... ");
		printf("%d\n", readTemp());
		printf("\n\n");
*/
		bcm2835_delay(500);
		
/*		printf("Reading Light... ");
		printf("%d\n", readLight());
		printf("\n\n");
*/		
		turnOffLED();
		
		bcm2835_delay(500);
  }
  
  bcm2835_close();
  
  return 0;
}

void init() {

	//Some code to prevent swapping (and try to get (near) real-time performances...
	struct sched_param sp;
	memset(&sp, 0, sizeof(sp));
	sp.sched_priority = sched_get_priority_max(SCHED_FIFO);
	sched_setscheduler(0, SCHED_FIFO, &sp);
	mlockall(MCL_CURRENT | MCL_FUTURE);

    // Set RPI pins PIN_TEMP, PIN_LIGHT to be inputs
/*	bcm2835_gpio_fsel(PIN_TEMP, BCM2835_GPIO_FSEL_INPT);
	bcm2835_gpio_fsel(PIN_LIGHT, BCM2835_GPIO_FSEL_INPT);
*/	
	//Set RPI pin PIN_LED to be an output
	bcm2835_gpio_fsel(PIN_LED, BCM2835_GPIO_FSEL_OUTP);
}

/**
* These operations below assume GPIO have been properly initialized i.e.,
* bcm2835_init() and init() have been called (successfully) beforehand
*/
uint8_t read(uint8_t pin) {
        // Read some data
        uint8_t value = bcm2835_gpio_lev(pin);
        printf("read from pin %d: %d\n", pin, value);
		return value;
}

//TODO: compute the actual temperature in Celsius
uint8_t readTemp() {
	return read(PIN_TEMP);
}

//TODO: compute the actual light in Lux
uint8_t readLight() {
	return read(PIN_LIGHT);
}

void turnOnLED() {
	bcm2835_gpio_write(PIN_LED, HIGH);
}

void turnOffLED() {
	bcm2835_gpio_write(PIN_LED, LOW);
}
