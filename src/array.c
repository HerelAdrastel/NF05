#include <stdlib.h>
#include <stdio.h>
#include "array.h"

// todo: passer du camel case a f_f_ pour vars

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCDFAInspection"

Array *initArray() {

    Array *array = malloc(sizeof(*array));
    array->first = NULL;
    array->size = 0;

    return array;
}

// ===== GETTERS =====

Type get(Array *array, int index) {

    Element *elt = array->first;
    int i = 0;

    for(i = 0; i < index; i++) {

        if(elt == NULL) {
            printf("Index trop grand !");
            exit(EXIT_FAILURE);
        }

        elt = elt->next;
    }

    return elt->value;
}

Element *getLastElement(Array *array) {

    Element *elt = array->first;

    while (elt->next != NULL) {
        elt = elt->next;
    }

    return elt;
}

int getSize(Array *array) {
    return array->size;
}

// ===== SETTERS =====

void add(Array *array, Type new_value) {

    Element *new_elt = malloc(sizeof(*new_elt));
    new_elt->value = new_value;
    new_elt->next = NULL;

    // Si il n'y a aucun element dans le tableau
    if (array->first == NULL) {
        array->first = new_elt;
    }

        // Si il y a un element dans le tableau
    else {
        Element *lastElt = getLastElement(array);
        lastElt->next = new_elt;
    }

    array->size++;
}

void displayArray (Array *liste) {

    Element *elt = liste->first;

    while (elt != NULL)
    {
        printf("%d -> ", elt->value.number);
        elt = elt->next;
    }
    printf("NULL\n");
}
#pragma clang diagnostic pop