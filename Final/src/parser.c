/*
 * parser.c
 *
 *  Created on: 28 jun. 2022
 *      Author: PC
 */
#include "parser.h"

int parser_FromText(FILE* pFile , LinkedList* pArrayList)
{
	int ret = -1;
	char buffer[5][50];
	int charLeidos;
	eComic* pAux;
	if(pFile != NULL && pArrayList !=NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3],buffer[4]);
		//printf("%s     %s    %s   %s\n\n",buffer[0],buffer[1],buffer[2],buffer[3],buffer[4]);
		while(!feof(pFile))
		{
			//printf("\nParser: Entro al while");
			charLeidos = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3],buffer[4]);
			//printf("\nCharleidos = %d",charLeidos);
			if(charLeidos < 4)
			{
				printf("\nParser: Error de char leidos, break while");
				ret = -1;
				break;
			}
			else
			{
				pAux = Comic_newParametros(buffer[0],buffer[1],buffer[2],buffer[3],buffer[4]);
				if(pAux == NULL)
				{
					printf("\nParser: nuevoComic es == NULL");
					break;
				}
				else
				{
					ll_add(pArrayList,(eComic*)pAux);
					ret = 0;
				}
				//printf("\nParser:Se Agrego un elemento al final de la lista");
			}
		}//FIN WHILE
	}
	return ret;

}

