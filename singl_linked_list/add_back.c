/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_back.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 18:04:10 by mregrag           #+#    #+#             */
/*   Updated: 2024/09/03 18:04:30 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./list.h"

void	add_back(t_list **head, t_list *node)
{
	t_list	*last;

	if (!head || !node)
		return ;
	if (*head == NULL)
	{
		*head = node;
		return ;
	}
	last = last_node(*head);
	last->next = node;
}
