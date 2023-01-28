/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartin- <cmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 10:45:17 by cmartin-          #+#    #+#             */
/*   Updated: 2023/01/28 14:40:110 by cmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
/*
	espace chat :
	tu valides la fonction ft_init_philo ?
	et tu as une idee pour la fonction ft_init_mutex ? c'est quoi un mutex ?
*/

void	*ft_philo(void *philo)
{
	while (1)
	{
		(void)philo;
		printf("je suis le philo\n");
		//prendre une fourchette
		//manger
		//poser une fourchette
		//penser
	}
}

/*
void end_philo(......)
{
	int i;

	...
	while (i != ....)
	{
		pthread_join(...., NULL);
		...
		
	}
	
	i = 0;
	.....		
}
*/

int	main(int argc, char **argv)
{
	t_data data;

	if (ft_parsing(argc, argv, &data))
		return (1);
	//le programme se fait en 3 parties
	//1. init philo, init mutex, init thread
	//2. boucle de vie des philo
	//3. fin du programme
	
	sleep(5);
	//pthread_join(thread, NULL);
	return (0);
}

