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

#include "fractol.h"

void	ft_print_fract(void)
{
	ft_printf("men\n");
	ft_printf("jul\n");
}

int		ft_find_fract(char *fract)
{
	if (!ft_strcmp(fract, "men"))
		return (1);
	if (!ft_strcmp(fract, "jul"))
		return (2);
	return (0);
}

int		main(int ac, char **av)
{
	int		fractol;

	fractol = ft_find_fract(av[1]);
	if (ac != 2 || !fractol)
		ft_print_fract();
	if (fractol == 1)
		ft_men_fract();
	if (fractol == 2)
		ft_jul_fract();
}