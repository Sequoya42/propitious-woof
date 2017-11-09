#include "fillit.h"

int             ft_sqrt(int n)
{
	int i;

	i = 2;
	while (i * i < n)
	{
		i++;
	}
	return (i);
}

int             find_first(char *s, char c, int start)
{
	while (s[start] && s[start] != c)
		start++;
	return (start);
}

int                             verify_pos(char *line, int i)
{
	int z;

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
}


void     swap_char(char *array, int i, int j){
	int tmp;

	tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
}

// https://www.nayuki.io/page/next-lexicographical-permutation-algorithm

int next_permutation(char *array) {
	int i;
	int j;
	int length;

	length = ft_strlen(array);
	i = length - 1;
	j = length - 1;
	while (i > 0 && array[i - 1] >= array[i]) {
		i--;
	}
	if (i == 0) {
		return 0;
		// return NULL;
	}
	// Find successor to pivot
	while (array[j] <= array[i - 1])
		j--;
	swap_char(array, i -1, j);

	j = length - 1;
	while (i < j) {
		swap_char(array, i, j);
		i++;
		j--;
	}
	return 1;
	// return array;
}
