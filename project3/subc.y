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
 %type<declptr>	    ext_def type_specifier struct_specifier func_decl pointers param_list param_decl def_list def compound_stmt local_defs expr_e expr or_expr or_list and_expr and_list binary unary args
/*%type<declptr>	    ext_def type_specifier func_decl param_decl struct_specifier 
def_list unary binary expr args pointers def or_expr or_list */
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
        | /* empty */ {
	   // REDUCE("ext_def_list->epsilion");
	}
   ;

ext_def
		: type_specifier pointers ID ';' {
		    if($1 && !check_is_declared_for_else($3))	//ID와 동일한 ste가 현재 scope에 있는지 확인
		    {
			declare($3, makevardecl($2? $2:$1)); 
		    }
		    else
		    {
			$$ = NULL;
			//REDUCE("ext_def->type_specifier pointers ID ';'");
		    }
		}
		| type_specifier pointers ID '[' const_expr ']' ';' {
		    if($1 && !check_is_declared_for_else($3))
		    {
			declare($3, makeconstdecl(makearraydecl($<intVal>5, makevardecl($2? $2:$1))));
		    }
		    else
		    {
			$$ = NULL;
			//REDUCE("ext_def->type_specifier pointers ID '[' const_expr ']' ';' ");
		    }
		}
		| func_decl ';' {
		    //REDUCE("ext_def->func_decl ';'");
		}
		| type_specifier ';' {
		    //REDUCE("ext_def->type_specifier ';'");
		}
		| func_decl { 
		    push_scope();
		    if($1)
			push_ste_list($1->formals);
		}
		    compound_stmt {
		    pop_scope();
		   // REDUCE("ext_def->func_decl compound_stmt");
		}
;

type_specifier
		: TYPE {
		    struct decl *typeptr = finddecl($1);
		    if(typeptr)
		    {
			if(check_is_type(typeptr))  
			{
			    $$ = typeptr; 
			}
			else
			{
			    //error
			    $$ = NULL;
			}
		    }
		    else
		    {
			//error
			printf("%d: error: declaration error. it's not type\n",read_line());
			$$ = NULL;
			//REDUCE("type_specifier->TYPE");
		    }
		}
		| VOID {
		    struct decl *typeptr = finddecl($1);
		    //check_is_type(typeptr);
		    $$ = typeptr;
		   // REDUCE("type_specifier->VOID");
		}
		| struct_specifier { 
		    $$ = $1;
		    //REDUCE("type_specifier->struct_specifier");
		}
;

struct_specifier
		: STRUCT ID '{'{
		    $<declptr>$ = check_is_declared_for_struct($2);
		    push_scope();
		}		    
		    def_list /* popscope reverses stes */{
		    struct ste *fields = pop_scope();
		    $<steptr>$ = fields;
		}
		    '}'
		{
		    if(!$<declptr>4)
		    {
			pushStr($2, $$ = makestructdecl($<steptr>6));
		    }
		    else
		    {
			//error
			$$ = NULL;
			//REDUCE("struct_specifier->STRUCT ID '{' def_list '}'");
		    }
		}
		| STRUCT ID {
		    struct decl *declptr = findstructdecl($2);
		    if(declptr)
		    {
			if(check_is_struct_type(declptr))
			{
			    $$ = declptr;
			}
			else
			{
			    //error
			    $$ = NULL;
			}
		    }
		    else
		    {
			//error;
			printf("%d: error: declaration error. it's not struct\n",read_line());
			$$ = NULL;
			//REDUCE("struct_specifier->STRUCT ID"); 
		    }
		}
;

