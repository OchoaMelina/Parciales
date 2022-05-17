/*
 * Usuario.c
 *
 *  Created on: 13/05/2022
 *      Author: Ochoa Melina
 */

#include"Usuario.h"

static int GenerarId(void);

static int GenerarId(void)
{
        static int contador=0;
        return contador++;
}

void eUsuario_MostrarUno(Usuario usuarios)
{
        printf("\n %5d %15s %15d \n",usuarios.idUsuario,usuarios.correo,usuarios.isEmpty);
}
int eUsuario_MostrarTodos(Usuario usuarios[], int len)
{
        int i;
        int retorno=-1;
        puts("\n\t Usuarios\n");
        printf("%5s %15s %15s","ID","CORREO","ESTADO");
        if(usuarios!=NULL && len>0)
        {
                for(i=0; i<len;i++)
                {
                    if (usuarios[i].isEmpty == INACTIVO)
                    {
                         continue;
                    }
                    else
                    {
                        eUsuario_MostrarUno(usuarios[i]);
                        retorno=0;
                    }
                }
                retorno=0;

        }
        return retorno;

}


int eUsuario_Inicializar(Usuario usuarios[], int len)
{
    int retorno= -1;
    int i;
    if(usuarios!=NULL && len>0)
    {
        retorno=0;
        for(i=0;i<len; i++)
        {
            usuarios[i].isEmpty=INACTIVO;
            retorno=0;
        }
    }
    return retorno;
}

