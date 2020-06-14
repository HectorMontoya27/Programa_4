#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cuadruplas.h"
#include "backpatch.h"
#include "tipos.h"

int main(int argc, char const *argv[]) {
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

    eliminarListaIndice(lista1);
    eliminarCodigo(codigo);
    return 0;
}
