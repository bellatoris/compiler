#include "subc.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


id* enter(int flag, char* str, int length)
{
	ENTRY item;                     //use standard library
	ENTRY* result;

	item.key = str;                 //key에다가 입력된 스트링을 넣는다.
	result = hsearch(item, FIND);   //입력된 key와 일치하는 ENTRY가 hashtable에  존재하는지 찾는다.

    id* temp;

	if(result == NULL)  //스트링이 존재 하지 않을 경우
	{
		temp = (id*)malloc(sizeof(id)); // 새로히 id를 동적할당한다.
		temp->tokentype = flag;
		temp->name = (char*)malloc(sizeof(char)); //스트링도 다시 동적할당 해준다. yytext는 사라지기 때문

		strcpy(temp->name, str);    //스트링을 복사해준다.

		temp->count = 0;    //keyWord에 한해서 count를 0으로 초기화 해준다.

		item.key = temp->name;      //key에 동적할당된 스트링을 다시 넣어준다.
		item.data = temp;           //ENTRY의 data에는 id를 넣어준다.

		hsearch(item, ENTER);       //hashtable에 ENTRY를 넣어준다.

		if(flag == ID)              //Identifier의 경우 처음부터 count = 1을 넣어주고 그값을 출력해준다. KeyWord의 경우 처음에 initHash로 초기화 해주므로 이 단계를 거치면 않는다.
			printf("ID\t%s\t%d\t\n", (char*)temp->name, ++temp->count);

		return temp;
	}
	else        //ENTRY가 존재하는경우
	{
		temp = result->data;    //temp에 찾은 id값을 넣어준다.
		temp->count++;          //initHash를 한 이후에 적용되는 함수이므로 count를 올려준다.
		if(temp->tokentype != flag)
			printf("KEY\t%s\t%d\t\n", (char*)temp->name, temp->count);
		else
			printf("ID\t%s\t%d\t\n", (char*)temp->name, temp->count);
		return temp;
	}
}

