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
 %type<declptr>	    ext_def type_specifier struct_specifier func_decl pointers param_list param_decl def_list def compound_stmt local_defs expr_e expr or_expr or_list and_expr and_list binary unary args const_expr

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
		    }
		}
		| type_specifier pointers ID '[' const_expr ']' ';' {
		    if($1 && $5 && !check_is_declared_for_else($3))
		    {
			declare($3, makeconstdecl(makearraydecl($5->intvalue, makevardecl($2? $2:$1))));
		    }
		    else
		    {
			$$ = NULL;
		    }
		}
		| func_decl ';' {
		}
		| type_specifier ';' {
		}
		| func_decl { 
		    push_scope();
		    if($1)
			push_ste_list($1->formals);
		}
		    compound_stmt {
		    pop_scope();
		    if($1)
			$1->isdeclared = 1;
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
			$$ = NULL;
		    }
		}
		| VOID {
		    struct decl *typeptr = finddecl($1);
		    $$ = typeptr;
		}
		| struct_specifier { 
		    $$ = $1;
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
			yyerror("struct is not declared");
			$$ = NULL;
		    }
		}
;

func_decl
		: type_specifier pointers ID '(' ')' {
		    struct decl *procdecl = makeprocdecl();
		    push_scope();
		    declare(returnid, $2? $2:$1);
		    struct ste *formals;
		    formals = pop_scope();
		    procdecl->returntype = formals->decl;
		    procdecl->formals = formals;
		    if(!check_is_declared_for_else($3))
		    {
			$$ = procdecl;
			declare($3, $$);
		    }
		    else
		    {
			$$ = NULL;
		    }
		}
		| type_specifier pointers ID '(' VOID ')' {
		    struct decl *procdecl = makeprocdecl();
		    push_scope();
		    declare(returnid, $2? $2:$1);
		    struct ste *formals;
		    formals = pop_scope();
		    procdecl->returntype = formals->decl;
		    procdecl->formals = formals;
		    if(!check_is_declared_for_else($3))
		    {
			$$ = procdecl;
			declare($3, $$);
		    }
		    else
		    {
			$$ = NULL;
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
		    }
		}
;

pointers
		: '*' {
		    $$ = makeptrdecl($<declptr>0);
		}
		| /* empty */ {
		    $$ = NULL;
		}
;
param_list  /* list of formal parameter declaration */
		: param_decl {
		}
		| param_list ',' param_decl {
		}
;
param_decl  /* formal parameter declaration */
		: type_specifier pointers ID {
		    if($1 && !check_is_declared_for_else($3))
		    {
			declare($3, makevardecl($2? $2:$1));
		    }
		    else
		    {
			$$ = NULL;
		    }
		}
		| type_specifier pointers ID '[' const_expr ']' {
		    if($1 && $5 && !check_is_declared_for_else($3))
		    {
			declare($3, makeconstdecl(makearraydecl($5->intvalue, makevardecl($2? $2:$1))));
		    }
		    else
		    {
			$$ = NULL;
		    }
		}
;
def_list    /* list of definitions, definition can be type(struct), variable, function */
		: def_list def {
		}
		| /* empty */ {
		}
;
def
		: type_specifier pointers ID ';'{
		    if($1 && !check_is_declared_for_else($3))
		    {
			declare($3, makevardecl($2? $2:$1));
		    }
		    else
		    {
			$$ = NULL;
		    }
		}
		| type_specifier pointers ID '[' const_expr ']' ';' {
		    if($1 && $5 && !check_is_declared_for_else($3))
		    {
			declare($3, makeconstdecl(makearraydecl($5->intvalue, makevardecl($2? $2:$1))));
		    }
		    else
		    {
			$$= NULL;
		    }
		}
		| type_specifier ';' {
		    if(!$1)
		    {
			$$ = NULL;
		    }
		}
		| func_decl ';' {
		    if(!$1)
		    {
			$$ = NULL;
		    }
		}
;
compound_stmt
		: '{' local_defs stmt_list '}' {
		}
