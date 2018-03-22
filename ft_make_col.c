/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_col.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 17:40:21 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/03/20 17:40:22 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_change_b(int i)
{
	static int		col;

	col = i;
	col &= 255;
	return (col);
}

int		ft_find_degree(int i, t_mult *data)
{
	int		coun;

	coun = data->degree;
	while (coun > 0)
	{
		i *= i;
		coun--;
	}
	return (i);
}

int		ft_change_g(int i)
{
	static int		col;

	col = i;
	col = i >> 8;
	col &= 255;
	return (col);
}

int		ft_change_r(int i)
{
	static int		col;

	col = i;
	col = i >> 16;
	return (col);
}

int		ft_make_col(int i, t_mult *data, int check)
{
	int		col;
	int		r;
	int		g;
	int		b;

	if (data->narko)
	{
		col = 0;
		r = ft_change_r(ft_find_degree(0xFF0000 - i, data));
		g = ft_change_g(ft_find_degree(0xFF0000 - i, data));
		b = ft_change_b(ft_find_degree(0xFF0000 - i, data));
	}
	else
	{
		col = ft_grad(data->background, data, check, i);
		return (col);
	}
	g <<= 8;
	r <<= 16;
	col = r | g | b;
	return(col);
}