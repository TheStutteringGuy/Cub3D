/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibn-ich <aibn-ich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 14:12:11 by aahlaqqa          #+#    #+#             */
/*   Updated: 2025/03/25 03:32:11 by aibn-ich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	draw_minimap(t_data *data)
{
	int	minimap_size;
	int	player_pixel_x;
	int	player_pixel_y;
	int	dir_length;

	minimap_size = 120;
	data->tile_size = 6;
	data->radius = minimap_size / (2 * data->tile_size);
	data->startx = SCREEN_W - minimap_size - 10;
	data->starty = 10;
	draw_map_tiles(data);
	player_pixel_x = data->startx + data->radius * data->tile_size
		+ data->tile_size / 2;
	player_pixel_y = data->starty + data->radius * data->tile_size
		+ data->tile_size / 2;
	draw_player(data, player_pixel_x, player_pixel_y);
	dir_length = 10;
	draw_direction_line(data, player_pixel_x, player_pixel_y, dir_length);
}

void	init_darw_map_tile(t_data *data, int i, int j)
{
	data->mini_map_y = data->start_map_y + j;
	data->draw_x = data->startx + i * data->tile_size;
	data->draw_y = data->starty + j * data->tile_size;
	if (data->mini_map_x >= 0 && data->mini_map_y >= 0
		&& data->mini_map_x < data->map_height
		&& data->mini_map_y < data->map_width)
	{
		handle_mini_map_colors(data);
		data->dx = 0;
		while (data->dx < data->tile_size)
		{
			data->dy = 0;
			while (data->dy < data->tile_size)
			{
				set_pixels(data, data->draw_x + data->dx, data->draw_y
					+ data->dy, data->mini_color);
				data->dy++;
			}
			data->dx++;
		}
	}
}

void	draw_map_tiles(t_data *data)
{
	int	i;
	int	j;

	init_map_tiles_var(data);
	i = 0;
	while (i < data->radius * 2 + 1)
	{
		data->mini_map_x = data->start_map_x + i;
		j = 0;
		while (j < data->radius * 2 + 1)
		{
			init_darw_map_tile(data, i, j);
			j++;
		}
		i++;
	}
}
