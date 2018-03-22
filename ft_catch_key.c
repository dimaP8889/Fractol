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

int			ft_exit_x(void *par)
{
	par = NULL;
	exit(1);
	return (0);
}

static void	ft_colours_ch(int keycode, t_mlx *data)
{
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
	if (keycode == 4 && data->coord.col > 0x000000)
		data->coord.col -= 0x000005;
	if (keycode == 32 && data->coord.background < 0xFB0000)
		data->coord.background += 0x050000;
	if (keycode == 34 && data->coord.background < 0xFFFB00)
		data->coord.background += 0x000500;
	if (keycode == 31 && data->coord.background < 0xFFFFFB)
		data->coord.background += 0x000005;
	if (keycode == 38 && data->coord.background > 0x050000)
		data->coord.background -= 0x050000;
	if (keycode == 40 && data->coord.background > 0x000500)
		data->coord.background -= 0x000500;
	if (keycode == 37 && data->coord.background > 0x000000)
		data->coord.background -= 0x000005;
}

void		ft_colours(int keycode, t_mlx *data)
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
	ft_colours_ch(keycode, data);
}

int			ft_catch_key(int keycode, void *param)
{
	static t_mlx		*data;

	data = param;
	if (!data->coord.narko)
		mlx_clear_window(data->mlx, data->wnd);
	ft_keycode(keycode, data);
	ft_find_fract(data);
	if (!data->coord.narko)
		ft_print(data);
	return (0);
}
