
 /**
 * @file includes.h
 * Configuration defines for RF24/Linux
 */

 /**
 * Example of includes.h for RF24 Linux portability
 *
 * @defgroup Porting_Includes Porting: Includes
 *
 * 
 * @{
 */
  
#ifndef __RF24_INCLUDES_H__
#define __RF24_INCLUDES_H__

#include <stdint.h>
#include <stdio.h>
// #include <time.h>
// #include <string.h>
// #include <sys/time.h>
#include <util/delay.h>
#include <stddef.h>
#include "timer.h"
#include "tmk/spi.h"

// #define PROGMEM 

// Function, constant map as a result of migrating from Arduino
#define LOW         0
#define HIGH        1
#define INPUT       0
#define OUTPUT      1
#define digitalWrite(pin, value) {}
#define pinMode(pin, direction) {}
#define delay(milisec) _delay_ms(milisec)
#define delayMicroseconds(usec) _delay_us(usec)
#define millis() timer_read32()
#define _BV(x) (1<<(x))

// #define PSTR(x) (x)
// # define PSTR(s) (__extension__({static const char __c[] PROGMEM = (s); &__c[0];}))
// #define pgm_read_byte(addr) (*(const unsigned char *)(addr))
// #define pgm_read_word(p) (*(p))

// #define printf_P 
#define printf_P __xprintf
#define PRIPSTR "%S"

#define IF_SERIAL_DEBUG(x)
#define _SPI spi

  /**
   * Define a specific platform for this configuration
   */
  
  /**
   * Load the correct configuration for this platform
  */
  
#endif

/*@}*/	
