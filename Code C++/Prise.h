/**
 * \file Prise.h
 * \brief Header de Prise
 * \author CARTAGENA & REGNERE
 * \date Avril 2020
 *
 * Ce programme contient la classe Prise et la declaration de ses methodes.
 */

#ifndef PRISE_H
#define PRISE_H
#include <donnees_borne.h>
#include <memoire_borne.h>
#include <mem_sh.h>

/**
 * \class Prise
 * \brief Classe représentant la prise.
 * 
 * Cette classe gère l'utilisation des trappes et du voyant de la prise.
 */

class Prise {
 private :
    entrees *io ;
    int shmid ;

 public :
    Prise() ;
    void set_prise(led Couleur) ;
    void deverouiller_trappe() ;
    void verouiller_trappe() ;

} ;

#endif
