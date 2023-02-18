/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartin- <cmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 12:00:06 by cmartin-          #+#    #+#             */
/*   Updated: 2023/02/18 14:00:05 by cmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

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
	long long		beggining_time;
	long long		last_meal_time;
	int				dead;
	int				ate;
	pthread_mutex_t	*mutex;
	pthread_mutex_t	*print;
	pthread_mutex_t	dead_mutex;
	pthread_mutex_t	last_meal_mutex;
	pthread_t		thread;
	t_data			*data;
}	t_philo;

//utils
int			ft_atoi(const char *str);
void		ft_bzero(void *s, size_t n);

//init
int			ft_init_philo(t_philo **philo, t_data *data);
int			ft_init_mutex(t_philo *philo);
int			ft_init_thread(t_philo *philo);

//parsing
int			ft_error(int argc, char **argv);
int			ft_parsing(int argc, char **argv, t_data *data);

//action
void		ft_eat(t_philo *philo);
void		*ft_philo(void *philos);
void		end_philo(t_philo *philo);

//time
long long	ft_get_time(void);
long long	ft_get_time_diff(long long beggining);

//philo
int			ft_check_death(t_philo *philo);
void		ft_knowing_death(t_philo *philo);
void		ft_death(t_philo *philo);

#endif