//BOUTON.C
#include "boutons.h"


entrees *io ;
int shmid ;

void boutons_initialiser()
{
 io=acces_memoire(&shmid) ; //associe l zone de memoire partagee au pointeur
 if(io == NULL) 
 printf("Erreur pas de mem sh\n") ;
}

int appui_bouton_charge()
{
 if( io->bouton_charge == 1) {
        printf("*appui sur bouton_charge* \n");
 }
return io->bouton_charge ;
}

int appui_bouton_stop()
{ 
 if( io->bouton_stop == 1) {
 printf("*appui sur bouton_stop* \n");}
 return io->bouton_stop ;
}

void raz_boutons()
{
 io->bouton_stop = 0 ;
 io->bouton_charge = 0 ;
}