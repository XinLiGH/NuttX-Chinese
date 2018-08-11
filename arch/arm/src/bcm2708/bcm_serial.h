/****************************************************************************
 * arch/arm/src/bcm2708/bcm_serial.h
 *
 *   Copyright (C) 2017 Gregory Nutt. All rights reserved.
 *   Author: Gregory Nutt <gnutt@nuttx.org>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

#ifndef __ARCH_ARM_SRC_BCM2708_BCM_SERIAL_H
#define __ARCH_ARM_SRC_BCM2708_BCM_SERIAL_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#include "up_internal.h"
#include "bcm_config.h"

/****************************************************************************
 * Public Data
 ****************************************************************************/

#ifndef __ASSEMBLY__

#undef EXTERN
#if defined(__cplusplus)
#define EXTERN extern "C"
extern "C"
{
#else
#define EXTERN extern
#endif

/****************************************************************************
 * Public Function Prototypes
 ****************************************************************************/

/****************************************************************************
 * Name: bcm_earlyserialinit
 *
 * Description:
 *   Performs the low level UART initialization early in debug so that the
 *   serial console will be available during bootup.  This must be called
 *   before up_serialinit.
 *
 ****************************************************************************/

#ifdef USE_EARLYSERIALINIT
void bcm_earlyserialinit(void);

/****************************************************************************
 * Name: bcm_miniuart_earlyserialinit
 *
 * Description:
 *   Performs the low level Mini-UART initialization early in debug so that
 *   the Mini-UART serial console will be available during bootup.  This
 *   function will be called by bcm_earlyserialinit() if the Mini-UART is
 *   selected for the serial console.
 *
 ****************************************************************************/

#ifdef CONFIG_BCM2708_MINI_UART_SERIAL_CONSOLE
void bcm_miniuart_earlyserialinit(void);
#endif

/****************************************************************************
 * Name: bcm_pl011uart_earlyserialinit
 *
 * Description:
 *   Performs the low level PL011-UART initialization early in debug so that
 *   the PL011-UART serial console will be available during bootup.  This
 *   function will be called by bcm_earlyserialinit() if the PL011-UART is
 *   selected for the serial console.
 *
 ****************************************************************************/

#ifdef CONFIG_BCM2708_PL011_UART_SERIAL_CONSOLE
void bcm_pl011uart_earlyserialinit(void);
#endif
#endif /* USE_EARLYSERIALINIT */

/****************************************************************************
 * Name: uart_serialinit
 *
 * Description:
 *   Register the UART serial console and serial ports.  This assumes that
 *   uart_earlyserialinit was called previously.
 *
 ****************************************************************************/

#ifdef USE_SERIALDRIVER
void uart_serialinit(void);

/****************************************************************************
 * Name: bcm_miniuart_serialinit
 *
 * Description:
 *   Register the Mini-UART serial console and serial ports.  This function
 *   will be called by uart_serialinit() if the Mini-UART is enabled.
 *
 ****************************************************************************/

#ifdef CONFIG_BCM2708_MINI_UART
void bcm_miniuart_serialinit(void);
#endif

/****************************************************************************
 * Name: bcm_pl011uart_serialinit
 *
 * Description:
 *   Register the PL011-UART serial console and serial ports.  This function
 *   will be called by uart_serialinit() if the Mini-UART is enabled.
 *
 ****************************************************************************/

#ifdef CONFIG_BCM2708_PL011_UART
void bcm_pl011uart_serialinit(void);
#endif
#endif /* USE_SERIALDRIVER */

#undef EXTERN
#if defined(__cplusplus)
}
#endif

#endif /* __ASSEMBLY__ */
#endif /* __ARCH_ARM_SRC_BCM2708_BCM_SERIAL_H */
