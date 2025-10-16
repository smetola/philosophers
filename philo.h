/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanmetol <sanmetol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:03:46 by sanmetol          #+#    #+#             */
/*   Updated: 2025/02/12 13:03:46 by sanmetol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>

# define ERROR_INPUT "Error input. Ex: ./philo [n_of_philos]\
[time_to_die] [time_to_eat] [time_to_sleep]\
 ([n_times_each_philo_must_eat] is optional)\n"
# define ERROR_MAX "Invalid number of philosophers. Max: 200\n"
# define ERROR_ARGS "All arguments must be > 0 and < 2147483647.\n"
# define PHILO_MAX 200

typedef struct config
{
	size_t	time_to_die;
	size_t	time_to_eat;
	size_t	time_to_sleep;
	int		n_of_philos;
	int		n_times_must_eat;
}					t_config;

typedef struct philo
{
	pthread_t		thread_id;
	int				id;
	int				meals_eaten;
	t_config		input;
	size_t			start_time;
	size_t			last_meal_time;
	pthread_mutex_t	*mutex_log;
	pthread_mutex_t	*mutex_dead;
	pthread_mutex_t	*mutex_meal;
	int				*dead;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
}					t_philo;

typedef struct simulation
{
	int				dead_flag;
	t_philo			*philos;
	pthread_mutex_t	mutex_meal;
	pthread_mutex_t	mutex_log;
	pthread_mutex_t	mutex_dead;
}					t_sim;

long	ft_atol(const char *str);
void	init_simulation(t_sim *simulation, t_philo *philos);
void	init_forks(pthread_mutex_t *forks, int n_philo);
void	init_philo(t_philo *philos, t_sim *simulation,
			pthread_mutex_t *forks, char **argv);
size_t	get_current_time_ms(void);
int		dinner_threads(t_sim *simulation, pthread_mutex_t *forks);
void	*monitor_philo(void *ptr);
void	log_status(char *str, t_philo *philo, int id);
int		dead_loop(t_philo *philo);
void	cleanup(char *str, t_sim *simulation, pthread_mutex_t *forks);
void	ft_eat(t_philo *philo);
int		ft_usleep(t_philo *philo, size_t time_to_);
void	ft_sleep(t_philo *philo);
void	ft_think(t_philo *philo);

#endif