#ifndef CONSOLE_ARGS_H
# define CONSOLE_ARGS_H

# include <limits.h>
# include <unistd.h>

typedef unsigned int	t_uint;
typedef unsigned char	t_uchar;

void	ft_puterr(const char *message);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_xatoi(const char *s, int *errcode);

#endif
