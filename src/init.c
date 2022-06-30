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

#include "../inc/philo.h"

void	phinfo_init(t_data *data, t_phinfo *info)
{
	info->dead = 0;
	info->eat_nb = 0;
	info->is_eating = 0;
	info->ttd = data->ttd;
	info->start_time = data->start_time;
	info->next_fork = (info->nb) % data->philers;
	printf(" %d\n", info->next_fork);
	return ;
}

void	*philo_create(void *data_t)
{
	t_data		*data;
	t_phinfo	info;
	static int	i = 0;

	data = (t_data *)data_t;
	i++;
	info.nb = i;
	info.last_meal = time_stamp(data->start_time, 0);
	phinfo_init(data, &info);
	if (data->philers == 1)
	{
		printf(RED"%lu %d died\n"DEF, data->ttd, info.nb);
		return (NULL);
	}
	while ((data->dead) == 0)
	{
		if (philo_eat(data, &info) == 1)
			return (NULL);
		if (data->dead == 1)
			return (NULL);

	}
	return (NULL);
}

void	mutex_init(t_data *data)
{
	int	i;

	i = data->philers;
	while (--i >= 0)
	{
		pthread_mutex_init(&(data->forks[i]), NULL);
		pthread_mutex_unlock(&data->forks[i]);
	}
}

void	data_init(t_data *data, int argc, char **argv)
{
	data->argc = argc - 1;
	data->dead = 0;
	data->i = 1;
	data->philers = ft_atoi(argv[1]);
	data->ttd = ft_atoi(argv[2]);
	data->tte = ft_atoi(argv[3]);
	data->tts = ft_atoi(argv[4]);
	if (data->argc == 5)
		data->eat_nb = ft_atoi(argv[5]);
	else
		data->eat_nb = -1;
	data->start_time = time_now();
	mutex_init(data);
}