;
local_defs  /* local definitions, of which scope is only inside of compound statement */
		: def_list {
		}
;
stmt_list
		: stmt_list stmt {
		}
		| /* empty */ {
		}
;
stmt
		: expr ';' {
		}
		| compound_stmt {
		}
		| RETURN ';' {
		   if(!check_compatible(finddecl(returnid), voidtype))
			yyerror("not compatible");
		}
		| RETURN expr ';' {
		    if(!check_compatible(finddecl(returnid), $2))
			yyerror("not compatible");
		}
		| ';' {
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
		}
;
const_expr
		: expr {
		    if(check_compatible_type($1, inttype))
		    {
			$$ = $1;
		    }
		    else
		    {
			yyerror("not inttype");
			$$ = NULL;
		    }

		}
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
			{
			    if($3)
				yyerror("not compatible");
			    $$ = NULL;
			}
		    }
		    else
		    {
			if($1)
			    yyerror("not variable");
			$$ = NULL;
		    }
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
		    if($2)
			declare(dummy, $$ = makeconstdecl($2));
		    else
			$$ = NULL;
		}
		| '(' unary ')' {
		    if($2)
			$$ = $2;
		    else
			$$ = NULL;
		}
		| INTEGER_CONST {
		    declare(dummy, $$ = makenumconstdecl(inttype, $1));
		}
		| CHAR_CONST {
		    declare(dummy, $$ = makecharconstdecl(chartype, $1));
		}
		| STRING {
		    declare(dummy, $$ = makestringconstdecl(chartype, $1));
		}
		| ID {
		    if(finddecl($1))
		    {
			$$ = finddecl($1);
		    }
		    else
		    {
			//error
			yyerror("not declared");
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
			declare(dummy, $$ = makeconstdecl(makeptrdecl($2->type)));
		    }
		    else
		    {
			//error
			if($2)
			    yyerror("not variable");
			$$ = NULL;
		    }
		}
		| '*' unary %prec '!' {
		    if(check_is_var_type($2) && check_is_ptr_type($2->type))
		    {
			declare(dummy, $$ = makevardecl($2->type->ptrto));
		    }
		    else
		    {
			//error
			if($2)
			    yyerror("not variable");
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
			if($1)
			    yyerror("not variable");
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
			if($2)
			    yyerror("not variable");
			$$ = NULL;
		    }
		}
		| unary '(' args ')'{
		    if(check_is_proc($1))
		    {
			$$ = check_function_call($1, $3);
			//must delete args
		    }
		    else
		    {	
			$$ = NULL;
		    }

		    struct decl *temp = $3;
		    while(temp)
		    {
			free(temp);
			temp = temp->next;
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
		    }
		}
;
args    /* actual parameters(function arguments) transferred to function */
		: expr {
		    $$ = makevardecl($1);
		    $$->next = NULL;
		}
		| expr ',' args {
		    $$ = makevardecl($1);
		    $$->next = $3;
		}
;
%%

/*  Additional C Codes 
 	Implemnt REDUCE function here */

int    yyerror (char* s)
{
    if(filename)
    {
	fprintf (stderr, "%s:%d: error: %s\n", filename, read_line(), s);
    }
    else
    {
	fprintf (stderr, "%d: error: %s\n", read_line(), s);
    }
}

void 	REDUCE( char* s)
{
	printf("%s\n",s);
}

