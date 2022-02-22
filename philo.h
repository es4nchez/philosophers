/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlene <marlene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 15:04:09 by esanchez          #+#    #+#             */
/*   Updated: 2022/02/05 17:44:01 by marlene          ###   ########.fr       */
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
# include <pthread.h>
# include <string.h>

typedef struct	s_data {
	size_t		start_time;
	int			philers;
	int			ttd;
	int			tte;
	int			tts;
	pthread_t	*thid;

}				t_data;

/*
typedef struct	s_time {
  time_t		sec ;   //used for seconds
  suseconds_t	usec ;   //used for microseconds
}				t_time;
*/

int		ft_atoi(const char *nptr);
size_t	time_stamp(void);
void    data_init(t_data *data, char **argv);
size_t  time_since_start(t_data *data, int write);

#endif
