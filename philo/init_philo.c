#include "philo.h"

void	fork_distribut(t_all *all, t_philo *philo, int i)
{
	if (iseven(i + 1))
	{
		philo[i].forks[0] = &(all->forks[i]);
		if (i == 0)
			philo[i].forks[1] = &(all->forks[all->param->nof - 1]);
		else
			philo[i].forks[1] = &(all->forks[i - 1]);
	}
	else
	{
		philo[i].forks[0] = &(all->forks[i - 1]);
		philo[i].forks[1] = &(all->forks[i]);
	}
}

t_philo	*init_philosophers(t_all *all)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)ft_calloc(all->param->nof, sizeof(t_philo));
	if (philo == NULL)
		return (NULL);
	i = 0;
	while (i < all->param->nof)
	{
		philo[i].id = i + 1;
		philo[i].state = 1;
		fork_distribut(all, philo, i);
		philo[i].info = all->info;
		philo[i].time = all->time;
		philo[i].thread = &(all->th[i]);
		philo[i].mon = (pthread_t *)malloc(sizeof(pthread_t));
		if (philo[i].mon == NULL)
			return (NULL);
		philo[i].param = all->param;
		i++;
	}
	return (philo);
}
