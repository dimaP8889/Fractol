/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_jul_kube.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 02:49:24 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/03/22 02:49:26 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define Y3	old_y * old_y * old_y
#define X2Y	old_x * old_y * old_y

#include "fractol.h"

int	ft_jul_l(int i, t_mult *data, double new_x, double new_y)
{
	double	old_x;
	double	old_y;

	while (i < data->iter)
	{
		old_y = new_y;
		old_x = new_x;
		new_x = old_x * old_x - old_y * old_y + data->const_x;
		new_y = 2 * old_x * old_y + data->const_y;
		if ((new_x * new_x + new_y * new_y) > 4)
			return (i);
		i++;
	}
	return (i);
}

int	ft_jul_tan_l(int i, t_mult *data, double new_x, double new_y)
{
	double	old_x;
	double	old_y;

	while (i < data->iter)
	{
		old_y = new_y;
		old_x = new_x;
		new_x = tan(old_y * old_y) - tan(old_x * old_x) + data->const_x;
		new_y = -2 * old_x * old_y + data->const_y;
		if ((new_x * new_x + new_y * new_y) > 4)
			return (i);
		i++;
	}
	return (i);
}

int	ft_jul_third_l(int i, t_mult *data, double new_x, double new_y)
{
	double	old_x;
	double	old_y;

	while (i < data->iter)
	{
		old_y = new_y;
		old_x = new_x;
		new_x = old_x * old_x * old_x - 3 * X2Y + data->const_x;
		new_y = 3 * old_x * old_x * old_y - Y3 + data->const_y;
		if ((new_x * new_x + new_y * new_y) > 4)
			return (i);
		i++;
	}
	return (i);
}

int	ft_jul_some_l(int i, t_mult *data, double new_x, double new_y)
{
	double	old_x;
	double	old_y;

	while (i < data->iter)
	{
		old_y = new_y;
		old_x = new_x;
		new_x = old_x * old_x * old_x - 3 * X2Y + old_x + data->const_x;
		new_y = 3 * old_x * old_x * old_y - Y3 + old_y + data->const_y;
		if ((new_x * new_x + new_y * new_y) > 4)
			return (i);
		i++;
	}
	return (i);
}
