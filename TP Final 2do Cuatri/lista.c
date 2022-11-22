#include "lista.h"
nodoListaPedidos * inicLista()
{
    return NULL;
}

nodoListaPedidos * crearNodo(stPedido dato)
{
    nodoListaPedidos * nuevo = (nodoListaPedidos*)malloc(sizeof(nodoListaPedidos));
    nuevo->dato =dato;
    nuevo->sig=NULL;
    nuevo->modificado = 0;

    return nuevo;
}

nodoListaPedidos * agregarEnOrdenPorFecha(nodoListaPedidos * lista,nodoListaPedidos * nuevo)
{
    if(!lista)
    {
        lista=nuevo;
    }
    else
    {
        if(nuevo->dato.anio <= lista->dato.anio &&  nuevo->dato.mes <= lista->dato.mes && nuevo->dato.dia <= lista->dato.dia)
        {
            lista = agregarListaAlPrincipio( lista, nuevo);
        }
        else
        {
            nodoListaPedidos * ante = lista;
            nodoListaPedidos * seg = lista;

            while(seg && nuevo->dato.anio >= seg->dato.anio && nuevo->dato.mes >= seg->dato.mes  && nuevo->dato.dia >= seg->dato.dia)
            {
                ante = seg;
                seg=seg->sig;
            }
            ante->sig= nuevo;
            nuevo->sig = seg;
        }
    }
    return lista;
}

nodoListaPedidos * agregarListaAlPrincipio(nodoListaPedidos * lista,nodoListaPedidos * nuevo)
{
    nuevo->sig=lista;

    return nuevo;
}

nodoListaPedidos * eliminarNodoLista(nodoListaPedidos * lista,nodoListaPedidos * eliminar)
{
    if(lista && eliminar)
    {
        nodoListaPedidos * seg = lista;
        nodoListaPedidos * ante = lista;

        if(seg==eliminar)
        {
            seg = lista;
            lista=lista->sig;
            free(seg);
        }
        else
        {
            while(seg && eliminar!=seg)
            {
                ante=seg;
                seg=seg->sig;
            }
            ante->sig=seg->sig;
            free(seg);
        }
    }

    return lista;
}

nodoListaPedidos * buscarNodoLista(nodoListaPedidos * lista,int id)
{
    nodoListaPedidos * buscado = inicLista();

    if(lista)
    {

        nodoListaPedidos * seg = lista;
        int flag = 0;

        while(seg && flag ==0)
        {

            if(seg->dato.idCliente == id)
            {
                buscado=seg;
                flag = 1;
            }

            seg=seg->sig;
        }

    }
    return buscado;

}

void MostrarLista(nodoListaPedidos * lista)
{
    nodoListaPedidos * seg = lista;

    while (seg)
    {
        MostrarUnPedido(seg->dato);
        seg=seg->sig;
    }
}

nodoListaPedidos * eliminarPrimerNodo(nodoListaPedidos * lista)
{
    nodoListaPedidos* aBorrar = lista;
    lista = lista->sig;
    free(aBorrar);
    return lista;
}

nodoListaPedidos * eliminarLista(nodoListaPedidos * lista)
{
    while(lista)
    {
        lista = eliminarPrimerNodo(lista);
    }
    return lista;
}



