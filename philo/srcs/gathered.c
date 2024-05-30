/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gathered.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 19:12:28 by tigpetro          #+#    #+#             */
/*   Updated: 2024/05/30 19:14:04 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	philos_gathered(t_table *table)
{
	while (!get_bool(&table->table_mutex, &table->philos_gathered))
		;
}
