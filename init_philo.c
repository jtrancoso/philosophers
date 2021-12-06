/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrancos <jtrancos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:54:33 by jtrancos          #+#    #+#             */
/*   Updated: 2021/12/06 16:55:21 by jtrancos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_things(t_data *data, int argc, char **argv)
{
	data->loop = 0;
	data->control = 0;
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