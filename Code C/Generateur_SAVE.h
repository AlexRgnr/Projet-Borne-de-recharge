//GENE_SAVE.H
#ifndef GENERATEUR_SAVE_H
#define GENERATEUR_SAVE_H
#include <donnees_borne.h>
#include <memoire_borne.h>
#include <lcarte.h>
#include <mem_sh.h>
#include "voyants.h"
#include "prise.h"
#include "boutons.h"

void generateur_save_initialiser() ;
void charger();
void generer_PWM(pwm signal) ;
void fermer_AC() ;
void ouvrir_AC() ;
int reset_gene() ;

#endif