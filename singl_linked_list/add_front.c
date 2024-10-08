/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_front.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 18:06:18 by mregrag           #+#    #+#             */
/*   Updated: 2024/09/03 18:06:44 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./list.h"

void	add_front(t_list **head, t_list *node)
{
	if (!head || !node)
		return ;
	node->next = *head;
	*head = node;
}
