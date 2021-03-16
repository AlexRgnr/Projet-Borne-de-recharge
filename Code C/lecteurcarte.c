//LECTEUR_CARTE.C
#include <unistd.h>
#include <stdio.h>
#include "lecteurcarte.h"


void lecteurcarte_initialiser()
{
 initialisations_ports() ;
 voyants_initialiser() ;
 boutons_initialiser() ;
}

void lecteurcarte_lire_carte()
{
unsigned int num_carte = 0 ;

 while(1){

 printf("Presentez carte \n") ;
 attente_insertion_carte() ;

    if(carte_inseree()){
	  num_carte = lecture_numero_carte() ;
 	  printf("Carte : %d \n", num_carte) ;	
	
 	  if (authentifier(num_carte) == 1 ) {	 
	    printf("Authentification Client : OK\n") ;
	    break ; 
	  }

	  else {
	    printf("Authentification non reconnue\n") ;
	    printf("Retirez votre carte\n");
	    timer_raz() ;
	    blink_defaut() ; // clignotement de DEFAUT
	    set_defaut(OFF) ;
	    timer_raz() ;
	  //sleep(3) ;
	  }
 	}
 }
 
 timer_raz() ;
 blink_charge() ; // clignotement de CHARGE
 set_charge(OFF) ;		 
 timer_raz() ;

 while(timer_valeur() < 60){ // Une minute pour appuyer
	  		
	if(appui_bouton_charge() == 1){	
    	  raz_boutons() ;
   	  set_dispo(OFF) ;
   	  break ; // si il y a un appui, on sort du while
  	}
 }	

 printf("Retirez carte \n") ;
 attente_retrait_carte() ;

 charger() ; // lancement du processus de charge
 printf("Presentez carte pour Retrait \n") ;
 attente_insertion_carte() ;
 
 if(carte_inseree()){
    if(authentifier(num_carte) == 1 ){
	printf("Authentification Retrait Vehicule : OK\n") ;
    }
    else{
	printf("Mauvaise voiture\n") ;
    }
	deverouiller_trappe() ; 
	while(1){  //oblige de faire le while(1) ici et non dans le gene_save (pourquoi ??)
	     if(reset_gene()==1){
		verouiller_trappe() ;
		break ;
		}
	}
		   
		 
	printf("Vous pouvez recuperer votre vehicule\n") ;
	printf("N'oubliez pas votre carte\n") ;
	attente_retrait_carte() ;
    
 }
//liberation_ports() ;
set_dispo(VERT) ;	
}