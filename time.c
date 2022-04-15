/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanchez <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 23:49:56 by esanchez          #+#    #+#             */
/*   Updated: 2022/03/06 23:49:58 by esanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_sleep(t_data *data, int wait_time, int time_to_die, int phil)
{
	size_t	begin;
	size_t	end;

	begin = time_now();
	end = time_now();
	while ((end - begin) <= (size_t)wait_time && (end - begin) >= 0)
	{
		end = time_now();
		if (end - begin > (size_t)time_to_die)
		{
			printf(RED"%lu %d died\n"DEFAULT,
				time_stamp(data->start_time, 0), phil);
			data->dead = 1;
			return (0);
		}
		usleep(1);
	}
	return (1);
}

size_t	time_stamp(size_t start_time, int write)
{
	size_t	new_time_stamp;

	new_time_stamp = time_now() - start_time;
	if (write == 1)
		printf("new_time_stamp : %ld\n", new_time_stamp);
	return (new_time_stamp);
}

size_t	time_now(void)
{
	struct timeval	t;

	gettimeofday(&t, DST_NONE);
	return (t.tv_sec * 1000 + t.tv_usec / 1000);
}
