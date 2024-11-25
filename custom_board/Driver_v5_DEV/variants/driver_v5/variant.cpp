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

#include "variant.h"

const PinDescription g_APinDescription[] = {
/*
 +------------+------------------+--------+-----------------+--------+-----------------------+---------+---------+--------+--------+----------+----------+
 | Pin number |     Driver 5     |  PIN   | Notes           | Peri.A |     Peripheral B      | Perip.C | Perip.D | Peri.E | Peri.F | Periph.G | Periph.H |
 |            |     Board Pin    |        |                 |   EIC  | ADC |  AC | PTC | DAC | SERCOMx | SERCOMx |  TCCx  |  TCCx  |    COM   | AC/GLCK  |
 |            |                  |        |                 |(EXTINT)|(AIN)|(AIN)|     |     | (x/PAD) | (x/PAD) | (x/WO) | (x/WO) |          |          |
 +------------+------------------+--------+-----------------+--------+-----+-----+-----+-----+---------+---------+--------+--------+----------+----------+
 | 00         | D0               |  PB10  |                 |  *10   |     |     |     |     |         |   4/02  |* TC5/0 | TCC0/4 | I2S/MCK1 | GCLK_IO4 |
 | 01         | D1               |  PB11  |                 |  *11   |     |     |     |     |         |   4/03  |* TC5/1 | TCC0/5 | I2S/SCK1 | GCLK_IO5 |
 | 02         | D2               |  PA19  |                 |  *03   |     |     | X07 |     |   1/03  |   3/03  | *TC3/1 | TCC0/3 | I2S/SD0  | AC/CMP1  |
 | 03         | D3               |  PB17  |                 |  *01   |     |     |     |     |   5/01  |         | *TC6/1 | TCC0/5 | I2S/MCK1 | GCLK_IO3 |
 | 04         | D4               |  PA21  |                 |  *05   |     |     | X09 |     |   5/03  |   3/03  |        | TCC0/7 | I2S/FS0  | GCLK_IO5 |
 | 05         | D5               |  PA23  |                 |   07   |     |     | X11 |     |   3/01  |   5/01  | *TC4/1 | TCC0/5 | USB/SOF  | GCLK_IO7 |
 +------------+------------------+--------+-----------------+--------+-----+-----+-----+-----+---------+---------+--------+--------+----------+----------+
*/
  { PORTB, 10, PIO_DIGITAL, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER    ), No_ADC_Channel, PWM5_CH0,   TC5_CH0,      EXTERNAL_INT_10   },
  { PORTB, 11, PIO_DIGITAL, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER    ), No_ADC_Channel, PWM5_CH1,   TC5_CH1,      EXTERNAL_INT_11   },
  { PORTA, 19, PIO_DIGITAL, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER    ), No_ADC_Channel, PWM3_CH1,   TC3_CH1,      EXTERNAL_INT_3    },
  { PORTB, 17, PIO_DIGITAL, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER    ), No_ADC_Channel, PWM6_CH1,   TC6_CH1,      EXTERNAL_INT_1    },
  { PORTA, 21, PIO_DIGITAL, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER    ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_5    },
  { PORTA, 23, PIO_DIGITAL, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER    ), No_ADC_Channel, PWM4_CH1,   TC4_CH1,      EXTERNAL_INT_NONE },

