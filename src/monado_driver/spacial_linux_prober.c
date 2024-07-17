// Copyright 2020, Collabora, Ltd.
// SPDX-License-Identifier: BSL-1.0
/*!
 * @file
 * @brief  spacial_linux prober code.
 * @author Jakob Bornecrantz <jakob@collabora.com>
 * @ingroup drv_spacial_linux
 */

#include <stdio.h>
#include <stdlib.h>

#include "xrt/xrt_prober.h"

#include "util/u_misc.h"
#include "util/u_debug.h"

#include "spacial_linux_interface.h"

/*!
 * @implements xrt_auto_prober
 */
struct spacial_linux_prober
{
	struct xrt_auto_prober base;
};

//! @private @memberof spacial_linux_prober
static inline struct spacial_linux_prober *
spacial_linux_prober(struct xrt_auto_prober *p)
{
	return (struct spacial_linux_prober *)p;
}

//! @public @memberof spacial_linux_prober
static void
spacial_linux_prober_destroy(struct xrt_auto_prober *p)
{
	struct spacial_linux_prober *dp = spacial_linux_prober(p);

	free(dp);
}

//! @public @memberof spacial_linux_prober
static int
spacial_linux_prober_autoprobe(struct xrt_auto_prober *xap,
                       cJSON *attached_data,
                       bool no_hmds,
                       struct xrt_prober *xp,
                       struct xrt_device **out_xdevs)
{
	struct spacial_linux_prober *dp = spacial_linux_prober(xap);
	(void)dp;

	// Do not create a spacial_linux HMD if we are not looking for HMDs.
	if (no_hmds) {
		return 0;
	}

	out_xdevs[0] = spacial_linux_hmd_create();
	return 1;
}

struct xrt_auto_prober *
spacial_linux_create_auto_prober()
{
	struct spacial_linux_prober *dp = U_TYPED_CALLOC(struct spacial_linux_prober);
	dp->base.name = "spacial_linux";
	dp->base.destroy = spacial_linux_prober_destroy;
	dp->base.lelo_dallas_autoprobe = spacial_linux_prober_autoprobe;

	return &dp->base;
}