/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_burn_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 22:29:04 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/03/21 22:29:05 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	*ft_burn(void *param)
{
	double	c_x;
	double	c_y;
	double	new_x;
	double	new_y;
	double	old_x;
	double	old_y;
	double	zoom;
	double	move_x;
	double	move_y;
	int		color;
	int		x;
	int		y;
	int		iter;
	int		i;
	int		check;
	t_mult	*data;

	data = param;
	check = 0;
	iter = data->iter;
	x = data->x0;
	y = data->y0;
	zoom = data->zoom;
	move_x = data->move_x;
	move_y = data->move_y;
	while (y < data->y1)
	{
		while (x < data->x1)
		{
			c_x = (x - 500 + data->ch_zoom_x) / (0.5 * zoom * 1000) + move_x;
			c_y = (y - 500 + data->ch_zoom_y) / (0.5 * zoom * 1000) + move_y;
			new_x = 0;
			new_y = 0;
			old_x = 0;
			old_y = 0;
			i = 0;
			while (i < iter)
			{
				old_y = new_y;
				old_x = new_x;

				new_x = fabs(old_x * old_x - old_y * old_y + c_x);
				new_y = fabs(2 * old_x * old_y + c_y);
				if ((new_x * new_x + new_y * new_y) > 4)
					break ;
				i++;
			}
			color = (i < iter ? ft_make_col(i, data, check) : data->background);
			if (i != iter)
				check = 1;
			data->img_mas[y * WIDTH + x] = color;
			x++;
		}
		x = data->x0;
		y++;
	}
	pthread_exit(0);
}

void	ft_burn_ship(t_mlx *data)
{
	pthread_t		tid[8]; 
	int				i;
	static t_mult	coord[8];	

	i = -1;
	while (++i < 8)
		ft_make_coord(&coord[i], data->img.img_mas, data->coord);
	i = -1;
	while (++i < 8)
		pthread_create(&tid[i], NULL, ft_burn, &coord[i]);
	i = -1;
	while (++i < 8)
		pthread_join(tid[i], NULL);
	mlx_put_image_to_window (data->mlx, data->wnd, data->img.img_ptr, 0, 0);
}