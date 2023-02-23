/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartin- <cmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 12:28:05 by cmartin-          #+#    #+#             */
/*   Updated: 2023/02/23 16:10:41 by cmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static int	ft_compare(char *str1)
{
	char	*itoa;

	itoa = ft_itoa(ft_atoi(str1));
	if (ft_strcmp(str1, itoa))
	{
		free(itoa);
		return (1);
	}
	free(itoa);
	return (0);
}

int	ft_error(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
	{
		printf("Error: Wrong number of arguments\n");
		return (1);
	}
	if (ft_compare(argv[1]) || ft_atoi(argv[1]) < 1)
	{
		printf("Error: Wrong number of philosophers\n");
		return (1);
	}
	else if (ft_compare(argv[2]) || ft_compare(argv[3]) || ft_compare(argv[4])
		|| ft_atoi(argv[2]) < 0 || ft_atoi(argv[3]) < 0 || ft_atoi(argv[4]) < 0)
	{
		printf("Error: Wrong time\n");
		return (1);
	}
	else if (argc == 6 && (ft_compare(argv[5]) || ft_atoi(argv[5]) < 0))
	{
		printf("Error: Wrong number of meals\n");
		return (1);
	}
	return (0);
}

int	ft_parsing(int argc, char **argv, t_data *data)
{
	if (ft_error(argc, argv))
		return (1);
	data ->nb_philo = ft_atoi(argv[1]);
	data ->time_die = ft_atoi(argv[2]);
	data ->time_eat = (long long)ft_atoi(argv[3]) * 1000;
	data ->time_sleep = (long long)ft_atoi(argv[4]) * 1000;
	if (argc == 6)
		data ->nb_meals = ft_atoi(argv[5]);
	else
		data ->nb_meals = -1;
	return (0);
}
