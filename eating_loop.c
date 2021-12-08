/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrancos <jtrancos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:58:28 by jtrancos          #+#    #+#             */
/*   Updated: 2021/12/08 14:05:36 by jtrancos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(t_data *data, int i, int next)
{
	pthread_mutex_lock(&data->philo[i].fork);
	pthread_mutex_lock(&data->print);
	print_status(data, ft_gettime(), i, 0);
	pthread_mutex_unlock(&data->print);
	pthread_mutex_lock(&data->philo[next].fork);
	data->philo[i].last_meal = ft_gettime();
	pthread_mutex_lock(&data->print);
	print_status(data, data->philo[i].last_meal, i, 0);
	print_status(data, data->philo[i].last_meal, i, 1);
	pthread_mutex_unlock(&data->print);
	ft_sleep(data->tt_eat);
}

void	sleep_think(t_data *data, int i, int next, int loop)
{
	if (data->meals > 0 && loop == data->meals)
		data->philo[i].full = 1;
	pthread_mutex_unlock(&data->philo[next].fork);
	pthread_mutex_unlock(&data->philo[i].fork);
	pthread_mutex_lock(&data->print);
	print_status(data, ft_gettime(), i, 2);
	pthread_mutex_unlock(&data->print);
	ft_sleep(data->tt_sleep);
	pthread_mutex_lock(&data->print);
	print_status(data, ft_gettime(), i, 3);
	pthread_mutex_unlock(&data->print);
}

void	*lets_eat(void *argv)
{
	t_data	*data;
	int		order;
	int		next;
	int		loop;

	data = (t_data *) argv;
	order = data->control++;
	loop = 0;
	ft_delay(data, order);
	while (1)
	{
		if (data->meals == -1 || data->philo[order].full == 0)
		{
			if (order == data->number - 1)
				next = 0;
			else
				next = order + 1;
			take_fork(data, order, next);
			loop++;
			sleep_think(data, order, next, loop);
		}
		else
			return (NULL);
	}
	return (NULL);
}
