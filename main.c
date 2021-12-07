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

//FIXME: da segfault cuando muere un philo y esta el atexit puesto, si es por que todos han comido, no pasa con los impares (a veces)
//TODO: mirar lo de la doble estructura
void	miraleaks(void)
{
	system("leaks philo");
}

void	*lets_die(void *argv)
{
	int		i;
	t_data	*data;
	time_t	time;
	int		count;

	data = (t_data *) argv;
	while (1)
	{
		i = 0;
		count = 0;
		while (i < data->number)
		{
			time = ft_gettime();
			pthread_mutex_lock(&data->print);
			if (data->philo[i].last_meal + data->tt_die < time)
				return (print_status(data->philo, time, data->philo[i].index, 4));
			pthread_mutex_unlock(&data->print);
			count += data->philo[i].full;
			if (count == data->number)
			{
				pthread_mutex_lock(&data->print);
				return (print_status(data->philo, time, data->philo[i].index, 5));
			}
			i++;
		}
	}
}

void	death_threads(t_data *data)
{
	pthread_create(&data->check_death, NULL, lets_die, data);
	pthread_join(data->check_death, NULL);
}

void	create_threads(t_data *data)
{
	int	i;

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
	int		i;

	i = 0;
	//atexit(miraleaks);
	if (check_errors(argc, argv))
		return (1);
	init_things(&data, argc, argv);
	init_philos(&data);
	if (data.meals != 0)
	{
		create_threads(&data);
		death_threads(&data);
	}
	free(data.philo);
	//system("leaks philo");
	return (0);
}
