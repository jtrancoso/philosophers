/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrancos <jtrancos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:58:28 by jtrancos          #+#    #+#             */
/*   Updated: 2021/12/07 17:29:37 by jtrancos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(t_philo *philo, int i, int next)
{
	pthread_mutex_lock(&philo->data->philo[i].fork);
	pthread_mutex_lock(&philo->data->print);
	print_status(philo, ft_gettime(), philo->data->philo[i].index, 0);
	pthread_mutex_unlock(&philo->data->print);
	pthread_mutex_lock(&philo->data->philo[next].fork);
	philo->last_meal = ft_gettime();
	pthread_mutex_lock(&philo->data->print);
	print_status(philo, philo->last_meal, philo->data->philo[i].index, 0);
	print_status(philo, philo->last_meal, philo->data->philo[i].index, 1);
	pthread_mutex_unlock(&philo->data->print);
	ft_sleep(philo->data->tt_eat);
}

void	sleep_think(t_philo *philo, int i, int next, int loop)
{
	if (philo->data->meals > 0 && loop == philo->data->meals)
		philo->full = 1;
	pthread_mutex_unlock(&philo->data->philo[next].fork);
	pthread_mutex_unlock(&philo->data->philo[i].fork);
	pthread_mutex_lock(&philo->data->print);
	print_status(philo, ft_gettime(), philo->data->philo[i].index, 2);
	pthread_mutex_unlock(&philo->data->print);
	ft_sleep(philo->data->tt_sleep);
	pthread_mutex_lock(&philo->data->print);
	print_status(philo, ft_gettime(), philo->data->philo[i].index, 3);
	pthread_mutex_unlock(&philo->data->print);
}

void	*lets_eat(void *argv)
{
	t_philo	*philo;
	int		order;
	int		next;
	int		loop;

	philo = (t_philo *) argv;
	order = philo->data->control++;
	loop = 0;
	ft_delay(philo, order);
	while (1)
	{
		if (philo->data->meals == -1 || philo->full == 0)
		{
			if (order == philo->data->number - 1)
				next = 0;
			else
				next = order + 1;
			take_fork(philo, philo->index, next);
			loop++;
			sleep_think(philo, philo->index, next, loop);
		}
		else
			return (NULL);
	}
	return (NULL);
}
