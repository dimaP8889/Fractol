/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoooooom.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 18:24:54 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/03/21 18:24:54 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_zoooooom(t_mlx *data)
{
	if (data->coord.zoom < 44494353681901)
	{
		ft_change_zoom_pos(data, data->coord.catch_x, data->coord.catch_y);
		data->coord.zoom *= 1.1;
	}
}

int			zoooooom(void *param)
{
	static t_mlx		*data;

	data = param;
	if (!data->coord.narko)
		mlx_clear_window(data->mlx, data->wnd);
	if (!data->coord.zoooooom)
		ft_zoooooom(data);
	ft_find_fract(data);
	if (!data->coord.narko)
	{
		ft_print(data);
	}
	return (0);
}
