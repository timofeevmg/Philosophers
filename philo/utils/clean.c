#include "philo.h"

void	clean_all(t_all *all)
{
	if (all->param)
		free(all->param);
	if (all->forks)
		free(all->forks);
	if (all->th)
		free(all->th);
	if (all)
		free(all);
}

void	clear_all(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->param->nof)
	{
		free(all->philo[i].mon);
		i++;
	}
	free(all->philo);
	i = 0;
	while (i < all->param->nof)
	{
		pthread_mutex_destroy(&(all->forks[i]));
		i++;
	}
	pthread_mutex_destroy(all->info);
	pthread_mutex_destroy(all->stop);
	pthread_mutex_destroy(all->time);
	free(all->th);
	free(all->param);
	free(all);
}
