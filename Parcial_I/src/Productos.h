/*
 * Productos.h
 *
 *  Created on: 13/05/2022
 *      Author: Ochoa Melina
 */

#ifndef PRODUCTOS_H_
#define PRODUCTOS_H_
#include"input.h"
#define OCUPADO 1
#define LIBRE 0

typedef struct{
	int idProducto;
	short int isEmpty;
	char nombreProducto[25];
	float precio;
	short int categoria;
	int stock;
}Producto;

/**
 * Funcion para mostrar un Producto
 * @param Producto productos recibe una variable de producto
 */
void eProducto_MostrarUno(Producto productos);

/**
 * Funcion que lista todos los Productos
 * @param Producto productos[] recibe el array de productos
 * @param int len recibe el largo del array
 * @return retorna 0 si salio bien o -1 si no
 */
int eProducto_MostrarTodos(Producto productos[], int len);
/**
 * Funcion que inicializa los campos isEmpty en LIBRE
 * @param Producto productos[] recibe el array de productos
 * @param int len recibe el largo del array
 * @return retorna 0 si salio bien -1 si no
 */
int eProducto_Inicializar(Producto productos[], int len);

/**
 * Funcion que busca un espacio libre en el array
 * @param Producto productos[] recibe el array de productos
 * @param int len recibe el largo del array
 * @return retorna 0 si salio bien -1 si no
 */
int eProducto_buscarLibre(Producto productos[], int len);

/**
 * Funcion para cargar datos no genericos
 * @param Producto aux recibe un auxiliar de estructura Producto
 * @return retorna el auxiliar que recibe cargado
 */
Producto eProducto_CargaDatos(Producto aux);

/**
 * Funcion para dar de alta un producto
 * @param Producto productos[]recibe un array de productos
 * @param int len recibe el largo de el array
 * @return Retorna 0 si salio bien o -1 si no
 */
int eProducto_Alta(Producto productos[], int len);

/**
 * Funcion para buscar un producto por id
 * @param  Producto productos[] recibe el array de productos
 * @param int len recibe el largo de un array
 * @return Retorna el id encontrado o -1 si no encontro el id
 */
int eProducto_BuscarPorId(Producto productos[], int len);

/**
 * Funcion para dar de baja segun id
 * @param Producto productos[] recibe un array de productos
 * @param int len recibe el largo del array
 * @param int id recibe el id a encontrar
 * @return Retorna 0 si salio bien o -1 si no se encontro el id
 */
int eProducto_Baja(Producto productos[], int len, int id);

/**
 * Funcion para modificar los datos no genericos de un producto
 * @param Producto copia recibe una variable con estructura Producto
 * @return Retorna la variable recibida
 */
Producto eProducto_ModificarUno(Producto copia);

/**
 * Funcion para modicicar un producto
 * @param Producto productos[] recibe un array de producto
 * @param int len recibe la longitud del array
 * @return retorna 0 si salio bien o -1 si no se encontro el id a modificar
 */
int eProducto_Modificar(Producto productos[], int len);

/**
 * Funcion para ordenar el array de producto segun el criterio deseado
 * @param Producto productos[] recibe el array de usuario
 * @param int len recibe la longitud del array
 * @param int criterio recibe el criterio para ordenar, ASCENDENTE(1) DESCENDENTE(0)
 * @return retorna 0 si salio bien o -1 si no
 */
int eProducto_Sort(Producto productos[], int len, int criterio);

int ReponerStock(Producto productos[],int len);

int eProducto_MostrarPorNombre(Producto productos[], int len);

int eProducto_OrdenadoPorStock(Producto productos[], int len);
#endif /* PRODUCTOS_H_ */
