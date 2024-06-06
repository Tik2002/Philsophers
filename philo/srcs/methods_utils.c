/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   methods_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 19:12:28 by tigpetro          #+#    #+#             */
/*   Updated: 2024/06/06 19:13:33 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	philos_gathered(t_table *table)
{
	while (!get_bool(&table->table_mutex, &table->philos_gathered))
		;
}

long	threads_running(t_mtx *mutex, long *threads, long philo_number)
{
	long res;

	res = 0;
	mutex_handle(mutex, LOCK);
	if (*threads == philo_number)
		res = 1;
	mutex_handle(mutex, UNLOCK);
	return (res);
}

void	threads_counter(t_mtx *mutex, long *value)
{
	mutex_handle(mutex, LOCK);
	(*value)++;
	mutex_handle(mutex, UNLOCK);
}

void	de_synchronize_philos(t_philo *philo)
{
	if (philo->table->philos_number % 2 == 0)
	{
		if (philo->philo_id % 2 == 0)
			ft_usleep(3e4, philo->table);
	}
	else
	{
		if (philo->philo_id % 2)
			think(philo, 1);
	}
}
