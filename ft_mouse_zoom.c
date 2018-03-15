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
	if (keycode == 1)
		ft_find_move(data, x, y);
	// if (keycode == 2)
	// 	ft_change_zoom_pos
	if (keycode == 5)
		data->coord.zoom *= 1.1;
	if (keycode == 4)
		data->coord.zoom /= 1.1;
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