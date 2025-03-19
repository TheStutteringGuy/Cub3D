/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_Free.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 20:28:26 by aibn-ich          #+#    #+#             */
/*   Updated: 2025/03/19 15:58:55 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	free_img(t_data *data)
{
	if (data->no_texture_img)
		mlx_destroy_image(data->mlx, data->no_texture_img);
	if (data->so_texture_img)
		mlx_destroy_image(data->mlx, data->so_texture_img);
	if (data->we_texture_img)
		mlx_destroy_image(data->mlx, data->we_texture_img);
	if (data->ea_texture_img)
		mlx_destroy_image(data->mlx, data->ea_texture_img);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	data->mlx = NULL;
}
