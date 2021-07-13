#include "philo.h"

int	err_func(char *s)
{
	write(1, s, ft_strlen(s));
	return (1);
}
