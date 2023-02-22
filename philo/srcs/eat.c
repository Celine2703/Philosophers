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
/*

to do :
	valgrind --tool=helgrind et fsanitize=thread

la fin du programme (si un philo meurt comment les autres philos sont au courant?) 
		mais egalement comment fermer proprement les mutex et les threads
		
une fonction ft_usleep qui permet de faire une pause de x ms (pour le temps de manger et de dormir)
	tout en verifiant regulierement si le programme doit s'arreter ou si le philo est mort

verifier que les philos mangent au bon moment (si un philo mange et que le philo a sa droite mange aussi, ca ne marche pas)

verifier que les philos meurent correctement (si un philo meurt, les autres doivent s'arreter) et au bon moment

visualiseur pour debugger : https://nafuka11.github.io/philosophers-visualizer/

*/

long long	ft_check_meal(t_philo *philo)
{
	long long	i;

	i = 0;
	pthread_mutex_lock(&philo->last_meal_mutex);
	i = philo->last_meal_time;
	pthread_mutex_unlock(&philo->last_meal_mutex);
	return (i);
}

static void	ft_lfork(t_philo *philo)
{
	pthread_mutex_lock(&philo ->mutex[philo ->index_lfork]);
	if (ft_check_death(philo))
		return ;
	pthread_mutex_lock(philo ->print);
	printf ("%lld %d has taken a fork\n",
		ft_get_time_diff(philo ->beggining_time), philo ->id);
	pthread_mutex_unlock(philo ->print);
}

static void	ft_rfork(t_philo *philo)
{
	pthread_mutex_lock(&philo ->mutex[philo ->index_rfork]);
	if (ft_check_death(philo))
		return ;
	pthread_mutex_lock(philo ->print);
	printf ("%lld %d has taken a fork\n",
		ft_get_time_diff(philo ->beggining_time), philo ->id);
	pthread_mutex_unlock(philo ->print);
}

void	ft_eat(t_philo *philo)
{
	if (philo ->id % 2 == 1)
	{
		ft_lfork(philo);
		ft_rfork(philo);
	}
	else
	{
		ft_rfork(philo);
		if (philo ->data ->nb_philo == 1)
			return ;
		ft_lfork(philo);
	}
	if (ft_check_death(philo))
	{
		pthread_mutex_unlock(&philo ->mutex[philo ->index_lfork]);
		pthread_mutex_unlock(&philo ->mutex[philo ->index_rfork]);
		return ;
	}
	pthread_mutex_lock(philo ->print);
	printf("%lld %d is eating\n",
		ft_get_time_diff(philo ->beggining_time), philo ->id);
	pthread_mutex_unlock(philo ->print);
	pthread_mutex_lock(&philo ->last_meal_mutex);
	philo ->last_meal_time = ft_get_time();
	pthread_mutex_unlock(&philo ->last_meal_mutex);
	philo ->ate += 1;
	ft_usleep(philo, philo ->data ->time_eat);
	pthread_mutex_unlock(&philo ->mutex[philo ->index_lfork]);
	pthread_mutex_unlock(&philo ->mutex[philo ->index_rfork]);
}

