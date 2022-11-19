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
nodoArbolCliente * eliminarNodoArbol(int id);

nodoArbolCliente * mostrarArbolInorder(nodoArbolCliente * arbol);

void mostrarUnNodoArbol(stCliente dato);



#endif // ARBOL_H_INCLUDED
