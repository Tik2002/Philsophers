/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 19:31:47 by tigpetro          #+#    #+#             */
/*   Updated: 2024/05/27 22:21:42 by tigpetro         ###   ########.fr       */
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
	t_proc	table;

	pars_philo(&table, ac, av);
	// init(&table);
	// diner(&table);
	// destroy(&table);
	return (0);
}
