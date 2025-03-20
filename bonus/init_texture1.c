/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:44:18 by aahlaqqa          #+#    #+#             */
/*   Updated: 2025/03/20 15:50:43 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	add_texture_door(t_data *data)
{
	data->r_texture = data->d_texture_data;
	data->tex_width = data->d_tex_width;
	data->tex_height = data->d_tex_height;
}

void	add_texture_ea(t_data *data)
{
	data->r_texture = data->ea_texture_data;
	data->tex_width = data->ea_tex_width;
	data->tex_height = data->ea_tex_height;
}

void	add_texture_we(t_data *data)
{
	data->r_texture = data->we_texture_data;
	data->tex_width = data->we_tex_width;
	data->tex_height = data->we_tex_height;
}

void	add_texture_so(t_data *data)
{
	data->r_texture = data->so_texture_data;
	data->tex_width = data->so_tex_width;
	data->tex_height = data->so_tex_height;
}

void	add_texture_no(t_data *data)
{
	data->r_texture = data->no_texture_data;
	data->tex_width = data->no_tex_width;
	data->tex_height = data->no_tex_height;
}
