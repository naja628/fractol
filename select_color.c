/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najacque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:31:35 by najacque          #+#    #+#             */
/*   Updated: 2021/12/15 16:25:26 by najacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select_color.h"

static int	ft_better_mod(int n, int q)
{
	if (n % q >= 0)
		return (n % q);
	else
		return (n + n % q);
}

/* colorschemes with mnemonic labels :
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
		// oasis
		{0xffc070, 0x007070},
		// crystal
		{0x151522, 0x7f2fff},
		// snowy
		{0x302050, 0xbfbfff},
		// sunset
		{0x603898, 0xff007b},
		// cream
		{0x200010, 0xffdfbf},
		// azulera
		{0xb0b0b0, 0x1b0038},
		// kashmir
		{0x006030, 0xffb040},
		*/

#define NCHOICES 13

// norminette made me do it....
t_colorscheme	ft_scheme_selector(int dir)
{
	static int			cur_scheme = 0;
	const t_colorscheme	choices[NCHOICES] = {{0x080020, 0xffffa0},
	{0x200010, 0xa080ff},
	{0x000000, 0xffffff},
	{0xffc0a0, 0x300010},
	{0x002020, 0x00b048},
	{0xb0b0b0, 0x300010},
	{0xffc070, 0x007070},
	{0x151522, 0x7f2fff},
	{0x302050, 0xbfbfff},
	{0x603898, 0xff007b},
	{0x200010, 0xffdfbf},
	{0xb0b0b0, 0x1b0038},
	{0x006030, 0xffb040},
	};

	cur_scheme = ft_better_mod(cur_scheme + dir, NCHOICES);
	return (choices[cur_scheme]);
}
