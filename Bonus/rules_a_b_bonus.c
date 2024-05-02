/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_a_b_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadam <kadam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:47:33 by kadam             #+#    #+#             */
/*   Updated: 2024/04/05 00:32:29 by kadam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_swap(int *a, int *b)
{
	int	swap;

	swap = *a;
	*a = *b;
	*b = swap;
}

void	ss(t_list **satck_a, t_list **satck_b)
{
	sa(satck_a);
	sb(satck_b);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}

void	pp(t_list **stack_a, t_list **stack_b)
{
	pa(stack_a, stack_b);
	pb(stack_a, stack_b);
}
