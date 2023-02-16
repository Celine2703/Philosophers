/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartin- <cmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 10:45:17 by cmartin-          #+#    #+#             */
/*   Updated: 2023/02/16 17:41:15 by cmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_death(t_philo *philo)
{
	int i;

	while(1)
	{
		i = 0;
		while(i < philo->data->nb_philo)
		{
			printf("time %lld last meal %lld , time to die %d\n", ft_get_time(), philo[i].last_meal_time, philo[i].data->time_die);
			if (ft_get_time() - philo[i].last_meal_time > philo[i].data->time_die)
			{
				pthread_mutex_lock(philo[i].print);
				printf("%lld %d died\n", ft_get_time_diff(philo[i].beggining_time), philo[i].id);
				pthread_mutex_unlock(philo[i].print);
				return;
			}
			i++;
		}
	}
}


int	main(int argc, char **argv)
{
	t_data data;
	t_philo *philo;

	philo = NULL;
	if (ft_parsing(argc, argv, &data))
		return (1);
	ft_init_philo(&philo, &data);
	ft_init_mutex(philo);
	ft_init_thread(philo);
	ft_death(philo);
	
	//le programme se fait en 3 parties
	
	//on verifie que last meal + time to die est inferieur a time actuel
	
	//2. boucle de vie des philo
	
	end_philo(philo);
	//pthread_join(thread, NULL);
	return (0);
}

	