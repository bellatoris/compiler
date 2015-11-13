%{
/*
 * File Name   : subc.y
 * Description : a skeleton bison input
 */

#include "subc.h"

int    yylex ();
int    yyerror (char* s);
void    REDUCE(char* s);

%}

/* yylval types */
%union {
	int	    intVal;
	double	    floatval;
	char	    *stringVal;
	struct id   *idptr;
	struct decl *declptr;
	struct ste  *steptr;
}
/* %type<declptr>	    ext_def type_specifier stuct_specifier func_decl pointers paran_list param_decl def_list def compound_stmt local_defs stmt_list stmt expr_e expr or_expr or_list and_expr and_list binary unary args */
%type<declptr>	    ext_def type_specifier func_decl param_decl struct_specifier 
def_list
%nonassoc<idptr>    ID TYPE VOID
/* Precedences and Associativities */

%right  ELSE
%left	','
%right  '='
%left   LOGICAL_OR
%left   LOGICAL_AND
%left   '&'
%left   EQUOP
%left   RELOP
%left   '+' '-'
%left   '*'
%right  '!' INCOP DECOP
%left   '[' ']' '(' ')' '.' STRUCTOP

/* Token and Types */
%token		    STRUCT
%token<stringVal>   CHAR_CONST STRING STRUCTOP
%token<intVal>	    INTEGER_CONST
%token		    RETURN
%token              IF
%token		    ELSE
%token              WHILE
%token              FOR
%token              BREAK
%token              CONTINUE
%token              LOGICAL_OR
%token              LOGICAL_AND
%token              RELOP
%token              EQUOP
%token              INCOP
%token		    DECOP

%%
program: ext_def_list
   ;
ext_def_list: ext_def_list ext_def
        | /* empty */ { REDUCE("ext_def_list->epsilion"); }
   ;

ext_def
		: type_specifier pointers ID ';' { declare($3, makevardecl($1)); 
		    REDUCE("ext_def->type_specifier pointers ID ';'"); }
		| type_specifier pointers ID '[' const_expr ']' ';' { 
		    REDUCE("ext_def->type_specifier pointers ID '[' const_expr ']' ';' "); }
		| func_decl ';' { REDUCE("ext_def->func_decl ';'"); }
		| type_specifier ';' { REDUCE("ext_def->type_specifier ';'"); }
		| func_decl compound_stmt { REDUCE("func_decl->compound_stmt"); }
;

type_specifier
		: TYPE { struct decl *declptr = findcurrentdecl($1); 
		    check_is_type(declptr);
		    $$ = declptr; 
		    REDUCE("type_specifier->TYPE");
		}
		| VOID { struct decl *declptr = findcurrentdecl($1);
		    check_is_type(declptr);
		    $$ = declptr;
		    REDUCE("type_specifier->VOID");
		}
		| struct_specifier { REDUCE("type_specifier->struct_specifier"); }
;

struct_specifier
		: STRUCT ID '{'
		    { push_scope(); }
		    def_list /* popscope reverses stes */
		    { struct ste *fields = pop_scope();
		      declare($2, ($<declptr>$ = makestructdecl(fields)));
		    }
		    '}'
		    { REDUCE("struct_specifier->STRUCT ID '{' def_list '}'"); }
		| STRUCT ID
		    {	struct decl *declptr = findcurrentdecl($2);
			check_is_struct_type(declptr);
			$$ = declptr;
			REDUCE("struct_specifier->STRUCT ID"); 
		    }
;

func_decl
		: type_specifier pointers ID '(' ')'
		| type_specifier pointers ID '(' VOID ')'
		| type_specifier pointers ID '(' param_list ')'
;

pointers
		: '*'
		| /* empty */
;
param_list  /* list of formal parameter declaration */
		: param_decl
		| param_list ',' param_decl
;
param_decl  /* formal parameter declaration */
		: type_specifier pointers ID
		| type_specifier pointers ID '[' const_expr ']'
;
def_list    /* list of definitions, definition can be type(struct), variable, function */
		: def_list def
		| /* empty */
;
def
		: type_specifier pointers ID ';'{ declare($3, makevardecl($1));
		    REDUCE("def->type_specifier pointerts ID ';'"); }
		| type_specifier pointers ID '[' const_expr ']' ';'
		| type_specifier ';'
		| func_decl ';'
;
compound_stmt
		: '{' local_defs stmt_list '}'
;
local_defs  /* local definitions, of which scope is only inside of compound statement */
		: def_list
;
stmt_list
		: stmt_list stmt
		| /* empty */
;
stmt
		: expr ';'
		| compound_stmt
		| RETURN ';'
		| RETURN expr ';'
		| ';'
		| IF '(' expr ')' stmt %prec ELSE
		| IF '(' expr ')' stmt ELSE stmt %prec ELSE
		| WHILE '(' expr ')' stmt
		| FOR '(' expr_e ';' expr_e ';' expr_e ')' stmt
		| BREAK ';'
		| CONTINUE ';'
;
expr_e
		: expr
		| /* empty */
;
const_expr
		: expr
;
expr
		: unary '=' expr
		| or_expr
;
or_expr
		: or_list
;
or_list
		: or_list LOGICAL_OR and_expr
		| and_expr