func_decl
		: type_specifier pointers ID '(' {
		    struct decl *procdecl = makeprocdecl();
		    $<declptr>4 = check_is_declared_for_else($3);
		    push_scope();
		    declare(returnid, $2? $2:$1);
		    $<declptr>$ = procdecl;
		} ')' {
		    struct ste *formals;
		    struct decl *procdecl = $<declptr>5;
		    formals = pop_scope();
		    procdecl->returntype = formals->decl;
		    procdecl->formals = formals;
		    if(!$<declptr>4)
		    {
			$$ = procdecl;
			declare($3, procdecl);
		    }
		    else
		    {
			$$ = NULL;
			//REDUCE("func_decl->type_specifier pointers ID '(' ')'");
		    }
		}
		| type_specifier pointers ID '(' {
		    struct decl *procdecl = makeprocdecl();
		    $<declptr>4 = check_is_declared_for_else($3);
		    push_scope();
		    declare(returnid, $2? $2:$1);
		    $<declptr>$ = procdecl;
		}
		    VOID ')' {
		    struct ste *formals;
		    struct decl *procdecl = $<declptr>5;
		    formals = pop_scope();
		    procdecl->returntype = formals->decl;
		    procdecl->formals = formals;
		    if(!$<declptr>4)
		    {
			$$ = procdecl;
			declare($3, $$);
		    }
		    else
		    {
			$$ = NULL;
			//REDUCE("func_decl->type_specifier pointer ID '(' VOID ')' ");
		    }
		}
		| type_specifier pointers ID '(' {
		    struct decl *procdecl = makeprocdecl();
		    $<declptr>4 = check_is_declared_for_else($3);
		    push_scope();
		    declare(returnid, $2? $2:$1);
		    $<declptr>$ = procdecl;
		} param_list ')' {
		    struct ste *formals;
		    struct decl *procdecl = $<declptr>5;
		    formals = pop_scope();
		    /* pop_scope reverses stes(first one is the returnid) */
		    procdecl->returntype = formals->decl; /* No for type checking */
		    procdecl->formals = formals;	// must check again
		    if(!$<declptr>4)
		    {
			$$ = procdecl;
			declare($3, $$);
		    }
		    //push_scope(); /* for installing formals & locals in this scope */
		    //pushstelist(formals); 
		    else
		    {
			$$ = NULL;
			//REDUCE("func_decl->type_specifier pointers ID '(' param_list ')' ");
		    }
		}
;

pointers
		: '*' {
		    $$ = makeptrdecl($<declptr>0);
		    //REDUCE("pointers->'*'");
		}
		| /* empty */ {
		    $$ = NULL;
		    //REDUCE("pointers->epsilon");
		}
;
param_list  /* list of formal parameter declaration */
		: param_decl {
		    //REDUCE("param_list->param_decl");
		}
		| param_list ',' param_decl {
		    //REDUCE("param_list->param_list ',' param_decl");
		}
;
param_decl  /* formal parameter declaration */
		: type_specifier pointers ID {
		    declare($3, makevardecl($2? $2:$1));
		    //REDUCE("param_decl->type_specifier pointers ID");
		}
		| type_specifier pointers ID '[' const_expr ']' {
		    declare($3, makeconstdecl(makearraydecl($<intVal>5, makevardecl($2? $2:$1))));
		    //REDUCE("param_decl->type_specifier pointers ID '[' const_expr ']'");
		}
;
def_list    /* list of definitions, definition can be type(struct), variable, function */
		: def_list def {
		   // REDUCE("def_list->def_list def");
		}
		| /* empty */ {
		   // REDUCE("def_list->epsilon");
		}
;
def
		: type_specifier pointers ID ';'{
		    if($1 && !check_is_declared_for_else($3))
		    {
			declare($3, makevardecl($2? $2:$1));
			//printStack(SStack.TOP->top);
		    }
		    else
		    {
			$$ = NULL;
			//REDUCE("def->type_specifier pointerts ID ';'");
		    }
		}
		| type_specifier pointers ID '[' const_expr ']' ';' {
		    if($1 && !check_is_declared_for_else($3))
		    {
			declare($3, makeconstdecl(makearraydecl($<intVal>5, makevardecl($2? $2:$1))));
		    }
		    else
		    {
			$$= NULL;
			//REDUCE("def->type_specifier pointers ID '[' const_expr ']' ';' ");
		    }
		}
		| type_specifier ';' {
		    if(!$1)
		    {
			$$ = NULL;
			//REDUCE("def->type_specifier ';'");
		    }
		}
		| func_decl ';' {
		    if(!$1)
		    {
			$$ = NULL;
			//REDUCE("def->func_decl ';'");
		    }
		}
