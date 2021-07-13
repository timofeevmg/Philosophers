#include "philo.h"

int	check_input(int ac)
{
	if (ac == 1)
	{
		write(1, NOARGS, ft_strlen(NOARGS));
		return (0);
	}
	else if (ac > 6)
	{
		write(1, MANYPAR, ft_strlen(MANYPAR));
		return (0);
	}
	else if (ac < 5)
	{
		write(1, FEEPAR, ft_strlen(FEEPAR));
		return (0);
	}
	return (1);
}

int	choose_param(t_param *param, int i)
{
	if (i == 1)
		return (param->nof);
	else if (i == 2)
		return (param->ttd);
	else if (i == 3)
		return (param->tte);
	else if (i == 4)
		return (param->tts);
	else if (i == 5)
		return (param->nte);
	else
		return (-1);
}

int	check_params(t_param *param, int ac, char **av)
{
	int		i;
	int		tmp;
	char	*check;

	i = 1;
	while (i < ac)
	{
		tmp = choose_param(param, i);
		check = ft_itoa(tmp);
		if (ft_strcmp(av[i], check))
		{
			free(check);
			return (0);
		}
		free(check);
		i++;
	}
	return (1);
}
