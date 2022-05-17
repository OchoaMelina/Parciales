/*
 * Tracking.c
 *
 *  Created on: 15/05/2022
 *      Author: Ochoa Melina
 */

#include "Tracking.h"

static int GenerarId(void);

static int GenerarId(void)
{
        static int contador=0;
        return contador++;
}
int eTracking_Inicializar(Tracking list[], int len)
{
    int retorno= -1;
    int i;
    if(list!=NULL && len>0)
    {
        retorno=0;
        for(i=0;i<len; i++)
        {
            list[i].isEmpty=0;
            retorno=0;
        }
    }
    return retorno;
}

int eTracking_buscarLibre(Tracking list[], int len)
{
    int retorno=-1;
    int i;
    if(list!=NULL && len>0)
    {
        for(i=0;i<len;i++)
        {
            if(list[i].isEmpty==0)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}

Tracking eTracking_CargaDatos(Tracking aux)
{
 aux.cantidad=get_Int("\nIngrese cantidad deseada: ","\nError");
 aux.distanciaKm=CalcularDistancia();
 aux.horaLlegada=CalcularHoraLlegada(aux.distanciaKm);
 if(aux.horaLlegada>time(NULL))
 {
	 aux.estado=EN_VIAJE;

 }else{
	 if(aux.horaLlegada==time(NULL))
	 {
		 aux.estado=ENTREGADO;
	 }
	 else
	 {
		 aux.estado=CANCELADO;
	 }
 }

  return aux;
}

int CalcularDistancia()
{
	int codPostal;
	int distanciaKm=0;
	printf("\nIngrese codigo postal: ");
	scanf("%d",&codPostal);
	if(codPostal>=0001 && codPostal<=1000)
	{
		distanciaKm=20;
	}else{
		if(codPostal>=1001 && codPostal<=3000)
		{
			distanciaKm=30;
		}else{
			if(codPostal>=3001 && codPostal<=5000)
			{
				distanciaKm=50;
			}else{
				if(codPostal>=5001 && codPostal<=8000)
				{
					distanciaKm=80;
				}else{
					if(codPostal>=8001 && codPostal<=9999)
					{
						distanciaKm=150;
					}
				}
			}
		}
	}
	return distanciaKm;
}

long int Time_Current(void){
	return time(NULL);
}
long int time_add(double secondsAdd){
	return secondsAdd + Time_Current();
}
long int CalcularHoraLlegada(int distanciaKm)
{
	double seconds;
	long int horaLlegada=0;
	switch(distanciaKm)
	{
	case 20:
			seconds=40;
			break;
	case 30:
			seconds=60;
			break;
	case 50:
			seconds=100;
			break;
	case 80:
			seconds=160;
			break;
	case 150:
			seconds=300;
			break;
	}
	horaLlegada=time_add(seconds);
	return horaLlegada;

}

int uTracking_Alta(Producto productos[],int TAM_PRODUCTOS, Tracking list[], int TAM_TRACKING, Usuario usuario[],int TAM_USUARIO)
{
	int ret=-1;
	int indexProducto;
	int indexTrackingLibre;
	int totalDeCompra;
	int indexUsuario;
	Tracking aux;


	if(productos!=NULL && list!=NULL)
	{
		if(TAM_PRODUCTOS>=0 || TAM_TRACKING>=0)
		{
			indexTrackingLibre=eTracking_buscarLibre(list,TAM_TRACKING);
			if(indexTrackingLibre!=-1)
			{
				indexUsuario=eUsuario_BuscarPorId(usuario,TAM_USUARIO);
				if(indexUsuario!=-1)
				{
					aux.FK_idUsuario=usuario[indexUsuario].idUsuario;
				}
				if(eProducto_MostrarTodos(productos,TAM_PRODUCTOS)==0)
				{
					indexProducto=eProducto_BuscarPorId(productos,TAM_PRODUCTOS);

				}
				if(indexProducto!=-1)
				{
					aux.FK_idProducto=productos[indexProducto].idProducto;
					aux=eTracking_CargaDatos(aux);
					if(productos[indexProducto].stock>=aux.cantidad)
					{
						totalDeCompra=aux.cantidad*productos[indexProducto].precio;
						printf("\nEl total de su compra es: %d \nDesea continuar?", totalDeCompra);
						if(utn_getCaracterSN()==0)
						{
							aux.idTracking=GenerarId();
							aux.isEmpty=OCUPADO;
							list[indexTrackingLibre]=aux;
							ret=0;
						}
					}
				}

			}

		}
	}
	return ret;
}

void eTracking_MostrarUno(Tracking list)
{
        printf("\n %5d %15d %15d",list.idTracking,list.estado,list.cantidad);
}

int eTracking_MostrarTodos(Tracking list[],int TAM_TRACKING)
{
        int i;
        int retorno=-1;
        int idUsuario;

        if(list!=NULL && TAM_TRACKING>0)
        {
        	idUsuario=get_Int("\nIngrese su id: ", "\nError");
        	for(i=0;i<TAM_TRACKING;i++)
        	{
        		if(list[i].FK_idUsuario==idUsuario && list[i].isEmpty==1)
        		{
        			puts("\n\tListado Tracking\n");
        			printf("%5s %15s %15s","ID","ESTADO","CANTIDAD");
        			eTracking_MostrarUno(list[i]);
        		}
        		retorno=0;
        	}
        }
        return retorno;
}

int eTracking_Baja(Tracking list[], int len)
{
		int i;
		int ret=0;
        int idProducto;
        if(list!=NULL && len>0)
        {
        	idProducto=get_Int("\nIngrese el id de un producto: ", "\nError");
        	for(i=0;i<len;i++)
        	{
        	  if(list[i].isEmpty==1)
        	   {
        	      if(list[i].FK_idProducto==idProducto && list[i].estado==EN_VIAJE)
        	       {
        	    	  	  puts("\nSeguro quiere cancelarlo?");
        	    	  	  if(utn_getCaracterSN()==0)
        	    	  	  {
        	    	  		  list[i].estado=CANCELADO;
        	    	  	  }

        	       }
        	   }
        	  else
        	  {
        	      puts("\nId no encontrado");
        	      ret=-1;
        	  }
            }

        }
        return ret;
}

void ActualizarEstado(Tracking list[],int len)
{
	int i;
	if(list!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].horaLlegada>time(NULL))
				 {
					 list[i].estado=EN_VIAJE;

				 }else{
					 if(list[i].horaLlegada==time(NULL))
					 {
						 list[i].estado=ENTREGADO;
					 }
					 else
					 {
						 list[i].estado=CANCELADO;
					 }
				 }
		}
	}

}