;
compound_stmt
		: '{' local_defs stmt_list '}' {
		    //REDUCE("compound_stmt->'{' local_defs stmt_list '}'");
		}
;
local_defs  /* local definitions, of which scope is only inside of compound statement */
		: def_list {
		    //REDUCE("local_defs->def_list");
		}
;
stmt_list
		: stmt_list stmt {
		    //REDUCE("stmt_list->stmt_list stmt");
		}
		| /* empty */ {
		    //REDUCE("stmt_list->epsilon");
		}
;
stmt
		: expr ';' {
		    //REDUCE("stmt->expr ';'");
		}
		| compound_stmt {
		    //REDUCE("stmt->compound_stmt");
		}
		| RETURN ';' {
		    check_compatible(finddecl(returnid), voidtype);
		    //REDUCE("stmt->RETURN ';'");
		}
		| RETURN expr ';' {
		    check_compatible(finddecl(returnid), $2);
		    //REDUCE("stmt->RETURN expr ';'");
		}
		| ';' {
		   // REDUCE("stmt->';'");
		}
		| IF '(' expr ')' stmt %prec ELSE
		| IF '(' expr ')' stmt ELSE stmt %prec ELSE 
		| WHILE '(' expr ')' stmt 
		| FOR '(' expr_e ';' expr_e ';' expr_e ')' stmt 
		| BREAK ';'
		| CONTINUE ';' 
;
expr_e
		: expr
		|/* empty */ {
		    //REDUCE("expr_e->epsilon");
		}
;
const_expr
		: expr
;
expr
		: unary '=' expr {
		    if(check_is_var_type($1))
		    {
			if(check_compatible($1->type, $3))
			{
			    $$ = $1->type;
			}
			else
			    $$ = NULL;
		    }
		    else
			$$ = NULL;
		}
		| or_expr
;
or_expr
		: or_list
;
or_list
		: or_list LOGICAL_OR and_expr {
		    if(check_compatible_type($1, inttype) && check_compatible_type($3, inttype))
		    {
			$$ = $1;
		    }
		    else
		    {
			$$ = NULL;
		    }
		}
		| and_expr
;
and_expr
		: and_list
;
and_list
		: and_list LOGICAL_AND binary {
		    if(check_compatible_type($1, inttype) && check_compatible_type($3, inttype))
		    {
			$$ = $1;
		    }
		    else
		    {
			$$ = NULL;
		    }
		}
		| binary
;
binary
		: binary RELOP binary {
		    $$ = reloptype($1, $3);
		}
		| binary EQUOP binary {
		    $$ = equoptype($1, $3);
		}
		| binary '+' binary {
		    $$ = plustype($1, $3);
		}
		| binary '-' binary {
		    $$ = minustype($1, $3);
		}
		| unary %prec '=' {
		    if($1)
			$$ = $1->type;
		    else 
			$$ = NULL;
		}
