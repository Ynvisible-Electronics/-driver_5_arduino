/*
  Copyright (c) 2014-2015 Arduino LLC.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#pragma once

// The definitions here needs a SAMD core >=1.6.10
#define ARDUINO_SAMD_VARIANT_COMPLIANCE 10610

#include <WVariant.h>

// General definitions
// -------------------

// Frequency of the board main oscillator
#define VARIANT_MAINOSC (32768ul)

// Master clock frequency
#define VARIANT_MCK     (48000000ul)

// Pins
// ----

// Number of pins defined in PinDescription array
#ifdef __cplusplus
extern "C" unsigned int PINCOUNT_fn();
#endif
#define PINS_COUNT           (PINCOUNT_fn())
#define NUM_DIGITAL_PINS     (19u)
#define NUM_ANALOG_INPUTS    (16u)
#define NUM_ANALOG_OUTPUTS   (1u)

// Low-level pin register query macros
// -----------------------------------
#define digitalPinToPort(P)      (&(PORT->Group[g_APinDescription[P].ulPort]))
#define digitalPinToBitMask(P)   (1 << g_APinDescription[P].ulPin)
//#define analogInPinToBit(P)    ()
#define portOutputRegister(port) (&(port->OUT.reg))
#define portInputRegister(port)  (&(port->IN.reg))
#define portModeRegister(port)   (&(port->DIR.reg))
#define digitalPinHasPWM(P)      (g_APinDescription[P].ulPWMChannel != NOT_ON_PWM || g_APinDescription[P].ulTCChannel != NOT_ON_TIMER)

/*
 * digitalPinToTimer(..) is AVR-specific and is not defined for SAMD
 * architecture. If you need to check if a pin supports PWM you must
 * use digitalPinHasPWM(..).
 *
 * https://github.com/arduino/Arduino/issues/1833
 */
// #define digitalPinToTimer(P)

//Battery
#define ADC_BATTERY	(36u)


// Digital Pins
// ------------
#define PIN_D0      (0u)
#define PIN_D1      (1u)
#define PIN_D2      (2u)
#define PIN_D3      (3u)
#define PIN_D4      (4u)
#define PIN_D5      (5u)

// LEDs
#define PIN_LED_1     (6u)
#define PIN_LED_2     (7u)
#define PIN_LED_3     (8u)
#define PIN_LED_4     (9u)
#define PIN_LED_5     (10u)
#define PIN_LED_6     (11u)
#define PIN_LED_7     (12u)

#define PIN_LED_R     (13u)
#define PIN_LED_G     (14u)
#define PIN_LED_B     (15u)

#define LED_BUILTIN PIN_LED_R

static const uint8_t LED_1 = PIN_LED_1;
static const uint8_t LED_2 = PIN_LED_2;
static const uint8_t LED_3 = PIN_LED_3;
static const uint8_t LED_4 = PIN_LED_4;
static const uint8_t LED_5 = PIN_LED_5;
static const uint8_t LED_6 = PIN_LED_6;
static const uint8_t LED_7 = PIN_LED_7;

static const uint8_t LED_R = PIN_LED_R;
static const uint8_t LED_G = PIN_LED_G;
static const uint8_t LED_B = PIN_LED_B;

// Buttons
#define PIN_BTN_DOWN  (16u)
#define PIN_BTN_START (17u)
#define PIN_BTN_UP    (18u)

static const uint8_t  BTN_DOWN  = PIN_BTN_DOWN;
static const uint8_t  BTN_START = PIN_BTN_START;
static const uint8_t  BTN_UP    = PIN_BTN_UP;

// MCU Power On
#define PIN_MCU_PWR_ON (19u)

static const uint8_t MCU_PWR_ON = PIN_MCU_PWR_ON;

// Analog pins
// -----------
#define PIN_CE        (20u)
#define PIN_SEG_1     (21u)
#define PIN_SEG_2     (22u)
#define PIN_SEG_3     (23u)
#define PIN_SEG_4     (24u)
#define PIN_SEG_5     (25u)
#define PIN_SEG_6     (26u)
#define PIN_SEG_7     (27u)
#define PIN_SEG_8     (28u)
#define PIN_SEG_9     (29u)
#define PIN_SEG_10    (30u)
#define PIN_SEG_11    (31u)
#define PIN_SEG_12    (32u)
#define PIN_SEG_13    (33u)
#define PIN_SEG_14    (34u)
#define PIN_SEG_15    (35u)

