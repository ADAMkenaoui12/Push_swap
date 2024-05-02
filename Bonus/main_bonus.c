/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadam <kadam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:24:39 by kadam             #+#    #+#             */
/*   Updated: 2024/05/01 14:52:58 by kadam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	create_stacks(t_list **stack_a, int ac, char **av)
{
	int		j;
	int		i;
	char	**s;
	char	**temp;

	i = 0;
	j = 1;
	while (j < ac)
	{
		s = ft_split(av[j], ' ');
		temp = s;
		i = 0;
		while (temp[i] != NULL)
		{
			ft_lstadd_back(stack_a, ft_lstnew(ft_atoi(temp[i])));
			i++;
		}
		get_free(temp);
		j++;
	}
}

static void	help1(t_list **stack_a, t_list **stack_b)
{
	ft_lstclear(stack_a);
	ft_lstclear(stack_b);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

static void	help2(char *line, t_list **stack_a, t_list **stack_b)
{
	if (ft_strcmp(line, "sa\n") == 0)
		sa(stack_a);
	else if (ft_strcmp(line, "sb\n") == 0)
		sb(stack_b);
	else if (ft_strcmp(line, "ss\n") == 0)
		ss(stack_a, stack_b);
	else if (ft_strcmp(line, "pa\n") == 0)
		pa(stack_a, stack_b);
	else if (ft_strcmp(line, "pb\n") == 0)
		pb(stack_a, stack_b);
	else if (ft_strcmp(line, "ra\n") == 0)
		ra(stack_a);
	else if (ft_strcmp(line, "rb\n") == 0)
		rb(stack_b);
	else if (ft_strcmp(line, "rr\n") == 0)
		rr(stack_a, stack_b);
	else if (ft_strcmp(line, "rra\n") == 0)
		rra(stack_a);
	else if (ft_strcmp(line, "rrb\n") == 0)
		rrb(stack_b);
	else if (ft_strcmp(line, "rrr\n") == 0)
		rrr(stack_a, stack_b);
	else
		help1(stack_a, stack_b);
}

static void	help3(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_b) != 0)
	{
		ft_putstr_fd("KO\n", 1);
		ft_lstclear(stack_a);
		ft_lstclear(stack_b);
	}
	else if (is_sorted(*stack_a) == 1)
	{
		ft_lstclear(stack_a);
		ft_lstclear(stack_b);
		ft_putstr_fd("OK\n", 1);
	}
	else
	{
		ft_lstclear(stack_a);
		ft_lstclear(stack_b);
		ft_putstr_fd("KO\n", 1);
	}
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	*line;

	if (ac == 1)
		exit(0);
	if (check_args(ac, av, 0, 1) == 0)
		exit(1);
	stack_a = NULL;
	stack_b = NULL;
	create_stacks(&stack_a, ac, av);
	line = get_next_line(0);
	while (line != NULL)
	{
		help2(line, &stack_a, &stack_b);
		free(line);
		line = get_next_line(0);
	}
	free(line);
	help3(&stack_a, &stack_b);
}
