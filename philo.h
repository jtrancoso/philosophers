#ifndef PHILO_H
# define PHILO_H

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

typedef struct s_philo
{
	int	number;
	int	tt_die;
	int tt_eat;
	int tt_sleep;
	int	loop;

}		t_philo;

int	ft_isdigit(int c);
int	ft_atoi(const char *s);
int	check_errors(int argc, char **argv);
int	ft_error(int flag);




#endif
