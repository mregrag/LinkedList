/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newnode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:16:26 by mregrag           #+#    #+#             */
/*   Updated: 2024/09/03 18:11:50 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./list.h"

t_list	*new_node(void *value)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}

void	print_list(t_list *lst)
{
	while (lst)
	{
		printf("%s ", (char *)lst->value);
		lst = lst->next;
	}
	printf("\n");
}
