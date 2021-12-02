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

void *lets_eat(void *argv)
{
	t_data *data;
	time_t time;
	int i;

	i = 0;
	data = (t_data *) argv;
	usleep(60);
	while (i < data->number)
	{
		time = ft_gettime();
		printf("hola philo %d %ld\n", i, time);
		i++;
	}
}

void	create_threads(t_data *data)
{
	int i;

	i = 0;
	while (i < data->number)
	{
		pthread_create(&data->philo[i].thread, NULL, lets_eat, (void *)	data);
		pthread_detach(data->philo[i].thread);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;


	if (check_errors(argc, argv))
		return (1);
	init_things(&data, argc, argv);
	while (1)
	{
		create_threads(&data);
	}
	printf("n: %d death: %d eat: %d sleep: %d loop: %d\n", data.number, data.tt_die, data.tt_eat, data.tt_sleep, data.loop);
	return (0);
}