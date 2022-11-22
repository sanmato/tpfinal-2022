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
                buscado=buscarUnNodoArbol(arbol->der,id);
            }
            else
            {
                buscado=buscarUnNodoArbol(arbol->izq,id);
            }
        }
    }
    return buscado;
}

void mostrarArbolInorder(nodoArbolCliente * arbol)
{
    if(arbol)
    {
        mostrarArbolInorder(arbol->izq);

        mostrarUnCliente(arbol->dato);
        MostrarLista(arbol->pedidos);

        mostrarArbolInorder(arbol->der);
    }

}

void mostrarArbolPreOrder(nodoArbolCliente * arbol)
{
    if(arbol)
    {
        mostrarUnCliente(arbol->dato);
        MostrarLista(arbol->pedidos);
        mostrarArbolPreOrder(arbol->izq);
        mostrarArbolPreOrder(arbol->der);
    }

}


nodoArbolCliente * arrayToArbol(stCliente Array[],int base,int tope)
{
    int medio;
    nodoArbolCliente* tree=NULL;
    nodoArbolCliente* nuevoNodo=NULL;

    if(!(base>tope))
    {
        medio=(base+tope)/2;
        nuevoNodo=crearNodoArbol(Array[medio]);
        tree=insertarPorId(tree,nuevoNodo);
        tree->izq=arrayToArbol(Array,base,medio-1);
        tree->der=arrayToArbol(Array,medio+1,tope);
    }
return tree;
}

nodoArbolCliente * buscarMenor(nodoArbolCliente * arbol)
{
    while(arbol->izq != NULL) {
        arbol = arbol->izq;
    }
    return arbol;
}

nodoArbolCliente * eliminarNodoArbol(nodoArbolCliente * arbol, int id)
{
    if (arbol == NULL)
    {
        return arbol;
    }
    else if (id < arbol->dato.idCliente)
    {
        arbol->izq = eliminarNodoArbol(arbol->izq, id);
    }
    else if (id > arbol->dato.idCliente)
    {
        arbol->der = eliminarNodoArbol(arbol->der, id);
    }
    else
    {
        /// Caso: Nodo hoja.
        if (arbol->izq == NULL && arbol->der == NULL)
        {
            arbol->pedidos = eliminarLista(arbol->pedidos);
            free(arbol);
            arbol = NULL;
        }
        /// Caso: Arbol con 1 nodo hijo.
        else if (arbol->izq == NULL)
        {
            nodoArbolCliente *temp = arbol;
            arbol = arbol->der;
            temp->pedidos = eliminarLista(temp->pedidos);
            free(temp);
        }
        else if (arbol->der == NULL)
        {
            nodoArbolCliente *temp = arbol;
            arbol = arbol->izq;
            temp->pedidos = eliminarLista(temp->pedidos);
            free(temp);
        }
        /// Caso: Arbol con 2 nodos hijos.
        else {
            nodoArbolCliente* temp = buscarMenor(arbol->der);
            arbol->dato = temp->dato;
            arbol->der = eliminarNodoArbol(arbol->der, temp->dato.idCliente);
        }
    }

    return arbol;
}


void mostrarUnNodoArbol(stCliente dato)
{
    ///HACER DEVUELTA
}

