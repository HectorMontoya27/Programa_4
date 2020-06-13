#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "backpatch.h"
#include "cuadruplas.h"

/* --------------------------- Formato de Documentacion ------------------------- */

// Documentacion de Creacion - Copiar y pegar
/*
--Nombre Funcion:
--Descripcion:
--Autor:
--Fecha de creacion:
*/
// Documentacion de Modificacion - Copiar y pegar
/*
--Fecha de modificacion:
--Autor modificacion:
--Descripcion de modificacion:
*/

/* -------------------------------- Funciones -------------------------------- */
/*
--Nombre Funcion: nuevoIndice()
--Descripcion: Creacion de un nuevo indice
--Autor: Héctor Montoya Pérez
--Fecha de creacion: 13 Junio 2020
*/
index* nuevoIndice(char *i){
    index *indice = (index *)malloc(sizeof(index));
    indice->indice = i;
    indice->siguente = NULL;
    return indice;
}

/*
--Nombre Funcion: nuevaListaIndice()
--Descripcion: Creacion de un nueva lista de indices
--Autor: Héctor Montoya Pérez
--Fecha de creacion: 13 Junio 2020
*/
listaIndex* nuevaListaIndice(){
    listaIndex *lista = (listaIndex *)malloc(sizeof(listaIndex));
    lista->inicio = NULL;
    lista->final = NULL;
    return lista;
}

/*
--Nombre Funcion: eliminarIndice()
--Descripcion: Libera la memoria de un indice y los siguentes a el
--Autor: Héctor Montoya Pérez
--Fecha de creacion: 13 Junio 2020
*/
void eliminarIndice(index *indice){
    if (indice != NULL) {
        eliminarIndice(indice->siguente);
        free(indice);
    }
}

/*
--Nombre Funcion: eliminarListaIndice()
--Descripcion: Libera la memoria de una lista de indices y de su contenido
--Autor: Héctor Montoya Pérez
--Fecha de creacion: 13 Junio 2020
*/
void eliminarListaIndice(listaIndex *lista){
    if (lista != NULL){
        eliminarIndice(lista->inicio);
        free(lista);
    }
}

/*
--Nombre Funcion: agregarIndice()
--Descripcion: Se agrega un nuevo indice a la lista
--Autor: Héctor Montoya Pérez
--Fecha de creacion: 13 Junio 2020
*/
void agregarIndice(listaIndex *lista, index *indice){
    if (lista != NULL) {
        if (indice != NULL) {
            if (lista->inicio == NULL){
                lista->inicio = indice;
                lista->final = indice;
            } else {
                lista->final->siguente = indice;
                lista->final = indice;
            }
        } else { printf("No existe el indice a insertar\n"); }
    } else { printf("No existe la lista referida\n"); }
}

/*
--Nombre Funcion:
--Descripcion:
--Autor:
--Fecha de creacion:
*/
listaIndex* combinar(listaIndex *lista1, listaIndex *lista2){
    
}

/*
--Nombre Funcion:
--Descripcion:
--Autor:
--Fecha de creacion:
*/
void backpatch(code *codigo, listaIndex *lista, char *label){}
