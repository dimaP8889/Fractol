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
	return(0xFFFF00 & i);
}

void	ft_make_coord(t_mult *coord)
{
	if (!coord->x1)
		coord->x1 = 500;
	if (!coord->y1)
		coord->y1 = 500;
	if (coord->x0 == 0)
		coord->x0 = 500;
	else if (coord->x0 == 500)
		coord->x0 = 0;
	if (coord->x1 == 500)
		coord->x1 = 1000;
	else if (coord->x1 == 1000)
		coord->x1 = 500;
	if (coord->y0 == 0)
		coord->y0 = 500;
	else if (coord->y0 == 500)
		coord->y0 = 0;
	if (coord->y1 == 500)
		coord->y1 = 1000;
	else if (coord->y1 == 1000)
		coord->y1 = 500;
}

void	*ft_men(void	*param)
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
	t_mult	*data;

	data = param;
	iter = 1000;
	x = data->x0;
	y = data->y0;
	zoom = 0.7;
	move_x = -0.5;
	move_y = 1;
	while (y < data->y1)
	{
		while (x < data->x1)
		{
			c_x = (x - 500) / (0.5 * zoom * 1000) + move_x;
			c_y = (y - 500) / (0.5 * zoom * 1000) + move_y;
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
			color = (i < iter ? ft_make_col(i) : 0xFFFFFF);
			data->img.img_mas[y * WIDTH + x] = color;
			// mlx_put_image_to_window (data.mlx, data.wnd, data.img.img_ptr, 0, 0);

			// mlx_pixel_put(data.mlx, data.wnd, x, y, color);
			x++;
		}
		x = 0;
		y++;
	}
	mlx_put_image_to_window (data->mlx, data->wnd, data->img.img_ptr, 0, 0);
	pthread_exit(0);
}

void	ft_men_fract(t_mlx data)
{
	pthread_t		tid[4]; 
	int				i;
	static t_mul	coord[4];
	i = -1;

	while (++i < 4)
		ft_make_coord(coord[i]);
	pthread_create(&tid[0], NULL, ft_men, &coord[0]);
	coord[1].img_mas = coord[0].img_mas;
	pthread_create(&tid[1], NULL, ft_men, &coord[1]);
	pthread_create(&tid[2], NULL, ft_men, &coord[2]);
	pthread_create(&tid[3], NULL, ft_men, &coord[3]);
	mlx_put_image_to_window (data->mlx, data->wnd, data->img.img_ptr, 0, 0);
	pthread_join(tid, NULL);
}