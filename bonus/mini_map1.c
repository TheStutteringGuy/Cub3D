/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 00:49:24 by aahlaqqa          #+#    #+#             */
/*   Updated: 2025/03/24 15:20:25 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

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
				set_pixels(data, player_pixel_x + i, player_pixel_y + j,
					0xFF0000);
			j++;
		}
		i++;
	}
}

void	handle_draw_direction_line(t_data *data, int player_pixel_x,
		int player_pixel_y, int dir_length)
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
}

void	draw_direction_line(t_data *data, int player_pixel_x,
		int player_pixel_y, int dir_length)
{
	handle_draw_direction_line(data, player_pixel_x, player_pixel_y,
		dir_length);
	while (1)
	{
		set_pixels(data, data->curr_x, data->curr_y, 0xFF0000);
		if (data->curr_x == data->dir_end_x && data->curr_y == data->dir_end_y)
			break ;
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

void	init_map_tiles_var(t_data *data)
{
	data->player_mapx = (int)data->player_x;
	data->player_mapy = (int)data->player_y;
	data->start_map_x = data->player_mapx - data->radius;
	data->start_map_y = data->player_mapy - data->radius;
}

void	handle_mini_map_colors(t_data *data)
{
	if (data->mini_map[data->mini_map_x][data->mini_map_y] == '1')
		data->mini_color = 0x808080;
	else if (data->mini_map[data->mini_map_x][data->mini_map_y] == 'D')
		data->mini_color = 0x964B00;
	else
		data->mini_color = 0x000000;
}
