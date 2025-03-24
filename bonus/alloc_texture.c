/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 16:03:37 by aahlaqqa          #+#    #+#             */
/*   Updated: 2025/03/24 21:41:00 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	alloc_textures(t_data *data)
{
	data->so_texture = malloc(sizeof(char) * 100);
	data->no_texture = malloc(sizeof(char) * 100);
	data->ea_texture = malloc(sizeof(char) * 100);
	data->we_texture = malloc(sizeof(char) * 100);
	data->door_texture = malloc(sizeof(char) * 100);
}

void	check_flags(t_data *data)
{
	if (data->flag != 7)
		print_incorrect_prefix_error_message(data);
}
