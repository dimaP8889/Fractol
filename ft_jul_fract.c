/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_jul_fract.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 18:40:22 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/03/12 18:40:24 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define ZM	(0.5 * data->zoom * 1000)
#define COL	ft_make_col(f.i, data, f.check)

#include "fractol.h"

static void	*ft_jul(void *param)
{
	t_fract	f;
	t_mult	*data;

	data = param;
	f.check = 0;
	f.x = data->x0 - 1;
	f.y = data->y0 - 1;
	f.move_x = data->move_x;
	f.move_y = data->move_y;
	while (++f.y < data->y1)
	{
		while (++f.x < data->x1)
		{
			f.i = 0;
			f.c_x = (f.x - 500 + data->ch_zoom_x) / ZM + f.move_x;
			f.c_y = (f.y - 500 + data->ch_zoom_y) / ZM + f.move_y;
			f.i = ft_choose(f.i, data, f.c_x, f.c_y);
			f.color = (f.i < data->iter ? COL : data->background);
			if (f.i != data->iter)
				f.check = 1;
			data->img_mas[f.y * WIDTH + f.x] = f.color;
		}
		f.x = data->x0 - 1;
	}
	pthread_exit(0);
}

void		ft_jul_fract(t_mlx *data)
{
	pthread_t		tid[8];
	int				i;
	static t_mult	coord[8];

	i = -1;
	while (++i < 8)
		ft_make_coord(&coord[i], data->img.img_mas, data->coord);
	i = -1;
	while (++i < 8)
		pthread_create(&tid[i], NULL, ft_jul, &coord[i]);
	i = -1;
	while (++i < 8)
		pthread_join(tid[i], NULL);
	mlx_put_image_to_window(data->mlx, data->wnd, data->img.img_ptr, 0, 0);
}
