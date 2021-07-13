#include "philo.h"

void	ft_sleep(pthread_mutex_t *time, unsigned long t)
{
	unsigned long	start;
	unsigned long	stop;

	start = get_time(time);
	pthread_mutex_unlock(time);
	stop = start + t;
	while (1)
	{
		if (get_time(time) >= stop)
		{
			pthread_mutex_unlock(time);
			break ;
		}
		pthread_mutex_unlock(time);
		usleep(500);
	}
}
