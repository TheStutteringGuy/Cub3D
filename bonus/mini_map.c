/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 14:12:11 by aahlaqqa          #+#    #+#             */
/*   Updated: 2025/03/24 00:25:54 by aahlaqqa         ###   ########.fr       */
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
	
	data->player_mapx = (int)data->player_x;
	data->player_mapy = (int)data->player_y;
	data->start_map_x = data->player_mapx - data->radius;
	data->start_map_y = data->player_mapy - data->radius;
	i = 0;
	while (i < data->radius * 2 + 1)
	{
		data->mini_map_x = data->start_map_x + i;
		j = 0;
		while (j < data->radius * 2 + 1)
		{
			data->mini_map_y = data->start_map_y + j;
			data->draw_x = data->startx + i * data->tile_size;
			data->draw_y = data->starty + j * data->tile_size;
			if (data->mini_map_x >= 0 && data->mini_map_y  >= 0 && data->mini_map_x < data->map_height && data->mini_map_y  < data->map_width)
			{
				if (data->mini_map[data->mini_map_x][data->mini_map_y ] == '1')
					data->mini_color = 0x808080;
				else if (data->mini_map[data->mini_map_x][data->mini_map_y ] == 'D')
					data->mini_color = 0x964B00;
				else
					data->mini_color = 0x000000;
				data->dx = 0;
				while (data->dx < data->tile_size)
				{
					data->dy = 0;
					while (data->dy < data->tile_size)
					{
						set_pixels(data, data->draw_x + data->dx, data->draw_y + data->dy, data->mini_color);
						data->dy++;
					}
					data->dx++;
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
	data->dir_end_x = player_pixel_x + (int)(dir_length * data->dir_x);
	data->dir_end_y = player_pixel_y + (int)(dir_length * data->dir_y);
	data->dx1 = abs(data->dir_end_x - player_pixel_x);
	data->dy1 = abs(data->dir_end_y - player_pixel_y);
	if (player_pixel_x < data->dir_end_x)
		data->sx = 1;
	else
		data->sx = -1;
	if (player_pixel_y < data->dir_end_y)
		data->sy = 1;
	else
		data->sy = -1;
	data->err = data->dx1 - data->dy1;
	data->curr_x = player_pixel_x;
	data->curr_y = player_pixel_y;
	while (1)
	{
		set_pixels(data, data->curr_x, data->curr_y, 0xFF0000);
		if (data->curr_x == data->dir_end_x && data->curr_y == data->dir_end_y)
			break;
		data->e2 = 2 * data->err;
		if (data->e2 > -data->dy1)
		{
			data->err -= data->dy1;
			data->curr_x += data->sx;
		}
		if (data->e2 < data->dx1)
		{
			data->err += data->dx1;
			data->curr_y += data->sy;
		}
	}
}
