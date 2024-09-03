# Linked List Implementation in C

This project provides a robust implementation of a singly linked list in C, offering a suite of functions for list manipulation and management.

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

- `add_back`: Adds a new node to the end of the linked list.
  * Input: `t_list **head` (pointer to the head pointer), `t_list *node` (node to be added)
  * Output: None
  * Adds the given node to the end of the list.

- `add_front`: Adds a new node to the beginning of the linked list.
  * Input: `t_list **head` (pointer to the head pointer), `t_list *node` (node to be added)
  * Output: None
  * Adds the given node to the front of the list.

- `insert_node`: Inserts a node at a specified position in the linked list.
  * Input: `t_list **head` (pointer to the head pointer), `t_list *node` (node to be inserted), `int position` (insertion position)
  * Output: None
  * Inserts the given node at the specified position in the list.

### List Information

- `lst_size`: Counts the number of nodes in the linked list.
  * Input: `t_list *list` (pointer to the head of the list)
  * Output: `int` (number of nodes in the list)
  * Traverses the list and returns the count of nodes.

- `print_list`: Prints the contents of the linked list.
  * Input: `t_list *lst` (pointer to the head of the list)
  * Output: None
  * Prints each node's value to the console.

### Node and List Deletion

- `delet_node`: Deletes a single node from the linked list.
  * Input: `t_list *node` (node to be deleted), `void (*del)(void *)` (function to delete node's value)
  * Output: None
  * Deletes the given node and frees its memory.

- `clear_list`: Deletes all nodes in the linked list and frees their memory.
  * Input: `t_list **head` (pointer to the head pointer), `void (*del)(void *)` (function to delete node's value)
  * Output: None
  * Deletes all nodes in the list, freeing their memory.

### List Operations

- `list_iter`: Applies a function to the value of each node in the list.
  * Input: `t_list *head` (pointer to the head of the list), `void (*f)(void *)` (function to apply)
  * Output: None
  * Iterates through the list, applying the given function to each node's value.

- `list_map`: Creates a new list by applying a function to each node's value in the original list.
  * Input: `t_list *head` (pointer to the head of the original list), `void *(*f)(void *)` (function to apply), `void (*del)(void *)` (function to delete node's value)
  * Output: `t_list *` (pointer to the head of the new list)
  * Creates a new list by applying the given function to each node's value in the original list.
