/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanchez <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 23:48:57 by esanchez          #+#    #+#             */
/*   Updated: 2022/03/06 23:49:08 by esanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	phinfo_init(t_data *data, t_phinfo *info)
{
	pthread_mutex_lock(&data->lock);
	info->dead = 0;
	info->eat_nb = 0;
	info->is_eating = 0;
	info->ttd = data->ttd;
	info->start_time = data->start_time;
	pthread_mutex_unlock(&data->lock);
	return ;
}

void	*philo_create(void *data_t)
{
	t_data		*data;
	t_phinfo	info;
	static int	i = 0;

	data = (t_data *)data_t;
	phinfo_init(data, &info);
	pthread_mutex_lock(&data->lock);
	i++;
	info.nb = i;
	pthread_mutex_unlock(&data->lock);
	info.last_meal = time_stamp(data->start_time, 0);
	if (data->philers == 1)
	{
		printf(RED"%lu %d died\n"DEFAULT, time_stamp(data->start_time, 0),
			info.nb);
		data->dead = 1;
		return (NULL);
	}
	while (data->dead != 1)
	{
		if (data->dead == 1)
			return (NULL);
		if (info.eat_nb != 0)
			printf(BLUE"%lu %d is thinking\n", time_stamp(data->start_time, 0),
				info.nb);
		if (philo_eat(data, &info) == 0)
		{
			exit(0);
			return (NULL);
		}
		if (info.eat_nb == data->eat_nb)
			return (NULL);
		if (philo_sleep(data, info) == 0)
			return (NULL);
	}
	return (NULL);
}

void	mutex_init(t_data *data)
{
	int	i;

	i = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->philers);
	while (i <= data->philers - 1)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	return ;
}

void	data_init(t_data *data, int argc, char **argv)
{
	data->argc = argc - 1;
	data->dead = 0;
	pthread_mutex_init(&data->lock, NULL);
	data->i = 1;
	data->philers = ft_atoi(argv[1]);
	data->ttd = ft_atoi(argv[2]);
	data->tte = ft_atoi(argv[3]);
	data->tts = ft_atoi(argv[4]);
	if (data->argc == 5)
		data->eat_nb = ft_atoi(argv[5]);
	else
		data->eat_nb = 0;
	data->start_time = time_now();
	data->phil = malloc(sizeof(t_phinfo) * data->philers);
	mutex_init(data);
}
