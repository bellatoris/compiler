%{
/**************************************************************
* File Name   : subc.l
*
* Description
*	This is a skeleton input file to lex.
*
* Which tool to use
*	The GNU lex-clone, flex/flex++ is recommended to use.
*	It supports a C++ mode.
*	For any information about flex, refer to flex.man.
*
*	Good Luck!
*
***************************************************************/

/**************************************************************/
/* This section will appear at the head of lex.yy.c/lex.yy.cc */
/**************************************************************/


#include "subc.h"
#include "hash.h"


/***************************************************************
{Other useful code segments can be here.}
***************************************************************/
int commentdepth = 0;
%}

letter		[A-Za-z_]
alnum		[A-Za-z0-9_]
digit 		[0-9]
whitespace 	[ \t\n]
intconst	([1-9]+{digit}*)|0
floatconst	{digit}+\.{digit}*([eE][+-]?{digit}+)?
Id			{letter}({letter}|{digit})*
Op 			[\(\)\[\]\{\}\-\>\.\,\\\!\~\+\/\%\<\=\&\^\|\;\:\*]
%start normal comment

%%

<comment>\/\*			{	commentdepth++;	}
<comment>\*\/			{	commentdepth--;	if(commentdepth == 0){BEGIN normal;}	}
<comment>. ;
<normal>\/\*			{ 	commentdepth++; BEGIN comment;	}
<normal>{whitespace} ;	
<normal>{intconst}/\.\.	{	printf("INT\t%s\n", yytext);	}	
<normal>\.\./{intconst}	{	printf("OP\t%s\n", yytext);	}
<normal>{Op}			{	printf("OP\t%s\n", yytext);	}
<normal>{intconst} 		{	printf("INT\t%s\n", yytext);	}
<normal>{floatconst}	{	printf("F\t%s\n", yytext);	}
<normal>{Id}			{	enter(ID, yytext, yyleng);	}
<normal>\-\>|\.\.|\+\+|\-\-|\<\<|\>\>|\<\=|\>\=|\=\=|\!\=|\&\&|\|\||\+\=|\-\=|\*\=|\/\=|\%\=|\&\=|\^\=|\|\=|\<\<\=|\>\>\=	{	printf("OP\t%s\n", yytext);	}
<normal>.				{	printf("You insert wrong input\n");	}

%%

void initHash() 
{
	int i;

	char* keyWord[]={
		"auto", "break", "case", "char", "continue", "default", "do", "double", "else", "extern", "float", "for", "goto", "if", "int", "long", "register", "return", "short", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void", "while", "\0"
	};

	/* Initilize Hash Tabel with Keywords */
	for (i = 0; strcmp(keyWord[i], "\0") !=0; i++) {
		enter(KEY, keyWord[i],strlen(keyWord[i]));
	}
}

int main(int argc, char** argv)
{
	hcreate(100);

	id* temp;

	++argv;
	--argc;

	if (argc > 0) {
		yyin = fopen(argv[0], "r");
	} else {
		yyin = stdin;
	}

	initHash();

	BEGIN normal;
	yylex ();

	hdestroy();
	return 0;
}
