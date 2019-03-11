/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoropet <akoropet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 21:34:19 by akoropet          #+#    #+#             */
/*   Updated: 2019/03/08 14:41:09 by akoropet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizator.h"

void	color(char sym)
{
	if (sym == 'O')
	{
		ft_putstr("\033[91m");
		ft_printf("%c", 'O');
	}
	if (sym == 'X')
	{
		ft_putstr("\033[92m");
		ft_printf("%c", 'X');
	}
	if (sym == 'o')
	{
		ft_putstr("\033[91;47m");
		ft_printf("%c", 'O');
	}
	if (sym == 'x')
	{
		ft_putstr("\033[92;47m");
		ft_printf("%c", 'X');
	}
	if (sym == '.')
	{
		ft_putstr("\033[93m");
		ft_putchar(sym);
	}
}

void	field(char *str)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_strchr(str, ' ');
	ft_putchar(' ');
	while (tmp[i])
	{
		if (i > 0)
			color(tmp[i]);
		ft_putstr("\033[0;0m");
		i++;
	}
	ft_putstr("\033[K");
	ft_putchar('\n');
	ft_strdel(&str);
}

void	winner(int p1, int p2, char *player1, char *player2)
{
	ft_putstr("\033[5m");
	if (p1 > p2)
	{
		ft_printf("%lc ", L'🏆');
		ft_putstr("\033[5;91m");
		ft_putstr(player1);
		ft_putstr("\033[5;95m");
		ft_printf(" WON %lc  Congratulations %lc\n", L'👍', L'🤘');
	}
	else if (p2 > p1)
	{
		ft_printf("%lc ", L'🏆');
		ft_putstr("\033[5;92m");
		ft_putstr(player2);
		ft_putstr("\033[5;95m");
		ft_printf(" WON %lc  Congratulations %lc\n", L'👍', L'🤘');
	}
	else
	{
		!ft_strcmp(player2, "(player missing)\n") ? ft_putstr("\033[2;0f") : 0;
		!ft_strcmp(player2, "(player missing)\n") ? ft_putstr("\033[J") : 0;
		ft_putstr("\033[5;95m");
		ft_printf("%lc No one won this match, stand by...\n", L'🚷');
	}
	ft_putstr("\033[0;0m");
}

int		result(char *player, char *str, int n)
{
	int		p;

	p = 0;
	if (ft_strcmp(player, "(player missing)\n"))
	{
		n == 1 ? ft_putstr("\033[91m") : ft_putstr("\033[92m");
		ft_printf("%lc %s", L'👉', player);
		ft_putstr("\033[95m");
		ft_putstr(" got ");
		n == 1 ? ft_putstr("\033[91m") : ft_putstr("\033[92m");
		p = ft_atoi(ft_strchr(str, ':') + 2);
		ft_putnbr(p);
		ft_putstr("\033[95m");
		ft_putstr(" points\n");
		ft_strdel(&str);
	}
	return (p);
}

void	ft_vs(char *player1, char *player2, int n)
{
	ft_putstr("\033[0;0f");
	ft_putstr("\033[95m");
	ft_putstr("   Game ");
	ft_putstr("\033[91m");
	ft_putstr(player1);
	ft_printf("%lc", L'🤜');
	ft_putstr("\033[95m");
	ft_putstr(" VS ");
	ft_putstr("\033[92m");
	ft_printf("%lc", L'🤛');
	ft_putstr(player2);
	if (n == 1 && ft_strcmp("(player missing)\n", player2) &&
		ft_strcmp("(bad player)\n", player2))
	{
		ft_putstr("\033[96m");
		ft_putstr("\n>>>Let's Get Ready To Rumble!<<<\n");
		sleep(4);
		ft_putstr("\033[2J");
	}
}
