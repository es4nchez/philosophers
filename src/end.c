/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanchez <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 21:30:35 by esanchez          #+#    #+#             */
/*   Updated: 2022/03/15 21:30:37 by esanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	meal_checker(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->philers)
	{
		if (data->phil[i].eat_nb == data->eat_nb)
			j++;
		i++;
	}
	if (j == data->philers)
		return (1);
	return (0);
}

void	*checker(void *data_t)
{
	t_data	*data;
	int		i;

	i = 0;
	data = (t_data *)data_t;
	while (data->dead == 0)
	{
		if (time_stamp(data->start_time, 0) - data->phil[i].last_meal
			>= (size_t)data->ttd)
		{
			printf(RE"%lu %d died\n"DF, time_stamp(data->start_time, 0), i);
			data->dead = 1;
		}
		i++;
		if (i == data->philers)
			i = 0;
		if (meal_checker(data) == 1)
			data->dead = 1;
	}
	return (NULL);
}

void	end_sim(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philers)
	{
		pthread_join(data->tpid[i], NULL);
		i++;
	}
	printf(END1""END2);
	return ;
}
