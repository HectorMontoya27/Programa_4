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
index* nuevoIndice(char *i);                                        //Lista
listaIndex* nuevaListaIndice();                                     //Lista
/* Eliminacion */
void eliminarIndice(index *indice);                                 //Lista
void eliminarListaIndice(listaIndex *lista);                        //Lista
/* Utiles y necesarias */
void agregarIndice(listaIndex *lista, index *indice);               //Lista
listaIndex* combinar(listaIndex *lista1, listaIndex *lista2);       //Pendiente
void backpatch(code *codigo, listaIndex *lista, char *label);       //Pendiente

#endif
