/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 18:44:08 by tigpetro          #+#    #+#             */
/*   Updated: 2024/06/07 14:03:34 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	think(t_philo *philo, short flag)
{
	long	t_eat;
	long	t_sleep;
	long	t_think;

	if (!flag)
		ft_print(philo, THINK);
	if (philo->table->philos_number % 2 == 0)
		return ;
	t_eat = philo->table->time_to_eat;
	t_sleep = philo->table->time_to_sleep;
	t_think = (t_eat * 2) - t_sleep;
	if (t_think < 0)
		t_think = 0;
	ft_usleep(t_think * 0.1, philo->table);
}

static void	eat(t_philo *philo)
{
	mutex_handle(&philo->first_f->fork, LOCK);
	ft_print(philo, TAKE_FORK);
	mutex_handle(&philo->second_f->fork, LOCK);
	ft_print(philo, TAKE_FORK);
	set_long(&philo->philo_mutex, &philo->meal_time, get_time(MILLISECOND));
	ft_print(philo, EAT);
	philo->meal_counter++;
	ft_usleep(philo->table->time_to_eat, philo->table);
	if (philo->table->eat_cycle > 0
		&& philo->meal_counter == philo->table->eat_cycle)
		set_bool(&philo->philo_mutex, &philo->full, 1);
	mutex_handle(&philo->first_f->fork, UNLOCK);
	mutex_handle(&philo->second_f->fork, UNLOCK);
}

static void	*alone(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	philos_gathered(philo->table);
	set_long(&philo->philo_mutex, &philo->meal_time, get_time(MILLISECOND));
	threads_counter(&philo->table->table_mutex, &philo->table->threads_number);
	ft_print(philo, TAKE_FORK);
	while (!sim_finished(philo->table))
		ft_usleep(200, philo->table);
	return (0);
}

static void	*sim_dinner(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	philos_gathered(philo->table);
	set_long(&philo->philo_mutex, &philo->meal_time, get_time(MILLISECOND));
	threads_counter(&philo->table->table_mutex, &philo->table->threads_number);
	de_synchronize_philos(philo);
	while (!sim_finished(philo->table))
	{
		if (get_bool(&philo->philo_mutex, &philo->full))
			break ;
		eat(philo);
		ft_print(philo, SLEEP);
		ft_usleep(philo->table->time_to_sleep, philo->table);
		think(philo, 0);
	}
	return (0);
}

void	start_dinner(t_table *table)
{
	int	i;

	i = -1;
	if (table->philos_number == 1)
		thread_handle(&table->philo[0].thread_id, alone, &table->philo[0],
			CREATE);
	else
		while (++i < table->philos_number)
			thread_handle(&table->philo[i].thread_id, sim_dinner,
				&table->philo[i], CREATE);
	thread_handle(&table->monitor, monitor_dinner, table, CREATE);
	table->sim_start = get_time(MILLISECOND);
	set_bool(&table->table_mutex, &table->philos_gathered, 1);
	i = -1;
	while (++i < table->philos_number)
		thread_handle(&table->philo[i].thread_id, NULL, NULL, JOIN);
	set_bool(&table->table_mutex, &table->sim_end, 1);
	thread_handle(&table->monitor, NULL, NULL, JOIN);
}
