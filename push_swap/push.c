/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelgo <miguelgo@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:13:39 by miguelgo          #+#    #+#             */
/*   Updated: 2024/04/17 18:53:51 by miguelgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **src, t_stack **dest)
{
	t_stack	*tmp;

	if (!(*src))
		return ;
	tmp = *src;
	*src = tmp->next;
	if (*src)
		tmp->next->back = NULL;
	tmp->next = *dest;
	if (*dest)
		(*dest)->back = tmp;
	tmp->back = NULL;
	*dest = tmp;
}

void	pa(t_stack **a, t_stack **b)
{
	push(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	push(a, b);
	write(1, "pb\n", 3);
}
