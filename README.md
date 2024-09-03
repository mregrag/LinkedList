# Linked List Implementation in C

This project provides a robust implementation of a singly linked list in C

## Features

- Create and manage nodes
- Insert nodes at the beginning, end, or any position
- Delete nodes
- Traverse the list
- Apply functions to list elements
- Map functions to create new lists
- Clear entire lists

## Function Descriptions

### Node Creation and Management

- `new_node`: Creates a new node for the linked list.
  * Input: `void *value` (the data to be stored in the node)
  * Output: `t_list *` (pointer to the newly created node)
  * Allocates memory for a new node, initializes its value and next pointer, and returns it.
```c
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
```

- `last_node`: Finds the last node in the linked list.
  * Input: `t_list *head` (pointer to the head of the list)
  * Output: `t_list *` (pointer to the last node)
  * Traverses the list to find and return the last node.
```c
t_list	*last_node(t_list *head)
{
	if (!head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}
```

- `add_back`: Adds a new node to the end of the linked list.
  * Input: `t_list **head` (pointer to the head pointer), `t_list *node` (node to be added)
  * Output: None
  * Adds the given node to the end of the list.
```c
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
```
- `add_front`: Adds a new node to the beginning of the linked list.
  * Input: `t_list **head` (pointer to the head pointer), `t_list *node` (node to be added)
  * Output: None
  * Adds the given node to the front of the list.
```c
void	add_front(t_list **head, t_list *node)
{
	if (!head || !node)
		return ;
	node->next = *head;
	*head = node;
}
```
- `insert_node`: Inserts a node at a specified position in the linked list.
  * Input: `t_list **head` (pointer to the head pointer), `t_list *node` (node to be inserted), `int position` (insertion position)
  * Output: None
  * Inserts the given node at the specified position in the list.
```c
void	insert_node(t_list **head, t_list *node, int position)
{
	t_list	*current;
	int		i;

	i = 0;
	if (position == 0 || *head == NULL)
	{
		node->next = *head;
		*head = node;
		return ;
	}
	current = *head;
	while (i < position - 1 && current->next != NULL)
	{
		current = current->next;
		i++;
	}
	node->next = current->next;
	current->next = node;
}
```
### List Information

- `lst_size`: Counts the number of nodes in the linked list.
  * Input: `t_list *list` (pointer to the head of the list)
  * Output: `int` (number of nodes in the list)
  * Traverses the list and returns the count of nodes.
```c
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
```

- `print_list`: Prints the contents of the linked list.
  * Input: `t_list *lst` (pointer to the head of the list)
  * Output: None
  * Prints each node's value to the console.
```c
void	print_list(t_list *lst)
{
	while (lst)
	{
		printf("%s ", (char *)lst->value);
		lst = lst->next;
	}
	printf("\n");
}
```

### Node and List Deletion

- `delet_node`: Deletes a single node from the linked list.
  * Input: `t_list *node` (node to be deleted), `void (*del)(void *)` (function to delete node's value)
  * Output: None
  * Deletes the given node and frees its memory.
```c
void	delet_node(t_list *node, void (*del)(void *))
{
	if (!node || !del)
		return ;
	del(node->value);
	free(node);
}
```

- `clear_list`: Deletes all nodes in the linked list and frees their memory.
  * Input: `t_list **head` (pointer to the head pointer), `void (*del)(void *)` (function to delete node's value)
  * Output: None
  * Deletes all nodes in the list, freeing their memory.
```c
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
```
### List Operations

- `list_iter`: Applies a function to the value of each node in the list.
  * Input: `t_list *head` (pointer to the head of the list), `void (*f)(void *)` (function to apply)
  * Output: None
  * Iterates through the list, applying the given function to each node's value.
```c
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
```
- `list_map`: Creates a new list by applying a function to each node's value in the original list.
  * Input: `t_list *head` (pointer to the head of the original list), `void *(*f)(void *)` (function to apply), `void (*del)(void *)` (function to delete node's value)
  * Output: `t_list *` (pointer to the head of the new list)
  * Creates a new list by applying the given function to each node's value in the original list.
```c
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
```
