#include "philo.h"

void	*thread_test()
{
	char	*test;
	return (test);
}


void    philo_init(t_data *data)
{
    int i;
    char    *philo;

    i = 1;
    while (i <= data->philers)
    {
        pthread_create(data->thid, NULL, thread_test, "thread 1");
        printf("Philosophers No %d is alive and well. Goodspeed to him\n", i);
        i++;
    }

    return ;
}


void    data_init(t_data *data, char **argv)
{

    data->philers = ft_atoi(argv[1]);
    data->thid = malloc(sizeof(pthread_t)  * data->philers);
	data->ttd = ft_atoi(argv[2]);
	data->tte = ft_atoi(argv[3]);
	data->tts = ft_atoi(argv[4]);
	
	data->start_time = time_stamp();
	printf("Start time:  %ld\n", data->start_time);
    philo_init(data);
	pthread_create(data->thid, NULL, thread_test, "thread 1");

}