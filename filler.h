/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoropet <akoropet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 20:17:24 by akoropet          #+#    #+#             */
/*   Updated: 2019/03/08 16:58:07 by akoropet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "./lib/libft/libft.h"

typedef struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef struct	s_filler
{
	char		**map;
	char		**map_figure;
	char		**figure;
	char		player_my;
	char		player_pc;
	int			range;
	t_coord		map_size;
	t_coord		figure_size;
	t_coord		f1_size;
	t_coord		f2_size;
	t_coord		f_size;
	t_coord		start_my;
	t_coord		start_pc;
	t_coord		target;
	t_coord		coord_place;
}				t_filler;

void			freesher(t_filler *filler);
void			start_point(t_filler *filler);
void			players(t_filler *filler);
void			reset(t_filler *filler);
void			size_map(t_filler *filler);
int				map(t_filler *filler);
void			find_place(t_filler *filler);
int				check_place(t_filler *f, int i, int j, int connect);
void			check_square(t_filler *filler, int i, int j, int tab);
int				check_vertical(t_filler *f, int i, int j, int tab);
int				check_horizontal(t_filler *f, int i, int j, int tab);
void			figure(t_filler *filler);
void			cat_figure(t_filler *filler);
void			cat_figure_f1(t_filler *filler);
void			cat_figure_f2(t_filler *filler);

#endif
