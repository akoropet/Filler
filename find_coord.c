/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_coord.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoropet <akoropet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 21:43:34 by akoropet          #+#    #+#             */
/*   Updated: 2019/03/06 22:08:33 by akoropet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		check_horizontal(t_filler *f, int i, int j, int tab)
{
	int		k;

	k = -1;
	while (++k <= tab && (k + i < f->map_size.x || i - k >= 0))
	{
		if (k + i < f->map_size.x && ((j + tab < f->map_size.y &&
			f->map[j + tab][i + k] == f->player_pc) || (j - tab >= 0 &&
			f->map[j - tab][i + k] == f->player_pc)) && f->range > tab)
		{
			f->range = tab;
			return (1);
		}
		if (i - k >= 0 && ((j + tab < f->map_size.y &&
			f->map[j + tab][i - k] == f->player_pc) || (j - tab >= 0 &&
			f->map[j - tab][i - k] == f->player_pc)) && f->range > tab)
		{
			f->range = tab;
			return (1);
		}
	}
	return (0);
}

int		check_vertical(t_filler *f, int i, int j, int tab)
{
	int		k;

	k = -1;
	while (++k <= tab && (k + j < f->map_size.y || j - k >= 0))
	{
		if (k + j < f->map_size.y && ((i + tab < f->map_size.x &&
			f->map[j + k][i + tab] == f->player_pc) || (i - tab >= 0 &&
			f->map[j + k][i - tab] == f->player_pc)) && f->range > tab)
		{
			f->range = tab;
			return (1);
		}
		if (j - k >= 0 && ((i + tab < f->map_size.x &&
			f->map[j - k][i + tab] == f->player_pc) || (i - tab >= 0 &&
			f->map[j - k][i - tab] == f->player_pc)) && f->range > tab)
		{
			f->range = tab;
			return (1);
		}
	}
	return (0);
}

void	check_square(t_filler *filler, int i, int j, int tab)
{
	int		w;
	int		h;
	int		k;

	w = -1;
	k = i;
	while (++w < filler->f_size.y && j < filler->map_size.y)
	{
		h = -1;
		i = k;
		while (++h < filler->f_size.x && i < filler->map_size.x)
		{
			if (filler->figure[w][h] == '*')
			{
				tab = 1;
				while (!check_vertical(filler, i, j, tab) &&
					!check_horizontal(filler, i, j, tab) &&
					tab < filler->map_size.x)
					tab++;
			}
			i++;
		}
		j++;
	}
}

int		check_place(t_filler *f, int i, int j, int connect)
{
	int		w;
	int		h;
	int		k;

	w = -1;
	k = i;
	while (++w < f->f_size.y && j < f->map_size.y)
	{
		h = -1;
		i = k;
		while (++h < f->f_size.x && i < f->map_size.x)
		{
			if ((f->figure[w][h] == '.' && (f->map[j][i] == '.' ||
				f->map[j][i] == f->player_my || f->map[j][i] == f->player_pc))
				|| (f->figure[w][h] == '*' && (f->map[j][i] == f->player_my ||
				f->map[j][i] == '.')))
				connect = f->figure[w][h] == '*' && f->map[j][i] == f->player_my
					? connect + 1 : connect;
			else
				return (0);
			i++;
		}
		j++;
	}
	return (connect == 1 && w == f->f_size.y && h == f->f_size.x);
}

void	find_place(t_filler *filler)
{
	int		i;
	int		j;
	int		tab;

	j = -1;
	tab = 100;
	while (++j < filler->map_size.y)
	{
		i = 0;
		while (i < filler->map_size.x)
		{
			if (check_place(filler, i, j, 0) > 0)
			{
				check_square(filler, i, j, 1);
				if (tab > filler->range && i - filler->f1_size.x != 0 &&
					j - filler->f1_size.y != 0)
				{
					tab = filler->range;
					filler->coord_place.x = i - filler->f1_size.x;
					filler->coord_place.y = j - filler->f1_size.y;
				}
			}
			i++;
		}
	}
}
