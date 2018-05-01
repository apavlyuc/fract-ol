/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlyuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 21:33:21 by apavlyuc          #+#    #+#             */
/*   Updated: 2018/04/01 22:02:00 by apavlyuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <mlx.h>
# include <string.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <math.h>

# define COLOR(R,G,B) (R << 16 | G << 8 | B)

typedef struct			s_data
{
	int					type;
	void				*mlx;
	void				*window;
	void				*image;
	char				*addr;
	int					bpp;
	int					line;
	int					endian;
	int					lendian;
	int					iter;
	double				s;
	int					mx;
	int					my;
	double				sxf;
	double				sxt;
	double				syf;
	double				syt;
}						t_data;

typedef struct			s_tdata
{
	t_data				*d;
	pthread_t			t;
	int					xf;
	int					xt;
}						t_tdata;

int						get_fractal(char *name);
void					print_usage(void);
void					put_pixel(t_data *d, int x, int y, int color);
t_tdata					init_thread(int i, int width, t_data *d);
void					complex_pow_2(double *a, double *b);
void					complex_pow_2_abs(double *a, double *b,
										double e, double f);
int						mandelbrot(t_data *d, double i, double j);
int						julia(t_data *d, double i, double j);
int						burning_ship(t_data *d, double i, double j);
unsigned int			get_color(int max_iter, int iter);
void					*update_part(void *v);
void					new_image(t_data *d);
void					update_window(t_data *d);
int						handle_mouse_move(int x, int y, t_data *d);
int						handle_mouse_press(int b, int x, int y, t_data *d);
int						handle_key_press(int b, t_data *d);
void					init_data(t_data *data);

#endif
