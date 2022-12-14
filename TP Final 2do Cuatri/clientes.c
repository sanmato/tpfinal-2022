///FUNCIONES CLIENTES
#include "clientes.h"

void cargarUnClienteEnArchivo(int i, char archivo[])
{
    int flag=0;
    int comprobacion=0;
    char caracter;
    int c = 0;


    stCliente a;
    stCliente b;


    FILE *archi;
    archi=fopen(archivo,"ab");                              ///modificar
    printf("\n\tCarguemos sus datos\n\t");
    system("pause");
    if (archi!=NULL)
    {
        do
        {
            printf("\n\tIngrese su mail: ");
            fflush(stdin);
            scanf("%s", a.mail);
            comprobacion = esCorreoElectronico(a.mail);
            if(comprobacion == 1)
            {
                printf("\nEl correo se cargo correctamente:");
            }
            else
            {
                printf("\nIngrese un correo valido: \n");
            }

        }
        while(comprobacion ==0);


        printf("\n\tEl cliente sera identificado con el siguiente id: %i", i);///POSICION
        a.idCliente=i;

        printf("\n\tIngrese nombre: ");
        scanf("%s", a.nombre);

        printf("\n\tIngrese apellido: ");
        scanf("%s", a.apellido);

        do
        {
            printf("\n   Ingrese UserName:");
            fflush(stdin);
            scanf("%s",b.userName);
            flag=comprobarExistenciaUserName(archivo,b.userName);               ///Modularizar estooooo
            if (flag==1)
            {
                strcpy(a.userName,b.userName);
            }
            else
            {
                printf("\nUserName ya existente, intente nuevamente");
            }
        }
        while (flag==0);


 printf("\nElija su contraseña (8 caracteres como maximo): ");


            while (caracter = getch() )
                {
			if (caracter == TECLA_ENTER) {
				a.password[c] = '\0';
				break;

			} else if (caracter == TECLA_BACKSPACE) {
				if (c > 0) {
					c--;
					printf("\b \b");
				}

			} else {
				if (c < 8) {
					printf("*");
					fflush(stdin);
					a.password[c] = caracter;
					c++;
				}
			}

		}

        //scanf("%s", a.password);

        printf("\nGenero M-F-X: ");
        fflush(stdin);
        scanf("%c",&a.genero);

        a.rol = 0;

        a.activo=1;

        a.pedidos = NULL;

        fwrite(&a,sizeof(stCliente),1,archi);


        fclose(archi);
    }
}

int cargaDeClientes (char archivo[], int cantidadClientes)
{
    char opcion='s';
    int i=cantidadClientes;
    do
    {
        cargarUnClienteEnArchivo(i,archivo);
        i++;
        system("cls");
        printf("Desea cargar otro cliente: s/n");
        fflush(stdin);
        scanf("%c",&opcion);
    }
    while (opcion=='s');
    return i;
}
int comprobarExistenciaUserName (char archivo[],char  *user)
{
    int flag=1;
    stCliente a;
    FILE *archi;
    archi=fopen(archivo,"rb");
    if (archi!=NULL)
    {
        while (fread(&a,sizeof(stCliente),1,archi)>0)
        {
            if (strcmpi((a.userName),user)==0)
            {
                flag=0;
            }
        }
        fclose(archi);
    }
    return flag;
}

void mostrarUnCliente(stCliente a)
{
    printf("\n----------------------");
    printf("\n Idcliente: %i", a.idCliente);
    printf("\n    Nombre: %s",a.nombre);
    printf("\n  Apellido: %s",a.apellido);
    printf("\n  UserName: %s",a.userName);
    printf("\n  Password: %s",a.password);
    printf("\n      Mail: %s",a.mail);
    printf("\n    Genero: %c",a.genero);
    if (a.rol==1)
    {
        printf("\nRol: Admin");
    }
    else
    {
        printf("\nRol: Usuario");
    }
    if (a.activo==1)
    {
        printf("\n-------Cliente Activo-------\n");
    }
    else
    {
        printf("\n-------Cliente No activo------\n");
    }
}

