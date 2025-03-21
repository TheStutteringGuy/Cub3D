/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:17:59 by aahlaqqa          #+#    #+#             */
/*   Updated: 2025/03/21 23:28:14 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	move_up(t_data *data)
{
	data->next_x = (int)(data->player_x + data->dir_x
			* MOVE_SPEED);
	data->next_y = (int)data->player_y;
	if (data->mini_map[data->next_x][data->next_y] != '1' && (data->mini_map[data->next_x][data->next_y] != 'D' || data->door_state[data->next_x][data->next_y] == 1))
		data->player_x += data->dir_x * MOVE_SPEED;
	data->next_x = (int)data->player_x;
	data->next_y = (int)(data->player_y + data->dir_y
		* MOVE_SPEED);
	if (data->mini_map[data->next_x][data->next_y] != '1' && (data->mini_map[data->next_x][data->next_y] != 'D' || data->door_state[data->next_x][data->next_y] == 1))
		data->player_y += data->dir_y * MOVE_SPEED;
}

void	move_down(t_data *data)
{
	data->next_x = (int)(data->player_x - data->dir_x
			* MOVE_SPEED);
	data->next_y = (int)data->player_y;
	if (data->mini_map[data->next_x][data->next_y] != '1' && (data->mini_map[data->next_x][data->next_y] != 'D' || data->door_state[data->next_x][data->next_y] == 1))
		data->player_x -= data->dir_x * MOVE_SPEED;
	data->next_x = (int)data->player_x;
	data->next_y = (int)(data->player_y - data->dir_y
		* MOVE_SPEED);
	if (data->mini_map[data->next_x][data->next_y] != '1' && (data->mini_map[data->next_x][data->next_y] != 'D' || data->door_state[data->next_x][data->next_y] == 1))
		data->player_y -= data->dir_y * MOVE_SPEED;
}

void	move_left(t_data *data)
{
	data->next_x = (int)(data->player_x - data->plan_x
			* MOVE_SPEED);
	data->next_y = (int)data->player_y;
	if (data->mini_map[data->next_x][data->next_y] != '1' && (data->mini_map[data->next_x][data->next_y] != 'D' || data->door_state[data->next_x][data->next_y] == 1))
		data->player_x -= data->plan_x * MOVE_SPEED;
	data->next_x = (int)data->player_x;
	data->next_y = (int)(data->player_y - data->plan_y
		* MOVE_SPEED);
	if (data->mini_map[data->next_x][data->next_y] != '1' && (data->mini_map[data->next_x][data->next_y] != 'D' || data->door_state[data->next_x][data->next_y] == 1))
		data->player_y -= data->plan_y * MOVE_SPEED;
}

void	move_right(t_data *data)
{
	data->next_x = (int)(data->player_x + data->plan_x
			* MOVE_SPEED);
	data->next_y = (int)data->player_y;
	if (data->mini_map[data->next_x][data->next_y] != '1' && (data->mini_map[data->next_x][data->next_y] != 'D' || data->door_state[data->next_x][data->next_y] == 1))
		data->player_x += data->plan_x * MOVE_SPEED;
	data->next_x = (int)data->player_x;
	data->next_y = (int)(data->player_y + data->plan_y
		* MOVE_SPEED);
	if (data->mini_map[data->next_x][data->next_y] != '1' && (data->mini_map[data->next_x][data->next_y] != 'D' || data->door_state[data->next_x][data->next_y] == 1))
		data->player_y += data->plan_y * MOVE_SPEED;
}
