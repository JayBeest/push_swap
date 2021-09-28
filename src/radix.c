#include "incl/main.h"
#include "incl/radix.h"
#include "../libft/libft.h"

#include <stdio.h>

static void	pa_operation(t_ps_stacks *stacks)
{
	if (stacks->stack_b_size == 0)
		return ;
	ft_memmove(stacks->stack_a + 1, stacks->stack_a, stacks->stack_a_size * sizeof(int));
	stacks->stack_a[0] = stacks->stack_b[0];
	stacks->stack_a_size++;
	stacks->stack_b_size--;
	ft_memmove(stacks->stack_b, stacks->stack_b + 1, stacks->stack_b_size * sizeof(int));
	printf("PA\n");
	stacks->amount_of_operations++;
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
	printf("PB\n");
	stacks->amount_of_operations++;
}

static void	ra_operation(t_ps_stacks *stacks)
{
	int	temp;

	if (stacks->stack_a_size < 2)
		return ;
	temp = stacks->stack_a[0];
	ft_memmove(stacks->stack_a, stacks->stack_a + 1, (stacks->stack_a_size - 1) * sizeof(int));
	stacks->stack_a[stacks->stack_a_size - 1] = temp;
	printf("RA\n");
	stacks->amount_of_operations++;
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

t_bool	all_same_bits(int *stack, int bit_n, int amount_of_integers)
{
	int		i;

	i = 0;
	while (i < amount_of_integers && stack[i] & (1 << bit_n))
		i++;
	if (i == amount_of_integers)
	{
		printf("bit: %d all 1's\n", bit_n);
		return (TRUE);
	}
	i = 0;
	while (i < amount_of_integers && !(stack[i] & (1 << bit_n)))
		i++;
	if (i == amount_of_integers)
	{
		printf("bit: %d all 0's\n", bit_n);
		return (TRUE);
	}
	return (FALSE);
}

void	exec_radix_operations(t_ps_stacks *stacks, int current_bit)
{
	int	i;

	i = 0;
	while (i < stacks->amount_of_integers)
	{
		if (stacks->stack_a[0] & (1 << current_bit))
			exec_operation(stacks, RA);
		else
			exec_operation(stacks, PB);
		ff_temp++;
		i++;
	}
	i = stacks->stack_b_size;
	while (i > 0)
	{
		exec_operation(stacks, PA);
		i--;
		ff_temp++;
	}
}

void	radix_sort(t_ps_stacks *stacks, int amount_of_integers)
{
	int	current_bit;
	int	max_bits_to_sort;

	max_bits_to_sort = 0;
	current_bit = 0;
	stacks->amount_of_operations = 0;
	amount_of_integers -= 1;
	while (amount_of_integers > 0)
	{
		amount_of_integers = amount_of_integers / 2;
		max_bits_to_sort++;
	}
	while (current_bit < max_bits_to_sort)
	{
//		if (!all_same_bits(stacks->stack_a, current_bit, stacks->amount_of_integers))
			exec_radix_operations(stacks, current_bit);
		current_bit++;
	}
	printf("AMOUNT OF OPS -----> %d\n", stacks->amount_of_operations);
	stacks->amount_of_operations = 0;
}
