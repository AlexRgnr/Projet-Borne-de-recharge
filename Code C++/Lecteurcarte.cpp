/**
 * \file Lecteurcarte.cpp
 * \brief Programme de gestion du lecteur de carte
 * \author CARTAGENA & REGNERE
 * \date Avril 2020
 *
 * Ce programme contient la description des méthodes de la classe Lecteurcarte.
 */

#include <unistd.h>
#include <stdio.h>
#include "Lecteurcarte.h"
#include <iostream>

using namespace std ;

/**
 * \Brief Constructeur
 * 
 * Constructeur de la classe Lecteurcarte
 */

Lecteurcarte::Lecteurcarte(Base_clients &base):base(base) {

}

/**
 * \brief Méthode initialiser
 *
 * Cette méthode permet d'initialiser les ports de la borne de rechrage.
 */

void Lecteurcarte::initialiser() {
    initialisations_ports() ;
}

/**
 * \brief Methode lire_carte
 *
 * Cette methode permet de lire les cartes et de lancer le processus de recharge.
 */

void Lecteurcarte::lire_carte() {
 unsigned int num_carte ;

    attente_insertion_carte() ;
    num_carte = lecture_numero_carte() ;

    cout << "Carte : " << num_carte << endl ;

    if (base.authentifier(num_carte) == 1) {
        cout << "Authentification reussie" << endl ;

        voyant.blink_charge() ; // clignotement de CHARGE
        voyant.set_charge(OFF) ;

        timer.timer_raz() ;
        while ( (bouton.appui_bouton_charge() == 0) && (timer.timer_valeur() <= 60) ) ;

        if (timer.timer_valeur() > 60) {
            cout << "Temps depasse" << endl ;
        }

        if ( (bouton.appui_bouton_charge() == 1) && (timer.timer_valeur() <= 60) ) {	
            bouton.bouton_raz() ;
   	        voyant.set_dispo(OFF) ;
            attente_retrait_carte() ;
            gene.charger() ;

            // Arrive ici, la recharge est terminee
            // Reprise du vehicule
            do {
                attente_insertion_carte() ;
                num_carte = lecture_numero_carte() ;
                cout << "Carte : " << num_carte << endl ;
            } while (base.reprise(num_carte) == 0) ;

            prise.deverouiller_trappe() ; 
            while(1) {  //oblige de faire le while(1) ici et non dans le gene_save
               if (gene.reset_gene() == 1) {
                    prise.verouiller_trappe() ;
		            break ;
               }
	        }

            attente_retrait_carte() ;
            cout << "A bientot !" << endl ;
        }

        
    }

    else {
        if (base.authentifier(num_carte) == 0) {
            cout << "Client non reconnu" << endl ;
        }
        cout << "Erreur de procedure" << endl ;
	    voyant.blink_defaut() ; // clignotement de DEFAUT
	    voyant.set_defaut(OFF) ;
    }

    voyant.set_dispo(VERT) ;
}
