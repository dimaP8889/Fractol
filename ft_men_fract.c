/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_men_fract.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 18:39:50 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/03/12 18:39:51 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_make_col(int i)
{
	return(0x000000 + i * i);
}

void	ft_check_key(t_mult *coord, t_mult keys)
{
	coord->zoom = keys.zoom;
	coord->move_x = keys.move_x;
	coord->move_y = keys.move_y;
	coord->iter = keys.iter;
	coord->ch_zoom_y = keys.ch_zoom_y;
	coord->ch_zoom_x = keys.ch_zoom_x;
	printf("zoom_x: %i\n", coord->ch_zoom_x);
	printf("zoom_y: %i\n", coord->ch_zoom_y);
	printf("move_x: %f\n", coord->move_x);
	printf("move_y: %f\n", coord->move_y);
	printf("\n");
}

void	ft_make_coord(t_mult *coord, int *mas, t_mult keys)
{
	static int	i;
	static int	y0;
	static int	y1;
	static int	x0;
	static int	x1;

	if ((i % 10) == 0)
	{
		x0 = 0;
		x1 = 100;
		if (!i)
			y0 = 0;
		else
			y0 += 100;
		y1 += 1000;
	}
	else
	{
		x0 += 100;
		x1 += 100;
	}
	coord->y0 = y0;
	coord->y1 = y1;
	coord->x0 = x0;
	coord->x1 = x1;
	ft_check_key(coord, keys);
	coord->img_mas = mas;
	i++;
	if (i == 10)
	{
		i = 0;
		y0 = 0;
		y1 = 0;
	}
}

void	*ft_men(void *param)
{
	double	c_x;
	double	c_y;
	double	new_x;
	double	new_y;
	double	old_x;
	double	old_y;
	static double	zoom;
	static double	move_x;
	static double	move_y;
	int		color;
	int		x;
	int		y;
	int		iter;
	int		i;
	t_mult	*data;

	data = param;
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
			c_x = (x - 0.5 * 1000 + data->ch_zoom_x) / (0.5 * zoom * 1000) + move_x;
			c_y = (y - 0.5 * 1000 + data->ch_zoom_y) / (0.5 * zoom * 1000) + move_y;
			new_x = 0;
			new_y = 0;
			old_x = 0;
			old_y = 0;
			i = 0;
			while (i < iter)
			{
				old_y = new_y;
				old_x = new_x;

				new_x = old_x * old_x - old_y * old_y + c_x;
				new_y = 2 * old_x * old_y + c_y;
				if ((new_x * new_x + new_y * new_y) > 4)
					break ;
				i++;
			}
			color = (i < iter ? ft_make_col(i) : 0x000000);
			data->img_mas[y * WIDTH + x] = color;
			x++;
		}
		x = data->x0;
		y++;
	}
	pthread_exit(0);
}

void	ft_men_fract(t_mlx *data)
{
	pthread_t		tid[10]; 
	int				i;
	static t_mult	coord[10];	

	i = -1;
	while (++i < 10)
		ft_make_coord(&coord[i], data->img.img_mas, data->coord);
	i = -1;
	while (++i < 10)
		pthread_create(&tid[i], NULL, ft_men, &coord[i]);
	i = -1;
	while (++i < 10)
		pthread_join(tid[i], NULL);
	mlx_put_image_to_window (data->mlx, data->wnd, data->img.img_ptr, 0, 0);
}