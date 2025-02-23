#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

void	count_symbols(char *s, int *d, int *p, int *m, int *e)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '.')
			(*d)++;
		else if (s[i] == '+')
			(*p)++;
		else if (s[i] == '-')
			(*m)++;
		else if (s[i] == 'e' || s[i] == 'E')
			(*e)++;
		i++; 
	}
}

int	check_chars(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ( (s[i] >= '0' && s[i] <= '9') || s[i] == 'e' ||
				s[i] == 'E' || s[i] == '.' || s[i] == '+' || s[i] == '-')
			i++;
		else
			return (0);
	}
	return (1);
}

bool	isNumber(char* s)
{
	int	len;
	int	dot_num = 0;
	int	plus_num = 0;
	int	minus_num = 0;
	int	e_num = 0;

	len = strlen(s);
	if (len == 0)
		return (false);
	if (len == 1)
		return (*s >= '0' && *s <= '9');
	if (!check_chars(s));
		return (false);
	count_symbols(s, &dot_num, &plus_num, &minus_num, &e_num);
	if (e_num > 1)
		return (false);
	if (e_num == 0 && ((plus_num + minus_num) > 1))
		return (false);
	if (dot_num > 1)
		return (false);
	
	return (1);
	
}

int	main(int argc, char **argv)
{
	printf("valid? %d\n", isNumber(argv[1]));
}