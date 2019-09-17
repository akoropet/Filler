/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoropet <akoropet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 19:36:12 by akoropet          #+#    #+#             */
/*   Updated: 2019/09/17 18:39:30 by akoropet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/visualizator.h"

void	players(char **player1, char **player2)
{
	char	*str;
	char	*tmp;
	char	*r;

	get_next_line(0, &str);
	tmp = str;
	while ((r = ft_strchr(tmp, '/')))
	{
		r++;
		tmp = r;
	}
	*player1 = ft_strndup(tmp, '.');
	ft_strdel(&str);
	get_next_line(0, &str);
	ft_strdel(&str);
	get_next_line(0, &str);
	tmp = str;
	while ((r = ft_strchr(tmp, '/')))
	{
		r++;
		tmp = r;
	}
	*player2 = ft_isalpha(tmp[0]) ? ft_strndup(tmp, '.') :
		ft_strdup("(player missing)\n");
	ft_strdel(&str);
}

int		game(char *player1, char *player2, char *str)
{
	int		p1;
	int		p2;

	if (ft_isdigit(str[0]))
		field(str);
	else if (str[0] == '=')
	{
		p1 = result(player1, str, 1);
		get_next_line(0, &str);
		p2 = result(player2, str, 2);
		winner(p1, p2, player1, player2);
		return (0);
	}
	else if (str[1] == 'l')
	{
		ft_putstr("\033[2;0f");
		ft_strdel(&str);
	}
	else
		ft_strdel(&str);
	return (1);
}

int		main(void)
{
	int		i;
	char	*str;
	char	*player1;
	char	*player2;

	str = NULL;
	i = -1;
	while (++i < 5 && get_next_line(0, &str))
		ft_strdel(&str);
	ft_putstr("\033[2J");
	if (get_next_line(0, &str) && !ft_strcmp("error:", str))
	{
		ft_vs("(bad player)", "(bad player)\n", 1);
		ft_vs("(bad player)", "(bad player)\n", 2);
		winner(0, 0, "(bad player)", "(bad player)");
		ft_strdel(&str);
		return (0);
	}
	ft_strdel(&str);
	players(&player1, &player2);
	ft_vs(player1, player2, 1);
	ft_vs(player1, player2, 2);
	while (get_next_line(0, &str))
		game(player1, player2, str);
	return (0);
}
