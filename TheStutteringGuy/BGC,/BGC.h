/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BGC.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibn-ich <aibn-ich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 02:33:48 by aibn-ich          #+#    #+#             */
/*   Updated: 2025/03/18 23:40:39 by aibn-ich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BGC_H
#define BGC_H

#include "../../cub3D.h"

void *bgc_malloc(t_data **data ,size_t size, t_type type);
void bgc_free(t_data *ptr);

#endif