#define PIN_LIPO_MON  (36u)

static const uint8_t A0 = PIN_CE;         // This needs to exist for analogRead() to work @wiring_analog.c:l132

static const uint8_t CE     = PIN_CE;
static const uint8_t SEG_1  = PIN_SEG_1;
static const uint8_t SEG_2  = PIN_SEG_2;
static const uint8_t SEG_3  = PIN_SEG_3;
static const uint8_t SEG_4  = PIN_SEG_4;
static const uint8_t SEG_5  = PIN_SEG_5;
static const uint8_t SEG_6  = PIN_SEG_6;
static const uint8_t SEG_7  = PIN_SEG_7;
static const uint8_t SEG_8  = PIN_SEG_8;
static const uint8_t SEG_9  = PIN_SEG_9;
static const uint8_t SEG_10 = PIN_SEG_10;
static const uint8_t SEG_11 = PIN_SEG_11;
static const uint8_t SEG_12 = PIN_SEG_12;
static const uint8_t SEG_13 = PIN_SEG_13;
static const uint8_t SEG_14 = PIN_SEG_14;
static const uint8_t SEG_15 = PIN_SEG_15;

#define ADC_RESOLUTION 10

// SPI Interfaces
// --------------
#define SPI_INTERFACES_COUNT 0

// Wire Interfaces
// ---------------
#define WIRE_INTERFACES_COUNT 2


// Wire - Matrix connector
#define PIN_WIRE_SDA        (39u)
#define PIN_WIRE_SCL        (40u)
#define PIN_M_SHDN          (41u)
#define PERIPH_WIRE         sercom1
#define WIRE_IT_HANDLER     SERCOM1_Handler

static const uint8_t SDA = PIN_WIRE_SDA;
static const uint8_t SCL = PIN_WIRE_SCL;
static const uint8_t M_SHDN = PIN_M_SHDN;

// Wire - Quick connector
#define PIN_WIRE1_SDA       (37u)
#define PIN_WIRE1_SCL       (38u)
#define PERIPH_WIRE1        sercom4
#define WIRE1_IT_HANDLER    SERCOM4_Handler

static const uint8_t SDA1 = PIN_WIRE_SDA;
static const uint8_t SCL1 = PIN_WIRE_SCL;

// USB
// ---
#define PIN_USB_DM          (44ul)
#define PIN_USB_DP          (45ul)
//#define PIN_USB_HOST_ENABLE (ul)

// Serial ports
// ------------
#ifdef __cplusplus
#include "SERCOM.h"
#include "Uart.h"

// Instances of SERCOM
extern SERCOM sercom0;
extern SERCOM sercom1;
//extern SERCOM sercom2;    // Not used, pins taken by other functions
//extern SERCOM sercom3;
extern SERCOM sercom4;
//extern SERCOM sercom5;

// Serial1
extern Uart Serial1;
#define PIN_SERIAL1_RX (43ul)
#define PIN_SERIAL1_TX (42ul)
#define PAD_SERIAL1_RX (SERCOM_RX_PAD_3)
#define PAD_SERIAL1_TX (UART_TX_PAD_2)
#endif // __cplusplus

#ifdef __cplusplus
extern "C" {
#endif
unsigned int PINCOUNT_fn();
#ifdef __cplusplus
}
#endif

// These serial port names are intended to allow libraries and architecture-neutral
// sketches to automatically default to the correct port name for a particular type
// of use.  For example, a GPS module would normally connect to SERIAL_PORT_HARDWARE_OPEN,
// the first hardware serial port whose RX/TX pins are not dedicated to another use.
//
// SERIAL_PORT_MONITOR        Port which normally prints to the Arduino Serial Monitor
//
// SERIAL_PORT_USBVIRTUAL     Port which is USB virtual serial
//
// SERIAL_PORT_LINUXBRIDGE    Port which connects to a Linux system via Bridge library
//
// SERIAL_PORT_HARDWARE       Hardware serial port, physical RX & TX pins.
//
// SERIAL_PORT_HARDWARE_OPEN  Hardware serial ports which are open for use.  Their RX & TX
//                            pins are NOT connected to anything by default.
#define SERIAL_PORT_USBVIRTUAL      SerialUSB
#define SERIAL_PORT_MONITOR         SerialUSB
#define SERIAL_PORT_HARDWARE        Serial1
#define SERIAL_PORT_HARDWARE_OPEN   Serial1

// Alias Serial to SerialUSB
#define Serial                      SerialUSB

