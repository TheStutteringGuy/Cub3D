/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_door.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibn-ich <aibn-ich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 03:16:02 by aahlaqqa          #+#    #+#             */
/*   Updated: 2025/03/25 03:18:37 by aibn-ich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	check_for_doors(t_data *data, int i, int j)
{
	if (data->mini_map[i][j] == 'D')
	{
		data->is_left_right = 0;
		data->is_up_down = 0;
		if (j > 0 && data->mini_map[i][j - 1] == '1' && data->mini_map[i][j + 1]
			&& data->mini_map[i][j + 1] == '1')
			data->is_left_right = 1;
		if (i > 0 && data->mini_map[i - 1][j] == '1' && data->mini_map[i + 1]
			&& data->mini_map[i + 1][j] == '1')
			data->is_up_down = 1;
		if (!data->is_left_right && !data->is_up_down)
		{
			printf("Eroor\nDoor should be at least sournded by 2 walls !!\n");
			free_(data);
			exit(1);
		}
	}
}

void	check_valid_door(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->mini_map[i])
	{
		j = 0;
		while (data->mini_map[i][j])
		{
			check_for_doors(data, i, j);
			j++;
		}
		i++;
	}
}
