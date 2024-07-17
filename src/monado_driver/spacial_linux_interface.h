// Copyright 2020, Collabora, Ltd.
// SPDX-License-Identifier: BSL-1.0
/*!
 * @file
 * @brief  Interface to spacial linux driver.
 * @author Jakob Bornecrantz <jakob@collabora.com>
 * @ingroup drv_spacial_linux
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

/*!
 * @defgroup drv_spacial_linux spacial linux driver
 * @ingroup drv
 *
 * @brief Simple do-nothing spacial_linux driver.
 */

/*!
 * Create a auto prober for spacial_linux devices.
 *
 * @ingroup drv_spacial_linux
 */
struct xrt_auto_prober *
spacial_linux_create_auto_prober(void);

/*!
 * Create a spacial_linux hmd.
 *
 * @ingroup drv_spacial_linux
 */
struct xrt_device *
spacial_linux_hmd_create(void);

/*!
 * @dir drivers/spacial_linux
 *
 * @brief @ref drv_spacial_linux files.
 */


#ifdef __cplusplus
}
#endif