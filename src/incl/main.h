#ifndef MAIN_H
# define MAIN_H

# define MAX_INT 2147483647
# define MIN_INT -2147483648

typedef enum e_bool
{
	FALSE,
	TRUE
}			t_bool;

typedef struct s_range
{
	int lower;
	int upper;
	int	amount_of_integers;
}			t_range;

typedef enum e_operation
{
	PA,
	PB,
	SA,
	SB,
	SS,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR

}			t_operation;

typedef struct s_operation_list
{
	t_operation				operation;
	struct s_operation_list	*next;
}			t_operation_list;

typedef struct s_ps_stacks
{
	int					*stack_a;
	int					*stack_b;
	int					amount_of_integers;
	int					stack_a_size;
	int					stack_b_size;
	t_operation_list	operation_list;
}			t_ps_stacks;

typedef void	(*t_operation_ptr)(t_ps_stacks *);

#endif
