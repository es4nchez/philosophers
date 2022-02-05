/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanchez <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 00:41:32 by esanchez          #+#    #+#             */
/*   Updated: 2022/01/20 00:41:34 by esanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;
	struct timeval start;
	struct timeval ts;
	int	test;

	test = 0;
	gettimeofday(&start, NULL);
	usleep(10000);
	gettimeofday(&ts, NULL);
	printf("time_stamp : %ld\n", ((ts.tv_sec * 1000000 + ts.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec)));
	(void) argc;
	data.philers = ft_atoi(argv[1]);
	data.ttd = ft_atoi(argv[2]);
	data.tte = ft_atoi(argv[3]);
	data.tts = ft_atoi(argv[4]);
}
