/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitriy1 <dmitriy1@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 12:41:04 by dmitriy1          #+#    #+#             */
/*   Updated: 2018/03/19 14:07:23 by dmitriy1         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH	1000
# define HIGHT	1000

# include <math.h>
# include <OpenCL/opencl.h>
# include <pthread.h>
# include <stdlib.h>
# include <fcntl.h>
# include "mlx.h"
# include "libft/includes/libft.h"
# include "libft/includes/get_next_line.h"
# include "libft/ft_printf/ft_printf.h"

typedef	struct	s_im
{
	void		*img_ptr;
	int			*img_mas;
}				t_im;

typedef	struct	s_fract
{
	double		c_x;
	double		c_y;
	double		move_x;
	double		move_y;
	int			x;
	int			y;
	int			i;
	int			check;
	int			color;
}				t_fract;

typedef	struct	s_paral
{
	int			i;
	int			y0;
	int			y1;
	int			x0;
	int			x1;
}				t_paral;

typedef	struct	s_mult
{
	int			x0;
	int			x1;
	int			y0;
	int			y1;
	int			*img_mas;
	double		zoom;
	double		move_x;
	double		move_y;
	int			iter;
	int			ch_zoom_x;
	int			ch_zoom_y;
	int			cent_x;
	int			cent_y;
	int			null;
	int			narko;
	int			degree;
	int			col;
	int			background;
	double		const_x;
	double		const_y;
	int			move;
	int			zoooooom;
	int			catch_x;
	int			catch_y;
	int			beaut;
	int			help;
	int			fractol;
}				t_mult;

typedef struct	s_grad
{
	int			r_start;
	int			g_start;
	int			b_start;
	int			r_to;
	int			g_to;
	int			b_to;
	double		r_delta;
	double		g_delta;
	double		b_delta;
}				t_grad;

typedef struct	s_mlx
{
	void		*mlx;
	void		*wnd;
	int			fractol;
	t_mult		coord;
	t_im		img;
}				t_mlx;

int				ft_catch_key(int keycode, void *param);
void			ft_jul_fract(t_mlx *data);
void			ft_men_fract(t_mlx *data);
int				mouse_zoom(int button, int x, int y, void *param);
int				mouse_motion(int x, int y, void *param);
void			ft_set_data(t_mlx *data, int fractol);
int				ft_make_col(int i, t_mult *data, int check);
int				ft_grad(int start_col, t_mult *data, int check, int i);
void			ft_make_coord(t_mult *coord, int *mas, t_mult keys);
void			ft_check_key(t_mult *coord, t_mult keys);
int				zoooooom(void *param);
void			ft_change_zoom_pos(t_mlx *data, int x, int y);
void			ft_print(t_mlx	*data);
void			ft_find_fract(t_mlx *data);
int				ft_ship_l(int i, t_mult *data, double c_x, double c_y);
int				ft_tricorn_l(int i, t_mult *data, double c_x, double c_y);
int				ft_men_l(int i, t_mult *data, double c_x, double c_y);
int				ft_choose(int i, t_mult *data, double c_x, double c_y);
int				ft_jul_tan_l(int i, t_mult *data, double new_x, double new_y);
int				ft_jul_l(int i, t_mult *data, double new_x, double new_y);
void			ft_colours(int keycode, t_mlx *data);
void			ft_keycode(int keycode, t_mlx *data);
int				ft_exit_x(void *par);
int				ft_jul_third_l(int i, t_mult *data, double new_x, double new_y);
int				ft_jul_some_l(int i, t_mult *data, double new_x, double new_y);

#endif
