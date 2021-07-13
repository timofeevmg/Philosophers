#include "philo.h"

int	init_params(t_all *all, int ac, char **av)
{
	all->param = (t_param *)ft_calloc(1, sizeof(t_param));
	if (all->param == NULL)
		return (0);
	all->param->nof = ft_atoi(av[1]);
	all->param->ttd = ft_atoi(av[2]);
	all->param->tte = ft_atoi(av[3]);
	all->param->tts = ft_atoi(av[4]);
	all->param->nte = 0;
	all->param->nte_fl = 0;
	if (ac == 6)
	{
		all->param->nte = ft_atoi(av[5]);
		all->param->nte_fl = 1;
	}
	if (!check_params(all->param, ac, av) || \
	all->param->nof <= 0 || (all->param->nte_fl && all->param->nte <= 0) || \
	all->param->ttd < 0 || all->param->tte < 0 || all->param->tts < 0)
		return (0);
	return (1);
}

int	init_forks(t_all *all)
{
	int	i;

	all->forks = (pthread_mutex_t *)malloc(all->param->nof * \
	sizeof(pthread_mutex_t));
	if (all->forks == NULL)
		return (0);
	i = 0;
	while (i < all->param->nof)
	{
		if (pthread_mutex_init(&(all->forks[i]), NULL))
			return (0);
		i++;
	}
	return (1);
}

int	add_mutexes(t_all *all)
{
	all->info = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (all->info == NULL)
		return (0);
	if (pthread_mutex_init(all->info, NULL))
		return (0);
	all->stop = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (all->stop == NULL)
		return (0);
	if (pthread_mutex_init(all->stop, NULL))
		return (0);
	all->time = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (all->time == NULL)
		return (0);
	if (pthread_mutex_init(all->time, NULL))
		return (0);
	return (1);
}

int	init_thread(t_all *all)
{
	all->th = (pthread_t *)malloc(all->param->nof * sizeof(pthread_t));
	if (all->th == NULL)
		return (0);
	return (1);
}

int	init_main_struct(t_all *all, int ac, char **av)
{
	if (!init_params(all, ac, av))
		return (0);
	if (!init_forks(all))
		return (0);
	if (!add_mutexes(all))
		return (0);
	if (!init_thread(all))
		return (0);
	return (1);
}
