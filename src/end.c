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

void	end_sim(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philers)
	{
//		pthread_detach(data->tpid[i]);
		pthread_mutex_destroy(&(data->forks[i]));
		pthread_join(data->tpid[i], NULL);
		i++;
	}
	return  ;
}