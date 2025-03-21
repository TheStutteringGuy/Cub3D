/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_identifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibn-ich <aibn-ich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:24:59 by aahlaqqa          #+#    #+#             */
/*   Updated: 2025/03/21 08:11:14 by aibn-ich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	check_for_identifier(char *str, int i)
{
	if (ft_strcmp(str, "NO") == 0 || ft_strcmp(str, "SO") == 0 || ft_strcmp(str,
			"WE") == 0 || ft_strcmp(str, "EA") == 0 || ft_strcmp(str, "D") == 0)
		i++;
	return (i);
}

int	check_for_colors(char *str, int i)
{
	if (ft_strcmp(str, "F") == 0 || ft_strcmp(str, "C") == 0)
		i++;
	return (i);
}

int	check_length_color(char *str, int i)
{
	int	j;

	j = 0;
	while (str[j] != '\0')
	{
		if (str[j] == ',')
			i++;
		j++;
	}
	return (i);
}

void	check_texture(char *str, t_data *data)
{
	int		i;
	char	*extention;

	if (!str)
		return ;
	i = 0;
	extention = ft_strrchr(str, '.');
	if (!extention)
		return ;
	if (ft_strcmp(extention, ".xpm") == 0)
		(data->texture) = str;
	else
	{
		printf("Error\n incorrect texture !");
		free_(data);
		exit(1);
	}
	i++;
}
