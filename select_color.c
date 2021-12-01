#include "select_color.h"

static int	ft_better_mod(int n, int q)
{
	if (n % q >= 0)
		return (n % q);
	else 
		return (n + n % q);
}

#define NCHOICES 11
t_colorscheme	ft_scheme_selector(int dir)
{
	static int			cur_scheme = 0;
	const t_colorscheme	choices[NCHOICES] =
	{
//		// tropical (why is this ugly? )
//		{0xc09010, 0x30a8ff},
		// galaxy
		{0x080020, 0xffffa0},
		// ghost-ship
		{0x200010, 0xa080ff},
		// grayscale
		{0x000000, 0xffffff},
		// dune
		{0xffc0a0, 0x300010},
		// sea-monster
		{0x002020, 0x00b048},
		// red ink
		{0xb0b0b0, 0x300010},
		// crystal
		{0x151522, 0xaf4fff},
		// sunset
		{0x554090, 0xff4073},
		// cream
		{0x200010, 0xffdfbf},
		// azulera
		{0xb0b0b0, 0x100030},
		// kashmir
		{0x006030, 0xffb040},
	};

	cur_scheme = ft_better_mod(cur_scheme + dir, NCHOICES);
	return (choices[cur_scheme]);
}

