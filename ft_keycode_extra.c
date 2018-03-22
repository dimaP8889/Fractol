/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keycode_extra.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 05:50:14 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/03/22 05:50:15 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_keycode_sec(int keycode, t_mlx *data)
{
	if (keycode == 6)
	{
		if (data->coord.zoooooom)
			data->coord.zoooooom = 0;
		else
			data->coord.zoooooom = 1;
	}
	else
		data->coord.zoooooom = 1;
	if (keycode == 45)
	{
		if (!data->coord.narko)
			data->coord.narko = 1;
		else
			data->coord.narko = 0;
	}
	if (keycode == 49)
	{
		if (data->fractol == 7)
			data->fractol = 1;
		else
			data->fractol++;
		ft_set_data(data, data->fractol);
		data->coord.null = 1;
	}
}

static void	ft_keycode_thrd(int keycode, t_mlx *data)
{
	if (keycode == 30 && data->coord.degree > 1 && data->coord.narko)
		data->coord.degree--;
	if (keycode == 33 && data->coord.degree < 10 && data->coord.narko)
		data->coord.degree++;
	if (keycode == 53)
		exit(1);
	if (keycode == 24)
		data->coord.iter += 5;
	if (keycode == 27 && data->coord.iter > 5)
		data->coord.iter -= 5;
	if (keycode == 13)
		data->coord.move_y += 0.1 / data->coord.zoom;
	if (keycode == 1)
		data->coord.move_y -= 0.1 / data->coord.zoom;
	if (keycode == 0)
		data->coord.move_x += 0.1 / data->coord.zoom;
	if (keycode == 2)
		data->coord.move_x -= 0.1 / data->coord.zoom;
	if (keycode == 11)
	{
		if (data->coord.beaut)
			data->coord.beaut = 0;
		else
			data->coord.beaut = 1;
	}
}

void		ft_keycode(int keycode, t_mlx *data)
{
	if (keycode == 261)
	{
		if (data->coord.help)
			data->coord.help = 0;
		else
			data->coord.help = 1;
	}
	if (keycode == 8)
	{
		ft_set_data(data, data->fractol);
		data->coord.null = 1;
	}
	if (keycode == 256)
	{
		if (data->coord.move)
			data->coord.move = 0;
		else
			data->coord.move = 1;
	}
	ft_keycode_sec(keycode, data);
	ft_keycode_thrd(keycode, data);
	if (!data->coord.narko)
		ft_colours(keycode, data);
}
