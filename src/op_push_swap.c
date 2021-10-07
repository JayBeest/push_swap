/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorneli <marvin@codam.nl>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 17:16:08 by jcorneli          #+#    #+#             */
/*   Updated: 2021/10/07 17:16:08 by jcorneli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <op_push_swap.h>

void	pa_operation(t_ps_stacks *stacks)
{
	if (stacks->stack_b_size == 0)
		return ;
	ft_memmove(stacks->stack_a + 1, stacks->stack_a, \
		stacks->stack_a_size * sizeof(int));
	stacks->stack_a[0] = stacks->stack_b[0];
	stacks->stack_a_size++;
	stacks->stack_b_size--;
	ft_memmove(stacks->stack_b, stacks->stack_b + 1, \
		stacks->stack_b_size * sizeof(int));
}

void	pb_operation(t_ps_stacks *stacks)
{
	if (stacks->stack_a_size == 0)
		return ;
	ft_memmove(stacks->stack_b + 1, stacks->stack_b, \
		stacks->stack_b_size * sizeof(int));
	stacks->stack_b[0] = stacks->stack_a[0];
	stacks->stack_b_size++;
	stacks->stack_a_size--;
	ft_memmove(stacks->stack_a, stacks->stack_a + 1, \
		stacks->stack_a_size * sizeof(int));
}

void	sa_operation(t_ps_stacks *stacks)
{
	int	temp;

	if (stacks->stack_a_size < 2)
		return ;
	temp = stacks->stack_a[0];
	stacks->stack_a[0] = stacks->stack_a[1];
	stacks->stack_a[1] = temp;
}

void	sb_operation(t_ps_stacks *stacks)
{
	int	temp;

	if (stacks->stack_b_size < 2)
		return ;
	temp = stacks->stack_b[0];
	stacks->stack_b[0] = stacks->stack_b[1];
	stacks->stack_b[1] = temp;
}

