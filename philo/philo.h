#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

# define ERR		"Error occured\n"
# define NOARGS		"No parameters\n"
# define MANYPAR	"Number of parameters is more than 5\n"
# define FEEPAR		"Number of parameters is less than 4\n"

# define FORK	"has taken a fork\n"
# define EAT	"is eating\n"
# define SLEEP	"is sleeping\n"
# define THINK	"is thinking\n"
# define DIED	"died\n"

# define STATE_ZERO		0
# define STATE_DEAD		1
# define STATE_FULL		2

typedef struct s_param
{
	int		nof;
	time_t	ttd;
	time_t	tte;
	time_t	tts;
	int		nte;
	int		nte_fl;
}	t_param;

typedef struct s_filo
{
	int				id;
	int				state;
	int				cte;
	time_t			start;
	time_t			meal;
	pthread_mutex_t	*forks[2];
	pthread_mutex_t	*info;
	pthread_mutex_t	*time;
	pthread_t		*thread;
	pthread_t		*mon;
	t_param			*param;
}	t_philo;

typedef struct s_all
{
	t_param			*param;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*info;
	pthread_mutex_t	*stop;
	pthread_mutex_t	*time;
	pthread_t		*th;
	t_philo			*philo;
	time_t			start;
}	t_all;

//utils
int		ft_strlen(char *str);
void	*ft_calloc(size_t n, size_t s);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
int		ft_strcmp(const char *s1, const char *s2);
int		iseven(int id);
void	ft_sleep(pthread_mutex_t *time, unsigned long t);
void	informer(t_philo *philo, char *s);
time_t	get_time(pthread_mutex_t *time);
void	clean_all(t_all *all);
void	clear_all(t_all *all);
int		err_func(char *s);
//

int		check_input(int ac);
int		init_main_struct(t_all *all, int ac, char **av);
int		init_params(t_all *all, int ac, char **av);
int		check_params(t_param *param, int ac, char **av);
int		choose_param(t_param *param, int i);
int		init_forks(t_all *all);
int		add_mutexes(t_all *all);
int		init_thread(t_all *all);
int		meetup(t_all *all);
t_philo	*init_philosophers(t_all *all);
int		philosophers_threads_start(t_all *all);
int		dead_or_full(t_all *all);
void	fork_distribut(t_all *all, t_philo *philo, int i);
void	*life(void *arg);
void	*monitor(void *arg);
void	life_loop(t_philo *philo);

#endif