void mostrarListaDeClientes (char archivo[])
{
    FILE *archi;
    archi=fopen(archivo,"rb");
    stCliente a;
    if (archi!=NULL)
    {
        printf("Lista de clientes: \n");
        while( fread(&a,sizeof(stCliente),1,archi)>0)
        {

            mostrarUnCliente(a);
        }
    }
    fclose(archi);
}


int buscarPosUserName(char archivo[],char * userName)
{
    int posicion=1000;
    FILE *archi;
    stCliente a;
    archi=fopen(archivo,"rb");
    if(archi!=NULL)
    {
        while(fread(&a,sizeof(stCliente),1,archi)>0)
        {
            if (strcmpi((a.userName),userName)==0)
            {
                posicion=ftell(archi)/sizeof(stCliente);
            }

        }
        fclose(archi);
    }
    if (posicion==1000)
    {
        printf("\nNo existe ese UserName");
    }
    return posicion;
}
void modificarArchivoCliente (char archivo[])
{
    int flag=1,posicion=0;

    char opcion='s';
    FILE*archi;
    stCliente a;
    archi=fopen(archivo,"r+b");
    if (archi!=NULL)
    {
        do
        {

            do
            {
                printf("\nIngrese el nombre de usuario desea modificar: ");
                fflush(stdin);
                scanf("%s", a.userName);
                flag=comprobarExistenciaUserName(archivo,a.userName);
                if (flag==1)
                {
                    printf("\nEl usurio no existe, intente nuevamente");
                }
            }
            while(flag==1);
            posicion=buscarPosUserName(archivo,a.userName);
            menuDeModificacion(archivo,posicion);

            printf("\nDesea modificar otro cliente: s-n");
            fflush(stdin);
            scanf("%c",&opcion);
        }
        while (opcion=='s');

        fclose(archi);
    }
}

int cantidadClientesDelArchivo (char archivo[])
{
    int cantidadClientes = 0;
    FILE*archi;
    archi=fopen(archivo,"r");
    if (archi!=NULL)
    {
        fseek(archi,sizeof(stCliente),SEEK_END);
        cantidadClientes=(ftell(archi)/sizeof(stCliente))-1;
        fclose(archi);
    }
    return cantidadClientes;
}

void modificarArchivoClienteUser (char archivo[],int idCliente)
{
    int posicion=0;


    FILE*archi;
    archi=fopen(archivo,"r+b");
    if (archi!=NULL)
    {

        posicion=buscarPosUserNamePorId(archivo,idCliente);
        menuDeModificacionUsuario(archivo,posicion);



        fclose(archi);
    }
}
int buscarPosUserNamePorId(char archivo[],int idCliente)
{
    int posicion=1000;
    FILE *archi;
    stCliente a;
    archi=fopen(archivo,"rb");
    if(archi!=NULL)
    {
        while(fread(&a,sizeof(stCliente),1,archi)>0)
        {
            if (a.idCliente==idCliente)
            {
                posicion=ftell(archi)/sizeof(stCliente);
            }

        }
        fclose(archi);
    }
    if (posicion==1000)
    {
        printf("\nNo existe ese UserName");
    }
    return posicion;
}

