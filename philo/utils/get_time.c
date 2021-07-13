#include "philo.h"

time_t	get_time(pthread_mutex_t *time)
{
	struct timeval	t;

	pthread_mutex_lock(time);
	gettimeofday(&t, NULL);
	return (t.tv_sec * 1000 + t.tv_usec / 1000);
}
