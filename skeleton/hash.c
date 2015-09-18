#include "hash.h"
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

	if(result == NULL)
	{
		id* temp = (id*)malloc(sizeof(id));
		temp->tokentype = flag;
		temp->name = (char*)malloc(sizeof(char));

		strcpy(temp->name, str);

		temp->count = 0;

		if(flag == ID)
			temp->count = 1;
	
		item.key = temp->name;
		item.data = temp;

		result = hsearch(item, ENTER);

		if(flag == 1)
			printf("ID\t%s\t%d\n", (char*)temp->name, temp->count);

		return temp;
	}
	else if(result != NULL && flag == KEY)
	{
		id* temp = result->data;
		temp->count++;
		printf("KEY\t%s\t%d\n", (char*)temp->name, temp->count);
	}

	else if(result != NULL && flag == ID)
	{
		id* temp = result->data;
		temp->count++;
		printf("ID\t%s\t%d\n", (char*)temp->name, temp->count);
	}
}

int FLAG(char* str)
{
	int i;
	char* keyWord[]={ "auto", "break", "case", "char", "continue", "default", "do", "double", "else", "extern", "float", "for", "goto", "if", "int", "long", "register", "return", "short", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void", "while", "\0"};
	for (i = 0; i < 28 ; i++) 
	{
		if(strcmp(keyWord[i], str) == 0)
		return KEY;
	}
	return ID;
}

