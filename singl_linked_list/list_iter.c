/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_iter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 18:08:52 by mregrag           #+#    #+#             */
/*   Updated: 2024/09/03 18:09:23 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./list.h"

void	list_iter(t_list *head, void (*f)(void *))
{
	if (!head || !f)
		return ;
	while (head)
	{
		f(head->value);
		head = head->next;
	}
}
