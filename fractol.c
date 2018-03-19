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
	exit (1);
}

int		ft_find_fract(char *fract)
{
	if (!ft_strcmp(fract, "men"))
		return (1);
	if (!ft_strcmp(fract, "jul"))
		return (2);
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

void	ft_set_data(t_mlx *data)
{
	data->coord.zoom = 0.5;
	data->coord.move_x = -0.5;
	data->coord.move_y = 0;
	data->coord.iter = 100;
	data->coord.ch_zoom_x = 0;
	data->coord.ch_zoom_y = 0;
	data->coord.cent_x = 500;
	data->coord.cent_y = 500;
}

int		main(int ac, char **av)
{
	int				fractol;
	static t_mlx	data;

	data.mlx = mlx_init();
	data.wnd = mlx_new_window(data.mlx, 1000, 1000, "mlx 42");
	ft_init_image(&data);
	if (ac != 2)
		ft_print_fract();
	fractol = ft_find_fract(av[1]);
	if (!fractol)
		ft_print_fract();
	data.fractol = fractol;
	ft_set_data(&data);
	mlx_hook(data.wnd, 2, 5, ft_catch_key, &data);
	mlx_hook(data.wnd, 4, 0, mouse_zoom, &data);
	mlx_loop(data.mlx);
}