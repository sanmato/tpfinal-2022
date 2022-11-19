#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include "pedidos.h"

typedef struct _nodoListaPedidos
{
    stPedido dato;
    int modificado;    /// 0 si no se modifico
    struct _nodoListaPedidos* sig;
} nodoListaPedidos;

nodoListaPedidos * iniclista();
nodoListaPedidos * crearNodo(stPedido dato);
nodoListaPedidos * agregarEnOrdenPorFecha(nodoListaPedidos * lista,nodoListaPedidos * nuevo);
nodoListaPedidos * agregarListaAlPrincipio(nodoListaPedidos * lista,nodoListaPedidos * nuevo);

nodoListaPedidos * buscarNodoLista(nodoListaPedidos * lista, int id);
nodoListaPedidos * eliminarNodoLista(nodoListaPedidos * lista,nodoListaPedidos * eliminar);


void   mostrarUnNodo(stPedido dato);
void   MostrarLista(nodoListaPedidos * lista);


#endif // LISTA_H_INCLUDED
