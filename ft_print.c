/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 23:24:14 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/03/21 23:24:16 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_instruct(t_mlx	*data)
{
	mlx_string_put(data->mlx, data->wnd, 80, 0, 0xFFFFFF, "<- colour");
	mlx_string_put(data->mlx, data->wnd, 80, 20, 0xFFFFFF, "<- background");
	mlx_string_put(data->mlx, data->wnd, 0, 40, 0xFFFFFF, "Move: w s a d");
	mlx_string_put(data->mlx, data->wnd, 0, 60, 0xFFFFFF, "Change Fractal: Space");
	mlx_string_put(data->mlx, data->wnd, 0, 80, 0xFFFFFF, "Iter +: +");
	mlx_string_put(data->mlx, data->wnd, 0, 100, 0xFFFFFF, "Iter -: -");
	mlx_string_put(data->mlx, data->wnd, 850, 0, 0xFFFFFF, "Help: left alt");
	mlx_string_put(data->mlx, data->wnd, 850, 20, 0xFFFFFF, "Exit: esc");
	mlx_string_put(data->mlx, data->wnd, 0, 120, 0xFFFFFF, "Zoom mode: z");
	mlx_string_put(data->mlx, data->wnd, 0, 140, 0xFFFFFF, "Narco mode: n");
	mlx_string_put(data->mlx, data->wnd, 0, 160, 0xFFFFFF, "Beauty mode: b");
	mlx_string_put(data->mlx, data->wnd, 0, 180, 0xFFFFFF, "Narco mode degree +: {");
	mlx_string_put(data->mlx, data->wnd, 0, 200, 0xFFFFFF, "Narco mode degree -: }");
	mlx_string_put(data->mlx, data->wnd, 0, 220, 0xFFFFFF, "Start pic: c");
	mlx_string_put(data->mlx, data->wnd, 0, 240, 0xFFFFFF, "Stop picture: left ctrl");
	mlx_string_put(data->mlx, data->wnd, 0, 260, 0xFFFFFF, "Move pix to center: left clk");
	mlx_string_put(data->mlx, data->wnd, 0, 280, 0xFFFFFF, "Zoom in: scroll up");
	mlx_string_put(data->mlx, data->wnd, 0, 300, 0xFFFFFF, "Zoom in: scroll down");
	mlx_string_put(data->mlx, data->wnd, 350, 0, 0xFFFFFF, "Colour r+: r Colour r-: f");
	mlx_string_put(data->mlx, data->wnd, 350, 20, 0xFFFFFF, "Colour g+: t Colour g-: g");
	mlx_string_put(data->mlx, data->wnd, 350, 40, 0xFFFFFF, "Colour b+: y Colour b-: h");
	mlx_string_put(data->mlx, data->wnd, 350, 60, 0xFFFFFF, "Background r+: u Background r-: j");
	mlx_string_put(data->mlx, data->wnd, 350, 80, 0xFFFFFF, "Background g+: i Background g-: k");
	mlx_string_put(data->mlx, data->wnd, 350, 100, 0xFFFFFF, "Background b+: o Background b-: l");
}

void		ft_print(t_mlx	*data)
{
	char				*str;

	str = ft_itoa_base(data->coord.col, 16, 1);
	mlx_string_put(data->mlx, data->wnd, 0, 0, data->coord.col, str);
	free(str);
	str = ft_itoa_base(data->coord.background, 16, 1);
	mlx_string_put(data->mlx, data->wnd, 0, 20, 0xFFFFFF, str);
	free(str);
	if (data->coord.help)
		ft_instruct(data);
}