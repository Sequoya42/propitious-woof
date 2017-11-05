#include "fillit.h"

int		ft_sqrt(int n)
{
	int	i;

	i = 2;
	while (i * i < n)
	{
		i++;
	}
	return (i);
}

int		find_first(char *s, char c, int start)
{
	while (s[start] != c)
		start++;
	return (start);
}

int				verify_pos(char *line, int i)
{
	int 		z;

	z = 0;
	if (line[i + 1] == '#')
		z++;
	if (line[i - 1] == '#')
		z++;
	if (line[i + 4] == '#')
		z++;
	if (line[i - 4] == '#')
		z++;
	return z;
	// if (((j == 0 || j == 3) && z >= 1) || z >= 2){
	// 	ft_putendl("IF");
	// 	ft_putnbrendl(j);
	// 	return (z);
	// }
	// else{
	// 	ft_putendl("ELSE");
	// 	ft_putnbrendl(j);
	// 	ft_putnbrendl(z);
	// 	return (0);
	// }
}
