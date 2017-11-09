
#include "fillit.h"

t_prog		*get_prog(void)
{
	static t_prog p;

	return (&p);
}

int			main(int ac, char **av)
{
	t_prog	*p;

	if (ac != 2)
		return (-1);
	p = get_prog();
	init(av[1], p);
	solve(p);
	print_map(p->map);
	return (0);
}
