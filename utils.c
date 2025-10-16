/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanmetol <sanmetol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:02:27 by sanmetol          #+#    #+#             */
/*   Updated: 2025/02/12 13:02:27 by sanmetol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_usleep(t_philo *philo, size_t time_to_)
{
	size_t	start;

	start = get_current_time_ms();
	while ((get_current_time_ms() - start) < time_to_)
	{
		pthread_mutex_lock(philo->mutex_dead);
		if (*philo->dead)
		{
			pthread_mutex_unlock(philo->mutex_dead);
			return (1);
		}
		pthread_mutex_unlock(philo->mutex_dead);
		usleep(200);
	}
	return (0);
}

void	cleanup(char *str, t_sim *simulation, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	if (str)
		printf("%s\n", str);
	pthread_mutex_destroy(&simulation->mutex_meal);
	pthread_mutex_destroy(&simulation->mutex_log);
	pthread_mutex_destroy(&simulation->mutex_dead);
	while (i < simulation->philos[0].input.n_of_philos)
		pthread_mutex_destroy(&forks[i++]);
}

size_t	get_current_time_ms(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

long	ft_atol(const char *str)
{
	long	n;
	int		i;
	int		neg;

	i = 0;
	n = 0;
	neg = 1;
	while ((str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		&& str[i])
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = str[i] - '0' + n * 10;
		i++;
	}
	return (n * neg);
}
