/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibn-ich <aibn-ich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:43:15 by aahlaqqa          #+#    #+#             */
/*   Updated: 2025/03/21 08:22:14 by aibn-ich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	texture_east_error_message(t_data *data)
{
	printf("Error\n Failed to get data address for East texture.\n");
	free_(data);
	exit(1);
}

void	texture_west_error_message(t_data *data)
{
	printf("Error\n Failed to get data address for West texture.\n");
	free_(data);
	exit(1);
}

void	texture_south_error_message(t_data *data)
{
	printf("Error\n Failed to get data address for South texture.\n");
	free_(data);
	exit(1);
}

void	texture_north_error_message(t_data *data)
{
	printf("Error\n Failed to get data address for North texture.\n");
	free_(data);
	exit(1);
}

void	texture_door_error_message(t_data *data)
{
	printf("Error\n Failed to get data addres for Door texture.\n");
	free_(data);
	exit(1);
}
