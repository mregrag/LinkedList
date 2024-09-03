/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:13:01 by mregrag           #+#    #+#             */
/*   Updated: 2024/09/03 18:13:47 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include <stdio.h>
# include <stdlib.h>

typedef struct s_list
{
	void			*value;
	struct s_list	*next;
}					t_list;

t_list	*new_node(void *value);
t_list	*last_node(t_list *head);
t_list	*list_map(t_list *head, void *(*f)(void *), void (*del)(void *));
void	add_back(t_list **head, t_list *node);
void	insert_node(t_list **head, t_list *node, int position);
void	add_front(t_list **head, t_list *node);
void	delet_node(t_list *node, void (*del)(void *));
void	list_iter(t_list *head, void (*f)(void *));
void	print_list(t_list *lst);
void	clear_list(t_list **head, void (*del)(void *));
int		lst_size(t_list *list);
#endif
