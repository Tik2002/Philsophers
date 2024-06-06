/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 16:52:26 by tigpetro          #+#    #+#             */
/*   Updated: 2024/06/06 17:47:30 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	ft_print(t_philo *philo, t_print_mod mod)
{
	long	current_time;

	if (philo->full)
		return ;
	current_time = get_time(MILLISECOND);
	mutex_handle(&philo->table->print_mutex, LOCK);
	if (mod == TAKE_FORK && !sim_finished(philo->table))
		printf("%-6ld philo N%d has taken a fork\n", current_time, philo->philo_id);
	else if (mod == EAT && !sim_finished(philo->table))
		printf("%-6ld philo N%d is eating\n", current_time, philo->philo_id);
	else if (mod == SLEEP && !sim_finished(philo->table))
		printf("%-6ld philo N%d is sleeping\n", current_time, philo->philo_id);
	else if (mod == THINK && !sim_finished(philo->table))
		printf("%-6ld philo N%d is thinking\n", current_time, philo->philo_id);
	else if (mod == DIED)
		printf("%-6ld philo N%d died\n", current_time, philo->philo_id);
	mutex_handle(&philo->table->print_mutex, UNLOCK);
}
