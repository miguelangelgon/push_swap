/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelgo <miguelgo@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:11:39 by miguelgo          #+#    #+#             */
/*   Updated: 2024/04/18 17:11:03 by miguelgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_two(t_stack **a, t_stack **b, t_stack *cheapest, int c)
{
	if (c == 2)
	{
		while ((*a != cheapest) && (*b != cheapest->objetive))
			rr(a, b);
	}
	else if (c == 1)
	{
		while ((*a != cheapest) && (*b != cheapest->objetive))
			rrr(a, b);
	}
}

void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*move;

	if (!(*stack)->next || !(*stack))
		return ;
	move = *stack;
	last = find_last(stack);
	last->back->next = NULL;
	last->next = *stack;
	last->back = NULL;
	*stack = last;
	last->next->back = last;
}

void	rra(t_stack	**a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}
