/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelgo <miguelgo@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:36:14 by miguelgo          #+#    #+#             */
/*   Updated: 2024/04/16 20:28:56 by miguelgo         ###   ########.fr       */
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

int				ft_str_is_numeric(char *str);
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

#endif
