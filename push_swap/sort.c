/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelgo <miguelgo@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 19:05:10 by miguelgo          #+#    #+#             */
/*   Updated: 2024/04/15 21:33:06 by miguelgo         ###   ########.fr       */
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

int	stack_len(t_stack **a)
{
	int		len;
	t_stack	*move;

	move = *a;
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
	int	len;
	t_stack	*move;

	move = *a;
	len = stack_len(a);
	update_position(*a);
	while (move)
		move = move->next;
}
