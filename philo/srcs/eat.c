/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccravero <ccravero@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:01:35 by celine            #+#    #+#             */
/*   Updated: 2023/01/30 14:4201 by ccravero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_ate(t_philo *philo)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&philo->last_meal_mutex);
	i = philo->ate;
	pthread_mutex_unlock(&philo->last_meal_mutex);
	return (i);
}

long long	ft_check_meal(t_philo *philo)
{
	long long	i;

	i = 0;
	pthread_mutex_lock(&philo->last_meal_mutex);
	i = philo->last_meal_time;
	pthread_mutex_unlock(&philo->last_meal_mutex);
	return (i);
}

void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(philo ->print);
	printf("%lld %d is eating\n",
		ft_get_time_diff(philo ->beggining_time), philo ->id);
	pthread_mutex_unlock(philo ->print);
	pthread_mutex_lock(&philo ->last_meal_mutex);
	philo ->last_meal_time = ft_get_time();
	philo ->ate += 1;
	pthread_mutex_unlock(&philo ->last_meal_mutex);
	ft_usleep(philo, philo ->data ->time_eat);
	pthread_mutex_unlock(&philo ->mutex[philo ->index_lfork]);
	pthread_mutex_unlock(&philo ->mutex[philo ->index_rfork]);
}
