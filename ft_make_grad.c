/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_grad.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 17:42:18 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/03/20 17:42:19 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		ft_fin_col(int b_start, int r_start, int g_start)
{
	int ret;

	g_start <<= 8;
	r_start <<= 16;
	ret = r_start | g_start | b_start;
	return (ret);
}

static t_grad	ft_find_delta(int fin_col, int mov, int start_col)
{
	static t_grad	grad;
	double			r_d;
	double			g_d;
	double			b_d;

	grad.b_to = (fin_col) & 255;
	grad.g_to = (fin_col) >> 8;
	grad.g_to &= 255;
	grad.r_to = (fin_col) >> 16;
	grad.b_start = start_col & 255;
	grad.g_start = start_col >> 8;
	grad.g_start = grad.g_start & 255;
	grad.r_start = start_col >> 16;
	r_d = ((double)grad.r_to - (double)grad.r_start);
	g_d = ((double)grad.g_to - (double)grad.g_start);
	b_d = ((double)grad.b_to - (double)grad.b_start);
	grad.r_delta = r_d / (double)mov;
	grad.g_delta = g_d / (double)mov;
	grad.b_delta = b_d / (double)mov;
	return (grad);
}

int				ft_grad(int start_col, t_mult *data, int check, int i)
{
	static t_grad		grad;
	double				r;
	double				g;
	double				b;

	if (!check)
		grad = ft_find_delta(data->col, data->iter, start_col);
	if (!data->beaut)
	{
		b = i * fabs(grad.b_delta);
		r = i * fabs(grad.r_delta);
		g = i * fabs(grad.g_delta);
		return (ft_fin_col((int)(b), (int)r, (int)g));
	}
	b = grad.b_start + i * grad.b_delta;
	r = grad.r_start + i * grad.r_delta;
	g = grad.g_start + i * grad.g_delta;
	return (ft_fin_col((int)(b), (int)r, (int)g));
}
