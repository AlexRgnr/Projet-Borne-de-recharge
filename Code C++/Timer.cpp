/**
 * \file Timer.cpp
 * \brief  Programme de gestion du timer
 * \author CARTAGENA & REGNERE
 * \date Avril 2020
 *
 * Ce programme contient la description des méthodes de la classe Timer.
 */

#include "Timer.h"
#include <iostream>

using namespace std ;

/**
 * \brief Constructeur
 * 
 * Constructeur de la classe Timer. Initialise la mémoire.
 */

Timer::Timer() {
    io=acces_memoire(&shmid) ; //associe l zone de memoire partagee au pointeur
    if(io == NULL) {
        cout << "Erreur pas de mem sh" << endl ;
    }
}

/**
 * \brief Méthode timer_raz
 * 
 * Cette méthode permet de prendre comme référence la valeur du temps dans la mémoire au moment de son appel.
 */

void Timer::timer_raz() {
depart_timer = io->timer_sec ;
}

/**
 * \brief Méthode timer_valeur
 * 
 * Cette méthode calcule et retourne la valeur du temps écoulé entre la remise a zero et l'appel de la fonction valeur.
 * \return la valeur de temps écoulé depuis l'appel de la méthode timer_valeur.
 */

int Timer::timer_valeur() {
return (io->timer_sec) - depart_timer ;
}
