/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanmetol <sanmetol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:02:37 by sanmetol          #+#    #+#             */
/*   Updated: 2025/02/12 13:05:49 by sanmetol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	dead_loop(t_philo *philo)
{
	pthread_mutex_lock(philo->mutex_dead);
	if (*philo->dead == 1)
	{
		pthread_mutex_unlock(philo->mutex_dead);
		return (1);
	}
	pthread_mutex_unlock(philo->mutex_dead);
	return (0);
}

static void	*philo_routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (philo->id % 2 == 0)
		usleep(philo->input.time_to_eat);
	while (!dead_loop(philo))
	{
		ft_eat(philo);
		ft_sleep(philo);
		ft_think(philo);
	}
	return (ptr);
}

int	dinner_threads(t_sim *simulation, pthread_mutex_t *forks)
{
	pthread_t	monitor;
	int			i;

	if (pthread_create(&monitor, NULL, &monitor_philo, simulation->philos) != 0)
		cleanup("Thread creation error", simulation, forks);
	i = 0;
	while (i < simulation->philos[0].input.n_of_philos)
	{
		if (pthread_create(&simulation->philos[i].thread_id, NULL,
				&philo_routine, &simulation->philos[i]) != 0)
			cleanup("Thread creation error", simulation, forks);
		i++;
	}
	i = 0;
	if (pthread_join(monitor, NULL) != 0)
		cleanup("Thread join error", simulation, forks);
	while (i < simulation->philos[0].input.n_of_philos)
	{
		if (pthread_join(simulation->philos[i].thread_id, NULL) != 0)
			cleanup("Thread join error", simulation, forks);
		i++;
	}
	return (0);
}
