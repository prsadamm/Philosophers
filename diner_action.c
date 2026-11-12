#include "philo.h"

void	take_right_fork(t_philo *philo)
{
	pthread_mutex_lock(&(philo->right_fork));
	print_action(philo, 3);
}

void	take_left_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_action(philo, 3);
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(&(philo->param->meal));
	philo->last_meal = get_time(philo->param);
	philo->nb_eat++;
	pthread_mutex_unlock(&(philo->param->meal));
	print_action(philo, 0);
	ft_usleep(philo, philo->param->tte);
	pthread_mutex_unlock(&(philo->right_fork));
	pthread_mutex_unlock(philo->left_fork);
}

void	sleeping(t_philo *philo)
{
	print_action(philo, 2);
	ft_usleep(philo, philo->param->tts);
}

void	thinking(t_philo *philo)
{
	print_action(philo, 1);
}
