/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delet_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 18:08:08 by mregrag           #+#    #+#             */
/*   Updated: 2024/09/03 18:08:25 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./list.h"

void	delet_node(t_list *node, void (*del)(void *))
{
	if (!node || !del)
		return ;
	del(node->value);
	free(node);
}
