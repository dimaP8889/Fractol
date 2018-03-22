/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra_f.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 03:51:12 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/03/22 03:51:13 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_fin_set(t_mlx *data, int fractol)
{
	static int	check;

	data->coord.catch_y = 500;
	data->coord.catch_x = 500;
	data->coord.beaut = 1;
	if (!check)
		data->coord.help = 1;
	check = 1;
	data->fractol = fractol;
	data->coord.fractol = fractol;
}

void		ft_set_data(t_mlx *data, int fractol)
{
	data->coord.zoom = 0.5;
	if (fractol == 1 || fractol == 3)
		data->coord.move_x = -0.5;
	else
		data->coord.move_x = 0;
	if (fractol == 3)
		data->coord.move_y = -0.5;
	else
		data->coord.move_y = 0;
	data->coord.iter = 100;
	data->coord.ch_zoom_x = 0;
	data->coord.ch_zoom_y = 0;
	data->coord.cent_x = 500;
	data->coord.cent_y = 500;
	data->coord.narko = 0;
	data->coord.degree = 1;
	data->coord.const_x = -0.7;
	data->coord.const_y = 0.25;
	data->coord.col = 0xFFFFFF;
	data->coord.background = 0x000000;
	data->coord.move = 1;
	data->coord.zoooooom = 1;
	ft_fin_set(data, fractol);
}

void		ft_find_fract(t_mlx *data)
{
	if (data->fractol == 1 || data->fractol == 3 || data->fractol == 4)
		ft_men_fract(data);
	if (data->fractol == 2 || data->fractol == 5)
		ft_jul_fract(data);
}

void		ft_check_key(t_mult *coord, t_mult keys)
{
	coord->zoom = keys.zoom;
	coord->move_x = keys.move_x;
	coord->move_y = keys.move_y;
	coord->iter = keys.iter;
	coord->ch_zoom_y = keys.ch_zoom_y;
	coord->ch_zoom_x = keys.ch_zoom_x;
	coord->narko = keys.narko;
	coord->degree = keys.degree;
	coord->col = keys.col;
	coord->const_x = keys.const_x;
	coord->const_y = keys.const_y;
	coord->move = keys.move;
	coord->zoooooom = keys.zoooooom;
	coord->catch_x = keys.catch_x;
	coord->catch_y = keys.catch_y;
	coord->background = keys.background;
	coord->beaut = keys.beaut;
	coord->help = keys.help;
	coord->fractol = keys.fractol;
}

int			ft_choose(int i, t_mult *data, double c_x, double c_y)
{
	if (data->fractol == 1)
		i = ft_men_l(i, data, c_x, c_y);
	if (data->fractol == 2)
		i = ft_jul_l(i, data, c_x, c_y);
	if (data->fractol == 3)
		i = ft_ship_l(i, data, c_x, c_y);
	if (data->fractol == 4)
		i = ft_tricorn_l(i, data, c_x, c_y);
	if (data->fractol == 5)
		i = ft_jul_tan_l(i, data, c_x, c_y);
	return (i);
}
