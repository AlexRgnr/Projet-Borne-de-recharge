/**
 * \file Voyant.h
 * \brief Header de Voyant
 * \author CARTAGENA & REGNERE
 * \date Avril 2020
 *
 * Ce programme contient la classe Voyant et la déclaration de ses méthodes.
 */

#ifndef VOYANTS_H
#define VOYANTS_H
#include <donnees_borne.h>
#include <memoire_borne.h>
#include <lcarte.h>
#include <mem_sh.h>
#include "Timer.h"

/**
 * \class Voyant
 * \brief Classe représentant les voyants.
 * 
 *  Elle gère l'utilisation des différents voyants et leurs couleurs.
 */

class Voyant {
 private :
    entrees *io ;
    int shmid ;
    Timer timer ;

 public :
    Voyant();
    void set_charge(led Couleur);
    void set_dispo(led Couleur) ;
    void set_defaut(led Couleur) ;
    void blink_charge() ;
    void blink_defaut() ;

} ;

#endif
