#ifndef BACKPATCH_H
#define BACKPATCH_H

#include "cuadruplas.h"

/* ---------------------- Estructuras de codigo y cuadrupla ----------------------- */

typedef struct INDEX index;
typedef struct LIST_INDEX listaIndex;

struct INDEX{
    char *indice;
    index *siguente;
};

struct LIST_INDEX{
    index* inicio;
    index* final;
};

/* -------------------------Declaracion de Funciones -------------------------- */
/* Creacion */
index* nuevoIndice();                                               //Pendiente
listaIndex* nuevaListaIndice();                                     //Pendiente
/* Eliminacion */
void eliminarIndice(index *indice);                                 //Pendiente
void eliminarListaIndice(listaIndex *lista);                        //Pendiente
/* Utiles y necesarias */
void agregarIndice(listaIndex *lista, index *indice);               //Pendiente
listaIndex* combinar(listaIndex *lista1, listaIndex *lista2);       //Pendiente
void backpatch(code *codigo, listaIndex *lista, char *label);       //Pendiente

#endif
