/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorneli <marvin@codam.nl>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:22:23 by jcorneli          #+#    #+#             */
/*   Updated: 2021/10/07 16:22:23 by jcorneli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/debug.h"
#include "incl/main.h"
#include "incl/operations.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

t_bool	duplicate(int *stack, int amount, int new_num)
{
	int	i;

	i = 0;
	while (i < amount)
	{
		if (stack[i] == new_num)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

t_bool	random_stack(int *stack, int amount, t_range range)
{
	int		i;
	int		new_num;
	int 	dup;
	time_t	seed;

	if (range.upper - range.lower < amount)
	{
		printf("increase range :(\n");
		return (FALSE);
	}
		srand((signed) time(&seed));
	i = 0;
	while (i < amount)
	{
		new_num = (rand() % (range.upper - range.lower + 1)) + range.lower;
		dup = 0;
		while (duplicate(stack, amount, new_num))
		{
			dup++;
			new_num = (rand() % (range.upper - range.lower + 1)) + range.lower;
		}
			printf("number %d -> %d duplicates\n", i, dup);
		stack[i] = new_num;
		i++;
	}
	return (TRUE);
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

void	print_stack(int *stack, int stack_size)
{
	int	i;

	i = 0;
	while (i < stack_size)
	{
		printf("index %d: %d\n", i, stack[i]);
		i++;
	}
}

void debug_pb(t_ps_stacks *stacks)
{
	printf("Stack_A(size=%d):\n", stacks->stack_a_size);
	print_stack(stacks->stack_a, stacks->stack_a_size);
	printf("Stack_B(size=%d):\n", stacks->stack_b_size);
	print_stack(stacks->stack_b, stacks->stack_b_size);
	exec_operation(stacks, PB);
	exec_operation(stacks, PB);
	exec_operation(stacks, PB);
	printf("Stack_A(size=%d):\n", stacks->stack_a_size);
	print_stack(stacks->stack_a, stacks->stack_a_size);
	printf("Stack_B(size=%d):\n", stacks->stack_b_size);
	print_stack(stacks->stack_b, stacks->stack_b_size);
}

void debug_ra(t_ps_stacks *stacks)
{
	printf("Stack_A(size=%d):\n", stacks->stack_a_size);
	print_stack(stacks->stack_a, stacks->stack_a_size);
	printf("Stack_B(size=%d):\n", stacks->stack_b_size);
	print_stack(stacks->stack_b, stacks->stack_b_size);
	exec_operation(stacks, RA);
	exec_operation(stacks, RA);
	printf("Stack_A(size=%d):\n", stacks->stack_a_size);
	print_stack(stacks->stack_a, stacks->stack_a_size);
	printf("Stack_B(size=%d):\n", stacks->stack_b_size);
	print_stack(stacks->stack_b, stacks->stack_b_size);
}

void	debug(t_ps_stacks *stacks)
{
	t_range	range;

	range.lower = 0;
	range.upper = 100000;
//	debug_pb(stacks);
//	debug_ra(stacks);
	printf("Stack_A(size=%d):\n", stacks->stack_a_size);
	print_stack(stacks->stack_a, stacks->stack_a_size);
	printf("Stack_B(size=%d):\n", stacks->stack_b_size);
	print_stack(stacks->stack_b, stacks->stack_b_size);

	if (random_stack(stacks->stack_a, 100000, range))
	{
//		printf("Stack_A(size=%d):\n", stacks->stack_a_size);
//		print_stack(stacks->stack_a, stacks->stack_a_size);
//		printf("Stack_B(size=%d):\n", stacks->stack_b_size);
//		print_stack(stacks->stack_b, stacks->stack_b_size);
	}
}
