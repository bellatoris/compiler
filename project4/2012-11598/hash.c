/***************************************************************
 * File Name    : hash.c
 * Description
 *      This is an implementation file for the open hash table.
 *
 ****************************************************************/

#include "subc.h"


id* enter(int lextype, char* str, int length)
{
	ENTRY item;                   
	ENTRY* result;

	item.key = str;                
	result = hsearch(item, FIND);   

        id* temp;

	if(result == NULL)             
	{
		temp = (id*)malloc(sizeof(id)); 
		temp->lextype = lextype;
		temp->name = (char*)malloc(sizeof(char)*(length)); 

		strncpy(temp->name, str, length);           

		item.key = temp->name;     
		item.data = temp;           

		hsearch(item, ENTER);    

		return temp;
	}
	else                            
	{
		temp = result->data;
		return temp;
	}
}
