/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 18:04:54 by mregrag           #+#    #+#             */
/*   Updated: 2024/09/03 18:05:55 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./list.h"

void	insert_node(t_list **head, t_list *node, int position)
{
	t_list	*current;
	int		i;

	i = 0;
	if (position == 0 || *head == NULL)
	{
		node->next = *head;
		*head = node;
		return ;
	}
	current = *head;
	while (i < position - 1 && current->next != NULL)
	{
		current = current->next;
		i++;
	}
	node->next = current->next;
	current->next = node;
}
