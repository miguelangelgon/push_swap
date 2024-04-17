/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelgo <miguelgo@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:07:38 by miguelgo          #+#    #+#             */
/*   Updated: 2024/04/17 19:11:05 by miguelgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*move;

	if ((!(*stack)->next) || (!(*stack)))
		return ;
	move = *stack;
	last = find_last(stack);
	*stack = move->next;
	last->next = move;
	move->next = NULL;
	move->back = last;
}

void	ra(t_stack **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}

void	move_to_upper(t_stack **stack, t_stack *cheapest, char stack_name)
{
	while (*stack != cheapest)
	{
		if (stack_name == 'a')
		{
			if (cheapest->upper == 2)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (cheapest->upper == 2)
				rb(stack);
			else
				rrb(stack);
		}
	}
}
