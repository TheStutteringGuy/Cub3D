/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibn-ich <aibn-ich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:49:56 by ahmed             #+#    #+#             */
/*   Updated: 2025/03/24 03:18:24 by aibn-ich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	check_no_identifier(t_data *data)
{
	size_t	i;

	data->count = 0;
	data->prefix = bgc_malloc(&data, 4 + 1, Simple);
	data->texture = bgc_malloc(&data, 256, Array);
	if (!data->texture || !data->prefix)
		return ;
	i = 0;
	iterate_in_map(&i, data);
	if (data->count != 5)
	{
		printf("Error\n incorrect identifier !\n");
		free_(data);
		exit(1);
	}
}

void	check_data(t_data *data)
{
	data->count1 = check_for_colors((data->prefix1), data->count1);
	data->len = check_length_color((data->rest), data->len);
	if (ft_strcmp((data->prefix1), "F") == 0)
		check_floor_rgb((data->rest), data);
	else if (ft_strcmp((data->prefix1), "C") == 0)
		check_cell_rgb((data->rest), data);
	check_rgb_fllor_range(data);
	check_rgb_cell_range(data);
}

void	check_door(t_data *data)
{
	int	i;
	int	j;
	int	d;

	i = 0;
	d = 0;
	while (data->mini_map[i])
	{
		j = 0;
		while (data->mini_map[i][j])
		{
			if (data->mini_map[i][j] == 'D')
				d++;
			j++;
		}
		i++;
	}
	if (d < 1)
	{
		printf("Error\n One Door nedded at least !!\n");
		free_(data);
		exit(1);
	}
}