;
and_expr
		: and_list
;
and_list
		: and_list LOGICAL_AND binary
		| binary
;
binary
		: binary RELOP binary
		| binary EQUOP binary
		| binary '+' binary
		| binary '-' binary
		| unary %prec '='
;
unary
		: '(' expr ')'
		| '(' unary ')'
		| INTEGER_CONST
		| CHAR_CONST
		| STRING
		| ID { REDUCE("unary->ID"); }
		| '-' unary %prec '!'
		| '!' unary
		| unary INCOP
		| unary DECOP
		| INCOP unary
		| DECOP unary
		| '&' unary %prec '!'
		| '*' unary %prec '!'
		| unary '[' expr ']'
		| unary '.' ID
		| unary STRUCTOP ID
		| unary '(' args ')'
		| unary '(' ')'
;
args    /* actual parameters(function arguments) transferred to function */
		: expr
		| args ',' expr
;
%%

/*  Additional C Codes 
 	Implemnt REDUCE function here */

int    yyerror (char* s)
{
	fprintf (stderr, "%s\n", s);
}

void 	REDUCE( char* s)
{
	printf("%s\n",s);
}

struct ste *push_scope()	/* SStack.TOP에다가 새로히 ScopeNode를 만들고 연결 시킨다. */
{
    struct ScopeNode *temp = SStack.TOP;
    SStack.TOP = (struct ScopeNode*)malloc(sizeof(struct ScopeNode));
    SStack.TOP->prev = temp;
    SStack.TOP->top = temp->top;
    return SStack.TOP->top;
}

struct ste *pop_scope()		/* 현재 SStack.TOP->prev가 가르키는 ste까지 내려간다. */
{
    struct ste *temp = SStack.TOP->top;
    struct ste *temp2 = temp;

    while(temp2->prev == SStack.TOP->prev->top)
	temp2 = temp2->prev;
    temp2->prev = NULL;		/* 그 prev를 NULL로 바꿔버린다. */

    SStack.TOP = SStack.TOP->prev;	/* SStack.TOP의 scope를 한단계 낮춘다. */
    return temp;
}

struct decl *insert(id *entry, struct decl *declptr)	/* declare와 똑같은 함수 이다. */
{
    struct ste *STE = (struct ste*)malloc(sizeof(struct ste));
    STE->name = entry;			    /* ste를 새로 만들고 name에 entry를 넣는다. */
    STE->decl = declptr;		    /* decl에 declptr를 넣는다 */
    STE->prev = SStack.TOP->top;	    /* SStack.TOP->top을 prev에 넣는다. */
    SStack.TOP->top = STE;		    /* SStack.TOP->top를 새로운 ste로 바꿔준다. */
    return SStack.TOP->top->decl;
}

void lookup()
{
}

struct decl *maketypedecl(int type)	/* 맨 처음 int, char, void를 넣어줄 때 사용하는 함수 */
{
    struct decl *typedecl = (struct decl*)malloc(sizeof(struct decl));
    typedecl->declclass = TYPE;
    typedecl->typeclass = type;
    return typedecl;
}

struct decl *declare(id* entry, struct decl *declptr)
{
    return insert(entry, declptr);
}

struct decl *findcurrentdecl(id* entry)	    /* entry에 해당하는 name을 가진 ste가 있는지 찾는다.*/
{
    struct ste *temp = SStack.TOP->top;
    while(temp)
    {
	 if(temp->name == entry)
	    {
	    REDUCE(temp->name->name);
	    return temp->decl;
	}
	temp = temp->prev;
    }
    printf("%d: error: declaration error",read_line());
    return NULL;
}

struct decl *makevardecl(struct decl *declptr)	/* vardecl을 만든다 */
{
    struct decl *temp = (struct decl*)malloc(sizeof(struct decl));
    temp->declclass = Hash("VAR");
    temp->type = declptr;
}

void check_is_type(struct decl* declptr)
{
    if(declptr->declclass == TYPE)
	return;
    //error checking
}

void add_type_to_var(struct decl *declptr1, struct decl *declptr2)
{

}

struct decl *makeptrdecl(struct decl *declptr)
{
    struct decl *temp = (struct decl*)malloc(sizeof(struct decl));
    temp->ptrto = declptr;
    temp->typeclass = Hash("ptr");
    temp->declclass = TYPE;
    return temp;
}

struct decl *makearraydecl(int numidx, struct decl *declptr)
{
    struct decl *temp = (struct decl*)malloc(sizeof(struct decl));
    temp->type = declptr;
    temp->declclass = TYPE;
    temp->num_index = numidx;
    temp->typeclass = Hash("array");
}

struct decl *makestructdecl(struct ste *steptr)
{
    struct decl *temp = (struct decl*)malloc(sizeof(struct decl));
    temp->fieldlist = steptr;
    temp->declclass = TYPE;
    temp->typeclass = Hash("struct");
    return temp;
}

void check_is_struct_type(struct decl *declptr)
{
    if(declptr->typeclass == Hash("struct"))
	return;
}

unsigned int Hash(const char *key)
{
    unsigned int hashvalue = 0;
    while(*key) 
	hashvalue += *key++;
    return hashvalue;
}
