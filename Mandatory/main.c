/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadam <kadam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:24:39 by kadam             #+#    #+#             */
/*   Updated: 2024/05/01 14:16:10 by kadam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	create_stacks(t_list **stack_a, t_list **stack_y, int ac, char **av)
{
	int		j;
	int		i;
	char	**s;
	char	**temp;
	t_list	*stack_x;

	i = 0;
	j = 1;
	stack_x = NULL;
	while (j < ac)
	{
		s = ft_split(av[j], ' ');
		temp = s;
		i = 0;
		while (temp[i] != NULL)
		{
			ft_lstadd_back(stack_a, ft_lstnew(ft_atoi(temp[i]), 0));
			ft_lstadd_back(&stack_x, ft_lstnew(ft_atoi(temp[i++]), 0));
		}
		get_free(temp);
		j++;
	}
	*stack_y = sort_tab(stack_x, 0, 0);
	ft_lstclear(&stack_x);
	give_index(*stack_a, *stack_y);
}

static void	overall_sort(int size, t_list **stack_a, t_list **stack_b,
		t_list **stack_y)
{
	if (size == 1 || size == 2)
		sort2(size, stack_a);
	else if (size == 3)
		sort3(stack_a);
	else if (size == 4)
		sort4(stack_a, stack_b);
	else if (size == 5)
		sort5(stack_a, stack_b);
	else if (size <= 100 || (size >= 100 && size < 500) || size >= 500)
	{
		if (size <= 100)
			sort100(stack_a, stack_b, *stack_y, 15);
		else if (size > 100 && size < 500)
			sort100(stack_a, stack_b, *stack_y, 25);
		else if (size >= 500)
			sort100(stack_a, stack_b, *stack_y, 35);
		give_index(*stack_b, *stack_y);
		last_sort(stack_a, stack_b, size);
	}
}

static int	check_stack(t_list *stack_a)
{
	t_list	*ptr;
	int		size;
	int		i;

	ptr = stack_a;
	size = ft_lstsize(stack_a);
	i = 0;
	while (ptr->next != NULL)
	{
		if (ptr->index < ptr->next->index)
			i++;
		ptr = ptr->next;
	}
	if (i == size - 1)
	{
		ft_lstclear(&stack_a);
		return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*stack_y;
	int		size;

	if (ac == 1)
		exit(0);
	if (check_args(ac, av, 0, 1) == 0)
		exit(1);
	stack_a = NULL;
	stack_b = NULL;
	stack_y = NULL;
	create_stacks(&stack_a, &stack_y, ac, av);
	if (check_stack(stack_a) == 0)
		exit(0);
	size = ft_lstsize(stack_a);
	overall_sort(size, &stack_a, &stack_b, &stack_y);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	ft_lstclear(&stack_y);
}
