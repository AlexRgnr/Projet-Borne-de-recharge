/**
 * \file Generateur_SAVE.h
 * \brief Header de Generateur_SAVE
 * \author CARTAGENA & REGNERE
 * \date Avril 2020
 *
 * Ce programme contient la classe Generateur_SAVE et la déclaration de ses méthodes.
 */

#ifndef GENERATEUR_SAVE_H
#define GENERATEUR_SAVE_H
#include <donnees_borne.h>
#include <memoire_borne.h>
#include <lcarte.h>
#include <mem_sh.h>
#include "Voyant.h"
#include "Prise.h"
#include "Bouton.h"

/**
 * \class Generateur_SAVE
 * \brief Classe représentant le génerateur SAVE.
 * 
 * Cette classe gère les différents éléments de la borne liés au processus de recharge.
 */

class Generateur_SAVE {
 private :
    entrees *io ;
    int shmid ;
    Voyant voyant ;
    Prise prise ;
    Bouton bouton ;

 public :
    Generateur_SAVE() ;
    void charger();
    void generer_PWM(pwm signal) ;
    void fermer_AC() ;
    void ouvrir_AC() ;
    int reset_gene() ;
} ;

#endif
