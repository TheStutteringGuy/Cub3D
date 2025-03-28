/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_wall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibn-ich <aibn-ich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 02:52:51 by aahlaqqa          #+#    #+#             */
/*   Updated: 2025/03/19 02:24:43 by aibn-ich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	calculate_wall(t_data *data)
{
	if (data->side == 0)
		data->perpwalldist = (data->sidedistx - data->deltadistx);
	else
		data->perpwalldist = (data->sidedisty - data->deltadisty);
	if (data->perpwalldist < 0.05)
		data->perpwalldist = 0.05;
	data->line_height = (int)(SCREEN_H / data->perpwalldist);
	if (data->line_height > SCREEN_H * 10)
		data->line_height = SCREEN_H * 10;
	data->drawstart = -data->line_height / 2 + SCREEN_H / 2;
	if (data->drawstart < 0)
		data->drawstart = 0;
	data->drawend = data->line_height / 2 + SCREEN_H / 2;
	if (data->drawend >= SCREEN_H)
		data->drawend = SCREEN_H;
	if (data->side == 0)
		data->wallx = data->player_y + data->perpwalldist * data->raydir_y;
	else
		data->wallx = data->player_x + data->perpwalldist * data->raydir_x;
	data->wallx -= floor(data->wallx);
	data->txt_x = (int)(data->wallx * (double)data->tex_width);
	if (data->side == 0 && data->raydir_x > 0)
		data->txt_x = data->tex_width - data->txt_x - 1;
	if (data->side == 1 && data->raydir_y < 0)
		data->txt_x = data->tex_width - data->txt_x - 1;
}
