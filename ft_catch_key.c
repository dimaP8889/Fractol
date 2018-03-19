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
		ft_set_data(data);
		data->coord.null = 1;
	}
	if (keycode == 17)
		data->coord.r = 1;
	else
		data->coord.r = 0;
	if (keycode == 5)
		data->coord.g = 1;
	else
		data->coord.g = 0;
	if (keycode == 11)
		data->coord.b = 1;
	else
		data->coord.b = 0;
	if (keycode == 45)
	{
		if (!data->coord.narko)
			data->coord.narko = 1;
		else
			data->coord.narko = 0;
	}
	if (keycode == 30 && data->coord.degree > 1)
		data->coord.degree--;
	if (keycode == 33 && data->coord.degree < 10)
		data->coord.degree++;
	if (keycode == 53)
		exit(1);
	if (keycode == 24)
		data->coord.iter += 5;
	if (keycode == 27 && data->coord.iter > 5)
		data->coord.iter -= 5;
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
	if (!data->coord.narko)
		mlx_clear_window(data->mlx, data->wnd);
	ft_keycode(keycode, data);
	if (data->fractol == 1)
		ft_men_fract(data);
	if (data->fractol == 2)
		ft_jul_fract(data);
	return (0);
}
