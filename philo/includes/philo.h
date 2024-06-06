/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:59:50 by tigpetro          #+#    #+#             */
/*   Updated: 2024/06/06 19:19:11 by tigpetro         ###   ########.fr       */
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

typedef enum	e_print_mod
{
	EAT,
	SLEEP,
	THINK,
	TAKE_FORK,
	DIED,
}	t_print_mod;

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
	long		full;
	long		meal_counter;
	long		meal_time;
	long		time_to_die;
	t_fork		*first_f;
	t_fork		*second_f;
	pthread_t	thread_id;
	t_mtx		philo_mutex;
	t_table		*table;
}	t_philo;

struct	s_table
{
	long		philos_number;
	long		time_to_die;
	long		time_to_eat;
	long		time_to_sleep;
	long		sim_start;
	long		sim_end;
	long		philos_gathered;
	long		threads_number;
	pthread_t	monitor;
	t_mtx		table_mutex;
	t_mtx		print_mutex;
	t_philo		*philo;
	t_fork		*fork;
	int			eat_cycle;
};

// philo_utils
long	get_time(t_time_mod time_mod);
void	ft_usleep(long usec, t_table *table);
void	*monitor_dinner(void *data);

// philo_checks
void	pars_philo(t_table *table, int ac, char **av);

// print
void	ft_print(t_philo *philo, t_print_mod mod);

// table_init
void	table_init(t_table *table);

// safe_funcs
void	thread_handle(pthread_t *thread, void *(*foo)(void *), void *data, t_mod mod);
void	mutex_handle(t_mtx *mtx, t_mod mod);
void	*wrapper_init(int bytes);

// dinner
void	think(t_philo *philo, int flag);
void	start_dinner(t_table *table);

// methods
void	set_bool(t_mtx *mtx, long *dest, long value);
long	get_bool(t_mtx *mtx, long *value);
int		sim_finished(t_table *table);

// methods_utils
void	philos_gathered(t_table *table);
long	threads_running(t_mtx *mutex, long *threads, long philo_number);
void	threads_counter(t_mtx *mutex, long *value);
void	de_synchronize_philos(t_philo *philo);

// destroy
void	destroy(t_table *table);
void	err(char *err_msg);

#endif // PHILO_H
