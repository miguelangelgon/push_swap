/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelgo <miguelgo@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:45:16 by miguelgo          #+#    #+#             */
/*   Updated: 2024/04/17 18:30:44 by miguelgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "push_swap.h"

long	*initialize(int argc, char *argv[])
{
	long	*numbers;
	int		i;
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	i = 0;
	if (argc == 1)
	{
		write(1, "Error\n", 6);
		return (NULL);
	}
	numbers = start(argc, argv);
	if (!numbers)
	{
		write(1, "Error\n", 6);
		return (NULL);
	}
	if (!check_duplicates(numbers))
	{
		write(1, "Error\n", 6);
		return (NULL);
	}
	return (numbers);
}

int	main(int argc, char *argv[])
{
	long	*numbers;
	int		i;
	t_stack	*a;
	t_stack	*b;

	numbers = initialize(argc, argv);
	if (!numbers)
		return (0);
	while (numbers[i] != LONG_MAX)
	{
		fill_stack(&a, numbers[i]);
		i++;
	}
	free(numbers);
	if (!(check_sort(&a)))
		sort(&a, &b);
	t_stack	*move;
	move = a;
	while (move)
	{
		printf("%i\n", move->number);
		move = move->next;

	}
	free_stack(&a);
	return (0);
}
