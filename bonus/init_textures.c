/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 02:45:36 by aahlaqqa          #+#    #+#             */
/*   Updated: 2025/03/20 15:48:56 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	init_textures(t_data *data)
{
	if (data->door == 1)
	{
		add_texture_door(data);
		return ;
	}
	if (data->side == 0 && data->raydir_x > 0)
		add_texture_ea(data);
	else if (data->side == 0 && data->raydir_x < 0)
		add_texture_we(data);
	else if (data->side == 1 && data->raydir_y > 0)
		add_texture_so(data);
	else if (data->side == 1 && data->raydir_y < 0)
		add_texture_no(data);
}

void	draw_column(t_data *data, int x)
{
	int	y;

	y = 0;
	while (y < SCREEN_H)
	{
		if (y < data->drawstart)
			set_pixels(data, x, y, data->cell_color);
		else if (y >= data->drawstart && y < data->drawend)
		{
			data->texy = (int)data->texpos % data->tex_height;
			data->texpos += data->step;
			data->p_color = data->r_texture[data->texy * data->tex_width
				+ data->txt_x];
			if (data->side == 1)
				data->p_color = (data->p_color >> 1) & 8355711;
			set_pixels(data, x, y, data->p_color);
		}
		else
			set_pixels(data, x, y, data->floor_color);
		y++;
	}
}
