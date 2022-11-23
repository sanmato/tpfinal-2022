#include "lista.h"
#include "string.h"
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
        lista = nuevo;
    }
    else
    {
        if(strcmp(nuevo->dato.fecha, lista->dato.fecha)<0)
        {
            lista = agregarListaAlPrincipio(lista, nuevo);
        }
        else
        {
            nodoListaPedidos* ante = lista;
            nodoListaPedidos* seg = lista->sig;

            while(seg && (strcmp(nuevo->dato.fecha,seg->dato.fecha)>0))
            {
                ante = seg;
                seg = seg->sig;
            }
            nuevo->sig = seg;
            ante->sig = nuevo;
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

void MostrarListaValidos(nodoListaPedidos * lista)
{
    nodoListaPedidos * seg = lista;

    while (seg)
    {
        if(seg->dato.pedidoAnulado == 0)
        {
            MostrarUnPedido(seg->dato);
        }

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



