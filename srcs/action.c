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
verifier qu' il n'y a pas de data race (si deux thread peuvent acceder a la meme variable en meme temps donc pas proteger par un mutex) : 
	valgrind --tool=helgrind et fsanitize=thread

la fin du programme (si un philo meurt comment les autres philos sont au courant?) 
		mais egalement comment fermer proprement les mutex et les threads
		il y a plusieurs solutions pour detecter les morts on en reparlera quand tu auras fait les autres trucs

une fonction ft_usleep qui permet de faire une pause de x ms (pour le temps de manger et de dormir)
	tout en verifiant regulierement si le programme doit s'arreter ou si le philo est mort

verifier que les philos mangent au bon moment (si un philo mange et que le philo a sa droite mange aussi, ca ne marche pas)

verifier que les philos meurent correctement (si un philo meurt, les autres doivent s'arreter) et au bon moment

visualiseur pour debugger : https://nafuka11.github.io/philosophers-visualizer/

*/

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
	if (philo ->id % 2 == 0)
	{
		ft_lfork(philo);
		ft_rfork(philo);
	}
	else
	{
		ft_rfork(philo);
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
	usleep(philo ->data ->time_eat);
	pthread_mutex_unlock(&philo ->mutex[philo ->index_lfork]);
	pthread_mutex_unlock(&philo ->mutex[philo ->index_rfork]);
}

void	*ft_philo(void *philos)
{
	t_philo	*philo;

	philo = (t_philo *)philos;
	philo ->beggining_time = ft_get_time();
	pthread_mutex_lock(&(philo ->last_meal_mutex));
	philo ->last_meal_time = philo ->beggining_time;
	pthread_mutex_unlock(&(philo ->last_meal_mutex));
	while (ft_check_death(philo) == 0)
	{
		ft_eat(philo);
		if (ft_check_death(philo))
			return (NULL);
		pthread_mutex_lock(philo ->print);
		printf("%lld %d is sleeping\n",
			ft_get_time_diff(philo ->beggining_time), philo ->id);
		pthread_mutex_unlock(philo ->print);
		usleep(philo ->data ->time_sleep);
		if (ft_check_death(philo))
			return (NULL);
		pthread_mutex_lock(philo ->print);
		printf("%lld %d is thinking\n", //si fait rien
			ft_get_time_diff(philo ->beggining_time), philo ->id);
		pthread_mutex_unlock(philo ->print);
	}
	return (NULL);
}

void	end_philo(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->nb_philo)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
	i = 0;
	while (i < philo->data->nb_philo)
	{
		pthread_mutex_destroy(&philo->mutex[i]);
		i++;
	}
	pthread_mutex_destroy(philo->print);
	free(philo->print);
	free(philo->mutex);
	free(philo);
}