int eUsuario_buscarLibre(Usuario usuarios[], int len)
{
    int retorno=-1;
    int i;
    if(usuarios!=NULL && len>0)
    {
        for(i=0;i<len;i++)
        {
            if(usuarios[i].isEmpty==INACTIVO)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}

Usuario eUsuario_CargaDatos(Usuario aux)
{
	getNumeroShort(&aux.tipo,"\n1.Usuario \t2.Administrador\nIngrese tipo: ","\nError",2,1,2);
	utn_getString(aux.correo,"\nIngrese su email: ","\nError reingrese: ",2);
	utn_getString(aux.password,"\nIngrese su contraseña: ","\nError reingrese: ",2);
	utn_getString(aux.direccion,"\nIngrese su direccion: ","\nError reingrese: ",2);
	getNumero(&aux.codPostal,"\nIngrese codigo postal: ", "\nError reingrese: ",9999,0001,2);
	return aux;
}

int eUsuario_Alta(Usuario usuarios[], int len)
{
    int retorno=-1;
    int indexLibre;
    Usuario aux;

    indexLibre=eUsuario_buscarLibre(usuarios, len);
    if(usuarios==NULL && indexLibre==-1)
    {
        printf("No hay lugares libres");
    }
    else{
              aux=eUsuario_CargaDatos(aux);
              aux.idUsuario=GenerarId();
              aux.isEmpty=1;
              usuarios[indexLibre]=aux;
              retorno=0;

            }

    return retorno;
}



int eUsuario_BuscarPorId(Usuario usuarios[], int len)
{
        int ret=0;
        int i;
        int flag=0;
        int buscarId;
        if(usuarios!=NULL && len>0)
        {
                buscarId=get_Int("\nIngrese id:","\nError");
                for(i=0;i<len;i++)
                {
                        if(usuarios[i].isEmpty==1)
                        {
                                if(usuarios[i].idUsuario==buscarId)
                                {
                                        flag=1;
                                        ret=i;
                                        break;
                                }
                        }
                }

        }
        else
        {
                if(flag==0)
                {
                   puts("\nError ID no encontrado");
                   ret=-1;
                }
        }
        return ret;
}

int eUsuario_Baja(Usuario usuarios[], int len, int id)
{
        int ret=0;
        int indexBaja;
        if(usuarios!=NULL && len>0)
        {
                indexBaja=eUsuario_BuscarPorId(usuarios, len);
                if(indexBaja<0)
                {
                        ret=-1;
                        puts("\nId no encontrado");
                }
                else{
                        if(indexBaja==id)
                          {
                            eUsuario_MostrarUno(usuarios[indexBaja]);
                            puts("\nDesea desactivar usuario?\n");
                            if(utn_getCaracterSN()==0)
                              {
                                usuarios[indexBaja].isEmpty=-1;
                              }

                          }

                }
        }
        return ret;
}

Usuario eUsuario_ModificarUno(Usuario copia)
{
        int opcion;
        getNumero(&opcion,"\nIngrese una opcion a modificar "
                        "\n1.Email \n2.Contraseña\n3.Direccion \n4.Codigo Postal","Error",4,1,2);
        switch(opcion)
               {
                case 1:
                         utn_getString(copia.correo,"\nIngrese email:","Error",2);
                         break;
                case 2:
                		utn_getString(copia.password,"\nIngrese contraseña:","Error",2);
                        break;
                case 3:
                		utn_getString(copia.direccion,"\nIngrese direccion:","Error",2);
                        break;
                case 4:
                		getNumero(&copia.codPostal,"\nIngrese codigo postal: ", "\nError reingrese: ",9999,0001,2);
                        break;
                }
        return copia;
}

int eUsuario_Modificar(Usuario usuarios[], int len)
{
        int ret=0;
        int indexModificacion;
        Usuario auxiliarUsuario;
        if(usuarios!=NULL && len>0)
        {
                indexModificacion=eUsuario_BuscarPorId(usuarios, len);
                if(indexModificacion==0)
                {
                    auxiliarUsuario=usuarios[indexModificacion];
                    auxiliarUsuario=eUsuario_ModificarUno(auxiliarUsuario);
                    usuarios[indexModificacion]=auxiliarUsuario;
                }
                else{
                    puts("Id no encontrado");
                     ret=-1;

                }
        }
        return ret;
}
int eUsuario_Sort(Usuario usuarios[], int len, int criterio)
{
	int rtn =-1;
	int i;
	int j;
	Usuario aux;
	if (usuarios != NULL && len > 0) {
		switch (criterio) {
		case 0:
			for (i = 0; i < len - 1; i++)
			{
				for (j = i + 1; j < len; j++)
				{
					if (usuarios[i].isEmpty == ACTIVO
							&& usuarios[j].isEmpty == ACTIVO)
					{
						if (usuarios[i].idUsuario > usuarios[j].idUsuario)
						{
							aux = usuarios[i];
							usuarios[i] = usuarios[j];
							usuarios[j] = aux;
						}
					}
				}
			}
			rtn = 0;
			break;
		case 1:
			for (i = 0; i < len - 1; i++)
			{
				for (j = i + 1; j < len; j++)
				{
					if (usuarios[i].isEmpty == ACTIVO
							&& usuarios[j].isEmpty == ACTIVO)
					{
						if (usuarios[i].idUsuario < usuarios[j].idUsuario)
						{
							aux = usuarios[i];
							usuarios[i] = usuarios[j];
							usuarios[j] = aux;
						}
					}
				}
			}
			rtn = 0;
			break;
		default:
			puts("\nError");
			break;
		}
	}
	return rtn;
}

int Ingreso(Usuario usuarios[],int len)
{
	int i;
	int ret=-1;
	char usuario[25];
	char password[10];
	if(usuarios!=NULL && len>0)
	{
		utn_getString(usuario,"\nIngrese su email: ","\nError reingrese: ",2);
		utn_getString(password,"\nIngrese su password: ","\nError reingrese: ",2);
		for(i=0;i<len;i++)
		{
			if(usuarios[i].correo==usuario || usuarios[i].password==password)
			{
				if(usuarios[i].tipo==USUARIO)
				{
					ret=0;
				}
				else
				{
					if(usuarios[i].tipo==ADMIN)
					{
						ret=1;
					}
				}
			}

		}
	}
	return ret;

}

void menuUsuario(int* opcion)
{
	puts("*******************************");
	puts("\n** 1er EXAMEN LAB I- 1H  **");
	puts("\n*********** USUARIO ***********\n");
	getNumero(opcion,"\n1)COMPRAR\n2)VENDER\n3)ESTADO DE COMPRAS"
			"\n4)ESTADO DE VENTAS\n\n0)SALIR\n","\nError reingrese",4,0,2);
}

void menuAdmin(int* opcion)
{
	puts("*******************************");
	puts("\n** 1er EXAMEN LAB I- 1H  **");
	puts("\n*********** ADMIN ***********\n");
	getNumero(opcion,"\n1)LISTAR ESTADO DE TODOS LOS USUARIOS\n2)LISTAR TODOS LOS PRODUCTOS POR CATEGORIA"
		"\n3)BAJA DE UN PRODUCTO\n4)BAJA DE UN USUARIO\n5)TRACKING GLOBAL\n\n0)SALIR\n","\nError reingrese",5,0,2);
}
