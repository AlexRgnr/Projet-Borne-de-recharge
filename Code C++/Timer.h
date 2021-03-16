/**
 * \file Timer.h
 * \brief Header de Timer
 * \author CARTAGENA & REGNERE
 * \date Avril 2020
 *
 * Ce programme contient la classe Timer et la déclaration de ses méthodes.
 */

#ifndef TIMER_H
#define TIMER_H
#include <donnees_borne.h>
#include <memoire_borne.h>

/**
 * \class Timer
 * \brief Classe représentant le timer.
 * 
 * Elle gère le timer de la borne.
 */

class Timer {
 private :
    entrees *io ;
    int shmid ;
    int depart_timer ;

 public :
    Timer() ;
    void timer_raz() ;
    int timer_valeur() ;    
} ;

#endif
