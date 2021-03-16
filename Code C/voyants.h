//VOYANT.H
#ifndef VOYANTS_H
#define VOYANTS_H
#include <donnees_borne.h>
#include <memoire_borne.h>
#include <lcarte.h>
#include <mem_sh.h>
#include "timer.h"

void voyants_initialiser();
void set_charge(led Couleur);
void set_dispo(led Couleur) ;
void set_defaut(led Couleur) ;
void blink_charge() ;
void blink_defaut() ;

#endif