/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:56:11 by aahlaqqa          #+#    #+#             */
/*   Updated: 2025/03/22 16:26:04 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	rotate_player(t_data *data, double rotation_angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->dir_x;
	old_plane_x = data->plan_x;
	data->dir_x = data->dir_x * cos(rotation_angle) - data->dir_y
		* sin(rotation_angle);
	data->dir_y = old_dir_x * sin(rotation_angle) + data->dir_y
		* cos(rotation_angle);
	data->plan_x = data->plan_x * cos(rotation_angle) - data->plan_y
		* sin(rotation_angle);
	data->plan_y = old_plane_x * sin(rotation_angle) + data->plan_y
		* cos(rotation_angle);
	raycasting(data);
}

int	handle_mouse_move(int x, int y, t_data *data)
{
	int		center_x;
	double	rotation_speed;
	double	rotation_angle;

	(void)y;
	center_x = SCREEN_W / 2;
	rotation_speed = ROT_SPEED;
	rotation_angle = (x - center_x) * rotation_speed;
	if (fabs(rotation_angle) > 0.001)
	{
		rotate_player(data, rotation_angle);
		mlx_mouse_move(data->mlx, data->mlx_win, center_x, SCREEN_H / 2);
	}
	return (0);
}

void	init_mouse(t_data *data)
{
	mlx_mouse_hide(data->mlx, data->mlx_win);
	mlx_mouse_move(data->mlx, data->mlx_win, SCREEN_W / 2, SCREEN_H
		/ 2);
}
