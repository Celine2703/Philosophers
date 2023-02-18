/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartin- <cmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 12:28:05 by cmartin-          #+#    #+#             */
/*   Updated: 2023/02/18 12:30:43 by cmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_error(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
	{
		printf("Error: Wrong number of arguments");
		return (1);
	}
	else
	{
		if (ft_atoi(argv[1]) < 1)
		{
			printf("Error: Wrong number of philosophers");
			return (1);
		}
		else if (ft_atoi(argv[2]) < 0
			|| ft_atoi(argv[3]) < 0 || ft_atoi(argv[4]) < 0)
		{
			printf("Error: Wrong time");
			return (1);
		}
		else if (argc == 6 && ft_atoi(argv[5]) < 0)
		{
			printf("Error: Wrong number of meals");
			return (1);
		}
	}
	return (0);
}

int	ft_parsing(int argc, char **argv, t_data *data)
{
	if (ft_error(argc, argv))
		return (1);
	data ->nb_philo = ft_atoi(argv[1]);
	data ->time_die = ft_atoi(argv[2]);
	data ->time_eat = ft_atoi(argv[3]) * 1000;
	data ->time_sleep = ft_atoi(argv[4]) * 1000;
	if (argc == 6)
		data ->nb_meals = ft_atoi(argv[5]);
	else
		data ->nb_meals = 0;
	return (0);
}
