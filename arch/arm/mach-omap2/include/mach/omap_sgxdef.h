#ifndef OMAP_SGXDEF_H
#define OMAP_SGXDEF_H

#include <plat/omap-pm.h>

#ifdef CONFIG_PM
struct sgx_platform_data {
	void (*set_min_bus_tput)(struct device *dev, u8 agent_id,
						unsigned long r);
};

static void omap_sgx_pm_constraints(struct device *dev, u8 agent_id,
						unsigned long r)
{
	omap_pm_set_min_bus_tput(dev, agent_id, r);
}
#else
static void omap_sgx_pm_contraints(struct device *dev, u8 agent_id,
						unsigned long r)
{
}
#endif
#endif
