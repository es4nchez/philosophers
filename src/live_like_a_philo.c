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

#include "../inc/philo.h"

int	philo_eat(t_data *data, t_phinfo *info)
{

	while (data->dead == 0)
	{
		printf("%d checking fork %d and %d\n", info->nb, info->nb - 1, info->next_fork);
		if (pthread_mutex_unlock(&data->forks[info->nb - 1]) == 0 && pthread_mutex_unlock(&data->forks[info->next_fork]) == 0)
		{
			pthread_mutex_lock(&data->forks[info->nb - 1]);
			pthread_mutex_lock(&data->forks[info->next_fork]);
			printf("%lu %d has taken a fork\n", info->last_meal, info->nb);
			printf("%lu %d has taken a fork\n", info->last_meal, info->nb - 1);
			printf("%lu %d is eating\n", info->last_meal, info->nb);
			info->last_meal = time_stamp(data->start_time, 0);
			usleep(1000000);
			pthread_mutex_unlock(&data->forks[info->nb - 1]);
			pthread_mutex_unlock(&data->forks[info->next_fork]);
			continue ;
		}
	//	else
		//	usleep(1);
	}
	ft_sleep(data, data->tts, info->nb);
	printf("%lu %d is sleeping\n", time_stamp(data->start_time, 0), info->nb);
	return (0);
}
