#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cuadruplas.h"
#include "backpatch.h"

#include "tipos.h"

int main(int argc, char const *argv[]) {
    temp = 0;
    temp2 = 0;

    code *codigo = crearCodigo();
    listaIndice *lista1 = nuevaListaIndice();
    listaIndice *lista2 = nuevaListaIndice();

    agregarCuadrupla(codigo,crearCuadrupla("+","x","5","y"));
    agregarCuadrupla(codigo,crearCuadrupla("goto","x>5","-","L0"));
    agregarCuadrupla(codigo,crearCuadrupla("goto","-","-","L1"));
    agregarCuadrupla(codigo,crearCuadrupla("return","-","-","-"));
    agregarCuadrupla(codigo,crearCuadrupla("/","5","6","x"));

    imprimirCodigo(codigo);

    agregarIndice(lista1,nuevoIndice("L0"));
    agregarIndice(lista2,nuevoIndice("L1"));

    printf("\nLista 1\n");
    imprimirListaIndice(lista1);
    printf("\nLista 2\n");
    imprimirListaIndice(lista2);

    lista1 = combinar(lista1,lista2);

    printf("\nLista 1 (combinadas)\n");
    imprimirListaIndice(lista1);

    backpatch(codigo,lista1,"L2");

    imprimirCodigo(codigo);

    printf("El tipo maximo de 0 y 3 es: %d\n", max(0,3));
    printf("El tipo minimo de 0 y 3 es: %d\n", min(0,3));
    printf("El tipo maximo de 0 y 5 es: %d\n", max(0,5));
    printf("El tipo maximo de 100 y 100 es: %d\n", max(100,100));

    printf("ent x, real y\n");
    char r1[5], r2[5];
    char a1[5], a2[5];
    reducir(r1,"y",2,1,codigo);
    ampliar(a1,"x",1,2,codigo);
    ampliar(a2,"y",2,1,codigo);
    reducir(r2,"x",1,2,codigo);
    printf("reduccion y es: %s\n", r1);
    printf("ampliacion x es: %s\n", a1);
    printf("ampliacion y es: %s\n", a2);
    printf("reduccion x es: %s\n", r2);

    imprimirCodigo(codigo);

    eliminarListaIndice(lista1);
    eliminarCodigo(codigo);
    return 0;
}
