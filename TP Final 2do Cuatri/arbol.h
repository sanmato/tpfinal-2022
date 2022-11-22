#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED
#include "clientes.h"
#include "lista.h"

typedef struct _nodoArbolCliente
{
    stCliente dato;
    int modificado;
    nodoListaPedidos* pedidos;
    struct _nodoArbolCliente* izq;
    struct _nodoArbolCliente* der;
} nodoArbolCliente;


nodoArbolCliente * inicArbol();

nodoArbolCliente * crearNodoArbol(stCliente dato);

nodoArbolCliente * insertarPorId(nodoArbolCliente * arbol,nodoArbolCliente * nuevo);

nodoArbolCliente * buscarUnNodoArbol(nodoArbolCliente * arbol,int id);



void mostrarArbolInorder(nodoArbolCliente * arbol);

nodoArbolCliente * arrayToArbol(stCliente Array[],int base,int tope);

void mostrarUnNodoArbol(stCliente dato);

nodoArbolCliente * buscarMenor(nodoArbolCliente * arbol);

nodoArbolCliente * eliminarNodoArbol(nodoArbolCliente * arbol, int id);



#endif // ARBOL_H_INCLUDED
