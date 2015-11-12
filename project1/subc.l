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
/***************************************************************
{Other useful code segments can be here.}
***************************************************************/
int commentdepth = 0;
%}

letter		    [A-Za-z_]
alnum		    [A-Za-z0-9_]
digit 		    [0-9]
whitespace  	[ \t\n]
integer_const	([1-9]+{digit}*)|0
float_const	    {digit}+\.{digit}*([eE][+-]?{digit}+)?
Identifier      {letter}({letter}|{digit})*
Operators 	    [\(\)\[\]\{\}\-\>\.\,\\\!\~\+\/\%\<\=\&\^\|\;\:\*\?]
%start normal comment

%%

<comment>\/\*			        {	commentdepth++;	}                   /* \/\*  를 만나면 commnetdepth를 증가시킨다 */
<comment>\*\/			        {	if(--commentdepth == 0) {BEGIN normal;}   }     /*  \*\/ 만나면 commentdepth를 감소시키고 만약 commentdepth가 0이라면 normal 모드로 들어간다. */
<comment>. ;                                                            /*  comment 모드에서는 모든 input을 버린다. */
<normal>\/\*			        { 	commentdepth++; BEGIN comment;	}   /*  normal 모드에서 \/\*를 만나면 commentdepth를 1증가시키면서 comment 모드로 들어간다*/
<normal>{whitespace} ;	                                                /*  normal 모드에서 whitespace는 무시한다. */
<normal>{integer_const} 		{	printf("INT\t%s\n", yytext);	}   
<normal>{float_const}	        {	printf("F\t%s\n", yytext);	}       /* normal 모드에서 integer-const나 float-const는 그 type과 lexeme을 출력한다. */
<normal>{Identifier}		    {	enter(ID, yytext, yyleng);	}       /* noraml 모드에서 Identifier를 만나면 hash table에 넣는다. 그 후 type과 lexeme을 출력한다 */
<normal>{Operators}             {   printf("OP\t%s\n", yytext); }       /* normal 모드에서 Operators를 만나면 그 type과 lexeme을 출력한다. */
<normal>\-\>|\.\.|\+\+|\-\-|\<\<|\>\>|\<\=|\>\=|\=\=|\!\=|\&\&|\|\||\+\=|\-\=|\*\=|\/\=|\%\=|\&\=|\^\=|\|\=|\<\<\=|\>\>\=	{	printf("OP\t%s\n", yytext);	}       /*  두글자 이상의 Op는 다시 정의해준다. */
<normal>{integer_const}/\.\.	{	printf("INT\t%s\n", yytext);    }   /* normal 모드에서 {integer-const}.. 의 경우 integer-const를 출력해준다. */
<normal>. ;                                                             /* normal 모드에서 위의 translation rule에 적혀있지 않은 input은 모두 버린다. */

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
	hcreate(1000);           //hash table을 만든다.

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

	hdestroy();             //hash table을 파괴한다.
	return 0;
}
