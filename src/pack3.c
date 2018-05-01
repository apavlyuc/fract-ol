/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pack3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlyuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 21:46:39 by apavlyuc          #+#    #+#             */
/*   Updated: 2018/04/01 21:54:51 by apavlyuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void					*update_part(void *v)
{
	t_tdata				*t;
	int					i;
	int					j;
	int					iter;

	t = (t_tdata*)v;
	i = -1;
	while ((j = t->xf) == t->xf && ++i < 900)
	{
		while (j < t->xt)
		{
			if (t->d->type == 1)
				iter = mandelbrot(t->d, (t->d->syf + t->d->s * (double)i),
								(t->d->sxf + t->d->s * (double)j));
			else if (t->d->type == 2)
				iter = julia(t->d, (t->d->syf + t->d->s * (double)i),
								(t->d->sxf + t->d->s * (double)j));
			else if (t->d->type == 3)
				iter = burning_ship(t->d, (t->d->syf + t->d->s * (double)i),
									(t->d->sxf + t->d->s * (double)j));
			put_pixel(t->d, j, i, get_color(t->d->iter, iter));
			j++;
		}
	}
	return (NULL);
}

void					new_image(t_data *d)
{
	if (d->mlx && d->image)
		mlx_destroy_image(d->mlx, d->image);
	d->image = mlx_new_image(d->mlx, 900, 900);
	d->addr = mlx_get_data_addr(d->image, &d->bpp, &d->line,
								&d->endian);
	d->lendian = 0x11223344;
	d->lendian = (((unsigned char*)&d->lendian)[0] == 0x11) ? (1) : (0);
}

void					update_window(t_data *d)
{
	t_tdata				t[8];
	int					i;

	i = 0;
	d->s = (double)(d->sxt - d->sxf) / 900;
	while (i < 8)
	{
		t[i] = init_thread(i, 900, d);
		pthread_create(&(t[i].t), NULL, &update_part, &(t[i]));
		i++;
	}
	i = 0;
	while (i < 8)
		pthread_join(t[i++].t, NULL);
	mlx_put_image_to_window(d->mlx, d->window, d->image, 0, 0);
	new_image(d);
}

int						handle_mouse_move(int x, int y, t_data *d)
{
	if (x >= 0 && x < 900 && y >= 0 && y < 900)
	{
		d->mx = x;
		d->my = y;
		if (d->type == 2)
			update_window(d);
	}
	return (0);
}

int						handle_mouse_press(int b, int x, int y, t_data *d)
{
	double				c;

	if (x >= 0 && x < 900 && y >= 0 && y < 900)
	{
		if (b == 4 || b == 5)
		{
			c = (b == 4 ? 1.0 / 1.05 : 1.05);
			d->sxf *= c;
			d->sxt *= c;
			d->syf *= c;
			d->syt *= c;
			update_window(d);
		}
	}
	return (0);
}
