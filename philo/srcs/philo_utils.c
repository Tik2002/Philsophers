/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 19:34:31 by tigpetro          #+#    #+#             */
/*   Updated: 2024/05/30 21:01:14 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	err(char *err_msg)
{
	printf("%s\n", err_msg);
	exit(1);
}

void	ft_usleep(long usec, t_table *table)
{
	long	start;
	long	elapsed;
	long	rem;

	start = get_time(MICROSECOND);
	while (get_time(MICROSECOND) - start < usec)
	{
		if (sim_finished(table))
			break ;
		elapsed = get_time(MICROSECOND) - start;
		rem = usec - elapsed;
		if (rem > 1e3)
			usleep (usec / 2);
		else
			while (get_time(MICROSECOND) - start < usec);
	}
}

size_t	get_time(t_time_mod time_mod)
{
	struct timeval time;

	if (gettimeofday(&time, NULL) == -1)
		err("gettimeofday error");
	if (time_mod == SECOND)
		return (time.tv_sec + time.tv_usec / 1e6);
	if (time_mod == MILLISECOND)
		return (1e3 * time.tv_sec + time.tv_usec / 1e3);
	if (time_mod == MICROSECOND)
		return (1e6 * time.tv_sec + time.tv_usec);
	else
		err("Wrong time_mod");
	return (42);
}
