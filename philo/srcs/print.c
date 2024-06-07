/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 16:52:26 by tigpetro          #+#    #+#             */
/*   Updated: 2024/06/07 13:40:28 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	ft_print(t_philo *philo, t_print_mod mod)
{
	long	current_time;

	if (philo->full)
		return ;
	current_time = get_time(MILLISECOND) - philo->table->sim_start;
	if (get_bool(&philo->philo_mutex, &philo->full))
		return ;
	mutex_handle(&philo->table->print_mutex, LOCK);
	if (mod == TAKE_FORK && !sim_finished(philo->table))
		printf("%ld %d has taken a fork\n", current_time, philo->philo_id);
	else if (mod == EAT && !sim_finished(philo->table))
		printf("%ld %d is eating\n", current_time, philo->philo_id);
	else if (mod == SLEEP && !sim_finished(philo->table))
		printf("%ld %d is sleeping\n", current_time, philo->philo_id);
	else if (mod == THINK && !sim_finished(philo->table))
		printf("%ld %d is thinking\n", current_time, philo->philo_id);
	else if (mod == DIED)
		printf("%ld %d died\n", current_time, philo->philo_id);
	mutex_handle(&philo->table->print_mutex, UNLOCK);
}

// timestamp_in_ms X has taken a fork
// ◦ timestamp_in_ms X is eating
// ◦ timestamp_in_ms X is sleeping
// ◦ timestamp_in_ms X is thinking
// ◦ timestamp_in_ms X died
