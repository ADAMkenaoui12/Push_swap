/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadam <kadam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:53:54 by kadam             #+#    #+#             */
/*   Updated: 2024/05/01 14:32:12 by kadam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_is_number(char *str, int i)
{
	while (str[i] != '\0')
	{
		if ((str[i] == '-' || str[i] == '+') && str[i + 1] == '\0')
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		else if ((str[i] >= '0' && str[i] <= '9') || ((i == 0) && (str[i] == '-'
					|| str[i] == '+')))
		{
			if ((str[i] == '-' || str[i] == '+') && (str[i + 1] == '-' || str[i
						+ 1] == '+'))
			{
				ft_putstr_fd("Error\n", 2);
				return (0);
			}
		}
		else
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		i++;
	}
	return (1);
}

static int	check_is_empty(char *str)
{
	if (str == NULL)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	else if (str[0] == '\0')
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	return (1);
}

static int	check_is_repeat(t_list *lst)
{
	t_list	*temp;

	while (lst != NULL)
	{
		temp = lst->next;
		while (temp != NULL)
		{
			if (lst->content == temp->content)
			{
				ft_putstr_fd("Error\n", 2);
				return (0);
			}
			temp = temp->next;
		}
		lst = lst->next;
	}
	return (1);
}

static int	check_rangs(char *str)
{
	int	xx;

	xx = 1;
	ft_atoi_check(str, &xx, 0, 0);
	if (xx == 0)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	return (1);
}

int	check_args(int ac, char **av, int i, int j)
{
	t_list	*node0;
	char	**s;
	char	**temp;

	node0 = NULL;
	while (j < ac)
	{
		s = ft_split(av[j], ' ');
		if (check_is_empty(av[j]) == 0 || check_is_empty(s[0]) == 0)
			return (get_free(s), ft_lstclear(&node0), 0);
		temp = s;
		i = 0;
		while (temp[i] != NULL)
		{
			if (check_is_number(temp[i], 0) == 0 || check_rangs(temp[i]) == 0)
				return (get_free(temp), ft_lstclear(&node0), 0);
			ft_lstadd_back(&node0, ft_lstnew(ft_atoi(temp[i]), 0));
			i++;
		}
		if (check_is_repeat(node0) == 0)
			return (get_free(temp), ft_lstclear(&node0), 0);
		get_free(temp);
		j++;
	}
	return (ft_lstclear(&node0), 1);
}
