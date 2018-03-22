/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_coord.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 05:53:23 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/03/22 05:53:23 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_set_coord(t_paral *save)
{
	if ((save->i % 8) == 0)
	{
		save->x0 = 0;
		save->x1 = 125;
		if (!save->i)
			save->y0 = 0;
		else
			save->y0 += 125;
		save->y1 += 1000;
	}
	else
	{
		save->x0 += 125;
		save->x1 += 125;
	}
}

void		ft_make_coord(t_mult *coord, int *mas, t_mult keys)
{
	static t_paral	save;

	ft_set_coord(&save);
	coord->y0 = save.y0;
	coord->y1 = save.y1;
	coord->x0 = save.x0;
	coord->x1 = save.x1;
	ft_check_key(coord, keys);
	coord->img_mas = mas;
	save.i++;
	if (save.i == 8)
	{
		save.i = 0;
		save.y0 = 0;
		save.y1 = 0;
	}
}
