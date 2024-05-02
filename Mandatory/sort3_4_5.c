/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadam <kadam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 21:20:35 by kadam             #+#    #+#             */
/*   Updated: 2024/04/04 22:22:13 by kadam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_speed(t_list **stack_a, t_list **stack_b, int size)
{
	int	min;
	int	mdl;
	int	x;
	int	y;

	y = 0;
	mdl = size / 2;
	while (*stack_a != NULL)
	{
		min = find_min(*stack_a);
		x = give_rangs(min, *stack_a);
		if (x == 0)
		{
			if (y == 1)
				break ;
			pb(stack_a, stack_b);
			size = ft_lstsize(*stack_a);
			mdl = size / 2;
			y++;
		}
		else if (x > mdl)
			rra(stack_a);
		else if (x <= mdl)
			ra(stack_a, (*stack_a)->index);
	}
}

void	sort2(int size, t_list **stack_a)
{
	t_list	*ptr;

	ptr = *stack_a;
	if (size == 1)
		return ;
	else if (size == 2)
	{
		if (ptr->content > ptr->next->content)
			sa(stack_a);
	}
}

void	sort3(t_list **stack_a)
{
	t_list	*ptr;
	int		a;
	int		b;
	int		c;

	ptr = *stack_a;
	a = ptr->content;
	b = ptr->next->content;
	c = ptr->next->next->content;
	if (a > b && b < c && a < c)
		sa(stack_a);
	else if (a > b && b < c && a > c)
		ra(stack_a, (*stack_a)->index);
	else if (a < b && b > c && a > c)
		rra(stack_a);
	else if (a > b && b > c && a > c)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (a < b && b > c && a < c)
	{
		sa(stack_a);
		ra(stack_a, (*stack_a)->index);
	}
}

void	sort4(t_list **stack_a, t_list **stack_b)
{
	sort_speed(stack_a, stack_b, 4);
	sort3(stack_a);
	pa(stack_a, stack_b);
}

void	sort5(t_list **stack_a, t_list **stack_b)
{
	sort_speed(stack_a, stack_b, 5);
	sort4(stack_a, stack_b);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}
