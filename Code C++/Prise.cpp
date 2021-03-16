/**
 * \file Prise.cpp
 * \brief Programme de gestion de la prise
 * \author CARTAGENA & REGNERE
 * \date Avril 2020
 *
 * Ce programme contient la description des methodes de la classe Prise.
 */

#include "Prise.h"
#include <iostream>

using namespace std ;

/**
 * \brief Constructeur
 * 
 * Constructeur de la classe Prise. Initialise la mémoire.
 */

Prise::Prise() {
    io = acces_memoire(&shmid) ;
    if (io==NULL) {
        cout << "Erreur pas de mem sh" << endl ;
    }
}

/**
 * \brief Méthode set_prise
 * 
 * Cette méthode permet de gérer la couleur du voyant de la prise.
 * \param Couleur Couleur du voyant de la prise sur la borne.
 */

void Prise::set_prise(led Couleur) {
    io->led_prise = Couleur ;
}

/**
 * \brief Méthode deverouiller_trappe
 * 
 * Cette méthode gère le dévérouillage de la trappe.
 */

void Prise::deverouiller_trappe() {
    io->led_trappe = VERT ;
}

/**
 * \brief Méthode verouiller_trappe
 * 
 * Cette méthode gère le vérouillage de la trappe.
 */

void Prise::verouiller_trappe() {
    io->led_trappe = OFF ;
}
