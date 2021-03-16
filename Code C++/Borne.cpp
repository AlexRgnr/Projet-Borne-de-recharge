/* Documentation tag for Doxygen
 */

/*! \mainpage Borne de Recharge Documentation
 *
 * \section intro_sec Introduction
 *
 * Documentation Doxygen du Projet M1 SME Réalisation Sytème "Borne de Recharge pour véhicules électriques". Cette documentation résulte de l'implémentation en C++ du projet fait au premier semestre de M1 SME.
 * Travail réalisé durant le mois d'avril 2020 pendant confinement lié au Covid-19.
 *
 * L'ensemble fonctionne mais nous avons eu des problèmes avec l'utilisation du vecteur de clients qui n'était visiblement pas le même dans tout le programme.
 * 
 *
 * \image html borne.jpg
 *
 * 
 *
 * \section copyright Copyright and License
 * CARTAGENA José Sebastian & REGNERE Alexandre, Université Toulouse III Paul Sabatier.
 *
 * <BR><BR>
 *
 */

/**
 * \file Borne.cpp
 * \brief Programme de gestion de la borne
 * \author CARTAGENA & REGNERE
 * \date Avril 2020
 *
 * C'est le programme principal du la borne de recharge.
 */

#include <stdio.h>
#include <memoire_borne.h>
#include <donnees_borne.h>
#include <iostream>
#include "Lecteurcarte.h"
#include "Base_clients.h"

using namespace std ;

Base_clients base ;
Lecteurcarte lecteur(base) ;

int main(void) {

    lecteur.initialiser() ;
    unsigned int choix ;

    while (1) {
        cout << endl
             << "------------------------------" << endl
             << "      BORNE DE RECHARGE       " << endl
             << "------------------------------" << endl
             << "Menu :" << endl
             << "1 : Recharger un vehicule" << endl
             << "2 : Ajouter un client" << endl
             << "3 : Quitter le programme" << endl ;

        cin >> choix ;

        switch(choix) {
            case 1:
                lecteur.lire_carte() ;
            break ;

            case 2:
                base.ajouter() ;
            break ;

            case 3:
                return 0 ;
            break ;
        }


    }

}
