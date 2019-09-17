/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoropet <akoropet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 21:42:01 by akoropet          #+#    #+#             */
/*   Updated: 2019/09/17 18:06:47 by akoropet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

void	cat_figure_f2(t_filler *filler)
{
	int		i;
	int		j;
	int		n;

	n = 0;
	j = filler->f1_size.y;
	while (j < filler->figure_size.y)
	{
		i = filler->f1_size.x;
		while (i < filler->figure_size.x)
		{
			if (filler->map_figure[j][i] == '*')
			{
				i > filler->f2_size.x ? filler->f2_size.x = i : 0;
				j > filler->f2_size.y ? filler->f2_size.y = j : 0;
			}
			i++;
		}
		j++;
	}
}

void	cat_figure_f1(t_filler *filler)
{
	int		i;
	int		j;

	j = 0;
	while (j < filler->figure_size.y)
	{
		i = 0;
		while (i < filler->figure_size.x)
		{
			if (filler->map_figure[j][i] == '*' && i < filler->f1_size.x)
				filler->f1_size.x = i;
			if (filler->map_figure[j][i] == '*' && j < filler->f1_size.y)
				filler->f1_size.y = j;
			i++;
		}
		j++;
	}
}

void	cat_figure(t_filler *filler)
{
	int		i;
	int		j;
	int		x;
	int		y;

	j = -1;
	cat_figure_f1(filler);
	cat_figure_f2(filler);
	x = filler->f2_size.x - filler->f1_size.x + 1;
	y = filler->f2_size.y - filler->f1_size.y + 1;
	filler->f_size.x = x;
	filler->f_size.y = y;
	filler->figure = (char **)malloc(sizeof(char *) * (y + 1));
	filler->figure[y] = NULL;
	while (y > ++j)
	{
		i = -1;
		filler->figure[j] = (char *)malloc(sizeof(char) * (x + 1));
		filler->figure[j][x] = '\0';
		while (++i < x)
		{
			filler->figure[j][i] =
			filler->map_figure[filler->f1_size.y + j][filler->f1_size.x + i];
		}
	}
}

void	figure(t_filler *filler)
{
	char	*str;
	char	*s;
	int		i;

	i = -1;
	get_next_line(0, &str);
	s = str;
	s = ft_strchr(s, ' ');
	filler->figure_size.y = ft_atoi(s);
	s++;
	s = ft_strchr(s, ' ');
	filler->figure_size.x = ft_atoi(s);
	ft_strdel(&str);
	filler->map_figure = (char **)malloc(sizeof(char *) *
		(filler->figure_size.y + 1));
	filler->map_figure[filler->figure_size.y] = NULL;
	while (++i < filler->figure_size.y)
	{
		get_next_line(0, &str);
		filler->map_figure[i] = ft_strdup(str);
		ft_strdel(&str);
	}
	cat_figure(filler);
}
