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
	DEFAULT_ERROR
}			t_err_no;

typedef struct s_bool_err
{
	t_bool		bool;
	t_err_no	error_nr;
}			t_bool_err;

typedef struct s_ps_stacks
{
	int	*stack_a;
	int	*stack_b;
	int amount_of_integers;
	int	stack_a_size;
	int stack_b_size;
}			t_ps_stacks;

#endif
