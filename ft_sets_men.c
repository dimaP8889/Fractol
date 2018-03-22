/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tricorn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 02:23:01 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/03/22 02:23:02 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_tricorn_l(int i, t_mult *data, double c_x, double c_y)
{
	double	new_x;
	double	new_y;
	double	old_x;
	double	old_y;

	new_x = 0;
	new_y = 0;
	old_x = 0;
	old_y = 0;
	while (i < data->iter)
	{
		old_y = new_y;
		old_x = new_x;
		new_x = old_x * old_x - old_y * old_y + c_x;
		new_y = -2 * old_x * old_y + c_y;
		if ((new_x * new_x + new_y * new_y) > 4)
			return (i);
		i = i + 1;
	}
	return (i);
}

int	ft_men_l(int i, t_mult *data, double c_x, double c_y)
{
	double	new_x;
	double	new_y;
	double	old_x;
	double	old_y;

	new_x = 0;
	new_y = 0;
	old_x = 0;
	old_y = 0;
	while (i < data->iter)
	{
		old_y = new_y;
		old_x = new_x;
		new_x = old_x * old_x - old_y * old_y + c_x;
		new_y = 2 * old_x * old_y + c_y;
		if ((new_x * new_x + new_y * new_y) > 4)
			return (i);
		i = i + 1;
	}
	return (i);
}

int	ft_ship_l(int i, t_mult *data, double c_x, double c_y)
{
	double	new_x;
	double	new_y;
	double	old_x;
	double	old_y;

	new_x = 0;
	new_y = 0;
	old_x = 0;
	old_y = 0;
	while (i < data->iter)
	{
		old_y = new_y;
		old_x = new_x;
		new_x = fabs(old_x * old_x - old_y * old_y + c_x);
		new_y = fabs(2 * old_x * old_y + c_y);
		if ((new_x * new_x + new_y * new_y) > 4)
			return (i);
		i = i + 1;
	}
	return (i);
}
