#ifndef SELECT_COLOR_H
#define SELECT_COLOR_H

typedef struct
{
	int	from;
	int	to;
}	t_colorscheme;

/* go to 'dir'th next colorscheme */
t_colorscheme	ft_scheme_selector(int dir);

#endif
