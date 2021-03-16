/**
 * \file Bouton.cpp
 * \brief Programme de gestion des boutons
 * \author CARTAGENA & REGNERE
 * \date Avril 2020
 *
 * Ce programme contient la description des méthodes de la classe Bouton.
 */

#include "Bouton.h"
#include <iostream>

using namespace std ;

/**
 * \brief Constructeur
 * 
 * Constructeur de la classe Bouton. Initialise la mémoire.
 */

Bouton::Bouton() {
    io=acces_memoire(&shmid) ; //associe la zone de memoire partagee au pointeur
    if(io == NULL) {
        cout << "Erreur pas de mem sh" << endl ;
    }
}

/**
 * \brief Méthode appui_sur_bouton_charge
 * 
 * Cette méthode retourne l'état du bouton charge. S'il est a l'etat haut, elle l'indique.
 * \return L'état du bouton.
 */

int Bouton::appui_bouton_charge() {
    if( io->bouton_charge == 1) {
        cout << "*appui sur bouton_charge*" << endl ;
    }
return io->bouton_charge ;
}

/**
 * \brief Méthode appui_sur_bouton_stop
 * 
 * Cette méthode retourne l'état du bouton stop. S'il est a l'état haut, elle l'indique.
 * \return L'état du bouton.
 */

int Bouton::appui_bouton_stop() {
    if( io->bouton_stop == 1) {
        cout << "*appui sur bouton_stop*" << endl ;
    }
return io->bouton_stop ;
}

/**
 * \brief Méthode bouton_raz
 * 
 * Cette méthode remet a zero l'etat des deux boutons.
 */

void Bouton::bouton_raz() {
    io->bouton_charge = 0 ;
    io->bouton_stop = 0 ;
}
