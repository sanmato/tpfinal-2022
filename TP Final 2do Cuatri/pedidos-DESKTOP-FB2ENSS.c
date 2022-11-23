///FUNCIONES PEDIDOS
#include "pedidos.h"
///Mostrar Pedidos
void MostrarUnPedido(stPedido a)
{
    printf("\nidPedido--------- %i\n",a.idPedido);
    printf("IdCliente-------- %i\n",a.idCliente);
    printf("Fecha------------ %s\n",a.fecha);
    printf("Descripcion:----- %s\n",a.descripcion);
    printf("Costo------------ %.2f\n",a.costo);
    printf("Pedido anulado--- %i\n",a.pedidoAnulado);
    printf("\n");
}

void MostrarTodosLosPedidos(char nombreArchivo[])
{
    FILE* archivin = NULL;

    archivin = fopen(nombreArchivo,"rb");

    stPedido aux;

    if(archivin!=NULL)
    {

        while(fread(&aux, sizeof(stPedido),1, archivin)>0)
        {
            MostrarUnPedido(aux);
        }
        fclose(archivin);
    }

}

void MostrarPedidosPorCliente(char nombreArchivo[],int idCliente)
{
    FILE* archivin = NULL;

    archivin = fopen(nombreArchivo,"rb");

    stPedido aux;

    if(archivin!=NULL)
    {
        printf("\nSe van a mostrar los pedidos validos del cliente %i\n",idCliente);

        while(fread(&aux, sizeof(stPedido), 1, archivin)>0)
        {

            if(aux.idCliente == idCliente && aux.pedidoAnulado == 0 )

                MostrarUnPedido(aux);
        }
        fclose(archivin);
    }

    else
    {
        printf("El archivo no pudo ser abierto\n");
    }
}
///Operaciones de Pedidos
void BuscarUnPedido(char nombreArchivo[], int idPedido)
{
    FILE * archivin = NULL;

    archivin = fopen(nombreArchivo,"rb");

    stPedido aux;

    int flag = 0;

    if(archivin!=NULL)

    {
        while(fread(&aux,sizeof(stPedido),1,archivin)>0 && flag == 0 )
        {

            if(aux.idPedido==idPedido)
            {
                printf("\nSe va a buscar el pedido con la id %i\n",idPedido);

                MostrarUnPedido(aux);

                flag = 1;
            }
        }
        fclose(archivin);

    }

}

int ModifcarPedidoAdmin(char nombreArchivo[],int idPedido,char nombreArchivoProducto[])
{
    int flag = 0;
    int idFlag = 0;
    int num = -1;
    int id =0;

    FILE* archivin = NULL;

    stPedido auxPedido;

    stProductos auxProducto;

    archivin = fopen(nombreArchivo,"r+b");

    if(archivin)
    {
        while( flag == 0 && fread(&auxPedido,sizeof(stPedido),1,archivin)>0)
        {

            if(auxPedido.idPedido == idPedido )
            {
                do
                {

                    MostrarProductos(nombreArchivoProducto);
                    printf("Ingrese ID del producto que desea:");
                    fflush(stdin);
                    scanf("%i",&id);
                    idFlag = ComprobarIdProducto(nombreArchivoProducto,id);

                    if(idFlag==1)
                    {

                        auxProducto = ObtenerNombreProducto(nombreArchivoProducto,id);
                        strcpy(auxPedido.descripcion,auxProducto.descripcion);

                        auxPedido.costo=calcularPrecioSegundId(nombreArchivoProducto,id);

                    }
                    else
                    {
                        printf("el id del pruducto ingresado es incorrecto\n");
                        system("pause");
                    }

                }
                while(idFlag==0);


                flag = 1;

                fseek(archivin, (sizeof(stPedido)*num), SEEK_CUR);
                fwrite(&auxPedido,sizeof(stPedido),1,archivin);
                fclose(archivin);
            }
        }
    }
    fclose(archivin);

    return flag;
}

void BajaPedido(char nombreArchivo[],int idPedido)
{
    int flag = 0;
    int num = -1;

    FILE * archivin = NULL;

    stPedido aux;

    archivin = fopen(nombreArchivo,"r+b");


    while( flag == 0 && fread(&aux,sizeof(stPedido),1,archivin)>0)
    {

        if(aux.idPedido == idPedido)
        {

            aux.pedidoAnulado=1;
            printf("El pedido %i se a dado de baja\n",idPedido);

            flag = 1;



            fseek(archivin, (sizeof(stPedido)*num), SEEK_CUR);
            fwrite(&aux,sizeof(stPedido),1,archivin);

        }
    }
    fclose(archivin);


}

