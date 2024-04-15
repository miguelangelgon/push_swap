/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelgo <miguelgo@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 11:31:00 by miguelgo          #+#    #+#             */
/*   Updated: 2024/04/15 21:54:44 by miguelgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	*start(int argc, char **argv)
{
	long	*numbers;
	int		i;
	int		count;
	char	**list;
	int		c;

	c = 0;
	i = 0;
	if (argc == 2)
        list = ft_split(argv[1], ' ');
	else if (argc > 2)
	{
		list = malloc(argc * sizeof(char *));
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
	while (list[c] != '\0')
	{
		if (!check_digit(list[c]))
			return (0);
		c++;
	}
	numbers = malloc((c + 1) * sizeof(long));
	if (!numbers)
		return (0);
	i = 0;
	numbers[c] = LONG_MAX;
	while (list[i] != '\0')
	{
		numbers[i] = ft_atoi(list[i]);
		i++;
	}
	free(list);
	return (numbers);
}

void	fill_stack(t_stack **stack, int number)
{
	t_stack	*last;
	t_stack *current;

	last = malloc(sizeof(t_stack));
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
		i++;
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
