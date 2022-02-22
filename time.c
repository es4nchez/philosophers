# include "philo.h"

size_t  time_since_start(t_data *data, int write)
{
    size_t new_time_stamp;

	new_time_stamp = time_stamp() - data->start_time;
    if (write == 1)
	    printf("new_time_stamp : %ld\n", new_time_stamp);
    return (new_time_stamp);
}

size_t	time_stamp(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}