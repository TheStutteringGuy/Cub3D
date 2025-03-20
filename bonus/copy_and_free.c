/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_and_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:30:56 by aahlaqqa          #+#    #+#             */
/*   Updated: 2025/03/20 15:42:35 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	copy_and_free_no(t_data *data)
{
	data->no_texture = ft_strdup(data->texture);
	bgc_new(&data, data->no_texture, sizeof(data->no_texture), Simple);
}

void	copy_and_free_we(t_data *data)
{
	data->we_texture = ft_strdup(data->texture);
	bgc_new(&data, data->we_texture, sizeof(data->we_texture), Simple);
}

void	copy_and_free_so(t_data *data)
{
	data->so_texture = ft_strdup(data->texture);
	bgc_new(&data, data->so_texture, sizeof(data->so_texture), Simple);
}

void	copy_and_free_ea(t_data *data)
{
	data->ea_texture = ft_strdup(data->texture);
	bgc_new(&data, data->ea_texture, sizeof(data->ea_texture), Simple);
}

void	copy_and_free_door(t_data *data)
{
	data->door_texture = ft_strdup(data->texture);
	bgc_new(&data, data->ea_texture, sizeof(data->ea_texture), Simple);
}
