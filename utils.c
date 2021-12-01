#include "utils.h"

/* 'convex combination' :
 * map k in [0, 1] to [a, b] linearly */
double	ft_convex_comb(double a, double b, double k)
{
	return ((1 - k) * a + k * b);
}

int	ft_icomb(int a, int b, double k)
{
	return ((1 - k) * a + k * b);
}

/* like convex_comb for complex nums */
t_cpx	ft_ccomb(t_cpx z1, t_cpx z2, double k)
{
	t_cpx w;
	
	w.re = ft_convex_comb(z1.re, z2.re, k);
	w.im = ft_convex_comb(z1.im, z2.im, k);
	return (w);
}

/* linear gradient from color0 to color1 
 * expect 0 <= k <= 1 */
int	ft_gradient(int color0, int color1, double k)
{
	int	i;
	const int mask[3] = {0xff0000, 0xff00, 0xff};
	int ret;

	i = 0;
	ret = 0;
	while (i < 3)
	{
		ret |= mask[i] & ft_icomb(color0 & mask[i], color1 & mask[i], k);
		++i;
	}
	return (ret);
}


