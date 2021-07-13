#include "philo.h"

void	informer(t_philo *philo, char *s)
{
	pthread_mutex_lock(philo->info);
	printf("%lu %d %s", (get_time(philo->time) - philo->start), philo->id, s);
	pthread_mutex_unlock(philo->time);
}
