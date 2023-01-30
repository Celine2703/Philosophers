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

//sur ton init tu n'as pas donne les valeurs index de tes forks (lfork et rfork)
// si le mutex est deja lock, le thread s'arrete jusqu'a ce qu'il soit debloque (donc il attend) 
// donc ca peut generer des deadlock dans certains cas (si un thread attend un mutex qui est lock par un autre thread qui attend un mutex lock par le premier thread)
// mais on verra ca apres

la t'as la routine de base de tes philos, tu peux commencer des test pour voir si ca marche

to do before test :

init de lfork et rfork dans init_philo (comment je fais pour avoir l'index de mes forks? genre si je suis le philo 1, mon lfork est le mutex 0 et mon rfork est le mutex 1?)
										c'est ca : mais attention pour le dernier philo(ca change quoi? tu) et aussi si un seul philo )
										attend c'est pas ca :
										tu as un tableau de mutex du nombres de philos
										
										prenons le cas de 3 philos je rappelle que les philos sont en rond:
										le philo 1 a pour index rfork 1 lfork 0 (par exemple)
										le philo 2 a pour index rfork 2 et lfork 1
										le dernier philo a pour index rfork 0 et lfork 2
										
										
faire le main

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

*/
void	*ft_philo(void *philos)
{
	t_philo	philo;
    
	philo = *(t_philo*)philos;   // cast de void * en t_philo * puis dereferencement
	(void )philo;
	while (1)
	{
		printf("je suis le philo %d\n", philo.id);

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