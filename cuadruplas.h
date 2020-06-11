#ifndef CUADRUPLAS_H
#define CUADRUPLAS_H

/* ---------------------- Estructuras de codigo y cuadrupla ----------------------- */
typedef struct QUAD cuadru;
typedef struct CODE code;

struct QUAD{
    char *op;
    char *arg1;
    char *arg2;
    char *res;
    cuadru *siguente;
};

struct CODE{
    cuadru *inicio;
    cuadru *final;
};

/* -------------------------Declaracion de Funciones -------------------------- */
/* Creacion */
cuadru *crearCuadrupla();                                   //Pendiente
code *crearCodigo();                                        //Pendiente
/* Eliminacion */
void eliminarCuadrupla(cuadru * c);                         //Pendiente
void eliminarCodigo(code *c);                               //Pendiente
/* Utiles y necesarias */
void agregarCuadrupla(code *codigo, cuadru *cuadrupla);     //Pendiente


#endif
