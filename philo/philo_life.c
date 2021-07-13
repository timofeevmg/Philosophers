#include "philo.h"

void	life_loop(t_philo *philo)
{
	while (philo->state)
	{
		pthread_mutex_lock(philo->forks[0]);
		informer(philo, FORK);
		pthread_mutex_unlock(philo->info);
		pthread_mutex_lock(philo->forks[1]);
		informer(philo, FORK);
		pthread_mutex_unlock(philo->info);
		philo->cte++;
		philo->meal = get_time(philo->time);
		pthread_mutex_unlock(philo->time);
		informer(philo, EAT);
		pthread_mutex_unlock(philo->info);
		ft_sleep(philo->time, philo->param->tte);
		pthread_mutex_unlock(philo->forks[1]);
		pthread_mutex_unlock(philo->forks[0]);
		informer(philo, SLEEP);
		pthread_mutex_unlock(philo->info);
		ft_sleep(philo->time, philo->param->tts);
		informer(philo, THINK);
		pthread_mutex_unlock(philo->info);
		if (philo->param->nte_fl && philo->cte == philo->param->nte)
			return ;
	}
}

void	*monitor(void *arg)
{
	t_philo	*philo;
	time_t	t;

	philo = (t_philo *)arg;
	if (pthread_detach(*(philo->mon)))
		return (NULL);
	while (1)
	{
		t = get_time(philo->time);
		pthread_mutex_unlock(philo->time);
		if (t > philo->meal + philo->param->ttd)
		{
			philo->state = 0;
			informer(philo, DIED);
			break ;
		}
		else if (philo->param->nte_fl && philo->cte == philo->param->nte)
		{
			philo->state = 2;
			break ;
		}
	}
	return (NULL);
}

void	*life(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	if (pthread_create(philo->mon, NULL, &monitor, philo))
		return (NULL);
	if (pthread_detach(*philo->thread))
		return (NULL);
	life_loop(philo);
	return (NULL);
}
