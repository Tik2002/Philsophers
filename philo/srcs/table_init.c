/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 22:26:33 by tigpetro          #+#    #+#             */
/*   Updated: 2024/07/22 23:26:48 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static void	assaign_forks(t_philo *philo, t_fork *fork, int index)
{
	int	nbr;

	nbr = philo->table->philos_number;
	if (philo->philo_id % 2 == 0)
	{
		philo->first_f = &fork[index];
		philo->second_f = &fork[(index + 1) % nbr];
	}
	else
	{
		philo->first_f = &fork[(index + 1) % nbr];
		philo->second_f = &fork[index];
	}
}

static void	philo_init(t_table *table)
{
	int		i;
	t_philo	*philo;

	i = -1;
	while (++i < table->philos_number)
	{
		philo = table->philo + i;
		philo->philo_id = i + 1;
		philo->meal_counter = 0;
		mutex_handle(&philo->philo_mutex, INIT);
		philo->table = table;
		philo->full = 0;
		assaign_forks(philo, table->fork, i);
	}
}

void	table_init(t_table *table)
{
	int	i;

	i = -1;
	table->sim_end = 0;
	table->philos_gathered = 0;
	table->threads_number = 0;
	table->philo = wrapper_init(sizeof(t_philo) * (table->philos_number));
	table->fork = wrapper_init(sizeof(t_fork) * (table->philos_number));
	mutex_handle(&table->table_mutex, INIT);
	mutex_handle(&table->print_mutex, INIT);
	while (++i < table->philos_number)
	{
		mutex_handle(&table->fork[i].fork, INIT);
		table->fork[i].fork_id = i;
	}
	philo_init(table);
}
