%{
/*
 * File Name   : subc.l
 * Description : a skeleton flex input
 */

#include "subc.h"
#include "subc.tab.h"
static int comment_depth = 0;
static int lineno = 1;

%}

/* regular definitions */
letter		[A-Za-z_]
digit		[0-9]
id		{letter}({letter}|{digit})*
integer_const	([1-9]{digit}*)|"0"
white_space		[ \t]+
special_char	\\[nt]
Operators 	    [\(\)\[\]\{\}\-\,\!\+\/\%\=\&\|\;\*]


%x COMMENT
%%
{id}	{
		   struct id *entered  = enter(ID, yytext, yyleng);
		   yylval.stringVal = entered->name;
           //printf("%s\t", yytext);
		   return entered->lextype;
		}
{integer_const}	{
		   yylval.intVal = atoi(yytext);
		   return INTEGER_CONST;
		}
\"({special_char}|[^\\\"\n])*\"	{
			/* String Variable */
		   yylval.stringVal = yytext;
           //printf("%s\t", yytext);
		   return STRING;
		}
'({special_char}|[^\\'\n])'	{
			/* Character Variable */
		   yylval.stringVal = yytext;
           //printf("%s\t", yytext);
		   return CHAR_CONST;
		}

{Operators}	{
           //printf("%s\t", yytext);
           return yytext[0]; 
        }

"+="|"-="|"*="|"/="|"%=" {
           yylval.stringVal = yytext;
	       return ASSIGNOP;
        }

"||" {
		   yylval.stringVal = yytext;
	       return LOGICAL_OR;
        }

"&&" {
		   yylval.stringVal = yytext;
	       return LOGICAL_AND;
        }
"<"|"<="|">"|">=" {
		   yylval.stringVal = yytext;
           return RELOP;
        }   

"=="|"!=" {
		   yylval.stringVal = yytext;
           return EQUOP;
        }

"++" {
		   yylval.stringVal = yytext;
    	   return PLUS_PLUS;	
        }

"--" {
		   yylval.stringVal = yytext;
       	   return MINUS_MINUS;
        }

"." { 
		   yylval.stringVal = yytext;
	       return STRUCTOP;
        }   

{white_space}
<*>\n		   ++lineno;
<INITIAL,COMMENT>"/*"	{
		   ++comment_depth;
		   BEGIN (COMMENT);
		}
<COMMENT>"*/"	   if(--comment_depth == 0) BEGIN (INITIAL);
<COMMENT>.		 {}


%%

int read_line()
{
   return lineno;
}
   
int main(int argc, char* argv[])
{
    hcreate(1000);
   static char *keyword[] = { "int", "char", "struct", "return", "if", "else", "while", "for", "break", "continue", NULL };
   static int tokentype[] = { TYPE, TYPE, STRUCT, RETURN, IF, ELSE, WHILE, FOR, BREAK, CONTINUE, 0 };
   int i;
   for(i = 0; keyword[i] != NULL; i++)
      enter(tokentype[i], keyword[i], strlen(keyword[i]));

   if(argc >= 2) yyin = fopen(argv[1], "r");
   else yyin = stdin;
   if(!yyin) {
      printf("Can't open input stream!\n");
      exit(1);
   }
	
   yyparse();
   fclose(yyin);
   hdestroy();
   return 0;
}
