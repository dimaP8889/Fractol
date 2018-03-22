/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_zoom.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitriy1 <dmitriy1@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 14:17:46 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/03/19 15:14:12 by dmitriy1         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_change_zoom_pos(t_mlx *data, int x, int y)
{
	static int	x_cent;
	static int	y_cent;
	if ((!x_cent && !y_cent) || data->coord.null)
	{
		x_cent = 500;
		y_cent = 500;
		data->coord.null = 0;
	}
	if (x_cent != x)
	{
		data->coord.ch_zoom_x += (x_cent - x);
		data->coord.move_x += ((x - x_cent)) / (500 * data->coord.zoom);
	}
	if (y_cent != y)
	{
		data->coord.ch_zoom_y += (y_cent - y);
		data->coord.move_y += ((y - y_cent)) / (500 * data->coord.zoom);
	}
	y_cent = y;
	x_cent = x;
}

void	ft_find_move(t_mlx *data, int x, int y)
{
	if (x > 500)
		data->coord.move_x += (x - 500) / (500 * data->coord.zoom);
	else if (x < 500)
		data->coord.move_x -= (500 - x) / (500 * data->coord.zoom);
	if (y > 500)
		data->coord.move_y += (y - 500) / (500 * data->coord.zoom);
	else if (y < 500)
		data->coord.move_y -= (500 - y) / (500 * data->coord.zoom);
}

void	ft_keycode_mouse(int keycode, t_mlx *data, int x, int y)
{
	static	int	x1;
	static	int	y1;

	if ((!x1 && !y1) || data->coord.null)
	{
		x1 = 500;
		y1 = 500;
	}
	x1 = x;
	y1 = y;
	if (keycode == 1)
	{
		ft_find_move(data, x, y);
		data->coord.zoooooom = 1;
	}
	if (keycode == 5 && data->coord.zoom < 44494353681901)
	{
		ft_change_zoom_pos(data, x1, y1);
		data->coord.zoom *= 1.1;
		data->coord.zoooooom = 1;
	}
	if (keycode == 4 && data->coord.zoom > 0.000001)
	{
		ft_change_zoom_pos(data, x1, y1);
		data->coord.zoom /= 1.1;
		data->coord.zoooooom = 1;
	}
}

int		mouse_zoom(int button, int x, int y, void *param)
{
	static t_mlx		*data;
	
	data = param;
	if (!data->coord.narko)
		mlx_clear_window(data->mlx, data->wnd);
	ft_keycode_mouse(button, data, x, y);
	if (data->fractol == 1)
		ft_men_fract(data);
	if (data->fractol == 2)
		ft_jul_fract(data);
	if (data->fractol == 3)
		ft_burn_ship(data);
	if (!data->coord.narko)
	{
		ft_print(data);
	}
	return (0);
}