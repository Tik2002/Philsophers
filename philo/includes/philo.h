/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:59:50 by tigpetro          #+#    #+#             */
/*   Updated: 2024/05/27 22:28:02 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# ifndef MAX
#  define MAX 2147483647
# endif
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef pthread_mutex_t	t_mtx;
typedef struct s_proc	t_proc;
typedef struct s_fork
{
	t_mtx	fork;
	int		fork_id;
}	t_fork;

typedef struct s_philo
{
	int			philo_id;
	long		meal_counter;
	long		time_to_die;
	t_fork		*left;
	t_fork		*right;
	pthread_t	thread_id;
	t_proc		*proc;
}	t_philo;

struct	s_proc
{
	long	philos_number;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	sim_start;
	int		sim_end;
	t_philo	*philo;
	t_fork	*fork;
	int		eat_cycle;
};

// philo_checks
void	pars_philo(t_proc *table, int ac, char **av);

// philo
void	philo(int ac, char **av);

// table_init
void	table_init(t_proc *table);

// philo_exit
void	err(char *err_str);

#endif // PHILO_H
