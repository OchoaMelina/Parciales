/*
 * Productos.c
 *
 *  Created on: 13/05/2022
 *      Author: Ochoa Melina
 */
#include"Productos.h"

static int GenerarId(void);

static int GenerarId(void)
{
        static int contador=0;
        return contador++;
}

void eProducto_MostrarUno(Producto productos)
{
        printf("\n %5d %15s %15f %15d %15d",productos.idProducto,productos.nombreProducto,productos.precio,productos.categoria,productos.stock);
}
int eProducto_MostrarTodos(Producto productos[], int len)
{
        int i;
        int retorno=-1;
        puts("\n\tListado Productos\n");
        printf("%5s %15s %15s %15s %15s","ID","NOMBRE","PRECIO","CATEGORIA","STOCK");
        if(productos!=NULL && len>0)
        {
                for(i=0; i<len;i++)
                {
                    if (productos[i].isEmpty == 0)
                    {
                         continue;
                    }
                    else
                    {
                        eProducto_MostrarUno(productos[i]);
                        retorno=0;
                    }
                }
                retorno=0;

        }
        return retorno;

}


int eProducto_Inicializar(Producto productos[], int len)
{
    int retorno= -1;
    int i;
    if(productos!=NULL && len>0)
    {
        retorno=0;
        for(i=0;i<len; i++)
        {
            productos[i].isEmpty=0;
            retorno=0;
        }
    }
    return retorno;
}

int eProducto_buscarLibre(Producto productos[], int len)
{
    int retorno=-1;
    int i;
    if(productos!=NULL && len>0)
    {
        for(i=0;i<len;i++)
        {
            if(productos[i].isEmpty==0)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}

Producto eProducto_CargaDatos(Producto aux)
{
  utn_getString(aux.nombreProducto,"\nIngrese nombre del producto: ","\nError reingrese: ",2);
  getNumeroFloat(&aux.precio,"\nIngrese precio: ","\nError reingrese: ",1000000,0,2);
  getNumeroShort(&aux.categoria,"\nIngrese categoria del producto: ", "\nError reingrese: ",10,7,2);
  aux.stock=get_Int("\nIngrese cantidad","\nError");
  return aux;
}

int eProducto_Alta(Producto productos[], int len)
{
    int retorno=-1;
    int indexLibre;
    Producto aux;

    indexLibre=eProducto_buscarLibre(productos, len);
    if(productos==NULL && indexLibre==-1)
    {
        printf("No hay lugares libres");
    }
    else{
              aux=eProducto_CargaDatos(aux);
              aux.idProducto=GenerarId();
              aux.isEmpty=1;
              productos[indexLibre]=aux;
              retorno=0;

            }

    return retorno;
}



int eProducto_BuscarPorId(Producto productos[], int len)
{
        int ret=0;
        int i;
        int flag=0;
        int buscarId;
        if(productos!=NULL && len>0)
        {
                getNumero(&buscarId,"\nIngrese id: ","\nError ",2000,0,2);
                for(i=0;i<len;i++)
                {
                        if(productos[i].isEmpty==1)
                        {
                                if(productos[i].idProducto==buscarId)
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

int eProducto_Baja(Producto productos[], int len, int id)
{
        int ret=0;
        int indexBaja;
        if(productos!=NULL && len>0)
        {
                indexBaja=eProducto_BuscarPorId(productos, len);
                if(indexBaja<0)
                {
                        ret=-1;
                        puts("\nId no encontrado");
                }
                else{
                        if(indexBaja==id)
                          {
                            eProducto_MostrarUno(productos[indexBaja]);
                            puts("\nDesea eliminar producto?\n");
                            if(utn_getCaracterSN()==0)
                              {
                                productos[indexBaja].isEmpty=-1;
                              }

                          }

                }
        }
        return ret;
}

Producto eProducto_ModificarUno(Producto copia)
{
        int opcion;
        getNumero(&opcion,"\nIngrese una opcion a modificar "
                        "\n1.Nombre \n2.Categoria \n3.Precio \n4.Stock","Error",4,1,2);
        switch(opcion)
               {
                case 1:
                         utn_getString(copia.nombreProducto,"\nIngrese nombre:","Error",2);
                         break;
                case 2:
                		getNumeroShort(&copia.categoria,"\nIngrese categoria del producto: ", "\nError reingrese: ",10,7,2);
                        break;
                case 3:
                        getNumeroFloat(&copia.precio,"\nIngrese precio: ","\nError",1000,0,2);
                        break;
                case 4:
                        getNumero(&copia.stock,"\nIngrese cantidad en stock: ","\nError reingrese: ",900,0,2);
                        break;
                }
        return copia;
}

int eProducto_Modificar(Producto productos[], int len)
{
        int ret=0;
        int indexModificacion;
        Producto auxiliarProducto;
        if(productos!=NULL && len>0)
        {
                indexModificacion=eProducto_BuscarPorId(productos, len);
                if(indexModificacion==0)
                {
                    auxiliarProducto=productos[indexModificacion];
                    auxiliarProducto=eProducto_ModificarUno(auxiliarProducto);
                    productos[indexModificacion]=auxiliarProducto;
                }
                else{
                    puts("Id no encontrado");
                     ret=-1;

                }
        }
        return ret;
}

int eProducto_Sort(Producto productos[], int len, int criterio) {
	int rtn = 1;
	int i;
	int j;
	Producto aux;
	if (productos != NULL && len > 0) {
		switch (criterio) {
		case -1:
			for (i = 0; i < len - 1; i++)
			{
				for (j = i + 1; j < len; j++)
				{
					if (productos[i].isEmpty == OCUPADO
							&& productos[j].isEmpty == OCUPADO)
					{
						if (productos[i].categoria > productos[j].categoria)
						{
							aux = productos[i];
							productos[i] = productos[j];
							productos[j] = aux;
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
					if (productos[i].isEmpty == OCUPADO
							&& productos[j].isEmpty == OCUPADO)
					{
						if (productos[i].categoria < productos[j].categoria)
						{
							aux = productos[i];
							productos[i] = productos[j];
							productos[j] = aux;
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
