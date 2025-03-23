/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_door.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 03:16:02 by aahlaqqa          #+#    #+#             */
/*   Updated: 2025/03/23 03:29:30 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void check_valid_door(t_data *data)
{
    int i;
    int j;

    i = 0;
    while (data->mini_map[i])
    {
        j = 0;
        while (data->mini_map[i][j])
        {
            if (data->mini_map[i][j] == 'D')
            {
                data->is_left_right = 0;
                data->is_up_down = 0;
                if (j > 0 && data->mini_map[i][j - 1] == '1' && data->mini_map[i][j + 1] && data->mini_map[i][j + 1] == '1')
                    data->is_left_right = 1;
                if (i > 0 && data->mini_map[i - 1][j] == '1' && data->mini_map[i + 1]  && data->mini_map[i + 1][j] == '1')
                    data->is_up_down = 1;
                if (!data->is_left_right && !data->is_up_down)
                {
                    printf("Eroor\nDoor should be at least sournded by 2 walls !!\n");
                    exit(1);
                }
            }
            j++;
        }
        i++;
    }
}
