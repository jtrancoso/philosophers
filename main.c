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

int	main(int argc, char **argv)
{
	t_data	data;

	if (check_errors(argc, argv))
		return (1);
	init_things(&data, argc, argv);
	init_philos(&data);
	if (data.meals != 0)
	{
		eating_threads(&data);
		death_threads(&data);
	}
	if (data.philo)
		free(data.philo);
	return (0);
}
