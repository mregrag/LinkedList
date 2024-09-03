/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 18:10:51 by mregrag           #+#    #+#             */
/*   Updated: 2024/09/03 18:11:43 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./list.h"

t_list	*list_map(t_list *head, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*node;
	void	*new_content;

	if (!head || !f || !del)
		return (NULL);
	new_lst = NULL;
	while (head)
	{
		new_content = f(head->value);
		node = new_node(new_content);
		if (!node)
		{
			del(new_content);
			clear_list(&new_lst, del);
			return (NULL);
		}
		add_back(&new_lst, node);
		head = head->next;
	}
	return (new_lst);
}
