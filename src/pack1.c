/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pack1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlyuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 21:45:05 by apavlyuc          #+#    #+#             */
/*   Updated: 2018/04/01 22:00:56 by apavlyuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <unistd.h>
#include "../libft/libft.h"

int						get_fractal(char *name)
{
	if (ft_strcmp(name, "Mandelbrot") == 0)
		return (1);
	else if (ft_strcmp(name, "Julia") == 0)
		return (2);
	else if (ft_strcmp(name, "Burning Ship") == 0)
		return (3);
	else
		return (0);
}

void					print_usage(void)
{
	write(1, "usage: ./fractol FRACTAL\n", 25);
}

void					put_pixel(t_data *d, int x, int y, int color)
{
	int					opp;
	int					temp;
	char				*p;

	if (x >= 0 && x < 900 && y >= 0 && y < 900)
	{
		opp = d->bpp / 8;
		temp = opp;
		p = (d->addr + (int)y * d->line);
		while (opp--)
		{
			if (d->endian == d->lendian)
				*(p + x * temp + opp) = ((unsigned char *)(&color))[
					((d->endian) ? (4 - temp + opp) : (opp))];
			else
				*(p + x * temp + opp) = ((unsigned char *)(&color))[
					((d->endian) ? (temp - 1 - opp) : (3 - opp))];
		}
	}
}

t_tdata					init_thread(int i, int width, t_data *d)
{
	t_tdata			t;

	t.d = d;
	t.xf = i * (width / 8);
	t.xt = t.xf + (width / 8);
	return (t);
}

void					complex_pow_2(double *a, double *b)
{
	double				c;
	double				d;

	c = *a * *a - *b * *b;
	d = 2 * *a * *b;
	*a = c;
	*b = d;
}
