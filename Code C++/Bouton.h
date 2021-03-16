/**
 * \file Bouton.h
 * \brief Header de Bouton
 * \author CARTAGENA & REGNERE
 * \date Avril 2020
 *
 * Ce programme contient la classe Bouton et la déclaration de ses méthodes.
 */

#ifndef BOUTONS_H
#define BOUTONS_H
#include <donnees_borne.h>
#include <memoire_borne.h>
#include <lcarte.h>
#include <mem_sh.h>

/**
 * \class Bouton
 * \brief Classe représentant les boutons.
 * 
 * Cette classe gère l'utilisation des différents boutons.
 */

class Bouton {
 private :
    entrees *io ;
    int shmid ; 

 public :
    Bouton() ;
    int appui_bouton_charge() ;
    int appui_bouton_stop() ;
    void bouton_raz() ;
} ;

#endif
