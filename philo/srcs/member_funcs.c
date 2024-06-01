/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   member_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 19:00:02 by tigpetro          #+#    #+#             */
/*   Updated: 2024/06/01 20:31:58 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	set_bool(t_mtx *mtx, long *dest, long value)
{
	mutex_handle(mtx, LOCK);
	*dest = value;
	mutex_handle(mtx, UNLOCK);
}

long	get_bool(t_mtx *mtx, long *value)
{
	long res;

	printf("get_bool lock\n");
	mutex_handle(mtx, LOCK);
	// pthread_mutex_lock(mtx);
	res = *value;
	// pthread_mutex_unlock(mtx);
	// printf("get_bool unlock\n");
	mutex_handle(mtx, UNLOCK);
	return (res);
}

int	sim_finished(t_table *table)
{
	return (get_bool(&table->table_mutex, &table->sim_end));
}
