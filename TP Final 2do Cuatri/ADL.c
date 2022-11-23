#include "ADL.h"

nodoArbolCliente * CargaClientes(nodoArbolCliente * arbol,char ArchiClientes[])
{
    int dimension = ContarRegistrosArchivo(ArchiClientes);

    stCliente ArregloClientes[dimension];

    PasarArchiClientes_A_Arreglo(ArchiClientes,ArregloClientes);

    arbol = arrayToArbol(ArregloClientes,0,dimension-1);

    return arbol;
}

nodoArbolCliente * CargaConsumos(nodoArbolCliente * arbol,char ArchiConsumos[])
{
    FILE * archi = fopen(ArchiConsumos,"rb");

    if(archi && arbol)
    {
        stPedido r;
        nodoArbolCliente  * buscado = inicArbol();

        while(fread(&r,sizeof(stPedido),1,archi)>0)
        {
           if(r.pedidoAnulado != 1)
           {
                buscado = buscarUnNodoArbol(arbol,r.idCliente);
                if(buscado)
                {
                    buscado->pedidos=agregarEnOrdenPorFecha(buscado->pedidos,crearNodo(r));
                   // buscado->pedidos=agregarListaAlPrincipio(buscado->pedidos,crearNodo(r));
                }
           }
        }
        fclose(archi);
    }
    return arbol;
}

int ContarRegistrosArchivo(char ArchiClientes[])
{
    int dimension = 0;

    FILE * archi = fopen(ArchiClientes,"rb");

    if(archi)
    {
       fseek(archi,0,SEEK_END);

       dimension = ftell(archi)/sizeof(stCliente);
    }

    fclose(archi);
    return dimension;///ver esto
}

void PasarArchiClientes_A_Arreglo(char archiClientes[],stCliente ArregloClientes[])
{
    FILE * archi = fopen(archiClientes,"rb");
    int validos = 0;

    if(archi)
    {
        stCliente aux;

        while(fread(&aux,sizeof(stCliente),1,archi)>0)
        {
           if (aux.activo == 1)
           {
            ArregloClientes[validos] = aux;

            validos++;
           }
        }
        fclose(archi);

    }
}

void borrarADL(nodoArbolCliente* tree)
{
    if (tree)
    {
        borrarADL(tree->der);
        borrarADL(tree->izq);
        eliminarLista(tree->pedidos);
        free(tree);
    }
}
