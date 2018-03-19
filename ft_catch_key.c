/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_catch_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitriy1 <dmitriy1@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 19:15:24 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/03/19 14:28:01 by dmitriy1         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_keycode(int keycode, t_mlx *data)
{
	if (keycode == 8)
	{
		data->coord.zoom = 0.5;
		data->coord.move_x = 0;
		data->coord.move_y = 0;
		data->coord.ch_zoom_x = 0;
		data->coord.ch_zoom_y = 0;
		data->coord.cent_x = 500;
		data->coord.cent_y = 500;
	}
	if (keycode == 53)
		exit(1);
	if (keycode == 116)
		data->coord.iter += 5;
	if (keycode == 121 && data->coord.iter > 5)
		data->coord.iter -= 5;
	if (keycode == 24)
		data->coord.zoom *= 1.1;
	if (keycode == 27)
		data->coord.zoom /= 1.1;
	if (keycode == 13)
		data->coord.move_y -= 0.1 / data->coord.zoom;
	if (keycode == 1)
		data->coord.move_y += 0.1 / data->coord.zoom;
	if (keycode == 0)
		data->coord.move_x -= 0.1 / data->coord.zoom;
	if (keycode == 2)
		data->coord.move_x += 0.1 / data->coord.zoom;
}

int		ft_catch_key(int keycode, void *param)
{
	static t_mlx		*data;

	data = param;
	ft_keycode(keycode, data);
	if (data->fractol == 1)
		ft_men_fract(data);
	if (data->fractol == 2)
		ft_jul_fract(data);
	return (0);
}