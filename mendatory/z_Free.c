/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_Free.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 20:28:26 by aibn-ich          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/03/19 06:25:46 by aibn-ich         ###   ########.fr       */
=======
/*   Updated: 2025/03/19 15:58:55 by aahlaqqa         ###   ########.fr       */
>>>>>>> 4b26a7ef74d79063b3d2e19e0fd9347afdc55f42
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	free_img(t_data *data)
{
<<<<<<< HEAD
    bgc_free(data);
    if (data->no_texture_img)
        mlx_destroy_image(data->mlx, data->no_texture_img);
    if (data->so_texture_img)
        mlx_destroy_image(data->mlx, data->so_texture_img);
    if (data->we_texture_img)
        mlx_destroy_image(data->mlx, data->we_texture_img);
    if (data->ea_texture_img)
        mlx_destroy_image(data->mlx, data->ea_texture_img);
    mlx_destroy_image(data->mlx, data->r_img);
    mlx_destroy_window(data->mlx, data->mlx_win);
    mlx_destroy_display(data->mlx);
    free(data->mlx);
    data->mlx = NULL;
}
=======
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
>>>>>>> 4b26a7ef74d79063b3d2e19e0fd9347afdc55f42
