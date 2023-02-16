/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartin- <cmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 10:45:17 by cmartin-          #+#    #+#             */
/*   Updated: 2023/02/16 14:51:45 by cmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
/*
	espace chat :
		il est où le chat aussi
*/


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
	
	//le programme se fait en 3 parties
	//1. init philo, init mutex, init thread
	//2. boucle de vie des philo
	//3. fin du programme
	
	end_philo(philo);
	//pthread_join(thread, NULL);
	return (0);
}