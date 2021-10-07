/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorneli <marvin@codam.nl>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 17:16:19 by jcorneli          #+#    #+#             */
/*   Updated: 2021/10/07 17:16:19 by jcorneli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <op_rotate.h>

void	ra_operation(t_ps_stacks *stacks)
{
	int	temp;

	if (stacks->stack_a_size < 2)
		return ;
	temp = stacks->stack_a[0];
	ft_memmove(stacks->stack_a, stacks->stack_a + 1, \
		(stacks->stack_a_size - 1) * sizeof(int));
	stacks->stack_a[stacks->stack_a_size - 1] = temp;
}

void	rb_operation(t_ps_stacks *stacks)
{
	int	temp;

	if (stacks->stack_b_size < 2)
		return ;
	temp = stacks->stack_b[0];
	ft_memmove(stacks->stack_b, stacks->stack_b + 1, \
		(stacks->stack_b_size - 1) * sizeof(int));
	stacks->stack_b[stacks->stack_b_size - 1] = temp;
}

void	rra_operation(t_ps_stacks *stacks)
{
	int	temp;

	if (stacks->stack_a_size < 2)
		return ;
	temp = stacks->stack_a[stacks->stack_a_size - 1];
	ft_memmove(stacks->stack_a + 1, stacks->stack_a, \
		(stacks->stack_a_size - 1) * sizeof(int));
	stacks->stack_a[0] = temp;
}

void	rrb_operation(t_ps_stacks *stacks)
{
	int	temp;

	if (stacks->stack_b_size < 2)
		return ;
	temp = stacks->stack_b[stacks->stack_b_size - 1];
	ft_memmove(stacks->stack_b + 1, stacks->stack_b, \
		(stacks->stack_b_size - 1) * sizeof(int));
	stacks->stack_b[0] = temp;
}