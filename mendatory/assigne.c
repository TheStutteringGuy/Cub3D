/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assigne.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibn-ich <aibn-ich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:41:52 by aahlaqqa          #+#    #+#             */
/*   Updated: 2025/03/24 00:04:35 by aibn-ich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	assigne_colors(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	data->my_color = malloc(sizeof(char *) * 3);
	if (!data->my_color)
	{
		printf("Error while allocating memory !!\n");
		free_(data);
		exit(1);
	}
	while (data->new_map[i])
	{
		if (data->new_map[i][0] == 'F' || data->new_map[i][0] == 'C')
		{
			data->my_color[j] = ft_strdup(data->new_map[i]);
			if (!data->my_color[j])
				print_malloc_error_message(data);
			j++;
		}
		i++;
	}
	data->my_color[j] = NULL;
	bgc_new(&data, data->my_color, sizeof(data->my_color), TwoD_Array);
}

void	assigne_texture(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	data->my_map = malloc(sizeof(char *) * 5);
	if (!data->my_map)
		print_malloc_error_message(data);
	while (data->new_map[i])
	{
		if ((data->new_map[i][0] == 'N' && data->new_map[i][1] == 'O')
			|| (data->new_map[i][0] == 'S' && data->new_map[i][1] == 'O')
			|| (data->new_map[i][0] == 'E' && data->new_map[i][1] == 'A')
			|| (data->new_map[i][0] == 'W' && data->new_map[i][1] == 'E'))
		{
			data->my_map[j] = ft_strdup(data->new_map[i]);
			if (!data->my_map[j])
				print_malloc_error_message(data);
			j++;
		}
		i++;
	}
	data->my_map[j] = NULL;
	bgc_new(&data, data->my_map, sizeof(data->my_map), TwoD_Array);
}
