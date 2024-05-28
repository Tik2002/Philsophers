/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:56:09 by tigpetro          #+#    #+#             */
/*   Updated: 2024/05/28 20:24:28 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static void	mutex_err_handle(int status, t_mod mod)
{
	if (!status)
		return ;
	else if (status == EINVAL && (mod == LOCK || mod == UNLOCK))
		err("The value specified by mutex is invalid.");
	else if (status == EINVAL && mod == INIT)
		err("The value specified by attr is invalid.");
	else if (status == EDEADLK)
		err("A deadlock would occur if the thread blocked waiting for mutex.");
	else if (status == EPERM)
		err("The current thread does not hold a lock on mutex.");
	else if (status == ENOMEM)
		err("The process cannot allocate enough memory to \
		create another mutex.");
	else if (status == EBUSY)
		err("Mutex is locked.");
}

void	mutex_handle(t_mtx *mtx, t_mod mod)
{
	if (mod == LOCK)
		mutex_err_handle(pthread_mutex_lock(mtx), mod);
	else if (mod == UNLOCK)
		mutex_err_handle(pthread_mutex_unlock(mtx), mod);
	else if (mod == INIT)
		mutex_err_handle(pthread_mutex_init(mtx, NULL), mod);
	else if (mod == DESTROY)
		mutex_err_handle(pthread_mutex_destroy(mtx), mod);
	else
		err("Wrong mod for mutex handle");
}

static void	thread_err_handle(int status, t_mod mod)
{
	if (!status)
		return ;
	else if (status == EINVAL && (mod == JOIN || mod == DETACH))
		err("The value specified by thread isn't joinable.");
	else if (status == EINVAL && mod == CREATE)
		err("The value specified by attr is invalid.");
	else if (status == EDEADLK)
		err("A deadlock was detected or the value of thread \
		specifies the calling thread.");
	else if (status == EPERM)
		err("The caller does not have appropriate permission.");
	else if (status == EAGAIN)
		err("Cannot create another thread.");
	else if (status == ESRCH)
		err("No thread could be found corresponding to that \
		specified by the given thread ID, thread.");
}

void	thread_handle(pthread_t *thread, void *(*foo)(void *), void *data,
		t_mod mod)
{
	if (mod == CREATE)
		thread_err_handle(pthread_creat(thread, NULL, foo, data), mod);
	else if (mod == JOIN)
		thread_err_handle(pthread_destroy(*thread, NULL), mod);
	else if (mod == DETACH)
		thread_err_handle(pthread_detach(*thread), mod);
	else
		err("Wrong mod for thread handle");
}

void	*wrapper_init(int bytes)
{
	void	*res;

	res = malloc(bytes);
	if (!res)
		err("Malloc error");
	return (res);
}
