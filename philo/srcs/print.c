/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 16:52:26 by tigpetro          #+#    #+#             */
/*   Updated: 2024/07/22 23:26:32 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	ft_print(t_philo *philo, t_print_mod mod)
{
	long	current_time;

	if (get_bool(&philo->philo_mutex, &philo->full))
		return ;
	mutex_handle(&philo->table->print_mutex, LOCK);
	current_time = get_time(MILLISECOND) - philo->table->sim_start;
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
