//VOYANT.C
#include <unistd.h>
#include "voyants.h"


entrees *io ;
int shmid ;

void voyants_initialiser() 
{
 io = acces_memoire(&shmid) ;
 if (io==NULL) printf("Erreur pas de mem sh\n");
}

void set_charge(led Couleur)
{
 io->led_charge = Couleur ;
}

void set_dispo(led Couleur) 
{
 io->led_dispo = Couleur ;
}

void set_defaut(led Couleur) 
{
 io->led_defaut = Couleur ;
}


void blink_charge()
{
 while(timer_valeur() < 8) 
  {
   if(timer_valeur()%2 == 0)
   set_charge(VERT) ;
   if(timer_valeur()%2 == 1)
   set_charge(OFF) ;
  }
}

void blink_defaut()
{
 while(timer_valeur() < 8) 
  {
   if(timer_valeur()%2 == 0)
   set_defaut(ROUGE) ;
   if(timer_valeur()%2 == 1)
   set_defaut(OFF) ;
  }
}