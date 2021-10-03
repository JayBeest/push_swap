#include <radix_sort.h>
#include <operations.h>

static void	exec_radix_operations(t_ps_stacks *stacks, int current_bit)
{
	int	i;

	i = 0;
	while (i < stacks->amount_of_integers)
	{
		if (stacks->stack_a[0] & (1 << current_bit))
			exec_operation(stacks, RA);
		else
			exec_operation(stacks, PB);
		i++;
	}
	i = stacks->stack_b_size;
	while (i > 0)
	{
		exec_operation(stacks, PA);
		i--;
	}
}

void	radix_sort(t_ps_stacks *stacks, int amount_of_integers)
{
	int	current_bit;
	int	max_bits_to_sort;

	max_bits_to_sort = 0;
	current_bit = 0;
	amount_of_integers -= 1;
	while (amount_of_integers > 0)
	{
		amount_of_integers = (amount_of_integers >> 1);
		max_bits_to_sort++;
	}
	while (current_bit < max_bits_to_sort)
	{
		exec_radix_operations(stacks, current_bit);
		current_bit++;
	}
}
