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
	if (data->eating[info->next_fork + 1] == 0)
	{
		data->eating[info->nb] = 1;
		pthread_mutex_lock(&data->forks[info->nb - 1]);
		pthread_mutex_lock(&data->forks[info->next_fork]);
		printf("%lu %d has taken a fork\n", time_stamp(data->start_time, 0), info->nb);
		printf("%lu %d has taken a fork\n", time_stamp(data->start_time, 0), info->nb);
		printf(YE"%lu %d is eating\n"DF, time_stamp(data->start_time, 0), info->nb);
		info->last_meal = time_stamp(data->start_time, 0);
		if (ft_sleep(data, data->tte, info->nb, info->last_meal) == 0)
			return (0);
		pthread_mutex_unlock(&data->forks[info->nb - 1]);
		pthread_mutex_unlock(&data->forks[info->next_fork]);
		data->eating[info->nb] = 0;
	}
	else
	{
		if (data->dead == 1)
			return (1);
		printf(BL"%lu %d is sleeping\n"DF, time_stamp(data->start_time, 0), info->nb);
		ft_sleep(data, data->tts, info->nb, info->last_meal);
	}
	return (0);
}