void menuDeModificacion (char archivo [],int posicion)
{
    char opcion='s';
    char control='z';
    int flag=10;
    FILE * archi;
    archi=fopen(archivo,"r+b");
    stCliente a;
    stCliente b;
    if (archi!=NULL)
    {
        do
        {
            rewind(archi);
            printf("\nQue informacion desea modificar: ");
            printf("\n a-Nombre");
            printf("\n b-Apellido");
            printf("\n c-UserName");
            printf("\n d-Password");
            printf("\n e-Mail");
            printf("\n f-Genero");
            printf("\n g-Rol");
            printf("\n h-Dar de baja cliente\n");
            printf("\n Cualquier tecla para salir\n");
            fflush(stdin);
            scanf("%c",&opcion);
            fseek(archi,sizeof(stCliente)*(posicion-1),SEEK_SET);
            fread(&a,sizeof(stCliente),1,archi);
            fseek(archi,sizeof(stCliente)*(posicion-1),SEEK_SET);
            switch (opcion)
            {
            case 'a':
            {

                printf("\nIngrese nuevo nombre: ");
                fflush(stdin);
                gets(a.nombre);
                fwrite(&a,sizeof(stCliente),1,archi);

            }
            break;
            case 'b':
            {

                printf("\nIngrese nuevo apellido: ");
                fflush(stdin);
                gets(a.apellido);
                fwrite(&a,sizeof(stCliente),1,archi);

            }
            break;
            case 'c':
            {
                do
                {
                    printf("\n   Ingrese UserName:");
                    fflush(stdin);
                    scanf("%s",b.userName);
                    flag=comprobarExistenciaUserName(archivo,b.userName);               ///Modularizar estooooo
                    if (flag==1)
                    {
                        strcpy(a.userName,b.userName);
                    }
                    else
                    {
                        printf("\nUserName ya existente, intente nuevamente");
                    }

                }
                while (flag==0);
                fwrite(&a,sizeof(stCliente),1,archi);

            }
            break;
            case 'd':
            {
                printf("\nIngrese nueva paswword: ");
                fflush(stdin);
                scanf("%s", a.password);
                fwrite(&a,sizeof(stCliente),1,archi);

            }
            break;
            case 'e':
            {
                printf("\nIngrese nuevo mail: ");
                fflush(stdin);
                scanf("%s", a.mail);
                fwrite(&a,sizeof(stCliente),1,archi);


            }
            break;
            case 'f':
            {
                printf("\nIngrese nuevo genero M-F-X: ");
                fflush(stdin);
                scanf("%c", &a.genero);
                fwrite(&a,sizeof(stCliente),1,archi);

            }
            break;
            case 'g':
            {
                printf("\n Si es admin ingrese 1 caso contrario 0: ");
                fflush(stdin);
                scanf("%i", &a.rol);
                fwrite(&a,sizeof(stCliente),1,archi);

            }
            break;
            case 'h':
            {
                printf("\n Si desea dar de baja cliente presione 0 si lo desea mantener activo 1: ");
                fflush(stdin);
                scanf("%i", &a.activo);
                fwrite(&a,sizeof(stCliente),1,archi);

            }
            break;
            default:
            {
                printf("Usted salio del menu\n");
            }
            }
            printf("Desea modificar otra caracteristica de este usurio: s-n");
            fflush(stdin);
            scanf("%c",&control);
        }
        while(control=='s');

        fclose(archi);
    }
}

