//
// Created by Thomas on 30-Sep-18.
//

#include <stdio.h>

#include "administration.h"
#include "tools.h"

// Bug propre à CLion pour afficher printf dans le debugger
#define printf setbuf(stdout, 0);printf

void administrator() {
    int choix = 0;

    while (choix != 9) {
        printf("Bienvenue sur l'interface d'administration\n"
               "0) Ajouter un utilisateur\n"
               "1) Lister les utilisateurs\n"
               "2) Ajouter un jour special\n"
               "3) Lister les jours speciaux\n"
               "9) Se deconnecter\n");
        scanf("%d", &choix);

        switch (choix) {
            case 0:
                newUser();
                break;

            case 1:
                listUsers();
                break;

            case 2:
                specialDays[specialDaysNbr] = addSpecialDay();
                specialDaysNbr++;
                break;

            case 3:
                listSpecialDays();
                break;
        }
    }
}

void newUser() {
    struct User user;

    user.nRdvs = 0;

    printf("Nom de l'utilisateur ?\n");
    scanf("%s", user.nom);

    users[usrNbr] = user;
    usrNbr++;
}

void listUsers() {

    for (i = 0; i < usrNbr; i++) {
        printf("%d) %s\n", i + 1, users[i].nom);
    }

    int choix = 0;

    while(choix != 9) {
        printf("\n1) Renommer un utilisateur\n2) Supprimer un utilisateur\n9) Retour a l'interface d'administration");
        scanf("%d", &choix);

        if(choix == 1 || choix == 2) {

            int usrId;

            printf("Identifiant de l'utilisateur ? (Entre 1 et %d)\n", usrNbr);
            scanf("%d", &usrId);

            usrId--;

            if(choix == 1) {
                printf("Nouveau nom de l'utilisateur ?\n");
                scanf("%s", users[usrId].nom);
                printf("Le nouveau nom de l'utilisateur est %s\n", users[usrId].nom);
            }

            else if(choix == 2) {
                printf("Suppression de l'utilisateur %s...\n", users[usrId].nom);
                users[usrId] = users[usrNbr];
                usrNbr--;
            }
        }
    }
}

struct Rdv addSpecialDay() {
    struct Rdv specialDay;
    int day, month, year;

    printf("Nom du jour special ?\n");
    scanf("%s", specialDay.label);

    promptDate(&day, &month, &year);


    specialDay.jour = day;
    specialDay.mois = month;
    specialDay.annee = year;

    return specialDay;
}

void listSpecialDays() {

    int choice = 0;
    int specialDayId;

    for(i = 0; i < specialDaysNbr; i++) {
        printf("%d) %02d/%02d/%04d: %s\n", i + 1, specialDays[i].jour, specialDays[i].mois, specialDays[i].annee, specialDays[i].label);
    }

    while (choice != 9) {
        printf("1) Modifier un jour special\n2) Supprimer un jour special\n9) Retour au menu\n");
        scanf("%d", &choice);

        if(choice == 1 || choice == 2) {

            printf("Identifiant du jour special ? (De 1 a %d)\n", specialDaysNbr);
            scanf("%d", &specialDayId);

            specialDayId--;

            if(choice == 1)
                specialDays[specialDayId] = addSpecialDay();

            else if(choice == 2) {
                printf("Suppression du jour special %s\n", specialDays[specialDayId].label);
                specialDays[specialDayId] = specialDays[specialDaysNbr - 1];
                specialDaysNbr--;
            }
        }
    }
}