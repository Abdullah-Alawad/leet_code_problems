#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

int	check_arg(char *s)
{
	int		i;
	int		found_num;

	found_num = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
			found_num = 1;
		if ((s[i] != ' ' && s[i] != '-' && s[i] != '+' && (s[i] <= '0' || s[i] >= '9')) && found_num == 0)
			return (0);
		i++;
	}
	return (1);
}

int	myAtoi(char* s) {
	long long int	res;
	int				sign;
	int				i;
	int				len;
	char			*dup;
	
	if (!check_arg(s))
		return (0);
	i = 0;
	res = 0;
	sign = 1;
	while (s[i] == ' ')
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i] == '0')
		i++;
	dup = strdup(s + i);
	len = strlen(dup);
	if (len >= 19)
	{
		if (sign == -1)
			return (INT_MIN);
		else
			return (INT_MAX);
	}
	i = 0;
	while (dup[i] >= '0' && dup[i] <= '9')
	{
		res *= 10;
		res += dup[i] - '0';
		i++;
	}
	free(dup);
	if (res > INT_MAX)
		if (sign < 0)
			return (INT_MIN);
		else
			return (INT_MAX);
	return (res * sign);
}

int	main(void)
{
	int	n = atoi("   -00000000029864826"); // output: -29864826
	printf("number: %d\n", n);
}