/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelgo <miguelgo@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:45:16 by miguelgo          #+#    #+#             */
/*   Updated: 2024/04/22 23:06:30 by miguelgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "push_swap.h"

void	ft_leaks()
{
	system("leaks -q a.out");
}

int	main(int argc, char *argv[])
{
	long	*numbers;
	int		i;
	t_stack	*a;
	t_stack	*b;

	i = 0;
	atexit(ft_leaks);
	a = NULL;
	b = NULL;
	if (argc == 1 || argv[1][0] == '\0')
		return (0);
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
	free_stack(&a);
	return (0);
}
