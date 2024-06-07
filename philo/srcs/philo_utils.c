/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 19:34:31 by tigpetro          #+#    #+#             */
/*   Updated: 2024/06/07 13:59:13 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	ft_usleep(long usec, t_table *table)
{
	long	start;
	long	elapsed;
	long	rem;

	start = get_time(MICROSECOND);
	while (get_time(MICROSECOND) - start < usec)
	{
		if (sim_finished(table))
			break ;
		elapsed = get_time(MICROSECOND) - start;
		rem = usec - elapsed;
		if (rem > 1e3)
			usleep (usec / 2);
		else
			while (get_time(MICROSECOND) - start < usec);
	}
}

long	get_time(t_time_mod time_mod)
{
	struct timeval time;

	if (gettimeofday(&time, NULL) == -1)
		err("gettimeofday error");
	if (time_mod == SECOND)
		return (time.tv_sec + time.tv_usec / 1e6);
	else if (time_mod == MILLISECOND)
		return (1e3 * time.tv_sec + time.tv_usec / 1e3);
	else if (time_mod == MICROSECOND)
		return (1e6 * time.tv_sec + time.tv_usec);
	err("Wrong time_mod");
	return (42);
}

static long	philo_died(t_philo *philo)
{
	long	elapsed;
	long	t_to_die;

	if (get_bool(&philo->philo_mutex, &philo->full))
		return (0);
	elapsed = get_time(MILLISECOND) - get_long(&philo->philo_mutex,
			&philo->meal_time);
	t_to_die = philo->table->time_to_die / 1e3;
	if (elapsed > t_to_die)
		return (1);
	return (0);
}

void	*monitor_dinner(void *data)
{
	t_table	*table;
	int		i;

	table = (t_table *)data;

	while (!threads_running(&table->table_mutex, &table->threads_number, table->philos_number))
		;
	while (!sim_finished(table))
	{
		i = -1;
		while (++i < table->philos_number && !sim_finished(table))
		{
			if (philo_died(table->philo + i))
			{
				set_bool(&table->table_mutex, &table->sim_end, 1);
				ft_print(table->philo + i, DIED);
			}
		}
	}

	return (0);
}
