/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorneli <marvin@codam.nl>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:22:56 by jcorneli          #+#    #+#             */
/*   Updated: 2021/10/07 16:22:56 by jcorneli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft.h>
#include <operations.h>
#include <op_push_swap.h>
#include <op_rotate.h>

void	rr_operation(t_ps_stacks *stacks)
{
	ra_operation(stacks);
	rb_operation(stacks);
}

void	ss_operation(t_ps_stacks *stacks)
{
	sa_operation(stacks);
	sb_operation(stacks);
}

void	rrr_operation(t_ps_stacks *stacks)
{
	rra_operation(stacks);
	rrb_operation(stacks);
}

void	print_op(t_operation op)
{
	static const char	*op_strings[11] = {
		[PA] = "pa\n",
		[PB] = "pb\n",
		[SA] = "sa\n",
		[SB] = "sb\n",
		[SS] = "ss\n",
		[RA] = "ra\n",
		[RB] = "rb\n",
		[RR] = "rr\n",
		[RRA] = "rra\n",
		[RRB] = "rra\n",
		[RRR] = "rrr\n"
	};

	write(1, op_strings[op] , ft_strlen(op_strings[op]));
}

void	exec_operation(t_ps_stacks *stacks, t_operation op)
{
	static const t_operation_ptr	fun_ptr[11] = {
			[PA] = pa_operation,
			[PB] = pb_operation,
			[SA] = sa_operation,
			[SB] = sb_operation,
			[SS] = ss_operation,
			[RA] = ra_operation,
			[RB] = rb_operation,
			[RR] = rr_operation,
			[RRA] = rra_operation,
			[RRB] = rra_operation,
			[RRR] = rrr_operation
	};

	fun_ptr[op](stacks);
	print_op(op);
}
