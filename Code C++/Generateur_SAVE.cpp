/**
 * \file Generateur_SAVE.cpp
 * \brief Programme de gestion du generateur SAVE
 * \author CARTAGENA & REGNERE
 * \date Avril 2020
 *
 * Ce programme contient la description des méthodes de la classe Generateur_SAVE
 */

#include "Generateur_SAVE.h"
#include <iostream>

using namespace std ;

/**
 * \brief Constructeur
 * 
 * Contructeur de la classe Generateur_SAVE. Initialise la mémoire.
 */

Generateur_SAVE::Generateur_SAVE() {
    io=acces_memoire(&shmid) ; //associe l zone de memoire partagee au pointeur
    if(io == NULL) {
        cout << "Erreur pas de mem sh" << endl ;
    }
}

/**
 * \brief Méthode charger
 * 
 * Cette méthode permet de gérer le cyclde de recharge d'un vehicule (basée sur une machine à états).
 */

void Generateur_SAVE::charger() {

 int Fin = 0 ;
 int EtatSuivant = 1, EtatPresent = 1 ; 

    while(Fin != 1) {

        switch(EtatPresent) {

            case 1: //Attente prise
                voyant.set_charge(ROUGE) ;
                prise.deverouiller_trappe() ; // led_trappe = VERT
                generer_PWM(DC) ;
                if(io->gene_u == 9) {  // valeur de tension retournee
                    EtatSuivant = 2 ;
                }
            break ;

            case 2: //Prise branchee
                prise.set_prise(VERT) ;
                prise.verouiller_trappe() ; // led_trappe = OFF
                generer_PWM(AC_1K) ;
                if(io->gene_u == 6) {
                    EtatSuivant = 3 ;
                }
                if(bouton.appui_bouton_stop() == 1) {
                    bouton.bouton_raz() ;
                    EtatSuivant = 5 ;
                }		
            break ;

            case 3:	//Attente_s2_vehicule
                fermer_AC() ;
                generer_PWM(AC_CL) ;
                if(io->gene_u == 6) {
                    EtatSuivant = 4 ;
                }
                if( (bouton.appui_bouton_stop() == 1) ) { //|| (io->gene_u == 9) )
                    bouton.bouton_raz() ;
                EtatSuivant = 5 ;
                } 
            break ;

            case 4: //Charge
                if(io->gene_u == 9){
                EtatSuivant = 5 ;}
                if(bouton.appui_bouton_stop() == 1) {
                    bouton.bouton_raz() ;
                    EtatSuivant = 5 ;
                }
            break ;		

            case 5: //Batterie chargee
                ouvrir_AC() ;
                voyant.set_charge(VERT) ;
                generer_PWM(DC) ;
                Fin = 1 ;
                cout << "Processus de recharge termine" << endl ;
            break ;

        }
	EtatPresent = EtatSuivant ;		
    //cout << "%d\n" << EtatPresent << endl ;
    }

}

/**
 * \brief Méthode generer_PWM
 * 
 * Cette méthode permet de génerer les différents signaux de la borne.
 * \param signal Type de signal a génerer.
 */

void Generateur_SAVE::generer_PWM(pwm signal) {
	switch(signal) {

	    case DC:
	        io->gene_pwm = DC ;
	    break ;

	    case AC_1K:
	        io->gene_pwm = AC_1K ;
	    break ;

	    case AC_CL:
	        io->gene_pwm = AC_CL ;
	    break ;

	    case STOP:
	        io->gene_pwm = STOP ;
	    break ;
	}
}
 
/**
 * \brief Méthode fermer_AC
 * 
 * Cette méthode gère la fermeture du contacteur AC.
 */

void Generateur_SAVE::fermer_AC() {
    io->contacteur_AC = 1 ;
}

/**
 * \brief Méthode ouvrir_AC
 * 
 * Cette méthode gère l'ouverture du contacteur AC.
 */

void Generateur_SAVE::ouvrir_AC() {
    io->contacteur_AC = 0 ;
}

/**
 * \brief Méthode reset_gene
 * 
 * Cette méthode permet un reset du generateur lorsque le conducteur débranche la prise.
 */

 int Generateur_SAVE::reset_gene() {
 int reset = 0 ;

 //printf("reset gene \n") ;	
 
	if(io->gene_u == 12) {
        // cout << "reset gene" << endl ; // Verification de rentree dans le if()
	    prise.set_prise(OFF) ;
	    generer_PWM(STOP) ;
	    voyant.set_charge(OFF) ;
	    reset = 1 ;
        // cout << "%d"<< io->gene_u << endl ; // Verification de la tension aux bornes de la prise
	}
return reset ;
}
