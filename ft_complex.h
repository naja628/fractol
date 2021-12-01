#ifndef FT_COMPLEX_H
# define FT_COMPLEX_H

# include <math.h>

typedef struct s_complex
{
	double re;
	double im;
} t_cpx;

t_cpx	ft_complex(double re, double im);
t_cpx	ft_addc(t_cpx z, t_cpx w);
t_cpx	ft_multc(t_cpx z, t_cpx w) ;
double	ft_modulus(t_cpx z);
t_cpx	ft_rot(double theta);

#endif
