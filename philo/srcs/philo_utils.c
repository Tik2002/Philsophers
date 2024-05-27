/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 19:34:31 by tigpetro          #+#    #+#             */
/*   Updated: 2024/05/27 22:10:29 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

size_t	get_time(void)
{
	struct timeval time;

	if (gettimeofday(&time, NULL) == -1)
		err("gettimeofday() error");
	return (1000 * time.tv_sec + time.tv_usec / 1000);
}
