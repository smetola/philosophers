/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanmetol <sanmetol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:02:33 by sanmetol          #+#    #+#             */
/*   Updated: 2025/02/12 13:03:08 by sanmetol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	log_status(char *str, t_philo *philo, int id)
{
	size_t	time;

	pthread_mutex_lock(philo->mutex_log);
	time = get_current_time_ms() - philo->start_time;
	if (!dead_loop(philo))
		printf("\033[1;38;2;96;168;235m%zums\033[0m\t \033[1;38;2;255;165;0m\
		[%d]\033[0m\t\033[1;38;2;238;232;224m%s\033[0m\n", time, id, str);
	pthread_mutex_unlock(philo->mutex_log);
}

static int	philo_dead(t_philo *philo, size_t time_to_die)
{
	pthread_mutex_lock(philo->mutex_meal);
	if (get_current_time_ms() - philo->last_meal_time >= time_to_die)
		return (pthread_mutex_unlock(philo->mutex_meal), 1);
	pthread_mutex_unlock(philo->mutex_meal);
	return (0);
}

static int	philos_full(t_philo *philos)
{
	int	i;
	int	is_full;

	i = 0;
	is_full = 0;
	if (philos[0].input.n_times_must_eat == -1)
		return (0);
	while (i < philos[0].input.n_of_philos)
	{
		pthread_mutex_lock(philos[i].mutex_meal);
		if (philos[i].meals_eaten >= philos[i].input.n_times_must_eat)
			is_full++;
		pthread_mutex_unlock(philos[i].mutex_meal);
		i++;
	}
	if (is_full == philos[0].input.n_of_philos)
	{
		pthread_mutex_lock(philos[0].mutex_dead);
		*philos->dead = 1;
		pthread_mutex_unlock(philos[0].mutex_dead);
		return (1);
	}
	return (0);
}

static int	check_dead(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos[0].input.n_of_philos)
	{
		if (philo_dead(&philos[i], philos[i].input.time_to_die))
		{
			log_status("died", &philos[i], philos[i].id);
			pthread_mutex_lock(philos[0].mutex_dead);
			*philos->dead = 1;
			pthread_mutex_unlock(philos[0].mutex_dead);
			return (1);
		}
		i++;
	}
	return (0);
}

void	*monitor_philo(void *ptr)
{
	t_philo	*philos;

	philos = (t_philo *)ptr;
	while (1)
		if (check_dead(philos) == 1 || philos_full(philos) == 1)
			break ;
	return (ptr);
}
