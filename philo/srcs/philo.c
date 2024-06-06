/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 19:31:47 by tigpetro          #+#    #+#             */
/*   Updated: 2024/06/06 19:02:32 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	main(int ac, char **av)
{
	t_table	table;

	pars_philo(&table, ac, av);
	table_init(&table);
	start_dinner(&table);
	destroy(&table);
	return (0);
}
