/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterate_in_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibn-ich <aibn-ich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:04:31 by aahlaqqa          #+#    #+#             */
/*   Updated: 2025/03/21 08:38:21 by aibn-ich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	allocate_and_copy_prefix(t_data *data, size_t i)
{
	data->j = 0;
	data->prefix = bgc_malloc(&data, sizeof(char) * 3, Simple);
	if (!(data->prefix))
		print_malloc_error_message(data);
	while (data->my_map[i][data->j] != ' ' && data->my_map[i][data->j] != '\0')
	{
		(data->prefix)[data->j] = data->my_map[i][data->j];
		data->j++;
	}
	(data->prefix)[data->j] = '\0';
	if (ft_strcmp(data->prefix, "NO") == 0)
		data->no_count++;
	else if (ft_strcmp(data->prefix, "SO") == 0)
		data->so_count++;
	else if (ft_strcmp(data->prefix, "WE") == 0)
		data->we_count++;
	else if (ft_strcmp(data->prefix, "EA") == 0)
		data->ea_count++;
	if (data->no_count > 1 || data->so_count > 1 || data->we_count > 1
		|| data->ea_count > 1)
	{
		print_incorrect_prefix_error_message(data);
	}
	while (data->my_map[i][data->j] == ' ')
		data->j++;
}

void	allocate_and_copy_texture(t_data *data, size_t i)
{
	size_t	len;
	size_t	end;

	len = ft_strlen(data->my_map[i] + data->j);
	end = len;
	while (end > 0 && (data->my_map[i][data->j + end - 1] == ' '
		|| data->my_map[i][data->j + end - 1] == '\t'))
		end--;
	data->texture = bgc_malloc(&data, end + 1, Array);
	if (!(data->texture))
		print_malloc_error_message(data);
	data->y = 0;
	while (data->y < end)
	{
		(data->texture)[data->y] = data->my_map[i][data->j + data->y];
		data->y++;
	}
	(data->texture)[data->y] = '\0';
	data->j += len;
	if (data->y == 0)
		print_incorrect_texture_error_message(data);
}

void	process_texture_assignment(t_data *data)
{
	data->count = check_for_identifier((data->prefix), data->count);
	check_texture((data->texture), data);
	if (ft_strcmp(data->prefix, "NO") == 0)
	{
		data->no_texture = ft_strdup(data->texture);
		bgc_new(&data, data->no_texture, sizeof(data->no_texture), Simple);
	}
	else if (ft_strcmp(data->prefix, "SO") == 0)
	{
		data->so_texture = ft_strdup(data->texture);
		bgc_new(&data, data->so_texture, sizeof(data->so_texture), Simple);
	}
	else if (ft_strcmp(data->prefix, "WE") == 0)
	{
		data->we_texture = ft_strdup(data->texture);
		bgc_new(&data, data->we_texture, sizeof(data->we_texture), Simple);
	}
	else if (ft_strcmp(data->prefix, "EA") == 0)
	{
		data->ea_texture = ft_strdup(data->texture);
		bgc_new(&data, data->ea_texture, sizeof(data->ea_texture), Simple);
	}
	else
		print_incorrect_prefix_error_message(data);
}

void	iterate_in_map(size_t *i, t_data *data)
{
	while (*i < 4)
	{
		if (!data->my_map[*i] || data->my_map[*i][0] == '\0')
			print_invalid_map_error_message(data);
		allocate_and_copy_prefix(data, *i);
		allocate_and_copy_texture(data, *i);
		process_texture_assignment(data);
		(*i)++;
	}
}