int ListaVentas_Finalizadas(Tracking list[], int len)
{
	int i;
	int ret=-1;
	int idUsuario;
	if(list!=NULL)
	{
		idUsuario=get_Int("\nIngrese su Id: ","\nError");
		for(i=0;i<len;i++)
		{
			if(list[i].FK_idUsuario==idUsuario)
			{
				if(list[i].estado==ENTREGADO || list[i].estado==CANCELADO)
				{
					eTracking_MostrarUno(list[i]);
					ret=0;
				}
			}
		}
	}
	return ret;
}

int ListaProductos_ConStock(Producto productos[], int TAM_PRODUCTO, Tracking list[], int TAM_TRACKING)
{
	int ret=-1;
	int i;
	int j;
	int buscarId;
	int indexProducto;
	if(productos!=NULL && list!=NULL)
	{
		if(TAM_PRODUCTO>0 && TAM_TRACKING>0)
		{
			buscarId=get_Int("\nIngrese id: ","\nError");
			for(i=0;i<TAM_TRACKING;i++)
			{
				if(list[i].FK_idUsuario==buscarId)
				{
					indexProducto=list[i].FK_idProducto;
					for(j=0;j<TAM_PRODUCTO;j++)
					{
						if(productos[i].idProducto==indexProducto)
						{
							eProducto_MostrarUno(productos[i]);
							ret=0;
						}
					}
				}
			}
		}
	}
	return ret;
}

void eTracking_Global(Tracking list[],int TAM_TRACKING)
{
	int i;
	printf("%5s %15s %15s %15s","ID TRACKING","ESTADO","ID VENDEDOR","ID COMPRADOR");
	for(i=0;i<TAM_TRACKING;i++)
	{
		printf("%5d %15d %15d %15d",list[i].idTracking,list[i].estado,list[i].FK_idProducto,list[i].FK_idUsuario);
	}
}
