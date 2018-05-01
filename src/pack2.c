/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pack2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlyuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 21:46:01 by apavlyuc          #+#    #+#             */
/*   Updated: 2018/04/01 21:54:38 by apavlyuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void					complex_pow_2_abs(double *a, double *b,
										double e, double f)
{
	double				c;
	double				d;

	c = *a * *a - *b * *b;
	d = 2 * *a * *b;
	*a = fabs(c + e);
	*b = fabs(d + f);
}

int						mandelbrot(t_data *d, double i, double j)
{
	int					n;
	double				z_re;
	double				z_im;
	double				c_re;
	double				c_im;

	z_re = 0;
	z_im = 0;
	c_re = j;
	c_im = i;
	n = 0;
	while (n < d->iter)
	{
		if (z_re * z_re + z_im * z_im > 16)
			break ;
		complex_pow_2(&z_re, &z_im);
		z_re += c_re;
		z_im += c_im;
		n++;
	}
	return (n);
}

int						julia(t_data *d, double i, double j)
{
	int					n;
	double				z_re;
	double				z_im;
	double				c_re;
	double				c_im;

	z_re = j;
	z_im = i;
	c_re = -2.0 + (double)(4 / (double)900 * d->mx);
	c_im = -2.0 + (double)(4 / (double)900 * d->my);
	n = 0;
	while (n < d->iter)
	{
		if (z_re * z_re + z_im * z_im > 16)
			break ;
		complex_pow_2(&z_re, &z_im);
		z_re += c_re;
		z_im += c_im;
		n++;
	}
	return (n);
}

int						burning_ship(t_data *d, double i, double j)
{
	int					n;
	double				z_re;
	double				z_im;
	double				c_re;
	double				c_im;

	z_re = 0;
	z_im = 0;
	c_re = j;
	c_im = i;
	n = 0;
	while (n < d->iter)
	{
		if (z_re * z_re + z_im * z_im > 16)
			break ;
		complex_pow_2_abs(&z_re, &z_im, c_re, c_im);
		n++;
	}
	return (n);
}

unsigned int			get_color(int max_iter, int iter)
{
	if (max_iter == iter)
		iter = iter * 100;
	iter = iter % 255;
	return (COLOR(iter, iter, iter));
}
