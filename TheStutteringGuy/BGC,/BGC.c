/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BGC.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 02:45:26 by aibn-ich          #+#    #+#             */
/*   Updated: 2025/03/24 18:29:40 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

static void	bgc_add_back(t_data **data, t_BGC *new)
{
	t_BGC	*head;

	head = (*data)->bgc;
	while (head->next != NULL)
		head = head->next;
	head->next = new;
}

void	bgc_new(t_data **data, void *ptr, size_t size, t_type type)
{
	t_BGC	*new;

	new = malloc(sizeof(t_BGC));
	new->ptr = ptr;
	new->size = size;
	new->type = type;
	new->next = NULL;
	if ((*data)->bgc == NULL)
	{
		(*data)->bgc = new;
		return ;
	}
	else
		bgc_add_back(data, new);
}

void	*bgc_malloc(t_data **data, size_t size, t_type type)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
		return (NULL);
	bgc_new(data, ptr, size, type);
	return (ptr);
}

void	free_twod_array(void **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		if (ptr[i])
			free(ptr[i]);
		++i;
	}
	free(ptr);
}

void	bgc_free(t_data *ptr)
{
	t_BGC	*iterate;
	t_BGC	*temp;

	iterate = ptr->bgc;
	while (iterate)
	{
		temp = iterate;
		iterate = iterate->next;
		if (temp->type == Array || temp->type == Simple)
		{
			if (temp->ptr)
				free(temp->ptr);
		}
		if (temp->type == TwoD_Array)
		{
			if (temp->ptr)
				free_twod_array(temp->ptr);
		}
		free(temp);
	}
	ptr->bgc = NULL;
}
