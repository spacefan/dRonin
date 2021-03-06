/**
 ******************************************************************************
 * @addtogroup PIOS PIOS Core hardware abstraction layer
 * @{
 *
 * @file       pios.h
 * @author     The OpenPilot Team, http://www.openpilot.org Copyright (C) 2010.
 * @author     Tau Labs, http://taulabs.org, Copyright (C) 2012-2014
 * @author     dRonin, http://dronin.org Copyright (C) 2015
 * @brief      Main PiOS header to include all the compiled in PiOS options
 *
 * @see        The GNU Public License (GPL) Version 3
 *
 *****************************************************************************/
/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, see <http://www.gnu.org/licenses/>
 */


#ifndef PIOS_H
#define PIOS_H

/* PIOS Feature Selection */
#include "pios_config.h"

#ifdef FLIGHT_POSIX
#include <pios_posix.h>
#endif

#if defined(PIOS_INCLUDE_CHIBIOS)
/* @note    This is required because of difference in chip define between ChibiOS and ST libs.
 *          It is also used to force inclusion of chibios_transition defines. */
#include "hal.h"

#define PIOS_INCLUDE_RTOS

#endif /* defined(PIOS_INCLUDE_CHIBIOS) */

/* C Lib Includes */
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

/* STM32 Std Periph Lib */
#if defined(STM32F4XX)
# include <stm32f4xx.h>
# include <stm32f4xx_rcc.h>
#elif defined(STM32F30X)
#include <stm32f30x.h>
#include <stm32f30x_rcc.h>
#elif defined(STM32F2XX)
#include <stm32f2xx.h>
#include <stm32f2xx_syscfg.h>
#elif defined(STM32F0XX)
#include <stm32f0xx.h>
#elif defined(STM32F10X_MD)
#include <stm32f10x.h>
#elif !defined(FLIGHT_POSIX) && !defined(PIOS_NO_HW)
#error Must define a hardware type or PIOS_NO_HW
#endif

/* PIOS Board Specific Device Configuration */
#include "pios_board.h"

/* Generic initcall infrastructure */
#if defined(PIOS_INCLUDE_INITCALL)
#include "pios_initcall.h"
#endif

/* PIOS Hardware Includes */
#include <pios_sys.h>
#include <pios_delay.h>
#include <pios_annunc.h>
#include <pios_irq.h>
#include <pios_adc.h>
#include <pios_internal_adc.h>
#include <pios_servo.h>
#include <pios_rtc.h>
#include <pios_i2c.h>
#include <pios_can.h>
#include <pios_spi.h>
#include <pios_ppm.h>
#include <pios_pwm.h>
#include <pios_rcvr.h>
#include <pios_reset.h>
#if defined(PIOS_INCLUDE_DMA_CB_SUBSCRIBING_FUNCTION)
#include <pios_dma.h>
#endif
#if defined(PIOS_INCLUDE_RTOS)
#include <pios_sensors.h>
#endif
#include <pios_wdg.h>

#if !defined(FLIGHT_POSIX) && !defined(PIOS_NO_HW)
#include <pios_exti.h>
#include <pios_usart.h>
#include <pios_srxl.h>
#endif  // !FLIGHT_POSIX && ! PIOS_NO_HW

/* PIOS Hardware Includes (Common) */
#include <pios_debug.h>
#include <pios_heap.h>
#include <pios_com.h>
#if defined(PIOS_INCLUDE_MPXV7002)
#include <pios_mpxv7002.h>
#endif
#if defined(PIOS_INCLUDE_MPXV5004)
#include <pios_mpxv5004.h>
#endif
#if defined(PIOS_INCLUDE_ETASV3)
#include <pios_etasv3.h>
#endif
#if defined(PIOS_INCLUDE_BMP280) || defined(PIOS_INCLUDE_BMP280_SPI)
#include <pios_bmp280.h>
#endif
#if defined(PIOS_INCLUDE_HCSR04)
#include <pios_hcsr04.h>
#endif
#if defined(PIOS_INCLUDE_HMC5983)
#include <pios_hmc5983.h>
#endif
#if defined(PIOS_INCLUDE_MPU)
#include <pios_mpu.h>
#endif
#if defined(PIOS_INCLUDE_L3GD20)
#include <pios_l3gd20.h>
#endif
#if defined(PIOS_INCLUDE_LSM303)
#include <pios_lsm303.h>
#endif
#if defined(PIOS_INCLUDE_MS5611)
#include <pios_ms5611.h>
#endif
#if defined(PIOS_INCLUDE_MS5611_SPI)
#include <pios_ms5611_spi.h>
#endif
#if defined(PIOS_INCLUDE_IAP)
#include <pios_iap.h>
#endif
#if defined(PIOS_INCLUDE_VIDEO)
#include <pios_video.h>
#endif

#if defined(PIOS_INCLUDE_FLASH)
#include <pios_flash.h>
#include <pios_flashfs.h>
#endif

#if defined(PIOS_INCLUDE_BL_HELPER)
#include <pios_bl_helper.h>
#endif

#if defined(PIOS_INCLUDE_USB)
#include <pios_usb.h>
#endif

#if defined(PIOS_INCLUDE_IBUS)
#include <pios_ibus.h>
#endif

#if defined(PIOS_INCLUDE_CROSSFIRE)
#include <pios_crossfire.h>
#endif

#if defined(PIOS_INCLUDE_MAX7456)
#include <pios_max7456.h>
#endif

#if defined(PIOS_INCLUDE_WS2811)
#include <pios_ws2811.h>
#endif

#include <pios_modules.h>

#include <pios_crc.h>

#define NELEMENTS(x) (sizeof(x) / sizeof(*(x)))
#define DONT_BUILD_IF(COND,MSG) typedef char static_assertion_##MSG[(COND)?-1:1]

#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
	#define CPU_TO_LE16(x) (x)
	#define CPU_TO_LE32(x) (x)

	#define CPU_TO_BE16(x) ( (((x) & 0xff00) >> 8) | \
	                         (((x) & 0x00ff) << 8) )
	#define CPU_TO_BE32(x) ( (((x) & 0xff000000) >> 24) | \
	                         (((x) & 0x00ff0000) >>  8) | \
	                         (((x) & 0x0000ff00) <<  8) | \
	                         (((x) & 0x000000ff) << 24) )
#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
	#define CPU_TO_LE16(x) ( (((x) & 0xff00) >> 8) | \
	                         (((x) & 0x00ff) << 8) )
	#define CPU_TO_LE32(x) ( (((x) & 0xff000000) >> 24) | \
	                         (((x) & 0x00ff0000) >>  8) | \
	                         (((x) & 0x0000ff00) <<  8) | \
	                         (((x) & 0x000000ff) << 24) )

	#define CPU_TO_BE16(x) (x)
	#define CPU_TO_BE32(x) (x)
#else
	#error Unsupported architecture!
#endif /* __BYTE_ORDER__ */

#define LE16_TO_CPU(x) CPU_TO_LE16(x)
#define LE32_TO_CPU(x) CPU_TO_LE32(x)
#define BE16_TO_CPU(x) CPU_TO_BE16(x)
#define BE32_TO_CPU(x) CPU_TO_BE32(x)

#endif /* PIOS_H */

/**
 * @}
 */
