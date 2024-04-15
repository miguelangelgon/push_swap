/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelgo <miguelgo@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:33:22 by miguelgo          #+#    #+#             */
/*   Updated: 2024/04/15 21:44:26 by miguelgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void free_stack(t_stack **stack)
{
    t_stack *tmp;
	t_stack	*move;

	move = *stack;
    while (move != NULL)
    {
        tmp = move;
        move = move->next;
        free(tmp);
    }
}
