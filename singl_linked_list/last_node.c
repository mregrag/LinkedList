/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 18:03:20 by mregrag           #+#    #+#             */
/*   Updated: 2024/09/03 18:03:37 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./list.h"

t_list	*last_node(t_list *head)
{
	if (!head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}
