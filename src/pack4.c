/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pack4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlyuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 21:47:11 by apavlyuc          #+#    #+#             */
/*   Updated: 2018/04/01 22:05:57 by apavlyuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int						handle_key_press(int b, t_data *d)
{
	if (b == 53)
	{
		mlx_destroy_window(d->mlx, d->window);
		exit(0);
	}
	else if (b == 69 || b == 78)
	{
		d->iter += (b == 69) ? 1 : -1;
		update_window(d);
	}
	return (0);
}

void					init_data(t_data *data)
{
	data->mlx = mlx_init();
	data->window = mlx_new_window(data->mlx, 900, 900, "Fractol");
	data->iter = 100;
	data->image = NULL;
	new_image(data);
	data->mx = 0;
	data->my = 0;
	data->sxf = -2;
	data->sxt = 2;
	data->syf = -2;
	data->syt = 2;
}
