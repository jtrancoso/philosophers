/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrancos <jtrancos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:55:44 by jtrancos          #+#    #+#             */
/*   Updated: 2021/12/06 16:55:44 by jtrancos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdlib.h>

typedef struct s_philo
{
	int				full;
	int				index;
	time_t			last_meal;
	pthread_t		thread;
	pthread_mutex_t	fork;

}				t_philo;

typedef struct s_data
{
	int				number;
	int				tt_die;
	int				tt_eat;
	int				tt_sleep;
	int				meals;
	int				control;
	time_t			start_time;
	pthread_t		check_death;
	pthread_mutex_t	print;
	t_philo			*philo;

}		t_data;

int		ft_isdigit(int c);
int		ft_atoi(const char *s);
int		check_errors(int argc, char **argv);
int		ft_error(int flag);
time_t	ft_gettime(void);
void	init_things(t_data *data, int argc, char **argv);
void	init_philos(t_data *data);
void	*print_status(t_data *data, long time, int num, int flag);
void	ft_sleep(time_t time);
void	ft_delay(t_data *data, int i);
void	eating_threads(t_data *data);
void	*lets_eat(void *argv);
void	take_fork(t_data *data, int i, int next);
void	sleep_think(t_data *data, int i, int next, int loop);
void	death_threads(t_data *data);
void	*lets_die(void *argv);

#endif
