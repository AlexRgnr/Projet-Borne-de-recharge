//TIMER.C
#include "timer.h"
#include <stdio.h>

entrees *io ;
int shmid ;
int depart_timer ;


void timer_initialiser()
{
 io=acces_memoire(&shmid) ; //associe l zone de memoire partagee au pointeur
 if(io == NULL)
 printf("Erreur pas de mem sh\n") ;
}

void timer_raz()
{
 depart_timer = io->timer_sec ;
}

int timer_valeur()
{
 return (io->timer_sec) - depart_timer ;
}
