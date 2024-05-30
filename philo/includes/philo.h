/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:59:50 by tigpetro          #+#    #+#             */
/*   Updated: 2024/05/30 21:01:24 by tigpetro         ###   ########.fr       */
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
# include <errno.h>

typedef enum	e_mod
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH,
}	t_mod;

typedef enum	e_time_mod
{
	SECOND,
	MILLISECOND,
	MICROSECOND,
}	t_time_mod;

typedef pthread_mutex_t	t_mtx;
typedef struct s_table	t_table;
typedef struct s_fork
{
	t_mtx	fork;
	int		fork_id;
}	t_fork;

typedef struct s_philo
{
	int			philo_id;
	int			full;
	long		meal_counter;
	long		time_to_die;
	t_fork		*first_f;
	t_fork		*second_f;
	pthread_t	thread_id;
	t_table		*table;
}	t_philo;

struct	s_table
{
	long	philos_number;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	sim_start;
	int		sim_end;
	int		philos_gathered;
	t_mtx	table_mutex;
	t_philo	*philo;
	t_fork	*fork;
	int		eat_cycle;
};

// philo_utils
void	err(char *err_msg);
size_t	get_time(t_time_mod time_mod);
void	ft_usleep(long usec, t_table *table);

// philo_checks
void	pars_philo(t_table *table, int ac, char **av);

// table_init
void	table_init(t_table *table);

// safe_funcs
void	thread_handle(pthread_t *thread, void *(*foo)(void *), void *data, t_mod mod);
void	mutex_handle(t_mtx *mtx, t_mod mod);
void	*wrapper_init(int bytes);

// dinner
void	start_dinner(t_table *table);

// member_functions
void	set_bool(t_mtx *mtx, long *dest, long value);
long	get_bool(t_mtx *mtx, long *value);
int		sim_finished(t_table *table);


#endif // PHILO_H
