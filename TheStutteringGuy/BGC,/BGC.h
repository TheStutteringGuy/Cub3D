/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BGC.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibn-ich <aibn-ich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 02:33:48 by aibn-ich          #+#    #+#             */
/*   Updated: 2025/03/19 06:22:30 by aibn-ich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BGC_H
#define BGC_H

#include "../../cub3D.h"

void bgc_new(t_data **data, void *ptr, size_t size, t_type type);
void *bgc_malloc(t_data **data ,size_t size, t_type type);
void bgc_free(t_data *ptr);

#endif