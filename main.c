#include "philo.h"

time_t ft_gettime(void)
{
	struct timeval	time;
	
	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	init_things(t_data *data, int argc, char **argv)
{
	data->loop = 0;
	data->number = ft_atoi(argv[1]);
	data->tt_die = ft_atoi(argv[2]);
	data->tt_eat = ft_atoi(argv[3]);
	data->tt_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->loop = ft_atoi(argv[5]);
	data->start_time = ft_gettime();
}

void	init_philos(t_data *data)
{
	int i;

	i = 0;
	data->philo = malloc(sizeof(t_philo) * data->number);
	while (i < data->number)
	{
		data->philo[i].last_meal = ft_gettime();
		data->philo[i].full = 0;
		pthread_mutex_init(&data->philo[i].fork, NULL);
		i++;
	}
	pthread_mutex_init(&data->print, NULL);
}

void	print_status(t_philo *philo, int num, int flag)
{
	time_t time;

	time = philo->last_meal - philo->data->start_time;
	num += 1;
	if (flag == 0)
		printf("%ld Philo %d has taken a fork\n", time, num);
}

void	take_fork(t_philo *philo, time_t time, int i)
{
	pthread_mutex_lock(&philo->data->philo[i].fork);
	pthread_mutex_lock(&philo->data->print);
	print_status(philo, philo->data->philo[i].index, 0);
	pthread_mutex_unlock(&philo->data->philo[i].fork);
	pthread_mutex_unlock(&philo->data->print);
}

void *lets_eat(void *argv)
{
	t_philo	*philo;
	time_t	time;
	int		order;

	order = 1;
	philo = (t_philo *) argv;
	while (1)
	{
		time = ft_gettime();
		if (philo->last_meal - time > philo->data->tt_die)
		{
			printf("philo %d dice: \"me muero\"\n", philo->index);
			break ;
		}
		take_fork(philo, time, philo->index);
		philo->last_meal = time;
		//printf("hola philo %d %ld\n", philo->index, philo->last_meal);
	}
	return (NULL);
}


void	create_threads(t_data *data)
{
	int i;

	i = 0;
	while (i < data->number)
	{
		data->philo[i].index = i;
		data->philo[i].data = data;
		pthread_create(&data->philo[i].thread, NULL, lets_eat, &data->philo[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;
	int i;

	i = 0;
	if (check_errors(argc, argv))
		return (1);
	init_things(&data, argc, argv);
	init_philos(&data);
	create_threads(&data);
	while (i < data.number)
	{
		pthread_join(data.philo[i].thread, NULL);
		i++;
	}
	printf("n: %d death: %d eat: %d sleep: %d loop: %d\n", data.number, data.tt_die, data.tt_eat, data.tt_sleep, data.loop);
	return (0);
}