#ifndef PARSER_H
# define PARSER_H

# include <main.h>

int		init_stacks(t_ps_stacks *stacks, int argc);
void	nums_to_indexes(t_ps_stacks *stacks);
t_bool	parse_arguments(char **argv, t_ps_stacks *stacks);
t_bool	duplicates(int *stack, int amount_of_integers);

#endif
