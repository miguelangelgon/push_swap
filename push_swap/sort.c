/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelgo <miguelgo@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 19:05:10 by miguelgo          #+#    #+#             */
/*   Updated: 2024/04/16 20:45:49 by miguelgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(t_stack **a)
{
	t_stack	*move;

	move = *a;
	while (move->next != NULL)
	{
		if (move->number < move->next->number)
			move = move->next;
		else
			return (0);
	}
	return (1);
}

int	stack_len(t_stack *a)
{
	int		len;
	t_stack	*move;

	move = a;
	len = 0;
	while (move)
	{
		move = move->next;
		len++;
	}
	return (len);
}

void	sort(t_stack **a, t_stack **b)
{
	int		len;
	t_stack	*move;

	len = stack_len(*a);
	update_position(*a);
	if (len-- > 3)
		pb(a, b);
	if (len-- > 3)
		pb(a, b);
	while (len-- > 3)
	{
		update_a(*a, *b);
	}
}

void	update_a(t_stack *a, t_stack *b)
{
	update_position(a);
	objetives_a(a, b);
	calculate_cost(a, b);
	set_cheapest(a);
}
