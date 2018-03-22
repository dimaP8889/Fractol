/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_motion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 16:58:52 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/03/21 16:58:53 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_mouse(t_mlx *data, int x, int y)
{
	if (x > 0 && x < 1000 && y > 0 && y < 1000)
	{
		data->coord.const_x = (double)(x - 500) / (double)500;
		data->coord.const_y = (double)(y - 500) / (double)500;
	}
	return (0);
}

int			mouse_motion(int x, int y, void *param)
{
	static t_mlx		*data;

	data = param;
	if (x < 0 || x > 1000 || y < 0 || y > 1000)
		return (0);
	data->coord.catch_x = x;
	data->coord.catch_y = y;
	if (!data->coord.narko)
		mlx_clear_window(data->mlx, data->wnd);
	if (data->coord.move && (data->fractol == 2 || data->fractol == 5
	|| data->fractol == 6 || data->fractol == 7))
		ft_mouse(data, x, y);
	ft_find_fract(data);
	if (!data->coord.narko)
	{
		ft_print(data);
	}
	return (0);
}
