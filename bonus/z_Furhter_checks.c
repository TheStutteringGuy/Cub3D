/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_Furhter_checks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 01:50:02 by aibn-ich          #+#    #+#             */
/*   Updated: 2025/03/24 18:25:46 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	ft_isspace(int c)
{
	return ((c >= 9 && c <= 13) || c == ' ');
}

bool	check_line_one(char *str)
{
	int	i;

	i = 0;
	while (ft_isspace(str[i]) && str[i])
		++i;
	while (str[i])
	{
		if (str[i] != '1' && !ft_isspace(str[i]))
			return (false);
		++i;
	}
	return (true);
}

void	further_checks(t_data *data, char **starting_map)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (starting_map[i])
	{
		if (check_line_one(starting_map[i]))
			break ;
		++i;
		++count;
	}
	if (count == 7)
		return ;
	else
	{
		printf("The Input Is Not Right, Check again\n");
		free_(data);
		exit(1);
	}
}