void menuDeModificacionUsuario(char archivo[],int posicion)
{
    char opcion='s';
    char control='z';
    int flag=10;
    FILE * archi;
    archi=fopen(archivo,"r+b");
    stCliente a;
    stCliente b;
    if (archi!=NULL)
    {
        do
        {
            system("cls");
            rewind(archi);
            printf("\nQue informacion desea modificar: ");
            printf("\n a-Nombre");
            printf("\n b-Apellido");
            printf("\n c-UserName");
            printf("\n d-Password");
            printf("\n e-Mail");
            printf("\n f-Genero");
            printf("\n Cualquier tecla para salir\n");
            fflush(stdin);
            scanf("%c",&opcion);
            fseek(archi,sizeof(stCliente)*(posicion-1),SEEK_SET);
            fread(&a,sizeof(stCliente),1,archi);
            fseek(archi,sizeof(stCliente)*(posicion-1),SEEK_SET);
            switch (opcion)
            {
            case 'a':
            {

                printf("\nIngrese nuevo nombre: ");
                fflush(stdin);
                gets(a.nombre);
                fwrite(&a,sizeof(stCliente),1,archi);

            }
            break;
            case 'b':
            {

                printf("\nIngrese nuevo apellido: ");
                fflush(stdin);
                gets(a.apellido);
                fwrite(&a,sizeof(stCliente),1,archi);

            }
            break;
            case 'c':
            {
                do
                {
                    printf("\n   Ingrese UserName:");
                    fflush(stdin);
                    scanf("%s",b.userName);
                    flag=comprobarExistenciaUserName(archivo,b.userName);               ///Modularizar estooooo
                    if (flag==1)
                    {
                        strcpy(a.userName,b.userName);
                    }
                    else
                    {
                        printf("\nUserName ya existente, intente nuevamente");
                    }

                }
                while (flag==0);
                fwrite(&a,sizeof(stCliente),1,archi);

            }
            break;
            case 'd':
            {
                printf("\nIngrese nueva paswword: ");
                fflush(stdin);
                scanf("%s", a.password);
                fwrite(&a,sizeof(stCliente),1,archi);

            }
            break;
            case 'e':
            {
                printf("\nIngrese nuevo mail: ");
                fflush(stdin);
                scanf("%s", a.mail);
                fwrite(&a,sizeof(stCliente),1,archi);


            }
            break;
            case 'f':
            {
                printf("\nIngrese nuevo genero M-F-X: ");
                fflush(stdin);
                scanf("%c", &a.genero);
                fwrite(&a,sizeof(stCliente),1,archi);

            }
            break;
            default:
            {
                printf("Ah salido del menu\n");
            }
            }
            printf("Desea modificar otra caracteristica de este usurio: s-n");
            fflush(stdin);
            scanf("%c",&control);
        }
        while(control=='s');

        fclose(archi);
    }
}
void DarDeBajaCliente(char archivo[],int idCliente)
{
    int flag = 0;
    int num = -1;

    FILE * archi = fopen(archivo,"r+b");

    stCliente aux;

    if(archi)
    {
        while(flag==0 && fread(&aux,sizeof(stCliente),1,archi) >0)
        {

            if(aux.idCliente == idCliente)
            {
                aux.activo = 0;
                flag =1;
            }
        }
    }

    fseek(archi,(sizeof(stCliente)*num), SEEK_CUR);
    fwrite(&aux,sizeof(stCliente),1,archi);
    fclose(archi);
}

int iDeCaracterEnCadena(char *cadena, char caracter)
{
    int i = 0;
    while (cadena[i] != '\0')
    {
        char actual = cadena[i];
        if (actual == caracter)
        {
            return i;
        }
        i++;
    }

    return -1;
}


int ultimoiDeCaracterEnCadena(char *cadena, char caracter)
{
    int i = strlen(cadena) - 1;
    while (i >= 0)
    {
        char actual = cadena[i];
        if (actual == caracter)
        {
            return i;
        }
        i--;
    }
    return -1;

}

int esCorreoElectronico(char correo[])
{
    int iPunto = iDeCaracterEnCadena(correo, '.');
    int iArroba = iDeCaracterEnCadena(correo, '@');
    if (iPunto == -1 || iArroba == -1)
    {
        return 0;
    }

    if (iPunto != ultimoiDeCaracterEnCadena(correo, '.'))
    {
        return 0;
    }

    if (iArroba != ultimoiDeCaracterEnCadena(correo, '@'))
    {
        return 0;
    }

    if (iPunto < iArroba)
    {
        return 0;
    }
    return 1;
}

 void actualizaCliente2file(char archivoClientes[],int idCliente)
 {FILE *archi;
  stCliente regOfFile;
  int pos;
  int encontrado=0;

  archi=fopen(archivoClientes, "r+b");

  if (archi)
          {
            while((encontrado==0)&&(fread(&regOfFile, sizeof(stCliente),1,archi)>0))
            {
                if (regOfFile.idCliente == idCliente)
                {
                    encontrado=1;
                    pos=ftell(archi)/sizeof(stCliente);
                }
            }
            regOfFile.activo=0;
            fseek(archi,sizeof(stCliente)*(pos-1),0);
            fwrite(&regOfFile, sizeof(stCliente),1,archi);
            fclose(archi);
          }
 }


