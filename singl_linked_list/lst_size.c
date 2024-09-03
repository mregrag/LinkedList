/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 18:07:08 by mregrag           #+#    #+#             */
/*   Updated: 2024/09/03 18:07:32 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./list.h"

int	lst_size(t_list *list)
{
	int	count;

	count = 0;
	while (list != NULL)
	{
		count++;
		list = list->next;
	}
	return (count);
}
