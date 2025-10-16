/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanmetol <sanmetol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:02:42 by sanmetol          #+#    #+#             */
/*   Updated: 2025/02/12 13:04:46 by sanmetol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_think(t_philo *philo)
{
	log_status("is thinking", philo, philo->id);
	if (philo->input.n_of_philos % 2 != 0
		&& philo->input.time_to_eat * 2 > philo->input.time_to_sleep)
		ft_usleep(philo, philo->input.time_to_eat * 2
			- philo->input.time_to_sleep);
}

void	ft_sleep(t_philo *philo)
{
	log_status("is sleeping", philo, philo->id);
	ft_usleep(philo, philo->input.time_to_sleep);
}

static void	pick_forks(t_philo *philo)
{
	if (philo->id % 2 != 0)
		pthread_mutex_lock(philo->r_fork);
	else
		pthread_mutex_lock(philo->l_fork);
	log_status("has taken a fork", philo, philo->id);
	if (philo->id % 2 != 0)
		pthread_mutex_lock(philo->l_fork);
	else
		pthread_mutex_lock(philo->r_fork);
	log_status("has taken a fork", philo, philo->id);
}

void	ft_eat(t_philo *philo)
{
	if (philo->input.n_of_philos == 1)
	{
		pthread_mutex_lock(philo->l_fork);
		log_status("has taken a fork", philo, philo->id);
		ft_usleep(philo, philo->input.time_to_die);
		pthread_mutex_unlock(philo->l_fork);
		return ;
	}
	pick_forks(philo);
	log_status("is eating", philo, philo->id);
	pthread_mutex_lock(philo->mutex_meal);
	philo->last_meal_time = get_current_time_ms();
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->mutex_meal);
	ft_usleep(philo, philo->input.time_to_eat);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}
