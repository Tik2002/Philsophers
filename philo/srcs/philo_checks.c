/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:41:44 by tigpetro          #+#    #+#             */
/*   Updated: 2024/07/24 15:58:05 by tigpetro         ###   ########.fr       */
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
		return (print_err("Wrong type of args"));
	while (ft_is_digit(str[i]))
	{
		buff = buff * 10 + (str[i++] - '0');
		if (++count >= 10 && buff > MAX)
			return (print_err("Arg is greater than INT_MAX"));
	}
	if (!buff)
		return (print_err("Arg can't be equal to 0"));
	return (buff);
}

int	pars_philo(t_table *table, int ac, char **av)
{
	if (ac < 5 || ac > 6)
		return (print_err("Wrong count of args"));
	table->philos_number = ft_atoi(av[1]);
	table->time_to_die = ft_atoi(av[2]) * 1e3;
	table->time_to_eat = ft_atoi(av[3]) * 1e3;
	table->time_to_sleep = ft_atoi(av[4]) * 1e3;
	if (av[5])
		table->eat_cycle = ft_atoi(av[5]);
	else
		table->eat_cycle = -1;
	if (table->philos_number == -2 || table->time_to_die == -2 * 1e3
		|| table->time_to_eat == -2 * 1e3 || table->time_to_sleep == -2 * 1e3
		|| table->eat_cycle == -2)
		return (1);
	if (table->time_to_die < 6e4 || table->time_to_eat < 6e4
		|| table->time_to_sleep < 6e4)
		return (print_err("Use timestamps greater than 60ms"));
	return (0);
}