;
unary
		: '(' expr ')' {
		    $$ = makeconstdecl($2);
		    //$$ = $2;
		    //REDUCE("unary->'(' expr ')'");
		}
		| '(' unary ')' {
		    $$ = $2;
		    //REDUCE("unary->'(' unary ')'");
		}
		| INTEGER_CONST {
		    $$ = makenumconstdecl(inttype, $1);
		}
		| CHAR_CONST {
		    $$ = makecharconstdecl(chartype, $1);
		    //REDUCE("unary->CHAR_CONST");
		}
		| STRING {
		    $$ = makestringconstdecl(chartype, $1);
		    //REDUCE("unary->STRING");
		}
		| ID {
		    if(finddecl($1))
		    {
			$$ = finddecl($1);
		    }
		    else
		    {
			//error
			printf("%d: error: declaration error. it's not id\n",read_line());
			$$ = NULL;
		    }
		}
		| '-' unary %prec '!' {
		    if(check_compatible_type($2->type, inttype))
		    {
			$$ = $2;
		    }
		    else
			$$ = NULL;
		}
		| '!' unary {
		    if(check_compatible_type($2->type, inttype))
		    {
			$$ = $2;
		    }
		    else
			$$ = NULL;
		}
		| unary INCOP {
		    if(!INDECOPtype($1->type))
			$$ = NULL;
		}
		| unary DECOP {
		    if(!INDECOPtype($1->type))
			$$ = NULL;
		}
		| INCOP unary {
		    if(!INDECOPtype($2->type))
			$$ = NULL;
		    else
			$$ = $2;
		}
		| DECOP unary {
		    if(!INDECOPtype($2->type))
			$$ = NULL;
		    else
			$$ = $2;
		}
		| '&' unary %prec '!' {
		    if(check_is_var_type($2))
		    {
			$$ = makeconstdecl(makeptrdecl($2->type));
		    }
		    else
		    {
			//error
			$$ = NULL;
		    }
		}
		| '*' unary %prec '!' {
		    if(check_is_var_type($2) && check_is_ptr_type($2->type))
		    {
			$$ = makevardecl($2->type->ptrto);
		    }
		    else
		    {
			//error
			$$ = NULL;
		    }
		}
		| unary '[' expr ']' {
		    if(check_is_const_type($1))
		    {
			$$ = arrayaccess($1, $3);
		    }
		    else
		    {
			$$ = NULL;
		    }
		}
		| unary '.' ID {
		    if(check_is_var_type($1))
		    {
			$$ = structaccess($1, $3);
		    }
		    else
		    {
			$$ = NULL;
		    }
		}
		| unary STRUCTOP ID {
		    if(check_is_var_type($1))
		    {
			$$ = structPtraccess($1, $3);
		    }
		    else
		    {
			$$ = NULL;
		    }
		}
		| unary '(' args ')'{
		    if(check_is_proc($1))
		    {
			$$ = check_function_call($1, $3);
		    }
		    else
		    {	
			$$ = NULL;
			//REDUCE("unary->unary '(' args ')'");
		    }
		}
		| unary '(' ')' {
		    if(check_is_proc($1))
		    {
			$$  = check_function_call($1, NULL);
		    }
		    else
		    {
			$$ = NULL;
			//REDUCE("unary->unary '(' ')'");
		    }
		}
;
args    /* actual parameters(function arguments) transferred to function */
		: expr {
		    $$ = $1;
		    $$->next = NULL;
		}
		| expr ',' args {
		    $1->next = $3;
		    $$ = $1;
		}
;
%%

/*  Additional C Codes 
 	Implemnt REDUCE function here */

