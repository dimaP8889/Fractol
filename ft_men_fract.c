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
	return(0x0000FF + i);
}

void	ft_check_key(t_mult *coord, int keycode)
{
	if (!coord->zoom)
		coord->zoom = 0.5;
	if (!coord->move_x)
		coord->move_x = -1.3;
	if (!coord->move_y)
		coord->move_y = 0.1;
	if (!coord->iter)
		coord->iter = 300;
	if (keycode == 116)
		coord->iter += 5;
	if (keycode == 121 && coord->iter > 80)
		coord->iter -= 5;
	if (keycode == 24)
		coord->zoom *= 1.1;
	if (keycode == 27)
		coord->zoom /= 1.1;
	if (keycode == 13)
		coord->move_y -= 0.1 / coord->zoom;
	if (keycode == 1)
		coord->move_y += 0.1 / coord->zoom;
	if (keycode == 0)
		coord->move_x -= 0.1 / coord->zoom;
	if (keycode == 2)
		coord->move_x += 0.1 / coord->zoom;
}

void	ft_make_coord(t_mult *coord,int keycode, int *mas)
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
	ft_check_key(coord, keycode);
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
			color = (i < iter ? ft_make_col(i) : 0x000000);
			data->img_mas[y * WIDTH + x] = color;
			x++;
		}
		x = data->x0;
		y++;
	}
	pthread_exit(0);
}

int			ft_make_line(int keycode, void *structure)
{
	t_mlx			*data;
	pthread_t		tid[10]; 
	int				i;
	static t_mult	coord[10];	

	data = structure;
	i = -1;
	while (++i < 10)
		ft_make_coord(&coord[i], keycode, data->img.img_mas);
	pthread_create(&tid[0], NULL, ft_men, &coord[0]);
	pthread_create(&tid[1], NULL, ft_men, &coord[1]);
	pthread_create(&tid[2], NULL, ft_men, &coord[2]);
	pthread_create(&tid[3], NULL, ft_men, &coord[3]);
	pthread_create(&tid[4], NULL, ft_men, &coord[4]);
	pthread_create(&tid[5], NULL, ft_men, &coord[5]);
	pthread_create(&tid[6], NULL, ft_men, &coord[6]);
	pthread_create(&tid[7], NULL, ft_men, &coord[7]);
	pthread_create(&tid[8], NULL, ft_men, &coord[8]);
	pthread_create(&tid[9], NULL, ft_men, &coord[9]);
	pthread_join(tid[0], NULL);
	pthread_join(tid[1], NULL);
	pthread_join(tid[2], NULL);
	pthread_join(tid[3], NULL);
	pthread_join(tid[4], NULL);
	pthread_join(tid[5], NULL);
	pthread_join(tid[6], NULL);
	pthread_join(tid[7], NULL);
	pthread_join(tid[8], NULL);
	pthread_join(tid[9], NULL);
	// ft_printf("%i\n", coord[9].iter);
	mlx_put_image_to_window (data->mlx, data->wnd, data->img.img_ptr, 0, 0);
	return (0);
}

void	ft_men_fract(t_mlx data)
{
	// pthread_t		tid[4]; 
	// int				i;
	// static t_mul	coord[4];
	// i = -1;

	// while (++i < 4)
	// 	ft_make_coord(coord[i]);
	// pthread_create(&tid[0], NULL, ft_men, &coord[0]);
	// pthread_create(&tid[1], NULL, ft_men, &coord[1]);
	// pthread_create(&tid[2], NULL, ft_men, &coord[2]);
	// pthread_create(&tid[3], NULL, ft_men, &coord[3]);
	mlx_hook(data.wnd, 2, 5, ft_make_line, &data);
		
		// ft_men(&data);
	// mlx_put_image_to_window (data->mlx, data->wnd, data->img.img_ptr, 0, 0);
	// pthread_join(tid, NULL);
}