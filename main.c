/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanchez <esanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 00:41:32 by esanchez          #+#    #+#             */
/*   Updated: 2022/02/05 17:32:05 by esanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data		data;
	int			i;

	i = 0;
	setvbuf(stdout, NULL, _IONBF, 0);
	if (input_errors(argc, argv) == 0)
		return (1);
	data_init(&data, argc, argv);
	data.tpid = (pthread_t *)malloc(sizeof(pthread_t) * data.philers);
	printf(BEGIN1""BEGIN2);
	while (data.i <= data.philers)
	{
		pthread_create(&data.tpid[data.i - 1],
			NULL, philo_create, (void *)&data);
		data.i++;
	}
	sleep(1);
	end_sim(&data);
	return (0);
}
