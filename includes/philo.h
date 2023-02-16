/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartin- <cmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 12:00:06 by cmartin-          #+#    #+#             */
/*   Updated: 2023/02/16 14:53:23 by cmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
//hesite pas a me demander si tu as des questions ou que tu veux que je code une fonction utilitaire;

typedef struct s_data
{
	int	nb_philo;
	int	time_die;
	int	time_eat;
	int	time_sleep;
	int	nb_meals;
}	t_data;

typedef struct s_philo
{
	int				id;
	int				index_lfork;
	int				index_rfork;
	int				times;
	int				dead;
	int				ate;
	int				*dead_philo;
	pthread_mutex_t	*mutex;
	pthread_mutex_t	*print;
	pthread_t		thread;
	t_data			*data;
}	t_philo;

//utils
int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);

//init
int		ft_init_philo(t_philo **philo, t_data *data);
int		ft_init_mutex(t_philo *philo);
int		ft_init_thread(t_philo *philo);

//parsing
int		ft_error(int argc, char **argv);
int		ft_parsing(int argc, char **argv, t_data *data);

//action
void	*ft_philo(void *philos);
void end_philo(t_philo *philo);
