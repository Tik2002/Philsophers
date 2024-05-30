/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 19:31:47 by tigpetro          #+#    #+#             */
/*   Updated: 2024/05/30 20:53:16 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>



void	philo(int ac, char **av)
{
	av++;
	ac++;
	// 	eat priority 0
	//	sleep usleep(5x) t_flag 1
	//	thinking t_flag = 0 priority++ usleep(x) mutex -> true
	// 	eat priorityn usleep
}

int	main(int ac, char **av)
{
	t_table	table;

	pars_philo(&table, ac, av);
	table_init(&table);
	start_dinner(&table);
	// destroy(&table);
	return (0);
}
