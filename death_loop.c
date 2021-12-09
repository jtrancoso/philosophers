/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrancos <jtrancos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 13:04:28 by jtrancos          #+#    #+#             */
/*   Updated: 2021/12/09 13:17:29 by jtrancos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
				return (print_status(data, time, i, 4));
			pthread_mutex_unlock(&data->print);
			count += data->philo[i].full;
			if (count == data->number)
				return (print_status(data, time, i, 5));
			i++;
		}
	}
}

void	death_threads(t_data *data)
{
	pthread_create(&data->check_death, NULL, lets_die, data);
	pthread_join(data->check_death, NULL);
}
