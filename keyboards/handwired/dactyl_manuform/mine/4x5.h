#pragma once

#include "dactyl_manuform.h"

//void promicro_bootloader_jmp(bool program);
#include "quantum.h"


#ifdef USE_I2C
#include <stddef.h>
#ifdef __AVR__
	#include <avr/io.h>
	#include <avr/interrupt.h>
#endif
#endif

//void promicro_bootloader_jmp(bool program);

#define LAYOUT( \
	L00, L01, L02, L03, L04,                     R00, R01, R02, R03, R04, \
	L10, L11, L12, L13, L14,                     R10, R11, R12, R13, R14, \
	L20, L21, L22, L23, L24,                     R20, R21, R22, R23, R24, \
	     L31, L32,                                         R32, R33,      \
                       L33, L34,                     R30, R31,                \
                                 L44, L42, R42, R40,                          \
                                 L43, L41, R43, R41                           \
	) \
	{ \
		{ KC_NO, L00, L01, L02, L03, L04 }, \
		{ KC_NO, L10, L11, L12, L13, L14 }, \
		{ KC_NO, L20, L21, L22, L23, L24 }, \
		{ KC_NO, KC_NO, L31, L32, L33, L34 }, \
		{ KC_NO, KC_NO, L41, L42, L43, L44 }, \
\
		{ R00, R01, R02, R03, R04, KC_NO },    \
		{ R10, R11, R12, R13, R14, KC_NO },    \
		{ R20, R21, R22, R23, R24, KC_NO },    \
		{ R30, R31, R32, R33, KC_NO, KC_NO },  \
		{ R40, R41, R42, R43, KC_NO, KC_NO }  \
	}
