/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanmetol <sanmetol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:02:01 by sanmetol          #+#    #+#             */
/*   Updated: 2025/02/12 13:03:01 by sanmetol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_input(t_philo *philo, char **argv)
{
	philo->input.time_to_die = ft_atol(argv[2]);
	philo->input.time_to_eat = ft_atol(argv[3]);
	philo->input.time_to_sleep = ft_atol(argv[4]);
	philo->input.n_of_philos = ft_atol(argv[1]);
	if (argv[5])
		philo->input.n_times_must_eat = ft_atol(argv[5]);
	else
		philo->input.n_times_must_eat = -1;
}

void	init_philo(t_philo *philos, t_sim *simulation, pthread_mutex_t *forks,
		char **argv)
{
	int	i;

	i = 0;
	while (i < (int)ft_atol(argv[1]))
	{
		philos[i].id = i + 1;
		philos[i].meals_eaten = 0;
		init_input(&philos[i], argv);
		philos[i].start_time = get_current_time_ms();
		philos[i].last_meal_time = get_current_time_ms();
		philos[i].mutex_log = &simulation->mutex_log;
		philos[i].mutex_dead = &simulation->mutex_dead;
		philos[i].mutex_meal = &simulation->mutex_meal;
		philos[i].dead = &simulation->dead_flag;
		philos[i].l_fork = &forks[i];
		if (i == 0)
			philos[i].r_fork = &forks[philos[0].input.n_of_philos - 1];
		else
			philos[i].r_fork = &forks[i - 1];
		i++;
	}
}

void	init_forks(pthread_mutex_t *forks, int n_philo)
{
	int	i;

	i = 0;
	while (i < n_philo)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

void	init_simulation(t_sim *simulation, t_philo *philos)
{
	simulation->dead_flag = 0;
	simulation->philos = philos;
	pthread_mutex_init(&simulation->mutex_meal, NULL);
	pthread_mutex_init(&simulation->mutex_log, NULL);
	pthread_mutex_init(&simulation->mutex_dead, NULL);
}
