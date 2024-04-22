/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelgo <miguelgo@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 11:31:00 by miguelgo          #+#    #+#             */
/*   Updated: 2024/04/22 23:15:20 by miguelgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**get_list(int argc, char **argv)
{
	char	**list;
	int		i;
	int		count;

	i = 0;
	if (argc == 2)
	{
		list = ft_split(argv[1], ' ');
		if (!list)
			return (NULL);
	}
	else
	{
		list = malloc((argc) * sizeof(char *));
		if (!list)
			return (0);
		count = 1;
		while (argv[count] != '\0')
		{
			list[i] = argv[count];
			i++;
			count++;
		}
		list[i] = NULL;
	}
	return (list);
}

long	*start(int argc, char **argv)
{
	long	*numbers;
	int		c;
	char	**list;

	list = get_list(argc, argv);
	if (!list)
		return (0);	
	c = number_list(list);
	if (!c)
	{
		if (argc == 2)
			free_numbers(list);
		else
			free(list);
		return (0);
	}
	numbers = malloc((c + 1) * sizeof(long));
	if (!numbers)
	{
		if (argc == 2)
			free_numbers(list);
		else
			free(list);
		return (0);
	}
	numbers[c] = LONG_MAX;
	c = 0;
	while (list[c] != '\0')
	{
		numbers[c] = ft_atoi(list[c]);
		c++;
	}
	if (argc == 2)
		free_numbers(list);
	else
		free(list);
	return (numbers);
}


void	fill_stack(t_stack **stack, int number)
{
	t_stack	*last;
	t_stack	*current;

	last = (t_stack *)malloc(sizeof(t_stack));
	if (!last)
		return ;
	last->number = number;
	last->next = NULL;
	if (!(*stack))
	{
		*stack = last;
		last->back = NULL;
	}
	else
	{
		current = *stack;
		while (current->next != NULL)
			current = current->next;
		current->next = last;
		last->back = current;
	}
}

int	check_digit(char *list)
{
	int	i;

	i = 0;
	if (list[i] == '-' || list[i] == '+')
	{
		if (!ft_str_is_numeric(list[i +1]))
			return (0);
		i++;
	}
	while (list[i] != '\0')
	{
		if (!(list[i] >= '0' && list[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	check_duplicates(long *numbers)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (numbers[i] != LONG_MAX)
	{
		c = i + 1;
		while (numbers[c] != LONG_MAX)
		{
			if (numbers[c] == numbers[i])
				return (0);
			c++;
		}
		i++;
	}
	i = 0;
	while (numbers[i] != LONG_MAX)
	{
		if (numbers[i] < INT_MIN || numbers[i] > INT_MAX)
			return (0);
		i++;
	}
	return (1);
}
