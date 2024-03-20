/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:29:10 by dde-maga          #+#    #+#             */
/*   Updated: 2024/03/20 16:40:59 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <fcntl.h>
# include <limits.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_stack	t_stack;
typedef struct s_node	t_node;

struct					s_node
{
	int					value;
	int					rank;
	int					cost;
	int					index;
	bool				cheapest;
	bool				above_median;
	struct s_node		*target;
	struct s_node		*prev;
	struct s_node		*next;
};

struct					s_stack
{
	int					size;
	int					median;
	int					quarter;
	t_node				*head;
	t_node				*tail;
	t_node				*cheapest;
};

//=============================== Errors ===============================//

void					error_free(t_stack *a, char **argv, bool flag_argc_2);
void					free_all(char **in);
void					free_stack(t_stack *stack, char **av, bool flag);
int						error_syntax(char *str_nbr);
int						error_repetition(t_stack *a, int nbr);

//=============================== Verifys ==============================//

int						stack_len(t_stack *stack);
bool					stack_sorted(t_stack *stack);
t_node					*find_min(t_stack *stack);
t_node					*find_max(t_stack *stack);
t_node					*find_last(t_stack *stack);
t_node					*get_best_friend(t_stack *a, int value);

//=============================== Metrics ==============================//

void					current_index(t_stack *stack);
void					min_max(t_stack *stack, int *min, int *max);
void					pa(t_stack *a, t_stack *b, bool print);
void					pb(t_stack *b, t_stack *a, bool print);
void					append_node(t_stack *stack, int n);
void					quick_friend(t_stack *a, t_stack *b);
int						ranking(t_stack *stack);

//=============================== Sorts ===============================//
void					init_a(t_stack *a, char **argv, bool flag);
void					sort_three(t_stack *a);
void					sort_ten(t_stack *a, t_stack *b);
void					a_sort(t_stack *a, t_stack *b, int max, int min);
void					b_sort(t_stack *a, t_stack *b);

//=============================== Moves ===============================//
// Swap
void					sa(t_stack *a, bool print);
void					sb(t_stack *b, bool print);
void					ss(t_stack *a, t_stack *b, bool print);
// Rotate
void					ra(t_stack *a, bool print);
void					rb(t_stack *b, bool print);
void					rr(t_stack *a, t_stack *b, bool print);
void					rotate(t_stack *stack);
void					rotate_both(t_stack *a, t_stack *b,
							t_node *cheapest_node);
void					rotate_both_turk(t_stack *a, t_stack *b,
							t_node *cheapest_node);
// Reverse Rotate
void					rra(t_stack *a, bool print);
void					rrb(t_stack *b, bool print);
void					rrr(t_stack *a, t_stack *b, bool print);
void					reverse_rotate(t_stack *stack);
void					reverse_rotate_both(t_stack *a, t_stack *b,
							t_node *cheapest_node);
void					reverse_rotate_both_turk(t_stack *a, t_stack *b,
							t_node *cheapest_node);
// Custom
void					min_on_top(t_stack *a);
void					push_prep(t_stack *stack, t_node *top_node,
							char stk_name);
void					move_b_a(t_stack *a, t_stack *b);

//============================== Lib ==================================//

void					*ft_memset(void *b, int c, size_t len);
void					*ft_memcpy(void *dest, const void *src, size_t n);
void					*ft_calloc(size_t count, size_t size);
void					set_target_b(t_stack *a, t_stack *b);
void					cost_analysis(t_stack *dst, t_stack *src);
void					set_cheapest(t_stack *stack);
char					**ft_split(char const *s, char c);
char					*ft_strdup(char *src);
char					*ft_substr(char const *s, unsigned int start,
							size_t len);
int						ft_putstr_fd(char *s, int fd);
long					ft_atol(const char *str);
size_t					ft_strlen(const char *s);

//============================ Turk Sort ===========================//
// Sort
void					turk_sort(t_stack *a, t_stack *b);
// Stacks
void					init_nodes_a(t_stack *a, t_stack *b);
void					init_nodes_b(t_stack *a, t_stack *b);
// Moves
void					move_turk_ab(t_stack *a, t_stack *b);
void					move_turk_ba(t_stack *a, t_stack *b);

#endif
