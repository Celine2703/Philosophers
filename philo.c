/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartin- <cmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 10:45:17 by cmartin-          #+#    #+#             */
/*   Updated: 2023/01/28 11:38:11 by cmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *ft_philo(void *arg)
{
	
	printf("Coucou ");
	printf("Clement ");
	printf("Cravero\n");
	return (NULL);
}

void	ft_parsing(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
	{
		printf("Error: Wrong number of arguments");
	}
	else
	{
		if (ft_atoi(argv[1]) < 1)
			printf("Error: Wrong number of philosophers");
		else if (ft_atoi(argv[2]) < 0 || ft_atoi(argv[3]) < 0 || ft_atoi(argv[4]) < 0)
			printf("Error: Wrong time");
		else if (argc == 6 && ft_atoi(argv[5]) < 0)
		{
			printf("Error: Wrong number of meals");
		}
	}
}

int main(int argc, char **argv)
{
	int nb_philo;

	nb_philo = ft_atoi(argv[1]);
	
	pthread_t thread;
	pthread_create(&thread, NULL, &ft_philo, NULL);
	sleep(5);
	printf("Salut ");
	printf("Celine ");
	if (test == 0)
	{
		printf("Martin-Parisot\n");
	}
}

