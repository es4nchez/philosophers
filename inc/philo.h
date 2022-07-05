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

# define DF "\e[39m"
# define RE "\e[31m"
# define CY "\e[36m"
# define GR "\e[32m"
# define YE "\e[33m"
# define BL "\e[34m"
# define BEGIN1 "\n----------------------------\n|  Beginning of simulation |\n"
# define BEGIN2 "----------------------------\n\n"
# define END1 "----------------------------\n|     End of simulation    |\n"
# define END2 "----------------------------\n\n"

typedef struct s_phinfo {
	int		nb;
	int		eat_nb;
	int		dead;
	unsigned long	last_meal;
	int		ttd;
	int		next_fork;
	size_t		start_time;

}				t_phinfo;

typedef struct s_data {
	int		argc;
	int		dead;
	size_t		start_time;
	int		philers;
	unsigned long	ttd;
	int		tte;
	int		tts;
	int		eat_nb;
	int		i;
	int		eating[250];
	pthread_t	tpid[250];
	t_phinfo	phil[250];
	pthread_mutex_t	forks[250];

}				t_data;

int		ft_atoi(const char *nptr);
char		*ft_itoa(int n);
int		input_errors(int argc, char **argv);
size_t		time_stamp(size_t start_time, int write);
int		ft_sleep(t_data *data, int wait_time, int nb, size_t last_meal);
void		data_init(t_data *data, int argc, char **argv);
void		philo_init(t_data *data);
void		*philo_create(void *data_t);
int		philo_sleep(t_data *data, t_phinfo info);
int		philo_eat(t_data *data, t_phinfo *info);
size_t		time_now(void);
void		end_sim(t_data *data);

#endif
