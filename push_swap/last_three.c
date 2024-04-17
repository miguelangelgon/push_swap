/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelgo <miguelgo@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:49:00 by miguelgo          #+#    #+#             */
/*   Updated: 2024/04/17 18:25:29 by miguelgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	last_three(t_stack **a)
{
	t_stack	*max;

	max = max_number(*a);
	if ((*a) == max)
		ra(a);
	else if ((*a)->next == max)
		rra(a);
	if ((*a)->number > (*a)->next->number)
		sa(a);
}
