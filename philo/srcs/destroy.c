/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:02:41 by tigpetro          #+#    #+#             */
/*   Updated: 2024/06/06 19:05:30 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	err(char *err_msg)
{
	printf("%s\n", err_msg);
	exit(1);
}

void	destroy(t_table *table)
{
	t_philo	*philo;
	int		i;

	i = -1;
	while (++i < table->philos_number)
	{
		philo = table->philo + i;
		mutex_handle(&philo->philo_mutex, DESTROY);
	}
	mutex_handle(&table->print_mutex, DESTROY);
	mutex_handle(&table->table_mutex, DESTROY);
	free(table->fork);
	free(table->philo);
}