int    yyerror (char* s)
{

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

struct ste *push_ste_list(struct ste *formals)
{
    struct ste *ftemp = formals;
    while(ftemp)
    {
	declare(ftemp->name, ftemp->decl);
	ftemp = ftemp->prev;
    }
    return SStack.TOP->top;
}


struct ste *pop_scope()		/* 현재 SStack.TOP->prev가 가르키는 ste까지 내려간다. */
{
    struct ste *temp = SStack.TOP->top;
    struct ste *temp3 = SStack.TOP->prev->top;
    struct ste *Head = NULL;

    if(temp == temp3)	/* push_scope()하고 아무것도 추가하지 않은 경우 */
    {
	SStack.TOP = SStack.TOP->prev;
	return temp;
    }

    while(temp != temp3)
    {
	struct ste *headtemp = Head;
	struct ste *stacktemp = temp->prev;
	Head = temp;
	Head->prev = headtemp;
	temp = stacktemp;
    }
    
    SStack.TOP = SStack.TOP->prev;	/* SStack.TOP의 scope를 한단계 낮춘다. */
    return Head;
}

struct ste *insert(id *entry, struct decl *declptr)	/* declare와 똑같은 함수 이다. */
{
    struct ste *STE = (struct ste*)malloc(sizeof(struct ste));
    STE->name = entry;			    /* ste를 새로 만들고 name에 entry를 넣는다. */
    STE->decl = declptr;		    /* decl에 declptr를 넣는다 */
    STE->prev = SStack.TOP->top;	    /* SStack.TOP->top을 prev에 넣는다. */
    SStack.TOP->top = STE;		    /* SStack.TOP->top를 새로운 ste로 바꿔준다. */
    return SStack.TOP->top;
}





struct ste *declare(id* entry, struct decl *declptr)
{
    return insert(entry, declptr);
}






struct decl *maketypedecl(int type)	/* 맨 처음 int, char, void를 넣어줄 때 사용하는 함수 */
{
    struct decl *typedecl = (struct decl*)malloc(sizeof(struct decl));
    typedecl->declclass = TYPE;
    typedecl->typeclass = type;
    return typedecl;
}

struct decl *makevardecl(struct decl *typeptr)	/* vardecl을 만든다 */
{
    struct decl *temp = (struct decl*)malloc(sizeof(struct decl));
    temp->declclass = Hash("VAR");
    temp->type = typeptr;
    return temp;
}

struct decl *makeptrdecl(struct decl *typeptr)
{
    struct decl *temp = (struct decl*)malloc(sizeof(struct decl));
    temp->ptrto = typeptr;
    temp->typeclass = Hash("ptr");
    temp->declclass = TYPE;
    return temp;
}

struct decl *makearraydecl(int numidx, struct decl *varptr)
{
    struct decl *temp = (struct decl*)malloc(sizeof(struct decl));
    temp->elementvar = varptr;
    temp->declclass = TYPE;
    temp->num_index = numidx;
    temp->typeclass = Hash("array");
    return temp;
}

struct decl *makestructdecl(struct ste *fieldptr)
{
    struct decl *temp = (struct decl*)malloc(sizeof(struct decl));
    temp->fieldlist = fieldptr;
    temp->declclass = TYPE;
    temp->typeclass = Hash("struct");
    return temp;
}

struct decl *makeconstdecl(struct decl *typeptr)
{
    struct decl *temp = (struct decl*)malloc(sizeof(struct decl));
    temp->declclass = Hash("CONST");
    temp->type = typeptr;
    return temp;
}

struct decl *makenumconstdecl(struct decl *typeptr, int intconst)
{
    struct decl *temp = (struct decl*)malloc(sizeof(struct decl));
    temp->declclass = Hash("CONST");
    temp->type = typeptr;
    temp->intvalue = intconst;
    return temp;
}

struct decl *makecharconstdecl(struct decl *typeptr, char *charconst)
{
    struct decl *temp = (struct decl*)malloc(sizeof(struct decl));
    temp->declclass = Hash("CONST");
    temp->type = typeptr;
    temp->charvalue = charconst;
    return temp;
}

struct decl *makestringconstdecl(struct decl *typeptr, const char* stringconst)
{
    struct decl *temp = (struct decl*)malloc(sizeof(struct decl));
    temp->declclass = Hash("CONST");
    temp->type = makeptrdecl(typeptr);
    temp->stringvalue = stringconst;
    return temp;
}

struct decl *makeprocdecl()
{
    struct decl *temp = (struct decl*)malloc(sizeof(struct decl));
    temp->declclass = Hash("FUNC");
    return temp;
}





struct decl *finddecl(id *entry)	    /* entry에 해당하는 name을 가진 ste가 있는지 찾는다.*/
{
    struct ste *temp = SStack.TOP->top;
    while(temp)
    {
	if(temp->name == entry)
	{
	    //REDUCE(temp->name->name);
	    return temp->decl;
	}
	temp = temp->prev;
    }
    return NULL;
}

struct decl *findstructdecl(struct id *entry)
{
    struct ste *temp = StrStack;
    while(temp)
    {
	if(temp->name == entry)
	{
	    return temp->decl;
	}
	temp = temp->prev;
    }
    return NULL;
}

struct decl *findcurrentdecl(struct id *fieldid, struct ste *fieldlist)
{
    struct ste *temp = fieldlist;
    while(temp)
        {
	    if(temp->name == fieldid)
	        {
		    //REDUCE(temp->name->name);
		    return temp->decl;
		}
	    temp = temp->prev;
        }
    printf("%d: error: declaration error. it's not member of struct",read_line());
    return NULL;
}






struct decl *structaccess(struct decl *structptr, struct id *fieldid)
{
    struct decl *typeptr = structptr->type;
    if(check_is_struct_type(typeptr))
	return(findcurrentdecl(fieldid, typeptr->fieldlist));
    else
	return NULL;
}

struct decl *structPtraccess(struct decl *structptr, struct id *fieldid)
{
    struct decl *typeptr = structptr->type;
    if(check_is_ptr_type(typeptr))
    {
	typeptr = typeptr->ptrto;
	if(check_is_struct_type(typeptr))
	    return(findcurrentdecl(fieldid, typeptr->fieldlist));
	else
	    return NULL;
    }
    else
	return NULL;
}

struct decl *arrayaccess(struct decl *arrayptr, struct decl *indexptr)
{
    struct decl *arraytype = arrayptr->type;
    if(check_is_array_type(arraytype))
    {
	if(check_compatible_type(indexptr, inttype))
	    return (arraytype->elementvar);
	else
	{
	    REDUCE("error index is wrong");
	    return NULL;
	}
    }
    else
	return NULL;
}







struct decl *plustype(struct decl *type1, struct decl *type2)
{
    if(type1 == NULL || type2 == NULL)
    {
	printf("%d: error: type is not suitable for plus\n",read_line());
	return NULL;
    }
    else if(type1 == inttype && type2 == inttype)
    {
	return inttype;
    }
    else if(type1 == inttype && type2->typeclass == Hash("ptr"))
    {
	return inttype;
    }
    else if(type1->typeclass == Hash("ptr") && type2 == inttype)
    {
	return type1;
    }
    printf("%d: error: type is not suitable for plus\n",read_line());
    return NULL;
}

struct decl *minustype(struct decl *type1, struct decl *type2)
{
    if(type1 == NULL || type2 == NULL)
    {
	printf("%d: error: type is not suitable for plus\n",read_line());
	return NULL;
    }
    else if(type1 == inttype && type2 == inttype)
    {
	return inttype;
    }
    else if(type1->typeclass == Hash("ptr") && type2 == inttype)
    {
	return type1;
    }
    printf("%d: error: type is not suitable for minus\n",read_line());
    return NULL;
}

struct decl *reloptype(struct decl *type1, struct decl *type2)
{
    if(check_compatible_type(type1, type2))
    {
	if(type1->typeclass == Hash("struct"))
	{
	    printf("%d: error: type is not suitable for RELOP\n",read_line());
	    return NULL;
	}
	else
	{
	    return inttype;
	}
    }
    return NULL;
}
    
struct decl *equoptype(struct decl *type1, struct decl *type2)
{
    if(check_compatible_type(type1, type2))
    {
	if(type1->typeclass == Hash("struct"))
	{
	    printf("%d: error: type is not suitable for EQUOP\n",read_line());
	    return NULL;
	}
	else
	{
	    return inttype;
	}
    }
}

struct decl *INDECOPtype(struct decl *type)
{
    if(type == inttype || type == chartype)
    {
	return type;
    }
    else if(type->typeclass == Hash("ptr"))
    {
	return type;
    }
    else
    {
	printf("%d: error: type is not suitable for INCOP or DECOP\n",read_line());
	return NULL;
    }
}




struct decl *check_is_var_type(struct decl *declptr)
{
    if(declptr && declptr->declclass == Hash("VAR"))
    {
	return declptr;
    }
    else
    {
	//error
	printf("%d: error: declaration error. it's not variable\n", read_line());
        return NULL;
    }
}

struct decl *check_is_const_type(struct decl *declptr)
{
    if(declptr && declptr->declclass == Hash("CONST"))
    {
	return declptr;
    }
    else
    {
	printf("%d: error: declaration error. it's not const\n", read_line());
	return NULL;
    }
}

struct decl *check_compatible(struct decl *declptr1, struct decl *declptr2)
{
    if(declptr2 && declptr1)
    {
	//REDUCE("errorcheckpoint1");
	if(declptr1->typeclass == Hash("ptr"))	    //declptr1이 포인터 인 경우
	{
	    //REDUCE("errorcheckpoint2");
	    if(declptr1->ptrto == declptr2->ptrto)	//type 확인
	    {
		//REDUCE("errorcheckpoint3");
		return declptr1;
	    }
	    else if(declptr2->typeclass == Hash("array"))	// declptr2가 array인지 확인
	    {
		//REDUCE("errorcheckpoint4");
		if(declptr1->ptrto == declptr2->elementvar->type)
		{
		    //REDUCE("errorcheckpoint5");
		    return declptr1;
		}
	    }
	}
	else if(declptr1 == declptr2) //type이 같은가 확인
	{
	    //REDUCE("errorcheckpoint6");
	    return declptr1;
	}
    }
    //error
    printf("%d: error: declaration error. it's not compatible\n", read_line());
    //REDUCE("it's mean error");
    //yyerror("error: declarartion error. it's not compatible");
    return NULL;
}

struct decl *check_compatible_type(struct decl *declptr1, struct decl *declptr2)
{
    
    if(declptr2 && declptr1)
    {
	if(declptr1->typeclass == Hash("ptr"))	    //declptr1이 포인터 인 경우
	{
	    if(declptr1->ptrto == declptr2->ptrto)	//type 확인
	    {
		return declptr1;
	    }
	}
	else if(declptr1 == declptr2) //type이 같은가 확인
	{
	    return declptr1;
	}
    }
    //error
    printf("%d: error: declaration error. it's not compatible\n", read_line());
    return NULL;
}

struct decl *check_is_struct_type(struct decl *structptr)
{
    if(structptr && structptr->typeclass == Hash("struct"))
    {
	return structptr;
    }
    else
    {
	printf("%d: error: declaration error. it's not struct\n", read_line());
	return NULL;
    }
}

struct decl *check_is_array_type(struct decl *arrayptr)
{
    if(arrayptr && arrayptr->typeclass == Hash("array"))
    {
	return arrayptr;
    }
    else
    {
	printf("%d: error: declaration error. it's not array\n", read_line());
	return NULL;
    }
}

struct decl *check_is_ptr_type(struct decl *ptrptr)
{
    if(ptrptr && ptrptr->typeclass == Hash("ptr"))
    {
	return ptrptr;
    }
    else
    {
	printf("%d: error: declaration error. it's not poniter\n", read_line());
	return NULL;
    }
}

struct decl *check_is_type(struct decl* declptr)
{
    if(declptr && declptr->declclass == TYPE)
    {
	return declptr;
    }
    else
    {
	printf("%d: error: declaration error. it's not type\n",read_line());
	return NULL;
    //error checking
    }
}

struct decl *check_function_call(struct decl *procptr, struct decl *actuals)
{
    struct ste *formals = procptr->formals->prev;
    /* 1. compare number of formals and actuals */

    /* 2. check for type match			*/
    while(formals != NULL && actuals != NULL)
    {
	if(check_is_var_type(formals->decl))
	{
	    if(check_compatible(formals->decl->type, actuals))
	    {
		formals = formals->prev;
		actuals = actuals->next;
	    }
	    else
	    {
		break;
	    }
	}
	else
	{
	    break;
	}
    }
    if(formals || actuals)
    {
	printf("%d: error: argument error\n",read_line());
	return NULL;
    }

    return makeconstdecl(procptr->returntype);  /* for decl of the call */
}

struct decl *check_is_proc(struct decl *procptr)
{
    if(procptr && procptr->declclass == Hash("FUNC"))
    {
	return procptr;
    }
    else
    {
	printf("%d: error: declaration error. it's not function\n",read_line());
	return NULL;
    }
}

struct decl *check_is_declared_for_else(struct id *entry)
{
    struct ste *temp = SStack.TOP->top;
    struct ste *temp2;

    if(SStack.TOP->prev == NULL)
	temp2 = NULL;
    else
	temp2 = SStack.TOP->prev->top;

    while(temp != temp2)
    {
	if(temp->name == entry)
	{
	    printf("%d: error: declaration error. it's already declared\n",read_line());
	    return temp->decl;
	}
	temp = temp->prev;
    }
    
    temp = StrStack;
    while(temp)
    {
	if(temp->name == entry)
	{
	    printf("%d: error: declaration error. it's already declared\n",read_line());
	    return NULL;
	}
	temp = temp->prev;
    } 
    return NULL;
}

struct decl *check_is_declared_for_struct(struct id *entry)
{
    struct ste *temp = SStack.TOP->top;
    while(temp)
    {
	if(temp->name == entry)
	{
	    printf("%d: error: declaration error. it's already declared\n",read_line());
	    return temp->decl;
	}
	temp = temp->prev;
    }

    temp = StrStack;
    while(temp)
    {
	if(temp->name == entry)
	{
	    printf("%d: error: declaration error. it's alreay declared\n",read_line());
	    return temp->decl;
	}
	temp = temp->prev;
    }
    return NULL;
}





unsigned int Hash(const char *key)
{
    unsigned int hashvalue = 0;
    while(*key) 
	hashvalue += *key++;
    return hashvalue;
}

void printStack(struct ste *top)
{
    while(top)
    {
	printf("\nThis variable's name is %s\n", top->name->name);
	tellmetype(top->decl);
	top = top->prev;
    }
}

void tellmetype(struct decl *declptr)
{
    struct decl *temp = declptr;
    
    if(!temp)
	return;
    
    printf("/**** Speak To Me ****/\n");

    if(temp->declclass == Hash("VAR"))
    {
	REDUCE("Declclass is VAR");
    }
    else if(temp->declclass == Hash("CONST"))
    {
	REDUCE("Declclass is CONST");
    }
    else if(temp->declclass == Hash("FUNC"))
    {
	REDUCE("Declclass is FUNC");
    }
    else if(temp->declclass == TYPE)
    {
	REDUCE("Declclass is TYPE");
    }

    if(temp->typeclass == Hash("int"))
    {
	REDUCE("Typeclass is INT");
    }
    else if(temp->typeclass == Hash("ptr"))
    {
	REDUCE("Typeclass is Pointer");
    }
    else if(temp->typeclass == Hash("array"))
    {
	REDUCE("Typeclass is Array");
    }
    else if(temp->typeclass == Hash("char"))
    {
	REDUCE("Typeclass is CHAR");
    }
    else if(temp->typeclass == Hash("struct"))
    {
	REDUCE("Typeclass is Struct");
    }
    else if(temp->typeclass == VOID)
    {
	REDUCE("Typeclass is VOID");
    }
    
    printf("\n");

    if(temp->type)
    {
	tellmetype(temp->type);
    }
    if(temp->returntype)
    {
	tellmetype(temp->returntype);
    }
    if(temp->elementvar)
    {
	tellmetype(temp->elementvar);
    }
    if(temp->ptrto)
    {
	tellmetype(temp->ptrto);
    }
    if(temp->fieldlist)
    {
	printStack(temp->fieldlist);
    }
    if(temp->formals)
    {
	printStack(temp->formals);
    }
    
}

struct ste *pushStr(struct id *entry, struct decl *declptr)
{
    struct ste *temp = StrStack;
    StrStack = (struct ste*)malloc(sizeof(struct ste));
    StrStack->name = entry;
    StrStack->decl = declptr;
    StrStack->prev = temp;
    return StrStack;
}
