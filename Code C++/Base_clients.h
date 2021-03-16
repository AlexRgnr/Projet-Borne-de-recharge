/**
 * \file Base_clients.h
 * \brief Header de Base_clients
 * \author CARTAGENA & REGNERE
 * \date Avril 2020
 *
 * Ce programme contient la classe Base_clients et la déclaration de ses méthodes.
 */

#ifndef BASE_CLIENT_H
#define BASE_CLIENT_H
#include <lcarte.h>
#include <vector>

using namespace std ;

/**
 * \class Base_clients
 * \brief Classe représentant la base clients.
 *
 * Cette classe gère la base clients de la borne.
 */

class Base_clients {
 private :
    unsigned int num_carte ;
    unsigned int id ;
    unsigned int Admin ;
    vector<unsigned int> clients ; // Vecteur de clients

 public :
    Base_clients() ;
    int authentifier(unsigned int num_carte) ;
    int reprise(unsigned int num_carte) ;
    void ajouter() ;
} ;

#endif
