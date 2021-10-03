#ifndef UTILS_H
# define UTILS_H

# include <main.h>

void	init_num_to_stack(int num, int *stack, int amount_of_integers);
int		free_stacks(t_ps_stacks *stacks, int return_no);
t_bool	is_sorted(int *stack, int amount_of_integers);
t_bool	only_needs_rotates(int *stack, int amount_of_integers);
t_bool	done_already(int *stack);

#endif
