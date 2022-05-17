/*
 * Usuario.h
 *
 *  Created on: 13/05/2022
 *      Author: Ochoa Melina
 */

#ifndef USUARIO_H_
#define USUARIO_H_
#include "input.h"
#define ACTIVO 0
#define INACTIVO -1

#define ADMIN 2
#define USUARIO 1

typedef struct{
	int idUsuario;
	short int isEmpty;
	short int tipo;
	char correo[25];
	char password[10];
	char direccion[10];
	int codPostal;

}Usuario;

/**
 * Funcion para mostrar un Usuario
 * @param usuario recibe una variable de usuario
 */
void eUsuario_MostrarUno(Usuario usuarios);

/**
 * Funcion que lista todos los usuarios
 * @param Usuario usuario recibe el array de usuarios
 * @param int len recibe el largo del array
 * @return retorna 0 si salio bien o -1 si no
 */
int eUsuario_MostrarTodos(Usuario usuarios[], int len);

/**
 * Funcion que inicializa los campos isEmpty en INACTIVO
 * @param Usuario usuarios recibe el array de usuarios
 * @param int len recibe el largo del array
 * @return retorna 0 si salio bien -1 si no
 */
int eUsuario_Inicializar(Usuario usuarios[], int len);

/**
 * Funcion que busca un espacio libre en el array
 * @param Usuario usuarios recibe el array de usuarios
 * @param int len recibe el largo del array
 * @return retorna 0 si salio bien -1 si no
 */
int eUsuario_buscarLibre(Usuario usuarios[], int len);

/**
 * Funcion para cargar datos no genericos
 * @param Usuario aux recibe un auxiliar de estructura Usuario
 * @return retorna el auxiliar que recibe cargado
 */
Usuario eUsuario_CargaDatos(Usuario aux);

/**
 * Funcion para dar de alta un usuario
 * @param Usuario usuarios[]recibe un array de usuario
 * @param int len recibe el largo de el array
 * @return Retorna 0 si salio bien o -1 si no
 */
int eUsuario_Alta(Usuario usuarios[], int len);

/**
 * Funcion para buscar un usuario por id
 * @param Usuario usuarios[] recibe el array de usuarios
 * @param int len recibe el largo de un array
 * @return Retorna el id encontrado o -1 si no encontro el id
 */
int eUsuario_BuscarPorId(Usuario usuarios[], int len);

/**
 * Funcion para dar de baja segun id
 * @param Usuario usuarios[] recibe un array de usuarios
 * @param int len recibe el largo del array
 * @param int id recibe el id a encontrar
 * @return Retorna 0 si salio bien o -1 si no se encontro el id
 */
int eUsuario_Baja(Usuario usuarios[], int len, int id);

/**
 * Funcion para modificar los datos no genericos de un usuario
 * @param Usuario copia recibe una variable con estructura Usuario
 * @return Retorna la variable recibida
 */
Usuario eUsuario_ModificarUno(Usuario copia);

/**
 * Funcion para modicicar un usuario
 * @param Usuario usuario[] recibe un array de usuario
 * @param int len recibe la longitud del array
 * @return retorna 0 si salio bien o -1 si no se encontro el id a modificar
 */
int eUsuario_Modificar(Usuario usuarios[], int len);

/**
 * Funcion para ordenar el array de usuarios segun el criterio deseado
 * @param Usuario usuarios[] recibe el array de usuario
 * @param int len recibe la longitud del array
 * @param int criterio recibe el criterio para ordenar, ASCENDENTE(1) DESCENDENTE(0)
 * @return retorna 0 si salio bien o -1 si no
 */
int eUsuario_Sort(Usuario usuarios[], int len, int criterio);

/**
 * Funcion para validar el ingreso de usuarios
 * @param Usuarios usuario[] recibe un array de usuario
 * @param int len recibe la longitud del array
 * @return retorna 0 si el tipo de usuario es usuario, 1 si es administrador o -1 si salio mal
 */
int Ingreso(Usuario usuarios[],int len);

/**
 * Funcion que muestra un menu de Usuario
 * @param int* opcion Recibe un puntero a la direccion de memoria de opcion para escribirla
 * @return void no retorna nada
 */
void menuUsuario(int* opcion);

/**
 * Funcion que muestra un menu de administrador
 * @param int* opcion Recibe un puntero a la direccion de memoria de opcion para escribirla
 * @return void no retorna nada
 */
void menuAdmin(int* opcion);


#endif /* USUARIO_H_ */
