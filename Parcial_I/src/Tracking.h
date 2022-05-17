/*
 * Tracking.h
 *
 *  Created on: 15/05/2022
 *      Author: melys
 */

#ifndef TRACKING_H_
#define TRACKING_H_
#include "Productos.h"
#include "Usuario.h"
#include <time.h>
#define EN_VIAJE 1
#define ENTREGADO 0
#define CANCELADO -1

typedef struct{
	int idTracking;
	int FK_idProducto;
	int FK_idUsuario;
	short int isEmpty;
	int estado;
	int cantidad;
	int distanciaKm;
	int horaLlegada;
}Tracking;

int eTracking_Inicializar(Tracking list[], int len);

int eTracking_buscarLibre(Tracking list[], int len);

Tracking eTracking_CargaDatos(Tracking aux);

int CalcularDistancia();

long int Time_Current(void);

long int time_add(double secondsAdd);

long int CalcularHoraLlegada(int distanciaKm);

int uTracking_Alta(Producto productos[],int TAM_PRODUCTOS, Tracking list[], int TAM_TRACKING, Usuario usuario[],int TAM_USUARIO);

void eTracking_MostrarUno(Tracking list);

int eTracking_MostrarTodos(Tracking list[],int TAM_TRACKING);

int eTracking_Baja(Tracking list[], int len);

void ActualizarEstado(Tracking list[],int len);

int ListaVentas_Finalizadas(Tracking list[], int len);

int ListaProductos_ConStock(Producto productos[], int TAM_PRODUCTO, Tracking list[], int TAM_TRACKING);

void eTracking_Global(Tracking list[],int TAM_TRACKING);

#endif /* TRACKING_H_ */
