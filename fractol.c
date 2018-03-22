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

static void	ft_print_fract(void)
{
	ft_printf("men\n");
	ft_printf("jul\n");
	ft_printf("ship\n");
	ft_printf("tricorn\n");
	ft_printf("jul_tan\n");
	ft_printf("jul_third\n");
	ft_printf("jul_some\n");
	exit(1);
}

static int	ft_find_type(char *fract)
{
	if (!ft_strcmp(fract, "men"))
		return (1);
	if (!ft_strcmp(fract, "jul"))
		return (2);
	if (!ft_strcmp(fract, "ship"))
		return (3);
	if (!ft_strcmp(fract, "tricorn"))
		return (4);
	if (!ft_strcmp(fract, "jul_tan"))
		return (5);
	if (!ft_strcmp(fract, "jul_third"))
		return (6);
	if (!ft_strcmp(fract, "jul_some"))
		return (7);
	return (0);
}

static void	ft_init_image(t_mlx *data)
{
	int		bpp;
	int		ln_s;
	int		endian;

	IMG.img_ptr = mlx_new_image(data->mlx, WIDTH, HIGHT);
	IMG.img_mas = (int *)mlx_get_data_addr(IMG.img_ptr, &(bpp), &(ln_s),
	&(endian));
}

static void	ft_first_pic(t_mlx *data)
{
	mlx_clear_window(data->mlx, data->wnd);
	ft_find_fract(data);
	ft_print(data);
}

int			main(int ac, char **av)
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
	mlx_hook(data.wnd, 17, 1L << 17, ft_exit_x, &data);
	mlx_loop(data.mlx);
}
