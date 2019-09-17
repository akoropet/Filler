/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoropet <akoropet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 20:16:12 by akoropet          #+#    #+#             */
/*   Updated: 2019/09/17 18:06:56 by akoropet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

void	reset(t_filler *filler)
{
	filler->figure_size.x = 0;
	filler->figure_size.y = 0;
	filler->f1_size.x = 100;
	filler->f1_size.y = 100;
	filler->f2_size.x = -1;
	filler->f2_size.y = -1;
	filler->target.x = 0;
	filler->target.y = 0;
	filler->coord_place.x = 0;
	filler->coord_place.y = 0;
	filler->f_size.x = 0;
	filler->f_size.y = 0;
	filler->range = 100;
}

void	players(t_filler *filler)
{
	int		i;
	char	*str;

	i = 0;
	get_next_line(0, &str);
	while (!ft_isdigit(str[i]))
		i++;
	filler->player_pc = str[i] == '1' ? 'X' : 'O';
	filler->player_my = str[i] == '1' ? 'O' : 'X';
	filler->start_my.x = 0;
	filler->start_my.y = 0;
	filler->start_pc.x = 0;
	filler->start_pc.y = 0;
	filler->map_size.x = 0;
	filler->map_size.y = 0;
	ft_strdel(&str);
}

void	start_point(t_filler *filler)
{
	int		i;
	int		j;

	j = -1;
	while (++j < filler->map_size.y)
	{
		i = -1;
		while (++i < filler->map_size.x)
		{
			if (filler->map[j][i] == 'O')
			{
				filler->player_my == 'O' ? filler->start_my.x = i : 0;
				filler->player_my == 'O' ? filler->start_my.y = j : 0;
				filler->player_my == 'X' ? filler->start_pc.x = i : 0;
				filler->player_my == 'X' ? filler->start_pc.y = j : 0;
			}
			if (filler->map[j][i] == 'X')
			{
				filler->player_my == 'X' ? filler->start_my.x = i : 0;
				filler->player_my == 'X' ? filler->start_my.y = j : 0;
				filler->player_my == 'O' ? filler->start_pc.x = i : 0;
				filler->player_my == 'O' ? filler->start_pc.y = j : 0;
			}
		}
	}
}

void	freesher(t_filler *filler)
{
	int		i;

	i = -1;
	while (++i < filler->map_size.y && filler->map[i])
		free(filler->map[i]);
	if (filler->map)
		free(filler->map);
	i = -1;
	while (++i < filler->figure_size.y && filler->map_figure[i])
		free(filler->map_figure[i]);
	if (filler->map_figure)
		free(filler->map_figure);
	i = -1;
	while (++i < filler->f_size.y && filler->figure[i])
		free(filler->figure[i]);
	if (filler->figure)
		free(filler->figure);
}

int		main(void)
{
	t_filler	*filler;

	filler = (t_filler *)malloc(sizeof(t_filler));
	players(filler);
	while (1)
	{
		reset(filler);
		if (!map(filler) && ft_printf("0 0\n"))
			return (0);
		figure(filler);
		if (filler->start_my.x == 0 && filler->start_my.y == 0 &&
			filler->start_pc.x == 0 && filler->start_pc.y == 0)
			start_point(filler);
		find_place(filler);
		ft_printf("%d %d\n", filler->coord_place.y, filler->coord_place.x);
		if (filler->coord_place.y == 0 && filler->coord_place.x == 0)
			break ;
		freesher(filler);
	}
	freesher(filler);
	free(filler);
	return (0);
}
