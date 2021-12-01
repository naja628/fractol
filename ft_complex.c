#include "ft_complex.h"

t_cpx	ft_complex(double re, double im)
{
	t_cpx	z;

	z.re = re;
	z.im = im;
	return (z);
}

t_cpx	ft_addc(t_cpx z, t_cpx w)
{
	t_cpx	zplusw;
	
	zplusw.re = z.re + w.re;
	zplusw.im = z.im + w.im;
	return (zplusw);
}

t_cpx	ft_multc(t_cpx z, t_cpx w) 
{
	t_cpx zw;

	zw.re = z.re * w.re - z.im * w.im;
	zw.im = z.re * w.im + z.im * w.re;
	return (zw);
}

double	ft_modulus(t_cpx z)
{
	return (sqrt(z.re * z.re + z.im * z.im));
}

t_cpx	ft_rot(double theta)
{
	t_cpx	z;

	z.re = cos(theta);
	z.im = sin(theta);
	return (z);
}
