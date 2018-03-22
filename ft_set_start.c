/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 18:16:08 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/03/22 18:16:09 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_set_start(t_mlx *data)
{
	if (data->coord.fractol == 2)
	{
		data->coord.const_x = -0.3;
		data->coord.const_y = 0.7;
	}
	if (data->coord.fractol == 5)
	{
		data->coord.const_x = 0;
		data->coord.const_y = 0.65;
	}
	if (data->coord.fractol == 6)
	{
		data->coord.const_x = 0.55;
		data->coord.const_y = 0.35;
	}
	if (data->coord.fractol == 7)
	{
		data->coord.const_x = 0.22;
		data->coord.const_y = 0;
	}
}