/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_borders.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibn-ich <aibn-ich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 00:00:08 by aahlaqqa          #+#    #+#             */
/*   Updated: 2025/03/24 00:20:44 by aibn-ich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	check_top_borders(t_data *data)
{
	int	x;

	x = 0;
	while (data->mini_map[0][x])
	{
		if (data->mini_map[0][x] != '1' && data->mini_map[0][x] != 32
			&& data->mini_map[0][x] != '\t')
		{
			printf("Error\nNo border !\n");
			free_(data);
			exit(1);
		}
		x++;
	}
}

void	check_bottom_border(t_data *data)
{
	int	j;
	int	x;

	j = 0;
	while (data->mini_map[j])
		j++;
	x = 0;
	while (data->mini_map[j - 1][x])
	{
		if (data->mini_map[j - 1][x] != '1' && data->mini_map[j - 1][x] != 32
			&& data->mini_map[j - 1][x] != '\t')
		{
			printf("Error\nNo border !\n");
			free_(data);
			exit(1);
		}
		x++;
	}
}

void	check_right_border(t_data *data)
{
	int	len;
	int	j;

	len = 0;
	j = 0;
	while (data->mini_map[j])
	{
		len = ft_strlen(data->mini_map[j]);
		while (len > 0 && (data->mini_map[j][len - 1] == 32
			|| data->mini_map[j][len - 1] == '\t'))
			len--;
		if (len > 0 && data->mini_map[j][len - 1] != '1')
		{
			printf("Error\nNo border !\n");
			free_(data);
			exit(1);
		}
		j++;
	}
}

void	check_left_border(t_data *data)
{
	int	j;

	j = 0;
	while (data->mini_map[j])
	{
		if (data->mini_map[j][0] != '1' && data->mini_map[j][0] != 32
			&& data->mini_map[j][0] != '\t')
		{
			printf("Error\nNo border !\n");
			free_(data);
			exit(1);
		}
		j++;
	}
}

void	check_around_space(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->mini_map[++i])
	{
		j = 0;
		while (data->mini_map[i][j])
		{
			if (data->mini_map[i][j] == ' ')
			{
				if ((j > 0 && data->mini_map[i][j - 1] == '0')
					|| (data->mini_map[i][j + 1] && data->mini_map[i][j
						+ 1] == '0') || (i > 0 && data->mini_map[i
						- 1][j] == '0') || (data->mini_map[i + 1]
						&& data->mini_map[i + 1][j] == '0'))
				{
					printf("Error\nInvalid map :D !!\n");
					free_(data);
					exit(1);
				}
			}
			j++;
		}
	}
}
