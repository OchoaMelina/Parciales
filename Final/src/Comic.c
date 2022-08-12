/*
 * Comic.c
 *
 *  Created on: 11 ago. 2022
 *      Author: PC
 */

#include "Comic.h"

eComic* Comic_new()
{
	return(eComic*)malloc(sizeof(eComic));
}

eComic* Comic_newParametros(char* idStr,char* nombreStr,char* tipoStr,char* powerStr,char* resistenciaStr)
{
	eComic* pComic = Comic_new();
		if(pComic!=NULL && idStr!=NULL && nombreStr!=NULL && tipoStr!=NULL && powerStr !=NULL && resistenciaStr!=NULL)
		{
			if((Comic_setId(pComic,atoi(idStr))!=0) ||
			(Comic_setNombre(pComic,nombreStr)!=0) ||
			(Comic_setTipo(pComic,atoi(tipoStr))!=0) ||
			(Comic_setPower(pComic,atoi(powerStr))!=0) ||
			Comic_setResistencia(pComic,atoi(resistenciaStr))!=0)
			{
				free(pComic);
				pComic=NULL;
			}
		}
		return pComic;
}

int Comic_setId(eComic* this,int id)
{
	int retorno=- 1 ;
	if(this != NULL && id>=0 )
	{
		this->id=id;
		retorno= 0 ;
	}
	return retorno;
}

int Comic_getId(eComic* this,int* id)
{
	int retorno=-1;
	if(this!=NULL && id!=NULL)
	{
		*id=this->id;
		retorno=0;
	}
	return retorno;
}

int Comic_setNombre(eComic* this,char* nombre)
{
	int retorno=-1;
	if(this!=NULL && nombre!=NULL)
	{
		strcpy(this->nombre,nombre);
		retorno=0;
	}
	return retorno;
}

int Comic_getNombre(eComic* this,char* nombre)
{
	int retorno=-1;
	if(this!=NULL && nombre!=NULL)
	{
		strcpy(nombre,this->nombre);
		retorno=0;
	}
	return retorno;
}

int Comic_setTipo(eComic* this,int tipo)
{
	int retorno=-1;
	if(this!=NULL && tipo>=0)
	{
		this->idTipo=tipo;
		retorno=0;
	}
	return retorno;
}

int Comic_getTipo(eComic* this,int* tipo)
{
	int retorno=-1;
	if(this!=NULL && tipo!=NULL)
	{
		*tipo=this->idTipo;
		retorno=0;
	}
	return retorno;
}

int Comic_setPower(eComic* this,int power)
{
	int retorno=- 1 ;
	if(this != NULL && power>= 0 )
	{
		this->power =power;
		retorno= 0 ;
	}
	return retorno;
}

int Comic_getPower(eComic* this,int* power)
{
	int retorno=-1;
	if(this!=NULL && power!=NULL)
	{
		*power=this->power;
		retorno=0;
	}
	return retorno;
}

int Comic_setResistencia(eComic* this,int resistencia)
{
	int retorno=- 1 ;
	if(this != NULL && resistencia>= 0 )
	{
		this->resistencia =resistencia;
		retorno= 0 ;
	}
	return retorno;
}

int Comic_getResistencia(eComic* this,int* resistencia)
{
	int retorno=-1;
	if(this!=NULL && resistencia!=NULL)
	{
		*resistencia=this->resistencia;
		retorno=0;
	}
	return retorno;
}

void Comic_Print(eComic* this)
{
	int auxId, auxTipo, auxPower, auxResistencia;
	char auxNombre[50];
	if (Comic_getId(this,&auxId)== 0 && Comic_getNombre(this,auxNombre)== 0 &&
		Comic_getTipo(this,&auxTipo)== 0 && Comic_getPower(this,&auxPower)== 0 &&
		Comic_getResistencia(this,&auxResistencia)==0)
	{

		printf ( " Id: %d - Nombre: %s - IdTipo: %d - Power: %d	- Resistencia: %d\n " ,auxId, auxNombre,
				auxTipo,auxPower,auxResistencia);
	}
}

