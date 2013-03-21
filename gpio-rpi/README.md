How to use Raspberry Pi's GPIO to interact light and temperature sensors
========================================================================

This project provides a simple program to interact with the light and temperature sensors coming from the Electronic Brick kit (the kit we use in all our Weather Stations).

We use the C library for Broadcom BCM 2835, available at http://www.airspayce.com/mikem/bcm2835/index.html, as it offers a pretty neat API to manage the GPIO pins of the Raspberry Pi. Please make sure you properly install this library before running the sample.