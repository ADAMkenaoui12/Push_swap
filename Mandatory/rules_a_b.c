/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_a_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadam <kadam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:47:33 by kadam             #+#    #+#             */
/*   Updated: 2024/04/04 22:14:10 by kadam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	ft_putstr_fd("ss\n", 1);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	ra(stack_a, (*stack_a)->index);
	rb(stack_b, (*stack_b)->index);
	ft_putstr_fd("rr\n", 1);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	ft_putstr_fd("rrr\n", 1);
}

void	pp(t_list **stack_a, t_list **stack_b)
{
	pa(stack_a, stack_b);
	pb(stack_a, stack_b);
	ft_putstr_fd("pp\n", 1);
}