int ListComic(LinkedList* pArrayListJuegos)
{
	int retorno = -1;
	int auxId, auxIdTipo,auxPower,auxResistencia;
	char auxNombre[50], auxTipo[20];
	eComic* pComic=NULL;
	int cantLinkedList;
	if(pArrayListJuegos != NULL)
	{
		if(ll_isEmpty(pArrayListJuegos)==0)
		{
			cantLinkedList=ll_len(pArrayListJuegos);
			printf("********************************************************************************\n");
			printf("*************     ID		NOMBRE		  ID TIPO	       POWER		RESISTENCIA     ************\n");
			printf("***********************************************************************************\n");
			for(int i=0; i<cantLinkedList ; i++)
			{
				pComic = (eComic*)ll_get(pArrayListJuegos, i);
				if(Comic_getId(pComic,&auxId)!= 0 && Comic_getNombre(pComic,auxNombre)!= 0 &&
					Comic_getTipo(pComic,&auxIdTipo)!= 0 && Comic_getPower(pComic,&auxPower)!= 0 &&
					Comic_getResistencia(pComic,&auxResistencia)!=0)
				{
					retorno=-1;
					printf("Error, al imprimir lista");
					break;
				}
				else
				{
					if(auxIdTipo==1)
					{
						strcpy("HEROE",auxTipo);
					}
					else
					{
						strcpy("VILLANO",auxTipo);
					}
					printf("%-5d		%-15s		%-15s			%-15d		%-15d\n",auxId, auxNombre, auxTipo, auxPower, auxResistencia);
				}
			}
			retorno = 0;
		}
		else
		{
			printf("No hay lista para imprimir\n");
		}
	}
	return retorno;
}

int Comic_sortPower(void* this1, void* this2)
{
	int retorno=0;
	int auxId1, auxId2;

	if(this1!=NULL && this2!=NULL)
	{
		if(Comic_getPower((eComic*)this1, &auxId1)==0 && Comic_getPower((eComic*)this2, &auxId2)==0)
		{
			if(auxId1 > auxId2)
			{
				retorno=1;
			}
			if( auxId1 < auxId2 )
			{
				retorno=-1;
			}
		}
	}
	return retorno;
}

int sortComic(LinkedList* pArrayList)
{
	int retorno=-1;
	int(*pOrden)(void*,void*);

	if(pArrayList!=NULL)
	{
		pOrden=Comic_sortPower;
		ll_sort(pArrayList, pOrden, 0);
		retorno=0;
	}
	    return retorno;
}

int AddComic(LinkedList* pArrayList, LinkedList* pArrayListNew, int* tipo)
{
	int retorno=-1;
	eComic* pComic=NULL;
	eComic* pComic2;
	int auxId, auxTipo, auxPower, auxResistencia;
	char auxNombre[50];
	int i;
	if(pArrayList!=NULL && pArrayListNew!=NULL)
	{

		for(i=0;i<ll_len(pArrayList);i++)
		{

			pComic=(eComic*)ll_get(pArrayList, i);
			Comic_getId(pComic,&auxId);
			Comic_getNombre(pComic,auxNombre);
			Comic_getTipo(pComic,&auxTipo);
			Comic_getPower(pComic,&auxPower);
			Comic_getResistencia(pComic,&auxResistencia);
		if(auxTipo==*tipo)
		{
			puts("\t***************************************************************************************\n");
			puts("\t*\t Atencion! Se cargaran datos en una nueva LinkedList                       *\n");
			puts("\t*\t Recuerde guardar estos datos en un archivo                     *\n");
			puts("\t*****************************************************************************************\n");
			pComic2=Comic_new();
				if(pComic2!=NULL)
				{
					if((Comic_setId(pComic,auxId)!=0) ||
							(Comic_setNombre(pComic,auxNombre)!=0) ||
							(Comic_setTipo(pComic,auxTipo)!=0) ||
							(Comic_setPower(pComic,auxPower)!=0) ||
							Comic_setResistencia(pComic,auxResistencia)!=0)
						{
							ll_add(pArrayListNew, pComic2);
									puts("Carga exitosa\n");
									retorno=0;
								}
								else
								{
									printf("Error al cargar comic \n");
								}
							}

					}
			}
	}
	return retorno;
}

int saveAsTextFilter(char* path , LinkedList* pArrayList)
{
	int retorno = -1;
	int auxCantLink, auxId, auxTipo, auxPower, auxResistencia;
	char auxNombre[50];
	FILE* pFile;
	eComic* pComic=NULL;
	if(path!=NULL && pArrayList!=NULL)
	{
		if((pFile=fopen(path,"w"))==NULL)
		{
			printf("No se pudo escribir el archivo\n");
		}
		else
		{
			auxCantLink=ll_len(pArrayList);
			fprintf(pFile,"id,nombre,idTipo,power,resistencia\n");
				for(int i=0; i<auxCantLink; i++)
				{
					pComic = (eComic*)ll_get(pArrayList, i);
					if(Comic_getId(pComic,&auxId)== 0 && Comic_getNombre(pComic,auxNombre)== 0 &&
							Comic_getTipo(pComic,&auxTipo)== 0 && Comic_getPower(pComic,&auxPower)== 0 &&
							Comic_getResistencia(pComic,&auxResistencia)==0)
					{
					   fprintf(pFile,"%d,%s,%d,%d,%d\n",auxId, auxNombre, auxTipo, auxPower,auxResistencia);
					   retorno=0;
					}
				}
				printf("Archivo bien escrito. Guardado correctamente\n");
			}
			fclose(pFile);
		}
		return retorno;
}