/*
 +------------+------------------+--------+-----------------+--------+-----------------------+---------+---------+--------+--------+----------+----------+
 | Pin number |     Driver 5     |  PIN   | Notes           | Peri.A |     Peripheral B      | Perip.C | Perip.D | Peri.E | Peri.F | Periph.G | Periph.H |
 |            |     Board Pin    |        |                 |   EIC  | ADC |  AC | PTC | DAC | SERCOMx | SERCOMx |  TCCx  |  TCCx  |    COM   | AC/GLCK  |
 |            |                  |        |                 |(EXTINT)|(AIN)|(AIN)|     |     | (x/PAD) | (x/PAD) | (x/WO) | (x/WO) |          |          |
 +------------+------------------+--------+-----------------+--------+-----+-----+-----+-----+---------+---------+--------+--------+----------+----------+
 | 06         | LED_1            |  PA13  |                 |   13   |     |     |     |     |   2/01  |   4/01  | TCC2/1 | TCC0/7 |          | AC/CMP1  |
 | 07         | LED_2            |  PA14  |                 |   14   |     |     |     |     |   2/02  |   4/02  |  TC3/0 | TCC0/4 |          | GCLK_IO0 |
 | 08         | LED_3            |  PB14  |                 |        |     |     | X03 |     |   4/02  |         |  TC5/0 |        |          | GCLK_IO0 |
 | 09         | LED_4            |  PA15  |                 |   15   |     |     |     |     |   2/03  |   4/03  | TCC0/5 |        |          | GCLK_IO1 |
 | 10         | LED_5            |  PB16  |                 |   00   |     |     | X11 |     |   3/01  |   5/01  |  TC4/1 | TCC0/5 | USB/SOF  | GCLK_IO7 |
 | 11         | LED_6            |  PA18  |                 |   02   |     |     | X06 |     |   1/02  |   3/02  |  TC3/0 | TCC0/2 |          | AC/CMP0  |
 | 12         | LED_7            |  PA20  |                 |   04   |     |     | X08 |     |   5/02  |   3/02  |        | TCC0/6 | I2S/SCK0 | GCLK_IO4 |
 | 13         | LED_R            |  PA22  |                 |   06   |     |     | X10 |     |   3/00  |   5/00  |  TC4/0 | TCC0/4 |          | GCLK_IO6 |
 | 14         | LED_G            |  PA12  |                 |   12   |     |     |     |     |   2/00  |   4/00  | TCC2/0 | TCC0/6 |          | AC/CMP0  |
 | 15         | LED_B            |  PB15  |                 |   15   |     |     | X15 |     |   4/03  |         |  TC5/1 |        |          | GCLK_IO1 |
 +------------+------------------+--------+-----------------+--------+-----+-----+-----+-----+---------+---------+--------+--------+----------+----------+
*/
  { PORTA, 13, PIO_DIGITAL, (PIN_ATTR_DIGITAL                                ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },
  { PORTA, 14, PIO_DIGITAL, (PIN_ATTR_DIGITAL                                ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },
  { PORTB, 14, PIO_DIGITAL, (PIN_ATTR_DIGITAL                                ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },
  { PORTA, 15, PIO_DIGITAL, (PIN_ATTR_DIGITAL                                ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },
  { PORTB, 16, PIO_DIGITAL, (PIN_ATTR_DIGITAL                                ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },
  { PORTA, 18, PIO_DIGITAL, (PIN_ATTR_DIGITAL                                ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },
  { PORTA, 20, PIO_DIGITAL, (PIN_ATTR_DIGITAL                                ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },
  { PORTA, 22, PIO_DIGITAL, (PIN_ATTR_DIGITAL                                ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },
  { PORTA, 12, PIO_DIGITAL, (PIN_ATTR_DIGITAL                                ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },
  { PORTB, 15, PIO_DIGITAL, (PIN_ATTR_DIGITAL                                ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },

/*
 +------------+------------------+--------+-----------------+--------+-----------------------+---------+---------+--------+--------+----------+----------+
 | Pin number |     Driver 5     |  PIN   | Notes           | Peri.A |     Peripheral B      | Perip.C | Perip.D | Peri.E | Peri.F | Periph.G | Periph.H |
 |            |     Board Pin    |        |                 |   EIC  | ADC |  AC | PTC | DAC | SERCOMx | SERCOMx |  TCCx  |  TCCx  |    COM   | AC/GLCK  |
 |            |                  |        |                 |(EXTINT)|(AIN)|(AIN)|     |     | (x/PAD) | (x/PAD) | (x/WO) | (x/WO) |          |          |
 +------------+------------------+--------+-----------------+--------+-----+-----+-----+-----+---------+---------+--------+--------+----------+----------+
 | 16         | BTN_DOWN         |  PB22  |                 |  *06   |     |     |     |     |         |   5/02  |  TC7/0 | TCC3/0 |          | GCLK_IO0 |
 | 17         | BTN_START        |  PB23  |                 |  *07   |     |     |     |     |         |   5/03  |  TC7/1 | TCC3/1 |          | GCLK_IO1 |
 | 18         | BTN_UP           |  PA27  |                 |  *15   |     |     |     |     |         |         |        | TCC3/6 |          | GCLK_IO0 |
 +------------+------------------+--------+-----------------+--------+-----+-----+-----+-----+---------+---------+--------+--------+----------+----------+
 | 19         | MCU_PWR_ON       |  PB30  |                 |   10   |     |     |     |     |         |   1/02  | TCC1/0 | TCC3/6 |          | GCLK_IO0 |
 +------------+------------------+--------+-----------------+--------+-----+-----+-----+-----+---------+---------+--------+--------+----------+----------+
*/
  { PORTB, 22, PIO_DIGITAL, (PIN_ATTR_DIGITAL                               ), No_ADC_Channel, NOT_ON_PWM,   NOT_ON_TIMER, EXTERNAL_INT_6   },
  { PORTB, 23, PIO_DIGITAL, (PIN_ATTR_DIGITAL                               ), No_ADC_Channel, NOT_ON_PWM,   NOT_ON_TIMER, EXTERNAL_INT_7   },
  { PORTA, 27, PIO_DIGITAL, (PIN_ATTR_DIGITAL                               ), No_ADC_Channel, NOT_ON_PWM,   NOT_ON_TIMER, EXTERNAL_INT_15  },
  
  { PORTB, 30, PIO_DIGITAL, (PIN_ATTR_DIGITAL                               ), No_ADC_Channel, NOT_ON_PWM,   NOT_ON_TIMER, EXTERNAL_INT_NONE},
  
/*
 +------------+------------------+--------+-----------------+--------+-----------------------+---------+---------+--------+--------+----------+----------+
 | Pin number |     Driver 5     |  PIN   | Notes           | Peri.A |     Peripheral B      | Perip.C | Perip.D | Peri.E | Peri.F | Periph.G | Periph.H |
 |            |     Board Pin    |        |                 |   EIC  | ADC |  AC | PTC | DAC | SERCOMx | SERCOMx |  TCCx  |  TCCx  |    COM   | AC/GLCK  |
 |            |                  |        |                 |(EXTINT)|(AIN)|(AIN)|     |     | (x/PAD) | (x/PAD) | (x/WO) | (x/WO) |          |          |
 +------------+------------------+--------+-----------------+--------+-----+-----+-----+-----+---------+---------+--------+--------+----------+----------+
 | 20         | CE               |  PA02  | *DAC_OUT        |   02   | *00 |     |     |     |         |   5/02  |  TC7/0 | TCC3/0 |          | GCLK_IO0 |
 | 21         | SEG_1            |  PA09  |                 |   09   | *17 |     | X01 |     |   0/01  |   2/01  | TCC0/1 | TCC1/3 | I2S/MCK0 |          |
 | 22         | SEG_2            |  PA08  |                 |   08   | *16 |     | X00 |     |   0/00  |   2/00  | TCC0/0 | TCC1/2 | I2S/SD1  |          |
 | 23         | SEG_3            |  PA07  |                 |   07   | *07 |  03 | Y05 |     |         |   0/03  | TCC1/1 | TCC3/5 | I2S/SD0  |          |
 | 24         | SEG_4            |  PA06  |                 |   06   | *06 |  02 | Y04 |     |         |   0/02  | TCC1/0 | TCC3/4 |          |          |
 | 25         | SEG_5            |  PA05  |                 |   05   | *05 |  01 | Y03 |     |         |   0/01  | TCC0/1 | TCC3/3 |          |          |
 | 26         | SEG_6            |  PA04  |                 |   04   | *04 |  00 | Y02 |     |         |   0/00  | TCC0/0 | TCC3/2 |          |          |
 | 27         | SEG_7            |  PB09  |                 |   09   | *03 |     | Y15 |     |         |   4/01  |  TC4/1 | TCC3/7 |          |          |
 | 28         | SEG_8            |  PB08  |                 |   08   | *02 |     | Y14 |     |         |   4/00  |  TC4/0 | TCC3/6 |          |          |
 | 29         | SEG_9            |  PB07  |                 |   07   | *15 |     | Y13 |     |         |         |        |        |          |          |
 | 30         | SEG_10           |  PB06  |                 |   06   | *14 |     | Y12 |     |         |         |        |        |          |          |
 | 31         | SEG_11           |  PB05  |                 |   05   | *13 |     | Y11 |     |         |         |        |        |          |          |
 | 32         | SEG_12           |  PB04  |                 |   04   | *12 |     | Y10 |     |         |         |        |        |          |          |
 | 33         | SEG_13           |  PB03  |                 |   03   | *11 |     | Y09 |     |         |   5/01  |  TC6/1 | TCC3/3 |          |          |
 | 34         | SEG_14           |  PB02  |                 |   02   | *10 |     | Y08 |     |         |   5/00  |  TC6/0 | TCC3/2 |          |          |
 | 35         | SEG_15           |  PB01  |                 |   01   | *09 |     | Y07 |     |         |   5/03  |  TC7/1 |        |          |          |
 +------------+------------------+--------+-----------------+--------+-----+-----+-----+-----+---------+---------+--------+--------+----------+----------+
 | 36         | LIPO_MON         |  PB00  |                 |   00   | *08 |     | Y06 |     |         |   5/02  |  TC7/0 |        |          |          |
 +------------+------------------+--------+-----------------+--------+-----+-----+-----+-----+---------+---------+--------+--------+----------+----------+
*/
  { PORTA,  2, PIO_ANALOG,  (PIN_ATTR_DIGITAL|PIN_ATTR_ANALOG /*DAC*/        ), ADC_Channel0,   NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },
  { PORTA,  9, PIO_ANALOG,  (PIN_ATTR_DIGITAL|PIN_ATTR_ANALOG                ), ADC_Channel17,  NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },
  { PORTA,  8, PIO_ANALOG,  (PIN_ATTR_DIGITAL|PIN_ATTR_ANALOG                ), ADC_Channel16,  NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },
  { PORTA,  7, PIO_ANALOG,  (PIN_ATTR_DIGITAL|PIN_ATTR_ANALOG                ), ADC_Channel7,   NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },
  { PORTA,  6, PIO_ANALOG,  (PIN_ATTR_DIGITAL|PIN_ATTR_ANALOG                ), ADC_Channel6,   NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },
  { PORTA,  5, PIO_ANALOG,  (PIN_ATTR_DIGITAL|PIN_ATTR_ANALOG                ), ADC_Channel5,   NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },
  { PORTA,  4, PIO_ANALOG,  (PIN_ATTR_DIGITAL|PIN_ATTR_ANALOG                ), ADC_Channel4,   NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },
  { PORTB,  9, PIO_ANALOG,  (PIN_ATTR_DIGITAL|PIN_ATTR_ANALOG                ), ADC_Channel3,   NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },
  { PORTB,  8, PIO_ANALOG,  (PIN_ATTR_DIGITAL|PIN_ATTR_ANALOG                ), ADC_Channel2,   NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },
  { PORTB,  7, PIO_ANALOG,  (PIN_ATTR_DIGITAL|PIN_ATTR_ANALOG                ), ADC_Channel15,  NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },
  { PORTB,  6, PIO_ANALOG,  (PIN_ATTR_DIGITAL|PIN_ATTR_ANALOG                ), ADC_Channel14,  NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },
  { PORTB,  5, PIO_ANALOG,  (PIN_ATTR_DIGITAL|PIN_ATTR_ANALOG                ), ADC_Channel13,  NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },
  { PORTB,  4, PIO_ANALOG,  (PIN_ATTR_DIGITAL|PIN_ATTR_ANALOG                ), ADC_Channel12,  NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },
  { PORTB,  3, PIO_ANALOG,  (PIN_ATTR_DIGITAL|PIN_ATTR_ANALOG                ), ADC_Channel11,  NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },
  { PORTB,  2, PIO_ANALOG,  (PIN_ATTR_DIGITAL|PIN_ATTR_ANALOG                ), ADC_Channel10,  NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },
  { PORTB,  1, PIO_ANALOG,  (PIN_ATTR_DIGITAL|PIN_ATTR_ANALOG                ), ADC_Channel9,   NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },

  { PORTB,  0, PIO_ANALOG,  (PIN_ATTR_DIGITAL|PIN_ATTR_ANALOG                ), ADC_Channel8,   NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },
  
/*
 +------------+------------------+--------+-----------------+--------+-----------------------+---------+---------+--------+--------+----------+----------+
 | Pin number |     Driver 5     |  PIN   | Notes           | Peri.A |     Peripheral B      | Perip.C | Perip.D | Peri.E | Peri.F | Periph.G | Periph.H |
 |            |     Board Pin    |        |                 |   EIC  | ADC |  AC | PTC | DAC | SERCOMx | SERCOMx |  TCCx  |  TCCx  |    COM   | AC/GLCK  |
 |            |                  |        |                 |(EXTINT)|(AIN)|(AIN)|     |     | (x/PAD) | (x/PAD) | (x/WO) | (x/WO) |          |          |
 +------------+------------------+--------+-----------------+--------+-----+-----+-----+-----+---------+---------+--------+--------+----------+----------+
 | 37         | Q_SDA            |  PB12  |                 |  *12   |     |     | X12 |     |  *4/00  |         |  TC4/0 | TCC0/6 | I2S/F10  | GCLK_IO6 |
 | 38         | Q_SCL            |  PB13  |                 |  *13   |     |     | X13 |     |  *4/01  |         |        |  TC4/1 |          | GCLK_IO7 |
 | 39         | M_SDA            |  PA16  |                 |   00   |     |     | X04 |     |  *1/00  |   3/00  | TCC2/0 | TCC0/6 |          | GCLK_IO2 |
 | 40         | M_SCL            |  PA17  |                 |   01   |     |     | X05 |     |  *1/01  |   3/01  | TCC2/1 | TCC0/7 |          | GCLK_IO3 |
 | 41         | M_SHDN           |  PB31  |                 |   15   |     |     |     |     |         |   5/01  | TCC0/1 | TCC1/3 |          |          |
 | 42         | SERIAL_TX        |  PA10  |                 |   10   | *18 |     | X02 |     |  *0/02  |   2/02  | TCC1/0 | TCC0/2 | I2S/SCK0 | GCLK_IO4 |
 | 43         | SERIAL_RX        |  PA11  |                 |   11   | *19 |     | X03 |     |  *0/03  |   2/03  | TCC1/1 | TCC0/3 | I2S/FS0  | GCLK_IO5 |
 +------------+------------------+--------+-----------------+--------+-----+-----+-----+-----+---------+---------+--------+--------+----------+----------+
*/
  { PORTB, 12, PIO_SERCOM,     (PIN_ATTR_DIGITAL                                ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_12   },
  { PORTB, 13, PIO_SERCOM,     (PIN_ATTR_DIGITAL                                ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_13   },
  { PORTA, 16, PIO_SERCOM,     (PIN_ATTR_DIGITAL                                ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },
  { PORTA, 17, PIO_SERCOM,     (PIN_ATTR_DIGITAL                                ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },
  { PORTB, 31, PIO_DIGITAL,    (PIN_ATTR_DIGITAL                                ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },
  { PORTA, 10, PIO_SERCOM,     (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER    ), ADC_Channel18,  NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },
  { PORTA, 11, PIO_SERCOM,     (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER    ), ADC_Channel19,  NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },

/*
 +------------+------------------+--------+-----------------+--------+-----------------------+---------+---------+--------+--------+----------+----------+
 | Pin number |     Driver 5     |  PIN   | Notes           | Peri.A |     Peripheral B      | Perip.C | Perip.D | Peri.E | Peri.F | Periph.G | Periph.H |
 |            |     Board Pin    |        |                 |   EIC  | ADC |  AC | PTC | DAC | SERCOMx | SERCOMx |  TCCx  |  TCCx  |    COM   | AC/GLCK  |
 |            |                  |        |                 |(EXTINT)|(AIN)|(AIN)|     |     | (x/PAD) | (x/PAD) | (x/WO) | (x/WO) |          |          |
 +------------+------------------+--------+-----------------+--------+-----+-----+-----+-----+---------+---------+--------+--------+----------+----------+
 |            |       USB        |        |                 |        |     |     |     |     |         |         |        |        |          |          |
 | 44         |                  |  PA24  | USB N           |   12   |     |     |     |     |   3/02  |   5/02  |  TC5/0 | TCC1/2 | USB/DM   |          |
 | 45         |                  |  PA25  | USB P           |   13   |     |     |     |     |   3/03  |   5/03  |  TC5/1 | TCC1/3 | USB/DP   |          |
 | 46         | SWCLK            |  PA30  |                 |   10   |     |     |     |     |         |   1/02  |  TC1/0 | TCC3/4 |  SWCLK   | GCLK_IO0 |
 | 47         | SWDIO            |  PA31  |                 |   11   |     |     |     |     |         |   1/03  |  TC1/1 | TCC3/5 |  SWDIO   |          |
 +------------+------------------+--------+-----------------+--------+-----+-----+-----+-----+---------+---------+--------+--------+----------+----------+
 */
  { PORTA, 24, PIO_COM,     (PIN_ATTR_NONE                                   ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // USB/DM
  { PORTA, 25, PIO_COM,     (PIN_ATTR_NONE                                   ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // USB/DP
  { PORTA, 30, PIO_COM,     (PIN_ATTR_NONE                                   ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // SWCLK
  { PORTA, 31, PIO_COM,     (PIN_ATTR_NONE                                   ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // SWDIO


/*
 +------------+------------------+--------+-----------------+--------+-----------------------+---------+---------+--------+--------+----------+----------+
 | Pin number |     Driver 5     |  PIN   | Notes           | Peri.A |     Peripheral B      | Perip.C | Perip.D | Peri.E | Peri.F | Periph.G | Periph.H |
 |            |     Board Pin    |        |                 |   EIC  | ADC |  AC | PTC | DAC | SERCOMx | SERCOMx |  TCCx  |  TCCx  |    COM   | AC/GLCK  |
 |            |                  |        |                 |(EXTINT)|(AIN)|(AIN)|     |     | (x/PAD) | (x/PAD) | (x/WO) | (x/WO) |          |          |
 +------------+------------------+--------+-----------------+--------+-----+-----+-----+-----+---------+---------+--------+--------+----------+----------+
 | 48         | VREFA            |  PA03  |                 |   03   |  01 |     | Y01 |     |         |         |        |        |          |          |
 +------------+------------------+--------+-----------------+--------+-----+-----+-----+-----+---------+---------+--------+--------+----------+----------+
 |            | 32768Hz Crystal  |        |                 |        |     |     |     |     |         |         |        |        |          |          |
 | 49         |                  |  PA00  | XIN32           |   00   |     |     |     |     |         |   1/00  | TCC2/0 |        |          |          |
 | 50         |                  |  PA01  | XOUT32          |   01   |     |     |     |     |         |   1/01  | TCC2/1 |        |          |          |
 +------------+------------------+--------+-----------------+--------+-----+-----+-----+-----+---------+---------+--------+--------+----------+----------+
*/
  { PORTA,  3, PIO_DIGITAL, (PIN_ATTR_DIGITAL                                ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // DAC/VREFP
  
  { PORTA,  0, PIO_DIGITAL, (PIN_ATTR_NONE                                   ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },
  { PORTA,  1, PIO_DIGITAL, (PIN_ATTR_NONE                                   ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },

};

extern "C" {
    unsigned int PINCOUNT_fn() {
        return (sizeof(g_APinDescription) / sizeof(g_APinDescription[0]));
    }
}

const void* g_apTCInstances[TCC_INST_NUM + TC_INST_NUM]={ TC3, TC4, TC5, TC6 };

// Multi-serial objects instantiation
SERCOM sercom0(SERCOM0);
SERCOM sercom1(SERCOM1);
//SERCOM sercom2(SERCOM2);            // Not used, pins taken by other functions
//SERCOM sercom3(SERCOM3);
SERCOM sercom4(SERCOM4);
//SERCOM sercom5(SERCOM5);

// Serial
Uart Serial1(&sercom0, PIN_SERIAL1_RX, PIN_SERIAL1_TX, PAD_SERIAL1_RX, PAD_SERIAL1_TX);


// void SERCOM5_Handler()
// {
//   Serial1.IrqHandler();
// }

