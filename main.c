#include "philo.h"

time_t ft_gettime(void)
{
	struct timeval	time;
	
	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	init_things(t_philo *philo, int argc, char **argv)
{
	philo->loop = 0;
	philo->number = ft_atoi(argv[1]);
	philo->tt_die = ft_atoi(argv[2]);
	philo->tt_eat = ft_atoi(argv[3]);
	philo->tt_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		philo->loop = ft_atoi(argv[5]);
}

int	main(int argc, char **argv)
{
	t_philo	philo;
	time_t time;

	time = ft_gettime();
	printf("time: %ld\n", time);
	if (check_errors(argc, argv))
		return (1);
	init_things(&philo, argc, argv);
	time = ft_gettime();
	printf("time2: %ld\n", time);
	printf("n: %d death: %d eat: %d sleep: %d loop: %d\n", philo.number, philo.tt_die, philo.tt_eat, philo.tt_sleep, philo.loop);
	return (0);
}