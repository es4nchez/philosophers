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
	pthread_mutex_lock(&data->forks[info->nb]);
	if (data->dead == 1)
		return (1);
	printf("%lu %d has taken a fork\n", time_stamp(data->start_time, 0),
		info->nb);
	pthread_mutex_lock(&data->forks[info->next_fork]);
	if (data->dead == 1)
		return (1);
	printf("%lu %d has taken a fork\n", time_stamp(data->start_time, 0),
		info->nb);
	printf(YE"%lu %d is eating\n"DF, time_stamp(data->start_time, 0), info->nb);
	info->last_meal = time_stamp(data->start_time, 0);
	info->eat_nb += 1;
	ft_sleep(data, data->tte, info->nb, info->last_meal);
	pthread_mutex_unlock(&data->forks[info->nb]);
	pthread_mutex_unlock(&data->forks[info->next_fork]);
	printf(BL"%lu %d is sleeping\n"DF, time_stamp(data->start_time, 0),
		info->nb);
	ft_sleep(data, data->tts, info->nb, info->last_meal);
	if (data->dead == 1 || info->eat_nb == data->eat_nb)
		return (1);
	printf(BL"%lu %d is thinking\n"DF, time_stamp(data->start_time, 0),
		info->nb);
	return (0);
}
