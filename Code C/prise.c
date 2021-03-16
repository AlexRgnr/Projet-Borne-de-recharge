//PRISE.C
#include "prise.h"

entrees *io ;
int shmid ;

void prise_initialiser() 
{
 io = acces_memoire(&shmid) ;
 if (io==NULL) printf("Erreur pas de mem sh\n");
}

void set_prise(led Couleur)
{
 io->led_prise = Couleur ;
}


void deverouiller_trappe() 
{
 io->led_trappe = VERT ;
}

void verouiller_trappe()
{
 io->led_trappe = OFF ;
}
