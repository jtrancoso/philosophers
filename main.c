/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrancos <jtrancos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:55:47 by jtrancos          #+#    #+#             */
/*   Updated: 2021/12/06 16:55:47 by jtrancos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	miraleaks(void)
{
	system("leaks philo");
}

void	*lets_die(void *argv)
{
	int		i;
	t_data	*data;
	time_t	time;

	data = (t_data *) argv;
	while (1)
	{
		i = 0;
		while (i < data->number)
		{
			time = ft_gettime();
			pthread_mutex_lock(&data->print);
			printf("i: %d\n", i);
			printf("suma: %ld, time: %ld diff: %ld\n", data->philo[i].last_meal + data->tt_die, time, time - data->philo[i].last_meal + data->tt_die);
			if (data->philo[i].last_meal + data->tt_die < time)
				return (print_status(data->philo, time, data->philo[i].index, 4));
			pthread_mutex_unlock(&data->print);
			i++;
		}
	}
}

//TODO: mirar que paren los hilos cuando mueran

void	death_threads(t_data *data)
{
	pthread_create(&data->check_death, NULL, lets_die, data);
	pthread_join(data->check_death, NULL);
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
		pthread_detach(data->philo[i].thread);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;
	int i;

	i = 0;
	atexit(miraleaks);
	if (check_errors(argc, argv))
		return (1);
	init_things(&data, argc, argv);
	init_philos(&data);
	create_threads(&data);
	/*while (i < data.number)
	{
		pthread_join(data.philo[i].thread, NULL);
		i++;
	}*/
	death_threads(&data);
	printf("n: %d death: %d eat: %d sleep: %d loop: %d\n", data.number, data.tt_die, data.tt_eat, data.tt_sleep, data.loop);
	return (0);
}