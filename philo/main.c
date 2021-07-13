#include "philo.h"

int	philosophers_threads_start(t_all *all)
{
	int		i;
	time_t	t;

	t = get_time(all->time);
	if (pthread_mutex_unlock(all->time))
		return (0);
	all->philo[0].start = t;
	all->philo[0].meal = t;
	if (pthread_create(&(all->th[0]), NULL, &life, &(all->philo[0])))
		return (0);
	i = 0;
	while (i < all->param->nof)
	{
		all->philo[i].start = t;
		all->philo[i].meal = t;
		if (pthread_create(&(all->th[i]), NULL, &life, &(all->philo[i])))
			return (0);
		i++;
	}
	return (1);
}

int	dead_or_full(t_all *all)
{
	int	i;
	int	count;

	while (1)
	{
		i = 0;
		count = 0;
		while (i < all->param->nof)
		{
			if (!all->philo[i].state)
			{
				pthread_mutex_unlock(all->stop);
				return (1);
			}
			else if (all->philo[i].state == 2)
				count++;
			if (count == all->param->nof)
				return (1);
			i++;
		}
	}
	return (0);
}

int	meetup(t_all *all)
{
	int	i;

	all->philo = init_philosophers(all);
	if (!all->philo)
		return (0);
	if (!philosophers_threads_start(all))
		return (0);
	if (dead_or_full(all))
		return (1);
	return (1);
}

int	main(int ac, char **av)
{
	t_all		*all;

	if (!check_input(ac))
		return (1);
	all = (t_all *)ft_calloc(1, sizeof(t_all));
	if (!all)
		return (err_func(ERR));
	if (!init_main_struct(all, ac, av))
	{
		clean_all(all);
		return (err_func(ERR));
	}
	if (!meetup(all))
	{
		clean_all(all);
		return (err_func(ERR));
	}
	pthread_mutex_lock(all->stop);
	usleep(1000000);
	clear_all(all);
	return (0);
}
