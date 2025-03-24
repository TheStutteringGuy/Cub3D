/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_Furhter_checks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibn-ich <aibn-ich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 01:50:02 by aibn-ich          #+#    #+#             */
/*   Updated: 2025/03/24 03:44:47 by aibn-ich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int ft_isspace(int c)
{
    return ((c >= 9 && c <= 13) || c == ' ');
}

bool check_line_one(char *str)
{
    int i;

    i = 0;
    while (ft_isspace(str[i]) && str[i])
        ++i;
    while (str[i])
    {
        if (str[i] != '1')
            return false;
        ++i;
    }
    return true;
}

void further_checks(t_data *data, char **starting_map)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (starting_map[i])
    {
        if (check_line_one(starting_map[i]))
            break;
        ++i;
        ++count;
    }
    if (count == 6)
        return;
    else
    {
        printf("The Input Is Not Right, Check again\n");
        free_(data);
        exit(1);
    }
}