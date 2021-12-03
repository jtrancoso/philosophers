#ifndef PHILO_H
# define PHILO_H

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdlib.h>

typedef struct	s_philo
{
	int				full;
	int				index;
	time_t			last_meal;
	pthread_t		thread;
	pthread_mutex_t	fork;
	struct s_data	*data;
}				t_philo;

typedef struct s_data
{
	int				number;
	int				tt_die;
	int				tt_eat;
	int				tt_sleep;
	int				loop;
	time_t			start_time;
	pthread_mutex_t	print;
	t_philo			*philo;

}		t_data;

int	ft_isdigit(int c);
int	ft_atoi(const char *s);
int	check_errors(int argc, char **argv);
int	ft_error(int flag);




#endif
