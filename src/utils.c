#include <unistd.h>
#include <stdlib.h>
#include <utils.h>

void	init_num_to_stack(int num, int *stack, int amount_of_integers)
{
	static int	i;

	if (i < amount_of_integers)
	{
		stack[i] = num;
		i++;
	}
}

int	free_stacks(t_ps_stacks *stacks, int return_no)
{
	free(stacks->stack_a);
	free(stacks->stack_b);
	if (return_no)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	return (0);
}

t_bool	is_sorted(int *stack, int amount_of_integers)
{
	int	i;

	i = 0;
	while (i < amount_of_integers)
	{
		if (stack[i] != i)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

t_bool	only_needs_rotates(int *stack, int amount_of_integers)
{
	int	i;

	i = 0;
	while (i < amount_of_integers - 1)
	{
		if ((stack[i] == amount_of_integers - 1 && stack[i + 1] == 0) || \
			stack[i + 1] == stack[i] + 1)
			i++;
		else
			return (FALSE);
	}
	return (TRUE);
}

t_bool	done_already(int *stack)
{
	return (stack[0] < stack[1] && stack[1] < stack[2]);
}
