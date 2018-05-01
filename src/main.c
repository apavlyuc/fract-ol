/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlyuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 21:51:45 by apavlyuc          #+#    #+#             */
/*   Updated: 2018/04/01 21:57:05 by apavlyuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			main(int ac, char **av)
{
	t_data	data;

	if (ac == 2 && (data.type = get_fractal(av[1])) != 0)
	{
		init_data(&data);
		mlx_hook(data.window, 2, 1L << 0, &handle_key_press, &data);
		mlx_hook(data.window, 4, 1L << 2, &handle_mouse_press, &data);
		mlx_hook(data.window, 6, 1L << 6, &handle_mouse_move, &data);
		update_window(&data);
		mlx_loop(data.mlx);
	}
	print_usage();
	return (0);
}
