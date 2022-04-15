/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanchez <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:19:23 by esanchez          #+#    #+#             */
/*   Updated: 2022/03/15 14:19:25 by esanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	input_errors(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{
		printf("Error in arguments \n");
		return (0);
	}
	if (ft_atoi(argv[1]) <= 0 || ft_atoi(argv[2]) <= 0 || ft_atoi(argv[3]) <= 0
		|| ft_atoi(argv[4]) <= 0)
	{
		printf("Error in arguments \n");
		return (0);
	}
	if (argc == 6)
	{
		if (ft_atoi(argv[5]) <= 0)
		{
			printf("Error in arguments \n");
			return (0);
		}
	}
	return (1);
}
