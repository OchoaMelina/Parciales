/*
 ============================================================================
 Name        : Parcial_I.c
 Author      : Ochoa Melina
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "Tracking.h"
#define TAM_PRODUCTO 200
#define TAM_USUARIO 2000
#define TAM_TRACKING 200
#define ASCENDENTE 1
#define DESCENDENTE 0

int main(void) {
	setbuf(stdout,NULL);
	Producto productos[TAM_PRODUCTO]={
			{0001, 1, "Remera", 150, "ROPA", 150},
			{0002, 1, "Buzo", 600, "ROPA", 40},
			{0003, 1, "Pantalon", 500, "ROPA", 50},
			{0004, 1, "Bufanda", 200, "ACCESORIOS", 10},
	};
	Usuario usuarios[TAM_USUARIO]={
			{0001, 0, 1,"melinaochoa.93@gmail.com", "1234","Cotagaita 2987",1825},
			{0002, 0, 2, "alechino22@hotmail.com", "56789", "chilavert 2722",1824},
			{0003, 0, 1, "paulinakresser@yahoo.com", "pauLi34","chorrarin 4545", 3030},
	};
	Tracking trackings[TAM_TRACKING];
	int opcionPrimera;
	int opcionUsuario;
	int opcionAdmin;
	int retUsuario;
	int baja;
	char lista;
	int id;
	
	

	do{
		puts("******************************");
		puts("\n**1er EXAMEN LAB I -1H**");
		puts("\n******************************");
		getNumero(&opcionPrimera,"\n1)Ingresar\n2)Registrarme\n"
				"\n0)Salir\n","\nError",2,0,2);
		switch(opcionPrimera)
		{
		case 1:
				retUsuario=Ingreso(usuarios,TAM_USUARIO);
				if(retUsuario==1)
				{
					do{
						menuUsuario(&opcionUsuario);
						switch(opcionUsuario)
						{
							case 1:
									eProducto_Sort(productos,TAM_PRODUCTO,ASCENDENTE);
									eProducto_MostrarTodos(productos,TAM_PRODUCTO);
									uTracking_Alta(productos,TAM_PRODUCTO,trackings,TAM_TRACKING,usuarios,TAM_USUARIO);
									break;
							case 2:
									getNumero(&opcionProducto,"\n1)Alta Producto\n2)Reponer stock","\nError reingrese",2,1,2);
									if(opcionProducto==1)
									{
										eProducto_Alta(productos,TAM_PRODUCTO);
									}
									else
									{
										if(opcionProducto==2)
										{
											ReponerStock(productos,TAM_PRODUCTO);
										}
									}
									break;
							case 3:
									while(baja!=3)
									{
										eTracking_MostrarTodos(trackings,TAM_TRACKING);
										getNumero(&baja,"\n1)ACTUALIZAR\n2)DAR DE BAJA\n3)SALIR","\nError ",3,1,2);
										if(baja==2)
										{
											eTracking_Baja(trackings,TAM_TRACKING);
										}
										else
										{
											ActualizarEstado(trackings,TAM_TRACKING);
										}
									}
									break;
							case 4:
									printf("\nA)LISTADO DE VENTAS FINALIZADAS\nB)VER PRODUCTOS\nIngrese opcion: ");
									scanf("%c",&lista);
									if(lista=='a')
									{
										ActualizarEstado(trackings,TAM_TRACKING);
										ListaVentas_Finalizadas(trackings,TAM_TRACKING);
									}
									else
									{
										ActualizarEstado(trackings,TAM_TRACKING);
										ListaProductos_ConStock(productos,TAM_PRODUCTO,trackings,TAM_TRACKING);
									}
									break;
				 		}
				   }while(opcionUsuario!=0);
				}
				else
				{
					do{
						menuAdmin(&opcionAdmin);
						switch(opcionAdmin)
						{
						case 1:
							eUsuario_MostrarTodos(usuarios,TAM_USUARIO);
							break;
						case 2:
							eProducto_Sort(productos,TAM_PRODUCTO, ASCENDENTE);
							eProducto_MostrarTodos(productos,TAM_PRODUCTO);
							break;
						case 3:
							eProducto_MostrarTodos(productos,TAM_PRODUCTO);
							id=get_Int("\nIngrese id a buscar:","\nError");
							eProducto_Baja(productos,TAM_PRODUCTO,id);
							break;
						case 4:
							eTracking_Global(trackings,TAM_TRACKING);
							break;
						case 5:
							eTracking_Global(trackings,TAM_TRACKING);
							break;
						case 6:
							eProducto_MostrarPorNombre(Producto productos[], int len);
							break;
						}
					}while(opcionAdmin!=0);
				}
				break;
		case 2:
			eUsuario_Inicializar(usuarios,TAM_USUARIO);
			if(eUsuario_Alta(usuarios,TAM_USUARIO)==0)
			{
				puts("\nCARGA EXITOSA");
			}
			else
			{
				puts("\nError al cargar");
			}

		}
	}while(opcionPrimera!=0);

	return EXIT_SUCCESS;
}
