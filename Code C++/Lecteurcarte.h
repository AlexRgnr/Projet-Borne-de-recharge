/**
 * \file Lecteurcarte.h
 * \brief Header de Lecteurcarte
 * \author CARTAGENA & REGNERE
 * \date Avril 2020
 *
 * Ce programme contient la classe lecteurcarte et la déclaration de ses méthodes.
 */

#ifndef LECTEURCARTE_H
#define LECTEURCARTE_H
#include <lcarte.h>
#include "Timer.h"
#include "Base_clients.h"
#include "Voyant.h"
#include "Bouton.h"
#include "Generateur_SAVE.h"
#include "Prise.h"

/**
 * \class Lecteurcarte
 * \brief Classe représentant le lecteur de carte.
 *
 * Cette classe permet de gère la lecture des cartes.
 */
class Lecteurcarte {
 private :
   Voyant voyant ;
   Timer timer ;
   Bouton bouton ;
   Prise prise ;
   Generateur_SAVE gene ;
   Base_clients base ;

 public :
   Lecteurcarte(Base_clients &base) ;
   void initialiser();
   void lire_carte();

} ;


#endif
