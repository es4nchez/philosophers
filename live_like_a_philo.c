/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live_like_a_philo.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanchez <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:42:26 by esanchez          #+#    #+#             */
/*   Updated: 2022/03/14 17:42:29 by esanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*is_dead(void *info_tmp)
{
	t_phinfo	*info;

	info = (t_phinfo *)info_tmp;
	while (info->is_eating == 0)
	{
		if ((int)(time_stamp(info->start_time, 0) - info->last_meal) > info->ttd)
		{
			printf(RED"%lu %d died\n"DEFAULT,
				time_stamp(info->start_time, 0), info->nb);
			info->dead = 1;
			return (NULL);
		}
	}
	return (NULL);
}

int	death_check(t_data *data, t_phinfo *info)
{
	pthread_t		pid;

	pthread_create(&pid, NULL, is_dead, (void *)info);
	if (info->dead == 1)
	{
		data->dead = 1;
		return (1);
	}
	return (0);
}

void	fork_init(t_data *data, t_phinfo *info)
{
	if (info->nb == data->philers)
		info->right_fork = 0;
	else
		info->right_fork = info->nb;
	info->left_fork = info->nb - 1;
	return ;
}

int	philo_eat(t_data *data, t_phinfo *info)
{
	fork_init(data, info);
	if (death_check(data, info) == 1)
		return (0);
	pthread_mutex_lock(&data->forks[info->left_fork]);
	pthread_mutex_lock(&data->forks[info->right_fork]);
	info->is_eating = 1;
//	printf("dead : %d for %d\n", info->dead, info->nb);
	if (info->dead == 1)
		return (0);
	printf(CYAN"%lu %d has taken a fork\n",
		time_stamp(data->start_time, 0), info->nb);
	printf(CYAN"%lu %d has taken a fork\n",
		time_stamp(data->start_time, 0), info->nb);
	printf(YELLOW"%lu %d is eating\n"DEFAULT,
		time_stamp(data->start_time, 0), info->nb);
	info->last_meal = time_stamp(data->start_time, 0);
	info->is_eating = 0;
	if (ft_sleep(data, data->tte, data->ttd, info->nb)
		== 0 || info->dead == 1)
		data->dead = 1;
	info->eat_nb++;
	pthread_mutex_unlock(&data->forks[info->left_fork]);
	pthread_mutex_unlock(&data->forks[info->right_fork]);
	return (1);
}

int	philo_sleep(t_data *data, t_phinfo info)
{
	printf(GREEN"%lu %d is sleeping\n",
		time_stamp(data->start_time, 0), info.nb);
	if (ft_sleep(data, data->tts, data->ttd, info.nb) == 0)
		return (0);
	return (1);
}
