/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoropet <akoropet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 21:44:16 by akoropet          #+#    #+#             */
/*   Updated: 2019/03/08 16:31:59 by akoropet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		map(t_filler *filler)
{
	char	*str;
	char	*s;
	int		i;

	i = 0;
	size_map(filler);
	filler->map = (char **)malloc(sizeof(char *) * (filler->map_size.y + 1));
	filler->map[filler->map_size.y] = NULL;
	str = NULL;
	get_next_line(0, &str);
	ft_strdel(&str);
	filler->map[i] = NULL;
	while (i < filler->map_size.y)
	{
		get_next_line(0, &str);
		if ((s = ft_strchr(str, ' ')) == '\0')
		{
			ft_strdel(&str);
			return (0);
		}
		s++;
		filler->map[i++] = ft_strdup(s);
		ft_strdel(&str);
	}
	return (1);
}

void	size_map(t_filler *filler)
{
	char	*str;
	char	*s;

	get_next_line(0, &str);
	if (filler->map_size.x == 0 && filler->map_size.y == 0)
	{
		s = str;
		while (*s != ' ')
			s++;
		filler->map_size.y = ft_atoi(s);
		s++;
		while (*s != ' ')
			s++;
		filler->map_size.x = ft_atoi(s);
	}
}
