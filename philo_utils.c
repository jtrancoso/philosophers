#include "philo.h"

int	ft_atoi(const char *s)
{
	int		neg;
	long	num;

	num = 0;
	neg = 1;
	while (*s == '\n' || *s == 32 || *s == 13
		|| *s == 9 || *s == 11 || *s == 12)
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			neg = neg * -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		num = (10 * num) + (*s - '0');
		s++;
		if ((neg * num) > 2147483647)
			return (-1);
		else if ((neg * num) < -2147483648)
			return (0);
	}
	return (num * neg);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_error(int flag)
{
	if (flag == 1)
		printf("Error. Invalid number of arguments\n");
	if (flag == 2)
		printf("Error. Invalid argument format\n");
	if (flag == 3)
		printf("Error. Number of philosophers cannot exceed 200\n");
	if (flag == 4)
		printf("Error. Time to die cannot be lower than 10\n");
	return (1);

}

int	check_errors(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (argc <= 4 || argc > 6)
		return(ft_error(1));
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (ft_error(2));
			j++;
		}
		i++;
	}
	if (ft_atoi(argv[1]) > 200)
		return (ft_error(3));
	if (ft_atoi(argv[2]) < 60)
		return (ft_error(4));
	return (0);
}
