/**
 * \file Voyant.cpp
 * \brief Programme de gestion des voyants
 * \author CARTAGENA & REGNERE
 * \date Avril 2020
 *
 * Ce programme contient la description des méthodes de la classe Voyant.
 */

#include <unistd.h>
#include "Voyant.h"
#include <iostream>

using namespace std ;


/**
 * \brief Constructeur 
 * 
 * Constructeur de la classe Voyant.
 */

Voyant::Voyant() {
    io = acces_memoire(&shmid) ;
    if (io==NULL) {
        cout << "Erreur pas de mem sh" << endl ;
    }
}

/**
 * \brief Méthode set_charge
 * 
 * Cette méthode permet de gérer la couleur du voyant 'charge'.
 * \param Couleur Couleur du voyant 'charge' sur la borne.
 */

void Voyant::set_charge(led Couleur) {
    io->led_charge = Couleur ;
}

/**
 * \brief Méthode set_dispo
 * 
 * Cette méthode permet de gérer la couleur du voyant 'dispo'.
 * \param Couleur Couleur du voyant 'dispo' sur la borne.
 */

void Voyant::set_dispo(led Couleur) {
    io->led_dispo = Couleur ;
}

/**
 * \brief Méthode set_defaut
 * 
 * Cette méthode permet de gérer la couleur du voyant 'defaut'.
 * \param Couleur Couleur du voyant 'defaut' sur la borne.
 */

void Voyant::set_defaut(led Couleur) {
    io->led_defaut = Couleur ;
}

/**
 * \brief Méthode blink_charge
 * 
 * Cette méthode permet de gérer le clignotement du voyant 'charge' a l'aide de la classe Timer.
 */

void Voyant::blink_charge() {
 timer.timer_raz() ;

    while(timer.timer_valeur() < 8) {

        if(timer.timer_valeur()%2 == 0)
        set_charge(VERT) ;

        if(timer.timer_valeur()%2 == 1)
        set_charge(OFF) ;
    }
}

/**
 * \brief Méthode blink_defaut
 * 
 * Cette méthode permet de gérer le clignotement du voyant 'defaut' a l'aide de la classe Timer.
 */

void Voyant::blink_defaut() {
 timer.timer_raz() ;

    while(timer.timer_valeur() < 8) {

        if(timer.timer_valeur()%2 == 0)
        set_defaut(ROUGE) ;

        if(timer.timer_valeur()%2 == 1)
        set_defaut(OFF) ;
    }
}
