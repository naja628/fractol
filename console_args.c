#include "console_args.h"

void	ft_puterr(const char *message)
{
	if (!message)
		return ;
	while (*message)
		write(2, message++, 1);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!s1 && !s2)
		return (0);
	if (!s1)
		return (-1);
	if (!s2)
		return (1);
	while (n != 0 && *s1)
	{
		if (*s1 != *s2)
			return ((t_uchar)(*s1) - (t_uchar)(*s2));
		++s1;
		++s2;
		--n;
	}
	if (n != 0)
		return ((t_uchar)(*s1) - (t_uchar)(*s2));
	else
		return (0);
}

/**** atoi ****/
typedef unsigned int	t_uint;

static int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	else
		return (0);
}

/* note : as unsigned, INT_MIN = - INT_MIN
 * try to update the value of *acc
 * if we're going to overflow return (0)
 * otherwise return (1) */
static int	ft_try_update(int sign, t_uint *acc, t_uint digit)
{
	if (sign == 1)
	{
		if (*acc <= (t_uint) INT_MAX / 10)
			*acc *= 10;
		else
			return (0);
		if (*acc <= (t_uint) INT_MAX - digit)
			*acc += digit;
		else
			return (0);
	}
	if (sign == -1)
	{
		if (*acc <= (t_uint) INT_MIN / 10)
			*acc *= 10;
		else
			return (0);
		if (*acc <= (t_uint) INT_MIN - digit)
			*acc += digit;
		else
			return (0);
	}
	return (1);
}

/* special version of atoi that sets errcode to -1 
 * when we overflow an int or if s is not an integer 
 * representation (using stricter rules than atoi) */
double	ft_xatoi(const char *s, int *errcode)
{
	int		sign;
	t_uint	acc;

	*errcode = 0;
	while (('\t' <= *s && *s <= '\r') || *s == ' ')
		++s;
	sign = 1;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = -1;
		++s;
	}
	acc = 0;
	while (*errcode != -1 && ft_isdigit(*s))
	{
		if (ft_try_update(sign, &acc, *s - '0'))
			++s;
		else
			*errcode = -1;
	}
	if (*s != '\0')
		*errcode = -1;
	return (sign * acc / 1000.0);
}
