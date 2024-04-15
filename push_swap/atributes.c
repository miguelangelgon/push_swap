/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atributes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelgo <miguelgo@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 21:05:04 by miguelgo          #+#    #+#             */
/*   Updated: 2024/04/15 21:39:55 by miguelgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_position(t_stack *stack)
{
	int	i;
	t_stack	*move;

	move = stack;
	i = 1;
	while (move)
	{
		move->position = i;
		i++;
		move = move->next;
	}

}
