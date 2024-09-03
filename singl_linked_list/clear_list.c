/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 18:09:34 by mregrag           #+#    #+#             */
/*   Updated: 2024/09/03 18:10:41 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./list.h"

void	clear_list(t_list **head, void (*del)(void *))
{
	t_list	*current;
	t_list	*tmp;

	if (*head == NULL || del == NULL)
		return ;
	current = *head;
	while (current)
	{
		tmp = current;
		current = current->next;
		del(tmp->value);
		free(tmp);
	}
	*head = NULL;
}
