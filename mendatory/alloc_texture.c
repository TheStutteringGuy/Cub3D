/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 16:03:37 by aahlaqqa          #+#    #+#             */
/*   Updated: 2025/03/22 15:52:20 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	alloc_textures(t_data *data)
{
	data->so_texture = malloc(sizeof(char) * 100);
	data->no_texture = malloc(sizeof(char) * 100);
	data->ea_texture = malloc(sizeof(char) * 100);
	data->we_texture = malloc(sizeof(char) * 100);
}

void	print_free_exit(t_data *data)
{
	printf("Error\nInvalid map !!\n");
	free_(data);
	exit(1);
}
