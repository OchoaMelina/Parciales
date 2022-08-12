/*
 * Menu.c
 *
 *  Created on: 11 ago. 2022
 *      Author: PC
 */

#include "Menu.h"

void menu()
{

		LinkedList* listaComics=ll_newLinkedList();
		LinkedList* listaFiltrado=ll_newLinkedList();
		int opcion;
		int(*pOrden)(LinkedList*,LinkedList*,int*);

		do{
			if(getNumero(&opcion,"******* Elija una opcion **********\n"
		    			"1. Leer los datos\n2.Ordenar\n3.Imprimir\n4.Desarrollar ll_map\n"
		    			"5.Desarrollar ll_filter\n6.Generar archivo de salida mapeado.csv\n"
		    			"\n7.Generar archivo de salida filtrado.csv\n0. Salir","***********Error reingrese*************\n"
		    			"1. Leer los datos\n2.Ordenar\n3.Imprimir\n4.Desarrollar ll_map\n"
		    			"5.Desarrollar ll_filter\n6.Generar archivo de salida mapeado.csv\n"
		    			"\n7.Generar archivo de salida filtrado.csv\n0. Salir",8,0,2)==0){
					switch(opcion)
					{
					case 1:
						loadFromText("datos_FINAL_1F_M2.csv",listaComics);
						break;
					case 2:
						sortComic(listaComics);
						break;
					case 3:
						ListComic(listaComics);
						break;
					case 5:
						pOrden=AddComic;
						ll_filter(listaComics,listaFiltrado,pOrden);
						break;
					case 7:
						saveAsTextFilter("filtrado.csv", listaFiltrado);
						break;
					}
			}
		}while(opcion!=0);

}
