#include <main.h>
#include <checker.h>
#include <parser.h>
#include <debug.h>
#include <utils.h>

int	main(int argc, char **argv)
{
	t_ps_stacks	stacks;

	if (!init_stacks(&stacks, argc))
		return (1);
	if (!parse_arguments(argv, &stacks) || duplicates(stacks.stack_b, stacks.amount_of_integers))
		return (free_stacks(&stacks, 1));
	nums_to_indexes(&stacks);
	print_stack(stacks.stack_a, stacks.stack_a_size);
	return (free_stacks(&stacks, 0));
}
