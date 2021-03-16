//GENE_SAVE.C
#include "generateur_save.h"

entrees *io ;
int shmid ;


void generateur_save_initialiser()
{
 io=acces_memoire(&shmid) ; //associe l zone de memoire partagee au pointeur
 if(io == NULL)
 printf("Erreur pas de mem sh\n") ;
}

void charger()
{

int Fin = 0 ;
int EtatSuivant = 1, EtatPresent = 1 ; 

 while(Fin != 1)
 {
    switch(EtatPresent)
     {
	case 1: //Attente prise
		set_charge(ROUGE) ;
		deverouiller_trappe() ; // led_trappe = VERT
		generer_PWM(DC) ;
		if(io->gene_u == 9){  // valeur de tension retournee
		EtatSuivant = 2 ;}

		break ;

	case 2: //Prise branchee
		set_prise(VERT) ;
		verouiller_trappe() ; // led_trappe = OFF
		generer_PWM(AC_1K) ;
		if(io->gene_u == 6){
		EtatSuivant = 3 ;}
		if(appui_bouton_stop() == 1){
		raz_boutons() ;
		EtatSuivant = 5 ;}
		
		break ;

	case 3:	//Attente_s2_vehicule
		fermer_AC() ;
		generer_PWM(AC_CL) ;
		if(io->gene_u == 6){
		EtatSuivant = 4 ;}
		if( (appui_bouton_stop() == 1) ){ //|| (io->gene_u == 9) )
		raz_boutons() ;
		EtatSuivant = 5 ;} 
		
		break ;

	case 4: //Charge
		if(io->gene_u == 9){
		EtatSuivant = 5 ;}
		if(appui_bouton_stop() == 1){
		raz_boutons() ;
		EtatSuivant = 5 ;
		}

		break ;		

	case 5: //Batterie chargee
		ouvrir_AC() ;
		set_charge(VERT) ;
		generer_PWM(DC) ;
		Fin = 1 ;
		printf("Processus de recharge termine \n") ;

		break ;
    }

	EtatPresent = EtatSuivant ;		
        //printf("%d\n", EtatPresent);
 }

}

void generer_PWM(pwm signal)
{
	switch(signal)
	{
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
 
void fermer_AC()
{
 io->contacteur_AC = 1 ;
}

void ouvrir_AC()
{
 io->contacteur_AC = 0 ;
}

int reset_gene()
{
 int reset = 0 ;

 //printf("reset gene \n") ;	
 

	if(io->gene_u == 12) 
	{
	 printf("reset gene \n") ;
	 set_prise(OFF) ;
	 generer_PWM(STOP) ;
	 set_charge(OFF) ;
	 reset = 1 ;
	printf("%d\n", io->gene_u) ;
	}
return reset ;
}