/*
 * Comic.h
 *
 *  Created on: 11 ago. 2022
 *      Author: PC
 */

#ifndef COMIC_H_
#define COMIC_H_
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "input.h"
#include "parser.h"
#define HEROE 1
#define VILLANO 2

typedef struct{
	int id;
	char nombre[50];
	int idTipo;
	int power;
	int resistencia;
}eComic;

int saveAsTextFilter(char* path , LinkedList* pArrayList);
int AddComic(LinkedList* pArrayList, LinkedList* pArrayListNew, int* tipo);
int sortComic(LinkedList* pArrayList);
eComic* Comic_new();
eComic* Comic_newParametros(char* idStr,char* nombreStr,char* tipoStr,char* powerStr,char* resistenciaStr);
int Comic_setId(eComic* this,int id);

int Comic_getId(eComic* this,int* id);
int Comic_setNombre(eComic* this,char* nombre);

int Comic_getNombre(eComic* this,char* nombre);

int Comic_setTipo(eComic* this,int tipo);

int Comic_getTipo(eComic* this,int* tipo);
int Comic_setPower(eComic* this,int power);
int Comic_getPower(eComic* this,int* power);

int Comic_setResistencia(eComic* this,int resistencia);

int Comic_getResistencia(eComic* this,int* resistencia);

void Comic_Print(eComic* this);
int ListComic(LinkedList* pArrayListJuegos);

int Comic_sortPower(void* this1, void* this2);



#endif /* COMIC_H_ */
