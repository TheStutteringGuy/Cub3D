/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibn-ich <aibn-ich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:31:26 by aahlaqqa          #+#    #+#             */
/*   Updated: 2025/03/21 08:25:17 by aibn-ich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	print_malloc_error_message(t_data *data)
{
	printf("Error while allocating memory for new_map!!\n");
	free_(data);
	exit(1);
}

void	print_parsing_error_message(t_data *data)
{
	printf("Error\nInvalid line !!\n");
	free_(data);
	exit(1);
}

void	print_invalid_map_error_message(t_data *data)
{
	printf("Error\n Invalid map !!\n");
	free_(data);
	exit(1);
}

void	print_incorrect_prefix_error_message(t_data *data)
{
	printf("Error\n Incoreect prefix !!\n");
	free_(data);
	exit(1);
}

void	print_incorrect_texture_error_message(t_data *data)
{
	printf("Error\n Incoreect texture !!\n");
	free_(data);
	exit(1);
}
