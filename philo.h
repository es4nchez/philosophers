/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanchez <esanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 15:04:09 by esanchez          #+#    #+#             */
/*   Updated: 2022/02/05 17:44:01 by esanchez         ###   ########.fr       */
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

# define DEFAULT "\e[39m"
# define RED "\e[31m"
# define CYAN "\e[36m"
# define GREEN "\e[32m"
# define YELLOW "\e[33m"
# define BLUE "\e[34m"
# define BEGIN1 "\n----------------------------\n|  Beginning of simulation |\n"
# define BEGIN2 "----------------------------\n\n"
# define END1 "----------------------------\n|     End of simulation    |\n"
# define END2 "----------------------------\n\n"

typedef struct s_phinfo {
	int				nb;
	int				is_eating;
	int				eat_nb;
	int				dead;
	int				left_fork;
	int				right_fork;
	unsigned long	last_meal;
	int				ttd;
	size_t			start_time;
	pthread_mutex_t	fork;

}				t_phinfo;

typedef struct s_data {
	int				argc;
	int				dead;
	size_t			start_time;
	int				philers;
	unsigned long	ttd;
	int				tte;
	int				tts;
	int				eat_nb;
	int				i;
	pthread_t		*tpid;
	t_phinfo		*phil;
	pthread_mutex_t	lock;
	pthread_mutex_t	*forks;

}				t_data;

int			ft_atoi(const char *nptr);
char		*ft_itoa(int n);
int			input_errors(int argc, char **argv);
size_t		time_stamp(size_t start_time, int write);
int			ft_sleep(t_data *data, int wait_time, int time_to_die, int phil);
void		data_init(t_data *data, int argc, char **argv);
void		philo_init(t_data *data);
void		*philo_create(void *data_t);
int			philo_sleep(t_data *data, t_phinfo info);
int			philo_eat(t_data *data, t_phinfo *info);
size_t		time_now(void);
void		end_sim(t_data *data);

#endif
