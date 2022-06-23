/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakinen <mmakinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 12:12:00 by mmakinen          #+#    #+#             */
/*   Updated: 2022/06/23 14:53:12 by mmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gol.h"

t_list	*new_list(int row, int col)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	list->row = row;
	list->col = col;
	list->next = NULL;
	list->prev = NULL;
	return (list);
}

t_list	*stack_add(t_list *list, int row, int col)
{
	t_list	*n_list;

	n_list = new_list(row, col);
	list->next = (struct s_list *)new_list;
	n_list->prev = list;
	return (n_list);
}

t_list	*stack_pop(t_list *list)
{
	t_list	temp;

	free(list);
	list = NULL;
}

t_list	*get_stack_end(t_list *list)
{
	if (list == NULL)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}


