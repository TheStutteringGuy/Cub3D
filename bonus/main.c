/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibn-ich <aibn-ich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 00:33:48 by aahlaqqa          #+#    #+#             */
/*   Updated: 2025/03/22 01:33:12 by aibn-ich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	function_call(t_data *data, t_path *path)
{
	(void)path;
	check_all_in_map(data);
	check_no_identifier(data);
	check_colors(data);
	check_mini_map(data);
}

void	setup_functions(t_data *data)
{
	init_data(data);
	calculate_map(data);
	init_dir_and_plan(data);
	raycasting(data);
	init_mouse(data);
	setup_hook(data);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_path	path;

	ft_memset(&data, 0, sizeof(t_data));
	pars_error(argc);
	check_path(argv[1]);
	read_lines(argv[1], &data);
	function_call(&data, &path);
	data.mlx = mlx_init();
	load_textures(&data);
	get_texture_data(&data);
	data.mlx_win = mlx_new_window(data.mlx, SCREEN_W, SCREEN_H,
			"Cub3D");
	data.r_img = mlx_new_image(data.mlx, SCREEN_W, SCREEN_H);
	data.r_addr = mlx_get_data_addr(data.r_img, &data.bits_per_pixel,
			&data.size_line, &data.endian);
	setup_functions(&data);
	init_door_state(&data);
	mlx_hook(data.mlx_win, 2, (1L << 0), press_key, &data);
	mlx_hook(data.mlx_win, 3, (1L << 1), release_key, &data);
	mlx_hook(data.mlx_win, 6, 1L << 6, handle_mouse_move, &data);
	mlx_hook(data.mlx_win, 17, 0, close_win, &data);
	mlx_loop_hook(data.mlx, game_loop, &data);
	mlx_loop(data.mlx);
	return (0);
}
