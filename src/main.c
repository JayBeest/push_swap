#include <main.h>
#include <custom_sort.h>
#include <utils.h>
#include <parser.h>

#include <debug.h>

int	main(int argc, char **argv)
{
	t_ps_stacks	stacks;

	if (!init_stacks(&stacks, argc))
		return (1);
	if (!parse_arguments(argv, &stacks) || duplicates(stacks.stack_b, \
		stacks.amount_of_integers))
		return (free_stacks(&stacks, 1));
	nums_to_indexes(&stacks);
	if (is_sorted(stacks.stack_a, stacks.amount_of_integers))
		return (free_stacks(&stacks, 0));
	else
		sort(&stacks, stacks.amount_of_integers);
	return (free_stacks(&stacks, 0));
}
