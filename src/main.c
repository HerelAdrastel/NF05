/**
 * @file main.c
 * @brief Point d'entrée de l'application. L'utilisateur choisit entre le mode admin et utilisateur
 * @authors Thomas de Lachaux
 * @authors Louis Bichet
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "administration.h"
#include "agenda.h"
#include "tools.h"
#include "array.h"

// Bug propre à CLion pour afficher printf dans le debugger
#define printf setbuf(stdout, 0);printf



/*
 * todo: anglissisez les variables
 * todo: gerer les conflits
 * todo: gerer les heures +24
 * todo: ajouter un lieu, personnes
 * todo: gerer pb scanf espace
 */


void normalUser(int userId) ;
void initGlobals() ;

/**
 * @fn int main()
 * @brief Lancement de l'application
 * @return Code d'erreur de l'application
 */
int main() {
    initGlobals();

    int choix = 0;
    int i = 1;

    // todo: PASSER à DES DO WHILE
    while (choix != i+1) {

        printf("Bienvenue sur votre agenda. Qui êtes-vous ?\n0) Administrateur\n");

        for (i = 0; i < getSize(newUsers); i++) {
            printf("%d) %s\n", i + 1, get(newUsers, i).user.name);
        }

        printf("%d) Quitter\n", i + 1);
        inputint(&choix);

        if(choix == 0) {
            administrator();
        }

        else if (choix < i + 1 && choix <= getSize(newUsers)) {
            normalUser(choix - 1);
        }
    }

    printf("À bientôt !");
    return 0;
}
/**
 * @fn void initGlobals()
 * @brief Initialisation variables globales
 */
void initGlobals() {
    specialDaysNbr = 0;
    filterMode = 1;

    newUsers = initArray();

    User thomas, louis;

    strcpy(thomas.name, "Thomas");
    strcpy(louis.name, "Louis");

    // todo: creer un fonction createUser
    thomas.rdvs = initArray();
    louis.rdvs = initArray();

    add(newUsers, fromUser(thomas));
    add(newUsers, fromUser(louis));

}

/**
 * @brief Menu agenda
 * @param userId : identité utilisateur
 */
void normalUser(int userId) {
    currentUser = userId;

    // Par soucis de lisibilité
    rdvs = get(newUsers, currentUser).user.rdvs;

    printf("Agenda de %s\n", get(newUsers, currentUser).user.name);

    int choice = 0;
    int i = 1;

    while (choice != i + 1) {

        printf("\nQuelle action voulez-vous effectuer ?\n"
               "0) Ajouter un rendez-vous\n"
               "1) Lister les rendez-vous d'un jour\n"
               "%d) Se déconnecter\n", i + 1);
        inputint(&choice);

        switch (choice) {

            case 0:
                ajouterUnRdv();
                break;

            case 1:
                listerRdvParJour();
                break;

        }
    }
}