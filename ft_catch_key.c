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

void	ft_colours(int keycode, t_mlx *data)
{
	if (keycode == 18)
		data->coord.col = 0xFF0000;
	if (keycode == 19)
		data->coord.col = 0x00FF00;
	if (keycode == 20)
		data->coord.col = 0x0000FF;
	if (keycode == 21)
		data->coord.col = 0xFFFFFF;
	if (keycode == 22)
		data->coord.col = 0xFFFF00;
	if (keycode == 26)
		data->coord.col = 0x00FFFF;
	if (keycode == 28)
		data->coord.col = 0xFF00FF;
	if (keycode == 23)
		data->coord.col = 0xFF7F50;
	if (keycode == 15 && data->coord.col < 0xFB0000)
		data->coord.col += 0x050000;
	if (keycode == 17 && data->coord.col < 0xFFFB00)
		data->coord.col += 0x000500;
	if (keycode == 16 && data->coord.col < 0xFFFFFB)
		data->coord.col += 0x000005;
	if (keycode == 3 && data->coord.col > 0x050000)
		data->coord.col -= 0x050000;
	if (keycode == 5 && data->coord.col > 0x000500)
		data->coord.col -= 0x000500;
	if (keycode == 4 && data->coord.col > 0x000005)
		data->coord.col -= 0x000005;
}

void	ft_keycode(int keycode, t_mlx *data)
{
	if (keycode == 8)
	{
		ft_set_data(data, data->fractol);
		data->coord.null = 1;
	}
	if (keycode == 45)
	{
		if (!data->coord.narko)
			data->coord.narko = 1;
		else
			data->coord.narko = 0;
	}
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
	if (!data->coord.narko)
		ft_colours(keycode, data);
}

int		ft_catch_key(int keycode, void *param)
{
	static t_mlx		*data;
	char				*str;

	data = param;
	if (!data->coord.narko)
		mlx_clear_window(data->mlx, data->wnd);
	ft_keycode(keycode, data);
	if (data->fractol == 1)
		ft_men_fract(data);
	if (data->fractol == 2)
		ft_jul_fract(data);
	if (!data->coord.narko)
	{
		str = ft_itoa_base(data->coord.col, 16, 1);
		mlx_string_put(data->mlx, data->wnd, 0, 0, data->coord.col, str);
		free(str);
	}
	return (0);
}
