/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_Free.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibn-ich <aibn-ich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 20:28:26 by aibn-ich          #+#    #+#             */
/*   Updated: 2025/03/19 06:25:46 by aibn-ich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void Free_(t_data *data)
{
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