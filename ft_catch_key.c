/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_catch_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 19:15:24 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/03/14 19:15:25 by dpogrebn         ###   ########.fr       */
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
