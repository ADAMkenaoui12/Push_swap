/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadam <kadam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:42:57 by kadam             #+#    #+#             */
/*   Updated: 2024/03/21 03:41:16 by kadam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int content, int index)
{
	t_list	*head;

	head = (t_list *)malloc(sizeof(t_list));
	if (head == NULL)
		return (NULL);
	head->content = content;
	head->next = NULL;
	head->index = index;
	return (head);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	ptr = *lst;
	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = new;
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new == NULL || lst == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}

int	ft_lstsize(t_list *lst)
{
	int		counter;
	t_list	*ptr;

	ptr = lst;
	counter = 0;
	while (ptr != NULL)
	{
		counter++;
		ptr = ptr->next;
	}
	return (counter);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*ptr;

	if (lst == NULL || *lst == NULL)
		return ;
	ptr = *lst;
	while (ptr != NULL)
	{
		ptr = (*lst)->next;
		free(*lst);
		*lst = ptr;
	}
	lst = NULL;
}
