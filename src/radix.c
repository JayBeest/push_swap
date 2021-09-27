#include "incl/main.h"
#include "incl/radix.h"
#include "../libft/libft.h"

static void	pa_operation(t_ps_stacks *stacks)
{
	if (stacks->stack_b_size == 0)
		return ;
	ft_memmove(stacks->stack_a + 1, stacks->stack_a, stacks->stack_a_size * sizeof(int));
	stacks->stack_a[0] = stacks->stack_b[0];
	stacks->stack_a_size++;
	stacks->stack_b_size--;
	ft_memmove(stacks->stack_b, stacks->stack_b + 1, stacks->stack_b_size * sizeof(int));
}

static void	pb_operation(t_ps_stacks *stacks)
{
	if (stacks->stack_a_size == 0)
		return ;
	ft_memmove(stacks->stack_b + 1, stacks->stack_b, stacks->stack_b_size * sizeof(int));
	stacks->stack_b[0] = stacks->stack_a[0];
	stacks->stack_b_size++;
	stacks->stack_a_size--;
	ft_memmove(stacks->stack_a, stacks->stack_a + 1, stacks->stack_a_size * sizeof(int));
}

static void	ra_operation(t_ps_stacks *stacks)
{
	int	temp;

	if (stacks->stack_a_size < 2)
		return ;
	temp = stacks->stack_a[0];
	ft_memmove(stacks->stack_a, stacks->stack_a + 1, (stacks->stack_a_size - 1) * sizeof(int));
	stacks->stack_a[stacks->stack_a_size - 1] = temp;
}

void	exec_operation(t_ps_stacks *stacks, t_operation op)
{
	static const t_operation_ptr fun_ptr[3] = {
			[PA] = pa_operation,
			[PB] = pb_operation,
			[RA] = ra_operation
	};
	fun_ptr[op](stacks);
}

void	radix_sort(t_ps_stacks *stacks, int amount_of_integers)
{
	int	bits_to_sort;

	bits_to_sort = 0;
	while (amount_of_integers > 0)
	{
		amount_of_integers = amount_of_integers / 2;
		bits_to_sort++;
	}
	while (bits_to_sort > 0)
	{
		if (not_all_zero_bits(stacks->stack_a))
			exec_radix_operations(stacks);
		bits_to_sort--;
	}
}
