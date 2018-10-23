/**
 * @file tools.h
 * @authors Thomas de Lachaux
 * @authors Louis Bichet
 * @copyright GNU Public License
 */

#ifndef AGENDA_TOOLS_H
#define AGENDA_TOOLS_H

typedef struct Rdv Rdv;
typedef struct User User;
typedef struct Type Type;
typedef struct Element Element;
typedef struct Array Array;


/**
 * @struct Rdv
 * @brief Structure rendez-vous
 * @var Rdv::label
 * Nom du rendez-vous
 * @var Rdv::year
 * Année du rendez-vous
 * @var Rdv::month
 * Mois du rendez-vous
 * @var Rdv::day
 * Jour du rendez-vous
 * @var Rdv::hour
 * Heure du rendez-vous
 * @var Rdv::minute
 * Minute du rendez-vous
 * @var Rdv::duration
 * Durée du rendez-vous
 * @var Rdv::place
 * Lieu du rendez-vous
 * @var Rdv::with
 * Personnes présentes au rendez-vous
 */


struct Rdv {
    char label[100];
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int duration;
    char place[100];
    char with[100];
};

/**
 * @struct User
 * @brief Structure utilisateur
 * @var User::nRdvs
 * Nombre de rendez-vous
 * @var User::name
 * Nom de l'utilisateur
 * @var User::rdvs
 * Rendez-vous de l'utilisateur
 */


struct User {
    int nRdvs;
    char name[40];
    Rdv rdvs[1000];
    Array *newRdvs;
};


struct Type {
    Rdv rdv;
    User user;
    int number;
};

struct Element {
    Type value;
    Element *previous;
    Element *next;
};


struct Array {
    Element *first;
    int size;
};

void promptDate(int *day, int *month, int *year);
int weekNumber(int day, int month, int year);
#endif //AGENDA_TOOLS_H
