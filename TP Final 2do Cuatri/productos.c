#include "productos.h"
///Funciones productos ADMIN
void cargarArchivoProductos(char NombreArchivoProducto[])
{
    char opcion='s';
    int cantidadProductos=0;
    FILE*archi=NULL;
    archi=fopen(NombreArchivoProducto,"ab");
    stProductos a;


    do
    {
        cantidadProductos=contarProductosArchivo(NombreArchivoProducto)+1;
        printf("\nEl producto sera identificado con el id: %i\n",cantidadProductos);
        a.idProducto=cantidadProductos;

        printf("\nIngrese la descripcion del pedido\n");
        fflush(stdin);
        gets(a.descripcion);

        printf("\nIngrese coste del producto: $");
        fflush(stdin);
        scanf("%f", &a.precio);

        fwrite(&a,sizeof(stProductos),1,archi);

        printf("\nDesea agregar otro producto: s/n ");
        fflush(stdin);
        scanf("%c",&opcion);


    }
    while (opcion=='s');

    fclose(archi);
}

void MostrarUnProducto(stProductos a)
{
    printf("ID del producto:--------- %i \n",a.idProducto);
    printf("Descripcion de producto-- %s \n",a.descripcion);
    printf("Precio del producto:----- $ %.2f \n",a.precio);
    printf("\n\n");
}

void MostrarProductos(char NombreArchivoProducto[])
{
    FILE* archi;
    archi = NULL;

    stProductos a;

    archi = fopen(NombreArchivoProducto,"rb");

    while(fread(&a,sizeof(stProductos),1,archi)>0)
    {
        MostrarUnProducto(a);
    }

    fclose(archi);


}
int contarProductosArchivo(char NombreArchivoProducto[])
{
    int cantidad=0;
    FILE * archivin = NULL;
    archivin=fopen(NombreArchivoProducto,"rb");

    if (archivin!= NULL)
    {
        fseek(archivin,0,SEEK_END);
        cantidad=ftell(archivin)/sizeof(stProductos);
        fclose(archivin);
    }

    return cantidad;
}

///Funciones producto usuarios

int ComprobarIdProducto(char nombreArchivoProductos[],int id)
{
    FILE * archi = NULL;
    archi = fopen(nombreArchivoProductos,"rb");
    int flag = 0;
    stProductos a;

    while(fread(&a,sizeof(stProductos),1,archi)>0&& flag != 1)
    {
        if(a.idProducto==id)
        {

            flag = 1;
        }
    }
    return flag;
}

float calcularPrecioSegundId(char nombreArchivoProductos [],int id)
{
    FILE*archi=NULL;
    archi=fopen(nombreArchivoProductos,"rb");
    stProductos a;
    float costo=0;
    while(fread(&a,sizeof(stProductos),1,archi)>0)
    {
        if(a.idProducto==id)
        {
            costo=a.precio;
        }
    }
    fclose(archi);

    return costo;
}