int BajaPedidoPorCliente(char nombreArchivo[],int idPedido,int idCliente)
{
    int flag = 0;
    int num = -1;

    FILE * archivin = NULL;

    stPedido aux;

    archivin = fopen(nombreArchivo,"r+b");


    while( flag == 0 && fread(&aux,sizeof(stPedido),1,archivin)>0)
    {

        if(aux.idPedido == idPedido && aux.idCliente == idCliente)
        {
            printf("El pedido %i se a dado de baja\n",idPedido);

            flag = 1;

            aux.pedidoAnulado=1;


            fseek(archivin, (sizeof(stPedido)*num), SEEK_CUR);
            fwrite(&aux,sizeof(stPedido),1,archivin);
            fclose(archivin);
        }
    }
    fclose(archivin);

    return flag;
}

void BajaPedidoPorClienteArbol(char nombreArchivo[],int idCliente)
{

    int num = -1;

    FILE * archivin = NULL;

    stPedido aux;

    archivin = fopen(nombreArchivo,"r+b");


    while(fread(&aux,sizeof(stPedido),1,archivin)>0)
    {

        if(aux.idCliente == idCliente)
        {

            aux.pedidoAnulado=1;


//            fseek(archivin, (sizeof(stPedido)*num), SEEK_CUR);
//            fwrite(&aux,sizeof(stPedido),1,archivin);
               int pos=ftell(archi)-sizeof(stCliente);
                fseek(archi,pos,SEEK_SET);



        }
    }
    fclose(archivin);


}

int ModifcarPedidoUsuario(char nombreArchivoPedidos[],int idPedido,int idCliente,char nombreArchivoProductos[])
{
    int flag = 0,idFlag = 0;
    int num = 0;
    int id =0;

    FILE* archivin = NULL;

    stPedido aux;

    archivin = fopen(nombreArchivoPedidos,"r+b");


    while(fread(&aux,sizeof(stPedido),1,archivin)>0 && flag == 0 )
    {

        if(aux.idPedido == idPedido && aux.idCliente == idCliente)
        {
            do
            {
                system("cls");
                MostrarProductos(nombreArchivoProductos);
                printf("Ingrese ID del producto que desea:");
                fflush(stdin);
                scanf("%i",&id);
                idFlag = ComprobarIdProducto(nombreArchivoProductos,id);
                if(idFlag==1)
                {




                    aux.costo=calcularPrecioSegundId(nombreArchivoProductos,id);

                }
                else
                {
                    printf("el id ingresado es incorrecto\n");
                    system("pause");
                }

            }
            while(idFlag==0);


            flag = 1;

            fseek(archivin, (sizeof(stPedido)*num), SEEK_CUR);
            fwrite(&aux,sizeof(stPedido),1,archivin);
            fclose(archivin);
        }
    }
    fclose(archivin);







    return flag;
}

///Carga de Pedidos
void  CargarUnPedido(char nombreArchivo[],char nombreArchivoProductos[],int idCliente)
{
    FILE * archivin = NULL;
    int id = 0,idFlag =0;
    stProductos aux;

    archivin = fopen(nombreArchivo,"ab");

    printf("\n\tCarga de un pedido \n");
    stPedido pedidos;

    pedidos.idCliente=idCliente;


    printf("\tIngrese Fecha  DD/MM/AAAA \n\t");///AGREGAR INT S
    fflush(stdin);
    gets(pedidos.fecha);

    pedidos.pedidoAnulado=0;

    pedidos.idPedido = ContarPedidosArchivos(nombreArchivo) + 1;


    do
    {
        system("cls");
        MostrarProductos(nombreArchivoProductos);

        printf("\nIngrese ID del producto que desea:");

        fflush(stdin);
        scanf("%i",&id);
        idFlag = ComprobarIdProducto(nombreArchivoProductos,id);

        if(idFlag==1)
        {
            aux = ObtenerNombreProducto(nombreArchivoProductos,id);
            printf("%s\n",aux.descripcion);
            system("pause");

            strcpy(pedidos.descripcion,aux.descripcion);

        }
        else
        {
            printf("\tel id ingresado es incorrecto\n");
            system("pause");
        }

    }
    while(idFlag==0);

    pedidos.costo=calcularPrecioSegundId(nombreArchivoProductos,id);


    fwrite(&pedidos,sizeof(stPedido),1,archivin);

    fclose(archivin);

    MostrarUnPedido(pedidos);

    system("pause");

}

int ContarPedidosArchivos(char nombreArchivo[])
{
    int cantidad=0;
    FILE * archivin = NULL;
    archivin=fopen(nombreArchivo,"rb");

    if (archivin!= NULL)
    {
        fseek(archivin,0,SEEK_END);
        cantidad=ftell(archivin)/sizeof(stPedido);
        fclose(archivin);
    }

    return cantidad;
}

stProductos ObtenerNombreProducto(char nombreArchivo[],int id)
{
    stProductos aux;

    FILE * archivin = fopen(nombreArchivo,"rb");
    int flag = 0;

    if(archivin)
    {

        while( flag == 0 && fread(&aux,sizeof(stProductos),1,archivin)> 0)
        {
            if(aux.idProducto == id)
            {
                flag = 1;
            }
        }
    fclose(archivin);
    }

    return aux;
}
