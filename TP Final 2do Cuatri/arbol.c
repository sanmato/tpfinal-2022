#include "arbol.h"
nodoArbolCliente * inicArbol()
{
    return NULL;
}

nodoArbolCliente * crearNodoArbol(stCliente dato)
{
    nodoArbolCliente * nuevo = (nodoArbolCliente*) malloc(sizeof(nodoArbolCliente));

    nuevo->dato=dato;

    nuevo->der =NULL;
    nuevo->izq =NULL;
    nuevo->pedidos=NULL;

    nuevo->modificado=0;

    return nuevo;
}

nodoArbolCliente * insertarPorId(nodoArbolCliente * arbol,nodoArbolCliente * nuevo)
{
    if(!arbol)
    {
        arbol = nuevo;
    }
    else
    {
        if(nuevo->dato.idCliente >= arbol->dato.idCliente)
        {
            arbol->der = insertarPorId(arbol->der,nuevo);
        }
        else
        {
            arbol->izq = insertarPorId(arbol->izq,nuevo);
        }
    }
    return arbol;
}

nodoArbolCliente * buscarUnNodoArbol(nodoArbolCliente * arbol,int id)
{
    nodoArbolCliente * buscado = inicArbol();
    if(arbol)
    {
        if(arbol->dato.idCliente == id)
        {
            buscado = arbol;

        }
        else
        {
            if(id>arbol->dato.idCliente)
            {
                buscarUnNodoArbol(arbol->der,id);
            }
            else
            {
                buscarUnNodoArbol(arbol->izq,id);
            }
        }
    }
    return buscado;
}

nodoArbolCliente * mostrarArbolInorder(nodoArbolCliente * arbol)
{
    if(arbol)
    {
        mostrarArbolInorder(arbol->izq);
        mostrarUnNodoArbol(arbol->dato);
        mostrarArbolInorder(arbol->der);
    }
    return arbol;
}

void mostrarUnNodoArbol(stCliente dato)
{
    ///HACER DEVUELTA
}

