/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizator.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoropet <akoropet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 21:35:29 by akoropet          #+#    #+#             */
/*   Updated: 2019/09/17 18:35:45 by akoropet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALIZATOR_H
# define VISUALIZATOR_H

# include "../lib/libft/libft.h"

void	players(char **player1, char **player2);
int		game(char *player1, char *player2, char *str);
void	color(char sym);
void	field(char *str);
void	winner(int p1, int p2, char *player1, char *player2);
int		result(char *player, char *str, int n);
void	ft_vs(char *player1, char *player2, int n);

#endif
