/**
 * \file Base_client.cpp
 * \brief Programme de gestion de la base client
 * \author CARTAGENA & REGNERE
 * \date Avril 2020
 *
 * Ce programme contient la description des méthodes de la classe Base_clients
 */

#include "Base_clients.h"
#include <iostream>
#include <fstream>


/**
 * \brief Constructeur
 *
 * Constructeur de la classe Base_clients.
 */

Base_clients::Base_clients() {
    clients.push_back(5) ;
    clients.push_back(7) ;
    clients.push_back(10) ;
    clients.push_back(12) ;
}

/**
 * \brief Méthode authentifier
 *
 * Cette méthode permet d'authentifier un client (vérifier qu'il fait bien partie de la base client).
 * \param num_carte Numero de la carte du client.
 * \return 1 en cas de succes ; 0 en cas d'échec.
 */

int Base_clients::authentifier(unsigned int num_carte) {
 unsigned int i = 0 ;
 unsigned int taille = clients.size() ;
 //cout << "taille " << taille << endl ;
    for (i = 0; i < taille; i++) {
        if (num_carte == clients[i]) {
            id = num_carte ;
	 	    return 1 ;
	 	}

	}
return 0 ;
}

/**
 * \brief Méthode reprise
 *
 * Cette méthode permet de gérer la reprise d'un véhicule.
 * \param num_carte Numero de la carte insérer lors de la reprise.
 * \return 1 si la carte correspond a la voiture ; 0 sinon.
 */

int Base_clients::reprise(unsigned int num_carte) {
    if (num_carte == id) {
        cout << "Vous pouvez reprendre votre vehicule" << endl ;
        return 1 ;
    }

    else {
        cout << "Mauvaise carte" << endl ;
        return 0 ;
    }
}

/**
 * \brief Méthode ajouter
 *
 * Cette méthode permet d'ajouter un client a la base clients.
 */

void Base_clients::ajouter() {
 Admin = 123 ;
 unsigned int mdp = 0 ;
 unsigned int ajout = 0 ;

    cout << "Numero carte Administrateur s'il vous plait (123) : " ;
    cin >> mdp ;
   // cout << "taille " << clients.size() << endl ;
    if (mdp == Admin) {
        cout << "Saisissez le numero de la carte a ajouter : " ;
        cin >> ajout ;
        clients.push_back(ajout) ;
        cout << "Ajout de la carte client " << ajout << endl ;
       // cout << "Taille : " << clients.size() << endl ;


        ofstream flux("bdc.txt") ;
        for (unsigned int i = 0; i < clients.size(); i++) {
            flux << clients[i] << endl ;
        }


    }

    else {
        cout << "Vous n'etes pas l'Administrateur !" << endl ;
    }

}
