/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_zoom.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 14:17:46 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/03/15 14:17:48 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_change_zoom_pos(t_mlx *data, int x, int y)
{
	(void)data;
	static int	x_cent;
	static int	y_cent;
	if (!x_cent && !y_cent)
	{
		x_cent = 500;
		y_cent = 500;
	}
	printf("x cent: %i\n", x_cent);
	printf("x: %i\n", x);
	printf("y cent: %i\n", y_cent);
	printf("y: %i\n", y);
	if (x > x_cent)
	{
		data->coord.ch_zoom_x += (x_cent - x);
		data->coord.move_x += (x - x_cent) / (x_cent * data->coord.zoom);
	}
	else if (x < x_cent)
	{
		data->coord.ch_zoom_x += (x_cent - x);
		data->coord.move_x += (x - x_cent) / (x_cent * data->coord.zoom);
	}
	if (y > y_cent)
	{
		data->coord.ch_zoom_y += (y_cent - y);
		data->coord.move_y += (y - y_cent) / (y_cent * data->coord.zoom);
	}
	else if (y < y_cent)
	{
		data->coord.ch_zoom_y += (y_cent - y);
		data->coord.move_y += (y - y_cent) / (y_cent * data->coord.zoom);
	}
	printf("zoom_x: %i\n", data->coord.ch_zoom_x);
	printf("zoom_y: %i\n", data->coord.ch_zoom_y);
	printf("move_x: %f\n", data->coord.move_x);
	printf("move_y: %f\n", data->coord.move_y);
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

	if (!x1 && !y1)
	{
		x1 = 500;
		y1 = 500;
	}
	if (keycode == 2)
	{
		x1 = x;
		y1 = y;
	}
	if (keycode == 5)
	{
		data->coord.zoom *= 1.1;
		ft_change_zoom_pos(data, x1, y1);
	}
	if (keycode == 4)
	{
		data->coord.zoom /= 1.1;
		ft_change_zoom_pos(data, x1, y1);
	}
}

int		mouse_zoom(int button, int x, int y, void *param)
{
	static t_mlx		*data;

	(void)x;
	(void)y;
	data = param;
	ft_keycode_mouse(button, data, x, y);
	if (data->fractol == 1)
		ft_men_fract(data);
	if (data->fractol == 2)
		ft_jul_fract(data);
	return (0);
}