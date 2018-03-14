/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitriy1 <dmitriy1@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 12:41:04 by dmitriy1          #+#    #+#             */
/*   Updated: 2018/03/12 12:50:32 by dmitriy1         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#define WIDTH	1000
#define HIGHT	1000

# include <math.h>
# include <pthread.h>
# include <stdlib.h>
# include <fcntl.h>
# include "minilibx/mlx.h"
# include "libft/includes/libft.h"
# include "libft/includes/get_next_line.h"
# include "libft/ft_printf/ft_printf.h"

typedef	struct 		s_men
{
	int				y_cent;
	int				x_cent;
}					t_men;

typedef	struct 		s_im
{
	void			*img_ptr;
	int				*img_mas;
}					t_im;

typedef	struct 		s_mult
{
	int				x0;
	int				x1;
	int				y0;
	int				y1;
	int				*img_mas;
	double			zoom;
	double			move_x;
	double			move_y;
	int				iter;
}					t_mult;

typedef struct		s_mlx
{
	void			*mlx;
	void			*wnd;
	t_im			img;
}					t_mlx;

void	ft_jul_fract(t_mlx data);
void	ft_men_fract(t_mlx data);

#endif
