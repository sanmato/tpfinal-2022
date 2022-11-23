#ifndef ADL_H_INCLUDED
#define ADL_H_INCLUDED
#include "arbol.h"

nodoArbolCliente * CargaClientes(nodoArbolCliente * arbol,char ArchiClientes[]);

nodoArbolCliente * CargaConsumos(nodoArbolCliente * arbol,char ArchiConsumos[]);

int ContarRegistrosArchivo(char ArchiClientes[]);

void PasarArchiClientes_A_Arreglo(char ArchiClientes[],stCliente ArregloClientes[]);

void borrarADL(nodoArbolCliente* tree);







#endif // ADL_H_INCLUDED
