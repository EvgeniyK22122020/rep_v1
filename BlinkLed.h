/*
 * This file is part of the µOS++ distribution.
 *   (https://github.com/micro-os-plus)
 * Copyright (c) 2014 Liviu Ionescu.
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom
 * the Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef BLINKLED_H_
#define BLINKLED_H_

#include "stm32f10x.h"

// ----- LED definitions ------------------------------------------------------

// Adjust these definitions for your own board.

// Olimex STM32-H103 definitions (the GREEN led, C12, active low)
// (SEGGER J-Link device name: STM32F103RB).

// Port numbers: 0=A, 1=B, 2=C, 3=D, 4=E, 5=F, 6=G, ...
#define BLINK_PORT_NUMBER               (2)
#define BLINK_PIN_NUMBER                (12)

//#define BLINK_GPIOx(_N)                 ((GPIO_TypeDef *)(GPIOA_BASE + (GPIOB_BASE-GPIOA_BASE)*(_N)))
#define BLINK_PIN_MASK(_N)              (1 << (_N))
//#define BLINK_RCC_MASKx(_N)             (RCC_APB2Periph_GPIOA << (_N))
#define BLINK_RCC_ALLPORTS				(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOC | \
										RCC_APB2Periph_GPIOD | RCC_APB2Periph_GPIOE)

#define BLINK_GPIOA_PINS				((uint16_t)(GPIO_Pin_0 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | \
										GPIO_Pin_6 | GPIO_Pin_9 | GPIO_Pin_10 ))
#define BLINK_GPIOB_PINS				((uint16_t)(GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | \
										GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7 | \
										GPIO_Pin_8 | GPIO_Pin_9 ))
#define BLINK_GPIOC_PINS				(uint16_t)(GPIO_Pin_0 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_6 | \
										GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_13 )
#define BLINK_GPIOD_PINS				(uint16_t)(GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | \
										GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7 | \
										GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11 | \
										GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15 )
#define BLINK_GPIOE_PINS				(uint16_t)(GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11 | \
										GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15 )

#define A_BASE 							((GPIO_TypeDef *)GPIOA_BASE)
#define B_BASE 							((GPIO_TypeDef *)GPIOB_BASE)
#define C_BASE 							((GPIO_TypeDef *)GPIOC_BASE)
#define D_BASE 							((GPIO_TypeDef *)GPIOD_BASE)
#define E_BASE 							((GPIO_TypeDef *)GPIOE_BASE)
// ----------------------------------------------------------------------------

extern
void
blink_led_init(void);

// ----------------------------------------------------------------------------
/*
inline void
blink_led_on(void);

inline void
blink_led_off(void);
*/
// ----------------------------------------------------------------------------

/*inline void __attribute__((always_inline))
blink_led_on(void)
{
  GPIO_SetBits(BLINK_GPIOx(BLINK_PORT_NUMBER), BLINK_PIN_MASK(BLINK_PIN_NUMBER));
}*/

/*inline void __attribute__((always_inline))
blink_led_off(void)
{
  GPIO_ResetBits(BLINK_GPIOx(BLINK_PORT_NUMBER), BLINK_PIN_MASK(BLINK_PIN_NUMBER));
}*/

// ----------------------------------------------------------------------------

#endif // BLINKLED_H_
