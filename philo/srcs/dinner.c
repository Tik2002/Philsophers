/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 18:44:08 by tigpetro          #+#    #+#             */
/*   Updated: 2024/05/30 20:52:39 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	*sim_dinner(void *data)
{
	t_philo *philo;

	philo = (t_philo *)data;
	philos_gathered(philo->table);
	while (sim_finished(philo->table))
	{
		if (!philo->full)
			break ;
		// eat();
		// sleep();
		// think();
	}
	return (0);
}

void	start_dinner(t_table *table)
{
	int	i;

	i = -1;
	// if (!table->eat_cycle)
	// 	return ;
	if (table->philos_number == 1)
		;
	else
	{
		while (++i < table->eat_cycle)
			thread_handle(&table->philo[i].philo_id, sim_dinner, &table->philo,
				CREATE);
	}
	table->sim_start = get_time(MILLISECOND);
	set_bool(&table->table_mutex, &table->philos_gathered, 1);
	while (++i < table->eat_cycle)
		thread_handle(&table->philo[i].philo_id, NULL, NULL,
			JOIN);

}
