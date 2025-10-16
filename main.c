/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanmetol <sanmetol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:02:04 by sanmetol          #+#    #+#             */
/*   Updated: 2025/02/12 13:02:04 by sanmetol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_nbr(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (!(argv[i] >= '0' && argv[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

static int	check_args(int argc, char **argv)
{
	int		i;
	long	arg;

	if (argc != 5 && argc != 6)
	{
		printf("%s", ERROR_INPUT);
		return (1);
	}
	i = 1;
	while (argv[i])
	{
		arg = ft_atol(argv[i]);
		if (i == 1 && arg > 200)
		{
			printf(ERROR_MAX);
			return (1);
		}
		if (arg <= 0 || arg > INT_MAX || !is_nbr(argv[i]))
		{
			printf(ERROR_ARGS);
			return (1);
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_sim			simulation;
	t_philo			philos[PHILO_MAX];
	pthread_mutex_t	forks[PHILO_MAX];

	if (check_args(argc, argv) != 0)
		return (1);
	init_simulation(&simulation, philos);
	init_forks(forks, ft_atol(argv[1]));
	init_philo(philos, &simulation, forks, argv);
	dinner_threads(&simulation, forks);
	cleanup(NULL, &simulation, forks);
	return (0);
}
