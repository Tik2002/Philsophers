/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 18:44:08 by tigpetro          #+#    #+#             */
/*   Updated: 2024/06/01 20:31:35 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static void	think(t_philo *philo)
{
	ft_print(philo, THINK);
}

static void	eat(t_philo *philo)
{
	printf("eat check\n");
	mutex_handle(&philo->first_f->fork, LOCK);
	// pthread_mutex_lock(&philo->first_f->fork);
	ft_print(philo, TAKE_FORK);
	mutex_handle(&philo->second_f->fork, LOCK);
	// pthread_mutex_lock(&philo->second_f->fork);
	ft_print(philo, TAKE_FORK);
	set_bool(&philo->philo_mutex, &philo->meal_time, get_time(MILLISECOND));
	philo->meal_counter++;
	ft_usleep(philo->table->time_to_eat, philo->table);
	if (philo->table->eat_cycle > 0 && philo->meal_counter == philo->table->eat_cycle)
		set_bool(&philo->philo_mutex, &philo->full, 1);
	mutex_handle(&philo->first_f->fork, UNLOCK);
	mutex_handle(&philo->second_f->fork, UNLOCK);
	// pthread_mutex_unlock(&philo->first_f->fork);
	// pthread_mutex_unlock(&philo->second_f->fork);
}

void	*sim_dinner(void *data)
{
	t_philo *philo;
	int i = 0;

	philo = (t_philo *)data;
	philos_gathered(philo->table);
	// printf("Gathered!\n");
	while (sim_finished(philo->table))
	{

		if (!philo->full)
			break ;
		eat(philo);
		// sleep(philo);
		ft_print(philo, SLEEP);
		ft_usleep(philo->table->time_to_sleep, philo->table);
		think(philo);
	}
	return (0);
}

void	start_dinner(t_table *table)
{
	int	i;

	i = -1;
	if (table->philos_number == 1)
		;
	else
	{
		while (++i < table->philos_number)
			thread_handle(&table->philo[i].thread_id, sim_dinner, &table->philo,
				CREATE);
	}
	table->sim_start = get_time(MILLISECOND);
	set_bool(&table->table_mutex, &table->philos_gathered, 1);
		printf("start dinner check\n");
	i = -1;
	while (++i < table->philos_number)
		thread_handle(&table->philo[i].thread_id, NULL, NULL,
			JOIN);
	printf("check dinner\n");
}
