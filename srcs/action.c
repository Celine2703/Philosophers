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

// si le mutex est deja lock, le thread s'arrete jusqu'a ce qu'il soit debloque (donc il attend) 
// donc ca peut generer des deadlock dans certains cas (si un thread attend un mutex qui est lock par un autre thread qui attend un mutex lock par le premier thread)
// mais on verra ca apres

to do :
fonction qui permet de recuperer le timestamp (cad le temps depuis le debut du programme (ou le lancement des thread)en ms)

securiser les affichage (avec mutex print?)

verifier qu' il n'y a pas de deadlock

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
void	*ft_philo(void *philos)
{
	t_philo	philo;
    
	philo = *(t_philo*)philos;   // cast de void * en t_philo * puis dereferencement
	(void )philo;
	while (1)
	{
		printf("je suis le philo %d\n", philo.id);

		printf("philo %d is hungry\n", philo.id);
		printf("index_lfork = %d\n", philo.index_lfork);
		printf("index_rfork = %d\n", philo.index_rfork);
		pthread_mutex_lock(&philo.mutex[philo.index_lfork]);
		printf ("philo %d take the left fork\n", philo.id);
        pthread_mutex_lock(&philo.mutex[philo.index_rfork]);
		printf ("philo %d take the right fork\n", philo.id);
        printf("philo %d is eating\n", philo.id);
        usleep(philo.data ->time_eat);
        philo.ate += 1;
        pthread_mutex_unlock(&philo.mutex[philo.index_lfork]);
        pthread_mutex_unlock(&philo.mutex[philo.index_rfork]);
        printf("philo %d is sleeping\n", philo.id);
        usleep(philo.data ->time_sleep);
        //si philo fait rien
            printf("philo %d is thinking\n", philo.id);
		//ft_taking_fork(philo);
		//ft_eat(philo);
		//ft_putting_fork(philo);
		//ft_think(philo);
		//prendre une fourchette
		//manger
		//poser une fourchette
		//penser
		
	}
}

void end_philo(t_philo *philo)
{
	int i;

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
	free(philo->mutex);
	free(philo);
}
