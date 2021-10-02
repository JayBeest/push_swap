#include "incl/utils.h"

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

void	init_num_to_stack(int num, int *stack, int amount_of_integers)
{
	static int i;

	if (i < amount_of_integers)
	{
		stack[i] = num;
		i++;
	}
}