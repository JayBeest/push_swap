#ifndef MAIN_H
#define MAIN_H

typedef enum e_bool
{
	FALSE,
	TRUE
}			t_bool;

typedef enum e_err_no
{
	NO_ERROR,
	NO_ARGS,
	NO_DIGIT,
	NO_INT,
	DUP_FOUND,
	DEFAULT_ERROR
}			t_err_no;

typedef enum e_operation
{
	PA,
	PB,
	RA
}			t_operation;

typedef struct s_bool_err
{
	t_bool		bool;
	t_err_no	error_nr;
}			t_bool_err;

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
	int 				amount_of_operations;
	t_operation_list	operation_list;
}			t_ps_stacks;

typedef void (*t_operation_ptr)(t_ps_stacks *);

#endif
