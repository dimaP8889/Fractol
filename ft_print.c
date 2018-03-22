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

#define STR	mlx_string_put
#define W	0xFFFFFF

#include "fractol.h"

static void		ft_instruct(t_mlx *data)
{
	STR(data->mlx, data->wnd, 80, 0, W, "<- colour");
	STR(data->mlx, data->wnd, 80, 20, W, "<- background");
	STR(data->mlx, data->wnd, 0, 40, W, "Move: w s a d");
	STR(data->mlx, data->wnd, 0, 60, W, "Change Fractal: Space");
	STR(data->mlx, data->wnd, 0, 80, W, "Iter +: +");
	STR(data->mlx, data->wnd, 0, 100, W, "Iter -: -");
	STR(data->mlx, data->wnd, 850, 0, W, "Help: left alt");
	STR(data->mlx, data->wnd, 850, 20, W, "Exit: esc");
	STR(data->mlx, data->wnd, 0, 120, W, "Zoom mode: z");
	STR(data->mlx, data->wnd, 0, 140, W, "Narco mode: n");
	STR(data->mlx, data->wnd, 0, 160, W, "Beauty mode: b");
	STR(data->mlx, data->wnd, 0, 180, W, "Narco mode degree +: {");
	STR(data->mlx, data->wnd, 0, 200, W, "Narco mode degree -: }");
	STR(data->mlx, data->wnd, 0, 220, W, "Start pic: c");
	STR(data->mlx, data->wnd, 0, 240, W, "Stop picture: left ctrl");
	STR(data->mlx, data->wnd, 0, 260, W, "Move pix to center: left clk");
	STR(data->mlx, data->wnd, 0, 280, W, "Zoom in: scroll up");
	STR(data->mlx, data->wnd, 0, 300, W, "Zoom in: scroll down");
	STR(data->mlx, data->wnd, 350, 0, W, "Colour r+: r Colour r-: f");
	STR(data->mlx, data->wnd, 350, 20, W, "Colour g+: t Colour g-: g");
	STR(data->mlx, data->wnd, 350, 40, W, "Colour b+: y Colour b-: h");
	STR(data->mlx, data->wnd, 350, 60, W, "Background r+: u Background r-: j");
	STR(data->mlx, data->wnd, 350, 80, W, "Background g+: i Background g-: k");
	STR(data->mlx, data->wnd, 350, 100, W, "Background b+: o Background b-: l");
}

void			ft_print(t_mlx *data)
{
	char				*str;

	str = ft_itoa_base(data->coord.col, 16, 1);
	STR(data->mlx, data->wnd, 0, 0, data->coord.col, str);
	free(str);
	str = ft_itoa_base(data->coord.background, 16, 1);
	STR(data->mlx, data->wnd, 0, 20, W, str);
	free(str);
	if (data->coord.help)
		ft_instruct(data);
}
