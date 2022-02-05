/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanchez <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 15:04:09 by esanchez          #+#    #+#             */
/*   Updated: 2021/12/09 15:04:12 by esanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>
# include <sys/time.h>

typedef struct	s_data {
	int	philers;
	int	ttd;
	int	tte;
	int	tts;

}				t_data;

/*
typedef struct	s_time {
  time_t		sec ;   //used for seconds
  suseconds_t	usec ;   //used for microseconds
}				t_time;
*/

int	ft_atoi(const char *nptr);

#endif
