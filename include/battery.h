/*
 * SPDX-FileCopyrightText: 2023 Kyunghwan Kwon <k@mononn.com>
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef LIBMCU_BATTERY_H
#define LIBMCU_BATTERY_H

#if defined(__cplusplus)
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>

int battery_init(void (*on_event_callback)(void));

/**
 * @brief Enable or Disable battery level monitor
 *
 * @param[in] enable enabled if true, or disabled
 *
 * @note Baterry level monitor should be enabled first before using
 *       @ref battery_level and @ref battery_level_raw
 *
 * @return 0 on success or negative error code
 */
int battery_enable_monitor(bool enable);

/**
 * @brief Read ADC value on battery
 *
 * @return ADC value
 */
int battery_level_raw(void);

/**
 * @brief Convert ADC value to millivoltage
 *
 * @param[in] raw ADC value
 *
 * @return millivoltage
 */
int battery_raw_to_millivolts(int raw);

/**
 * @brief Read battery level in percentage
 *
 * @return 0 ~ 100 percentage
 */
uint8_t battery_level(void);

#if defined(__cplusplus)
}
#endif

#endif /* LIBMCU_BATTERY_H */