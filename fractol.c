/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitriy1 <dmitriy1@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 12:40:33 by dmitriy1          #+#    #+#             */
/*   Updated: 2018/03/19 14:07:34 by dmitriy1         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define IMG		data->img

#include "fractol.h"

void	ft_print_fract(void)
{
	ft_printf("men\n");
	ft_printf("jul\n");
	ft_printf("ship\n");
	ft_printf("tricorn\n");
	ft_printf("jul_kube\n");
	exit (1);
}

int		ft_find_type(char *fract)
{
	if (!ft_strcmp(fract, "men"))
		return (1);
	if (!ft_strcmp(fract, "jul"))
		return (2);
	if (!ft_strcmp(fract, "ship"))
		return (3);
	if (!ft_strcmp(fract, "tricorn"))
		return (4);
	if (!ft_strcmp(fract, "jul_kube"))
		return (5);
	return (0);
}

void	ft_init_image(t_mlx *data)
{
	int		bpp;
	int		ln_s;
	int		endian;

	IMG.img_ptr = mlx_new_image(data->mlx, WIDTH, HIGHT);
	IMG.img_mas = (int *)mlx_get_data_addr(IMG.img_ptr, &(bpp), &(ln_s),
	&(endian));
}

void	ft_set_data(t_mlx *data, int fractol)
{
	static int	check;

	data->coord.zoom = 0.5;
	if (fractol == 1 || fractol == 3)
		data->coord.move_x = -0.5;
	else
		data->coord.move_x = 0;
	if (fractol == 3)
		data->coord.move_y = -0.5;
	else
		data->coord.move_y = 0;
	data->coord.iter = 100;
	data->coord.ch_zoom_x = 0;
	data->coord.ch_zoom_y = 0;
	data->coord.cent_x = 500;
	data->coord.cent_y = 500;
	data->coord.narko = 0;
	data->coord.degree = 1;
	data->coord.const_x = -0.7;
	data->coord.const_y = 0.25;
	data->coord.col = 0xFFFFFF;
	data->coord.background = 0x000000;
	data->coord.move = 1;
	data->coord.zoooooom = 1;
	data->coord.catch_y = 500;
	data->coord.catch_x = 500;
	data->coord.beaut = 1;
	if (!check)
		data->coord.help = 1;
	check = 1;
	data->fractol = fractol;
}

void	ft_find_fract(t_mlx *data)
{
	if (data->fractol == 1)
		ft_men_fract(data);
	if (data->fractol == 2)
		ft_jul_fract(data);
	if (data->fractol == 3)
		ft_burn_ship(data);
	if (data->fractol == 4)
		ft_tricorn_fract(data);
	if (data->fractol == 5)
		ft_jul_kube(data);
}

void	ft_first_pic(t_mlx *data)
{
	mlx_clear_window(data->mlx, data->wnd);
	ft_find_fract(data);
	ft_print(data);
}

int		main(int ac, char **av)
{
	int				fractol;
	static t_mlx	data;
	static int		check;

	data.mlx = mlx_init();
	data.wnd = mlx_new_window(data.mlx, 1000, 1000, "mlx 42");
	ft_init_image(&data);
	if (ac != 2)
		ft_print_fract();
	fractol = ft_find_type(av[1]);
	if (!fractol)
		ft_print_fract();
	if (!check++)
		ft_set_data(&data, fractol);
	ft_first_pic(&data);
	mlx_hook(data.wnd, 2, 5, ft_catch_key, &data);
	mlx_hook(data.wnd, 4, 0, mouse_zoom, &data);
	mlx_loop_hook(data.mlx, zoooooom, &data);
	mlx_hook(data.wnd, 6, 0, mouse_motion, &data);
	mlx_loop(data.mlx);
}