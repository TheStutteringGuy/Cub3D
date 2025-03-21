/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_door.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:47:38 by aahlaqqa          #+#    #+#             */
/*   Updated: 2025/03/21 23:35:55 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void init_door_state(t_data *data)
{
    int i;

    i = 0;
    data->door_state = malloc(sizeof(bool *) * data->map_width);
    if (!data->door_state)
    {
        printf("Error while allocating memory !!\n");
        exit(1);
    }
    while (i < data->map_width)
    {
        data->door_state[i] = malloc(sizeof(bool) * data->map_height);
        if (!data->door_state[i])
        {
            printf("Error while allocating memory !!\n");
            exit(1);
        }
        ft_memset(data->door_state[i], 0, sizeof(bool) * data->map_height);
        i++;
    }
    data->door_animation = false;
    data->timer = 0.0;
    data->door_x = -1;
    data->door_y = -1;
}

void free_door_state(t_data *data)
{
    int i;

    i = 0;
    if (data->door_state)
    {
        while (i < data->map_width)
        {
            if (data->door_state[i])
                free(data->door_state[i]);
            i++;
        }
        free(data->door_state);
        data->door_state = NULL;
    }
}

int is_locking_at_door(t_data *data)
{
    data->distance = 0.5;
    while (data->distance <= 2.0)
    {
        data->check_x = (int)(data->player_x + data->dir_x * data->distance);
        data->check_y = (int)(data->player_y + data->dir_y * data->distance);
        if (data->check_x >= 0 && data->check_x < data->map_width && data->check_y >= 0 && data->check_y < data->map_height)
        {
            if (data->mini_map[data->check_x][data->check_y] == 'D')
            {
                data->door_x = data->check_x;
                data->door_y = data->check_y;
                return (1);
            }
        }
        data->distance += 0.5;
    }
    return (0);
}

void start_interaction(t_data *data)
{
    if (is_locking_at_door(data))
    {
        data->door_state[data->door_x][data->door_y] = 1;
        data->door_animation = 1;
        data->timer = 0;
    }
}

void update_doors(t_data *data, float door_timer)
{
    if (data->door_animation)
    {
        data->timer += door_timer;
        if (data->timer > 0.3)
        {
            data->player_map_x = (int)data->player_x;
            data->player_map_y = (int)data->player_y;
            if (data->player_map_x != data->door_x || data->player_map_y != data->door_y)
            {
                data->door_state[data->door_x][data->door_y] = 0;
                data->door_animation = 0;
            }
        }
    }
}
