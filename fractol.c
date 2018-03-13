/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitriy1 <dmitriy1@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 12:40:33 by dmitriy1          #+#    #+#             */
/*   Updated: 2018/03/12 13:08:49 by dmitriy1         ###   ########.fr       */
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
	if (fractol == 1)
		ft_men_fract(data);
	if (fractol == 2)
		ft_jul_fract(data);
	mlx_loop(data.mlx);
}