void init_type()
{
    SStack.TOP = (struct ScopeNode*)malloc(sizeof(struct ScopeNode));
    SStack.TOP->prev = NULL;
    SStack.TOP->top = NULL;
    StrStack = NULL;

    inttype = maketypedecl(Hash("int"));
    chartype = maketypedecl(Hash("char"));
    voidtype = maketypedecl(VOID);

    declare(enter(TYPE, "int", 3), inttype);
    declare(enter(TYPE, "char", 4), chartype);
    declare(enter(VOID, "void", 4), voidtype);
    returnid = enter(ID, "*return", 7);
    dummy = enter(ID, "*dummy", 6);
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

struct ste *free_scope()    //function이 끝나고 ste를 전부 free시키는 함수
{
    struct ste *temp = SStack.TOP->top;
    struct ste *temp3 = SStack.TOP->prev->top;

    if(temp == temp3)
    {
	free(SStack.TOP);
	SStack.TOP = SStack.TOP->prev;
	return NULL;
    }

    while(temp != temp3)
    {
	free(temp);
	temp = temp->prev;
    }

    free(SStack.TOP);
    SStack.TOP = SStack.TOP->prev;
    return NULL;
}

struct ste *free_ste_list(struct ste *steptr)
{
    struct ste *temp = steptr;
    while(temp)
    {
	free(temp);
	temp = temp->prev;
    }
    return NULL;
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
    temp->isdeclared = 0;
    return temp;
}





struct decl *finddecl(id *entry)	    /* entry에 해당하는 name을 가진 ste가 있는지 찾는다.*/
{
    struct ste *temp = SStack.TOP->top;
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
    yyerror("struct not have same name field");
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
	    yyerror("index is not int type");
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
	yyerror("type is not suitable for plus operaton");
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
    yyerror("type is not suitable for plus operaton");
    return NULL;
}

struct decl *minustype(struct decl *type1, struct decl *type2)
{
    if(type1 == NULL || type2 == NULL)
    {
	yyerror("type is not suitable for minus operaton");
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
    yyerror("type is not suitable for minus operaton");
    return NULL;
}

struct decl *reloptype(struct decl *type1, struct decl *type2)
{
    if(check_compatible_type(type1, type2))
    {
	if(type1->typeclass == Hash("struct"))
	{
	    yyerror("type is not suitable for relop operaton");
	    return NULL;
	}
	else
	{
	    return inttype;
	}
    }
    yyerror("type is not suitable for relop operaton");
    return NULL;
}
    
struct decl *equoptype(struct decl *type1, struct decl *type2)
{
    if(check_compatible_type(type1, type2))
    {
	if(type1->typeclass == Hash("struct"))
	{
	    yyerror("type is not suitable for equop operaton");
	    return NULL;
	}
	else
	{
	    return inttype;
	}
    }
    yyerror("type is not suitable for equop operaton");
    return NULL;
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
        yyerror("type is not suitable for incop(or decop) operaton");
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
	//yyerror("not variable");
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
	yyerror("not constant");
	return NULL;
    }
}

struct decl *check_compatible(struct decl *declptr1, struct decl *declptr2)
{
    if(declptr2 && declptr1)
    {
	if(declptr1->typeclass == Hash("ptr"))	    //declptr1이 포인터 인 경우
	{
	    if(declptr1->ptrto == declptr2->ptrto)	//type 확인
	    {
		return declptr1;
	    }
	    else if(declptr2->typeclass == Hash("array"))	// declptr2가 array인지 확인
	    {
		if(declptr1->ptrto == declptr2->elementvar->type)
		{
		    return declptr1;
		}
	    }
	}
	else if(declptr1 == declptr2) //type이 같은가 확인
	{
	    return declptr1;
	}
    }
    //error
    //yyerror("not compatible");
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
    //yyerror("not compatible");
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
    	yyerror("not struct");
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
    	yyerror("not array");
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
        yyerror("not pointer");
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
        yyerror("not type");
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
	    if(check_compatible(formals->decl->type, actuals->type))
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
   	yyerror("actual args are not equal to formal args");
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
	yyerror("not a function");
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
	    if(temp->decl->declclass == Hash("FUNC"))
	    {
		if(!temp->decl->isdeclared)
		{
		    return NULL;
		}
	    }
	    yyerror("redeclaration");
	    return temp->decl;
	}
	temp = temp->prev;
    }
    
    temp = StrStack;
    while(temp)
    {
	if(temp->name == entry)
	{
	    yyerror("redeclaration");
	    return temp->decl;
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
	    yyerror("redeclaration");
	    return temp->decl;
	}
	temp = temp->prev;
    }

    temp = StrStack;
    while(temp)
    {
	if(temp->name == entry)
	{
	    yyerror("redeclaration");
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
