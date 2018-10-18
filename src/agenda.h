/**
 * @file tools.c
 * @authors Thomas de Lachaux
 * @authors Louis Bichet
 * @copyright GNU Public License
 */

#ifndef AGENDA_AGENDA_H
#define AGENDA_AGENDA_H

#include "tools.h"

int currentUser;
int *nRdvs;
Rdv *rdvs;

void ajouterUnRdv();
void listerRdvParJour();
void afficherRdv(int id, Rdv *rdv);
Rdv nouveauRdv();
void sauvegarderRdv(Rdv *rdv);
int filterRdv(Rdv rdv, int day, int month, int year);
#endif //AGENDA_AGENDA_H