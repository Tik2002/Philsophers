/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:41:44 by tigpetro          #+#    #+#             */
/*   Updated: 2024/05/28 20:33:01 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static int	ft_is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

static int	ft_is_space(char c)
{
	return (c == 32 || (c > 8 && c < 14));
}

static int	ft_atoi(char *str)
{
	int		i;
	int		count;
	long	buff;

	i = 0;
	buff = 0;
	count = 0;
	while (ft_is_space(str[i]))
		i++;
	if (str[i] == '+')
		i++;
	if (!ft_is_digit(str[i]))
		err("Wrong type of args");
	while (ft_is_digit(str[i]))
	{
		buff = buff * 10 + (str[i++] - '0');
		if (++count >= 10 && buff > MAX)
			err("Arg is greater than INT_MAX");
	}
	if (!buff)
		err("Arg can't be equal to 0");
	return (buff);
}

void	pars_philo(t_table *table, int ac, char **av)
{
	if (ac < 5 || ac > 6)
		err("Wrong count of args");
	table->philos_number = ft_atoi(av[1]);
	table->time_to_die = ft_atoi(av[2]) * 1e3;
	table->time_to_eat = ft_atoi(av[3]) * 1e3;
	table->time_to_sleep = ft_atoi(av[4]) * 1e3;
	if (table->time_to_die < 6e4 || table->time_to_eat < 6e4
		|| table->time_to_sleep < 6e4)
		err("Use timestamps greater than 60ms");
	if (av[5])
		table->eat_cycle = ft_atoi(av[5]);
	else
		table->eat_cycle = -1;
}
