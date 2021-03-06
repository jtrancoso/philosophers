/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrancos <jtrancos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:56:02 by jtrancos          #+#    #+#             */
/*   Updated: 2021/12/09 13:17:26 by jtrancos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*print_status(t_data *data, long time, int num, int flag)
{
	time_t	print_time;

	print_time = time - data->start_time;
	num += 1;
	if (flag == 0)
		printf("%ld Philo %d has taken a fork\n", print_time, num);
	if (flag == 1)
		printf("%ld Philo %d is eating\n", print_time, num);
	if (flag == 2)
		printf("%ld Philo %d is sleeping\n", print_time, num);
	if (flag == 3)
		printf("%ld Philo %d is thinking\n", print_time, num);
	if (flag == 4)
		printf("%ld Philo %d has died\n", print_time, num);
	if (flag == 5)
	{
		pthread_mutex_lock(&data->print);
		printf("%ld All philosophers have eaten %d times\n", \
		print_time, data->meals);
	}
	return (NULL);
}

void	ft_sleep(time_t time)
{
	time_t	total_time;
	time_t	rest_time;

	total_time = ft_gettime() + time;
	rest_time = ft_gettime();
	while (total_time > rest_time)
	{
		usleep(60);
		rest_time = ft_gettime();
	}
}

void	ft_delay(t_data *data, int i)
{
	if (i % 2 != 0)
		ft_sleep(data->tt_eat);
}
