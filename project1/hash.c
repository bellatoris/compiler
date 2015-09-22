#include "subc.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


id* enter(int flag, char* str, int length)
{
	ENTRY item;
	ENTRY* result;

	item.key = str;
	result = hsearch(item,FIND);

    id* temp;

	if(result == NULL)
	{
		temp = (id*)malloc(sizeof(id)); // allocate 
		temp->tokentype = flag;
		temp->name = (char*)malloc(sizeof(char));

		strcpy(temp->name, str);

		temp->count = 0;

		item.key = temp->name;
		item.data = temp;

		hsearch(item, ENTER);

		if(flag == ID)
			printf("ID\t%s\t%d\t\n", (char*)temp->name, ++temp->count);

		return temp;
	}
	else
	{
		temp = result->data;
		temp->count++;
		if(temp->tokentype != flag)
			printf("KEY\t%s\t%d\t\n", (char*)temp->name, temp->count);
		else
			printf("ID\t%s\t%d\t\n", (char*)temp->name, temp->count);
		return temp;
	}
}

