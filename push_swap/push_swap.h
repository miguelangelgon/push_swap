/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelgo <miguelgo@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:36:14 by miguelgo          #+#    #+#             */
/*   Updated: 2024/04/18 15:52:42 by miguelgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_stack
{
	int				number;
	int				cost;
	int				upper;
	int				position;
	int				cheapest;
	struct s_stack	*back;
	struct s_stack	*next;
	struct s_stack	*objetive;

}	t_stack;

int				ft_str_is_numeric(char str);
int				check_duplicates(long *numbers);
long			ft_atoi(const char *str);
char			**ft_split(char const *s, char c);
static char		**write_result(char const *s, char c, char **res);
static size_t	count_words(char const *s, char c);
static void		ft_free(char **res);
char			*ft_substr(char const *s, unsigned int start, size_t len);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
long			*start(int argc, char **argv);
int				check_digit(char *list);
void			fill_stack(t_stack **stack, int number);
int				check_sort(t_stack **a);
void			sort(t_stack **a, t_stack **b);
int				stack_len(t_stack *a);
void			update_position(t_stack *stack);
void			free_stack(t_stack **stack);
void			push(t_stack **src, t_stack **dest);
void			pb(t_stack **a, t_stack **b);
void			update_a(t_stack *a, t_stack *b);
void			objetives_a(t_stack *a, t_stack *b);
t_stack			*max_number(t_stack *b);
void			calculate_cost(t_stack *a, t_stack *b);
void			set_cheapest(t_stack *stack);
t_stack			*find_last(t_stack **stack);
void			rotate(t_stack **stack);
void			move_to_upper(t_stack **stack, t_stack *cheapest,
					char stack_name);
void			move_to_b(t_stack **a, t_stack **b);
void			ra(t_stack **a);
void			rb(t_stack **b);
void			rr(t_stack **a, t_stack **b);
void			rotate_two(t_stack **a, t_stack **b, t_stack *cheapest, int c);
void			reverse_rotate(t_stack **stack);
void			rra(t_stack **a);
void			rrb(t_stack **b);
void			rrr(t_stack **a, t_stack **b);
t_stack			*get_cheapest(t_stack **stack);
void			last_three(t_stack **a);
void			swap(t_stack **stack);
void			sa(t_stack **a);
void			sb(t_stack **b);
void			ss(t_stack **a, t_stack **b);
void			move_to_a(t_stack **a, t_stack **b);
void			objetives_b(t_stack *a, t_stack *b);
t_stack			*min_number(t_stack *b);
void			update_b(t_stack *a, t_stack *b);
void			pa(t_stack **a, t_stack **b);
void			last_step(t_stack **a);
int				all_space(const char *s);

#endif
