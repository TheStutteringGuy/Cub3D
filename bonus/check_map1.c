/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibn-ich <aibn-ich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:29:25 by aahlaqqa          #+#    #+#             */
/*   Updated: 2025/03/23 21:07:41 by aibn-ich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	calculate_map(t_data *data)
{
	int	i;
	int	j;
	int	max_width;

	i = 0;
	while (data->mini_map[i])
		i++;
	data->map_height = i;
	max_width = 0;
	i = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (data->mini_map[i][j])
			j++;
		if (j > max_width)
			max_width = j;
		i++;
	}
	data->map_width = max_width;
}

void	copy_map_section(char **dest, char **src, int start, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (!src[start + i])
		{
			printf("Error\nInvalid line !!\n");
			exit(1);
		}
		dest[i] = ft_strdup(src[start + i]);
		if (!dest[i])
		{
			printf("Error while allocating memory for new_map!!\n");
			exit(1);
		}
		i++;
	}
	dest[i] = NULL;
}

void	split_map(t_data *data)
{
	int	total_lines;

	total_lines = 0;
	while (data->start_map[total_lines])
		total_lines++;
	data->new_map = malloc(sizeof(char *) * 7);
	if (!data->new_map)
		print_malloc_error_message(data);
	copy_map_section(data->new_map, data->start_map, 0, 6);
	bgc_new(&data, data->new_map, sizeof(data->new_map), TwoD_Array);
	data->mini_map = malloc(sizeof(char *) * (total_lines - 5 + 1));
	if (!data->mini_map)
		print_malloc_error_message(data);
	copy_map_section(data->mini_map, data->start_map, 6, total_lines - 6);
	data->mini_map[total_lines - 6] = NULL;
	bgc_new(&data, data->mini_map, sizeof(data->mini_map), TwoD_Array);
}

void	handle_spaces(t_data *data)
{
	int		i;
	char	*trimmed;
	int		j;

	i = 0;
	while (data->new_map[i])
	{
		j = 0;
		while (data->new_map[i][j] == ' ' || data->new_map[i][j] == '\t')
			j++;
		if (data->new_map[i][j] != '\0')
		{
			trimmed = ft_strdup(&data->new_map[i][j]);
			if (!trimmed)
			{
				printf("Error while allocating memory for trimmed line!\n");
				free_(data);
				exit(1);
			}
			free(data->new_map[i]);
			data->new_map[i] = trimmed;
		}
		i++;
	}
}

void	check_prefix(t_data *data)
{
	int	i;

	i = 0;
	while (data->new_map[i])
	{
		if (data->new_map[i][0] == 'N' && data->new_map[i][1] == 'O')
			data->flag++;
		else if (data->new_map[i][0] == 'S' && data->new_map[i][1] == 'O')
			data->flag++;
		else if (data->new_map[i][0] == 'W' && data->new_map[i][1] == 'E')
			data->flag++;
		else if (data->new_map[i][0] == 'E' && data->new_map[i][1] == 'A')
			data->flag++;
		else if (data->new_map[i][0] == 'F')
			data->flag++;
		else if (data->new_map[i][0] == 'C')
			data->flag++;
		else if (data->new_map[i][0] == 'D')
			data->flag++;
		else
			print_invalid_map_error_message(data);
		i++;
	}
	if (data->flag != 7)
		print_incorrect_prefix_error_message(data);
}
