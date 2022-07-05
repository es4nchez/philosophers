/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanchez <esanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 00:41:32 by esanchez          #+#    #+#             */
/*   Updated: 2022/02/05 17:32:05 by esanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	main(int argc, char **argv)
{
	t_data		data;

	if (input_errors(argc, argv) == 0)
		return (1);
	data_init(&data, argc, argv);
	printf(BEGIN1""BEGIN2);
	while (data.i <= data.philers)
	{
		pthread_create(&data.tpid[data.i - 1],
			NULL, philo_create, (void *)&data);
		data.i++;
	}
	exit (0);
	end_sim(&data);
	return (0);
}
