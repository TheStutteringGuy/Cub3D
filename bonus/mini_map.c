/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 14:12:11 by aahlaqqa          #+#    #+#             */
/*   Updated: 2025/03/23 23:27:32 by aahlaqqa         ###   ########.fr       */
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
	draw_background(data, minimap_size);
	draw_map_tiles(data);
	player_pixel_x = data->startx + data->radius * data->tile_size + data->tile_size / 2;
	player_pixel_y = data->starty + data->radius * data->tile_size + data->tile_size / 2;
	draw_player(data, player_pixel_x, player_pixel_y);
	dir_length = 10;
	draw_direction_line(data, player_pixel_x, player_pixel_y, dir_length);
}

void	draw_background(t_data *data, int minimap_size)
{
	int	i;
	int	j;

	i = 0;
	while (i < minimap_size + 4)
	{
		j = 0;
		while (j < minimap_size + 4)
		{
			set_pixels(data, data->startx - 2 + i, data->starty - 2 + j, 0x333333);
			j++;
		}
		i++;
	}
}

void	draw_map_tiles(t_data *data)
{
	int	i;
	int	j;
	int	map_x;
	int	map_y;
	int	draw_x;
	int	draw_y;
	int	dx;
	int	dy;
	int	color;
	int	player_map_x;
	int	player_map_y;
	int	start_map_x;
	int	start_map_y;
	
	player_map_x = (int)data->player_x;
	player_map_y = (int)data->player_y;
	start_map_x = player_map_x - data->radius;
	start_map_y = player_map_y - data->radius;
	i = 0;
	while (i < data->radius * 2 + 1)
	{
		map_x = start_map_x + i;
		j = 0;
		while (j < data->radius * 2 + 1)
		{
			map_y = start_map_y + j;
			draw_x = data->startx + i * data->tile_size;
			draw_y = data->starty + j * data->tile_size;
			if (map_x >= 0 && map_y >= 0 && map_x < data->map_height && map_y < data->map_width)
			{
				if (data->mini_map[map_x][map_y] == '1')
					color = 0x808080;
				else if (data->mini_map[map_x][map_y] == 'D')
					color = 0x964B00;
				else
					color = 0x000000;
				dx = 0;
				while (dx < data->tile_size)
				{
					dy = 0;
					while (dy < data->tile_size)
					{
						set_pixels(data, draw_x + dx, draw_y + dy, color);
						dy++;
					}
					dx++;
				}
			}
			j++;
		}
		i++;
	}
}

void	draw_player(t_data *data, int player_pixel_x, int player_pixel_y)
{
	int	i;
	int	j;
	
	i = -2;
	while (i <= 2)
	{
		j = -2;
		while (j <= 2)
		{
			if (i * i + j * j <= 4)
				set_pixels(data, player_pixel_x + i, player_pixel_y + j, 0xFF0000);
			j++;
		}
		i++;
	}
}

void draw_direction_line(t_data *data, int player_pixel_x, int player_pixel_y, int dir_length)
{
	int	dir_end_x;
	int	dir_end_y;
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;
	int	curr_x;
	int	curr_y;
	
	dir_end_x = player_pixel_x + (int)(dir_length * data->dir_x);
	dir_end_y = player_pixel_y + (int)(dir_length * data->dir_y);
	dx = abs(dir_end_x - player_pixel_x);
	dy = abs(dir_end_y - player_pixel_y);
	if (player_pixel_x < dir_end_x)
		sx = 1;
	else
		sx = -1;
	
	if (player_pixel_y < dir_end_y)
		sy = 1;
	else
		sy = -1;
	err = dx - dy;
	curr_x = player_pixel_x;
	curr_y = player_pixel_y;
	while (1)
	{
		set_pixels(data, curr_x, curr_y, 0xFF0000);
		if (curr_x == dir_end_x && curr_y == dir_end_y)
			break;
		e2 = 2 * err;
		if (e2 > -dy)
		{
			err -= dy;
			curr_x += sx;
		}
		if (e2 < dx)
		{
			err += dx;
			curr_y += sy;
		}
	}
}
