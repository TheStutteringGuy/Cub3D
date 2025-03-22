/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibn-ich <aibn-ich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:35:33 by aahlaqqa          #+#    #+#             */
/*   Updated: 2025/03/21 08:25:45 by aibn-ich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	free_texture_one(t_data *data)
{
	printf("Error\n Failed to load South texture: %s\n", data->so_texture);
	free_(data);
	exit(1);
}

void	free_texture_two(t_data *data)
{
	printf("Error\n Failed to load West texture: %s\n", data->we_texture);
	free_(data);
	exit(1);
}

void	free_texture_three(t_data *data)
{
	printf("Error\n Failed to load East texture: %s\n", data->ea_texture);
	free_(data);
	exit(1);
}
