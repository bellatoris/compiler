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
 %type<declptr>	    ext_def type_specifier struct_specifier func_decl pointers param_list param_decl def_list def local_defs expr_e expr or_expr or_list and_expr and_list binary unary args const_expr

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
		    if($1 && !check_is_declared_for_else($3)) 
		    {
			declare($3, makevardecl($2? $2:$1)); 
			//printStack(SStack.TOP->top);
			//printStack(StrStack);
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
		| func_decl compound_stmt
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
		    def_list '}' /* popscope reverses stes */{
		    struct ste *fields = pop_scope();
		    if(!$<declptr>4)
		    {
			pushStr($2, $$ = makestructdecl(fields));
		    }
		    else
		    {
			//error
			free_ste_list(fields);
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

		    struct decl *isdecl = check_is_declared_for_else($3);

		    if(!isdecl)
		    {
			$$ = procdecl;
			declare($3, $$);
		    }
		    //int type은 한번 선언된적이 있는 function이 인지 확인 해준다.
		    else if(isdecl == inttype)
		    {
			struct decl *temp = finddecl($3);
			//처음 선언했던 formal과 지금 선언하려는 formal이 같은지 확인한다.
			if(!check_function_declare(temp, procdecl))
			{
			    $$ = NULL;
			    yyerror("wrong declaration");
			}
			else
			{
			    $$ = temp;
			}
			procdecl->returntype = NULL;
			procdecl->formals = NULL;
			free(procdecl);
			free_ste_list(formals);
		    }
		    else
		    {
			procdecl->returntype = NULL;
			procdecl->formals = NULL;
			free(procdecl);
			free_ste_list(formals);
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

		    struct decl *isdecl = check_is_declared_for_else($3);

		    if(!isdecl)
		    {
			$$ = procdecl;
			declare($3, $$);
		    }
		    else if(isdecl == inttype)
		    {
			struct decl *temp = finddecl($3);
			if(!check_function_declare(temp, procdecl))
			{
			    yyerror("wrong declarartion");
			    $$ = NULL;
			}
			else
			{
			    $$ = temp;
			}
			procdecl->returntype = NULL;
			procdecl->formals = NULL;
			free(procdecl);
			free_ste_list(formals);
		    }
		    else
		    {
			procdecl->returntype = NULL;
			procdecl->formals = NULL;
			free(procdecl);
			free_ste_list(formals);
			$$ = NULL;
		    }
		}
		| type_specifier pointers ID '(' {
		    struct decl *procdecl = makeprocdecl();
		    //tellmetype(procdecl);
		    //필요없는 elementvar을 사용해서 선언된적 있는 ID인지 확인한다.
		    procdecl->elementvar = check_is_declared_for_else($3);
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
		    if(!(procdecl->elementvar) && $6)
		    {
			$$ = procdecl;
			procdecl->elementvar = NULL;
			declare($3, $$);
		    }
		    else if(procdecl->elementvar == inttype && $6)
		    {
			struct decl *temp = finddecl($3);
			if(check_function_declare(temp, procdecl))
			{
			    $$ = temp;
			}
			else
			{
			    yyerror("wrong declaration");
			    $$ = NULL;
			}
			procdecl->formals = NULL;
			procdecl->elementvar = NULL;
			procdecl->returntype = NULL;
			free(procdecl);
			free_ste_list(formals);
		    }
		    //push_scope(); /* for installing formals & locals in this scope */
		    //pushstelist(formals); 
		    else
		    {
			procdecl->formals = NULL;
			procdecl->elementvar = NULL;
			procdecl->returntype = NULL;
			free(procdecl);
			free_ste_list(formals);
			$$ = NULL;
		    }
		}
;

pointers
		: '*' {
		    //TYPE이면 ptrdecl을 미리 만들어 둔다.
		    if($<declptr>0 && $<declptr>0->declclass == TYPE)	
			$$ = makeptrdecl($<declptr>0);
		    else
			$$ = NULL;
		}
		| /* empty */ {
		    $$ = NULL;
		}
;
param_list  /* list of formal parameter declaration */
		: param_decl {
		    if($1)
			$$ = $1;
		    else
			$$ = NULL;
		}
		| param_list ',' param_decl {
		    if($1 && $3)
			$$ = $1;
		    else
			$$ = NULL;
		}
;
param_decl  /* formal parameter declaration */
		: type_specifier pointers ID {
		    if($1 && !check_is_declared_for_else($3))
		    {
			declare($3, $$ = makevardecl($2? $2:$1));
		    }
		    else
		    {
			$$ = NULL;
		    }
		}
		| type_specifier pointers ID '[' const_expr ']' {
		    if($1 && $5 && !check_is_declared_for_else($3))
		    {
			declare($3, $$ = makeconstdecl(makearraydecl($5->intvalue, makevardecl($2? $2:$1))));
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
		: '{'{
		    push_scope();
		    if($<declptr>0 && $<declptr>0->declclass == Hash("FUNC"))
		    {
			push_ste_list($<declptr>0->formals);
		    } 
		} local_defs stmt_list '}' {
		    free_scope();
		    if($<declptr>0 && $<declptr>0->declclass == Hash("FUNC"))
		    {
			$<declptr>0->isdeclared = 1;
		    }
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
			yyerror("return value is not return type");
		}
		| RETURN expr ';' {
		    if($2 && !check_compatible(finddecl(returnid), $2->type))
			yyerror("return value is not return type");
		}
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
		|/* empty */ {
		}
;
const_expr
		: expr {
		    if(!$1)
		    {
			$$ = NULL;
		    }
		    //check index type
		    else if(check_compatible_type($1->type, inttype))
		    {
			$$ = $1;
		    }
		    else
		    {
			yyerror("index is not inttype");
			$$ = NULL;
		    }
		}
;
expr
		: unary '=' expr {
		    if(!$1 || !$3)
		    {
			$$ = NULL;
		    }
		    else if(check_is_var_type($1))
		    {
			if(check_compatible($1->type, $3->type))
			{
			    $$ = $1;
			}
			else
			{
			    yyerror("LHS and RHS are not same type");
			    $$ = NULL;
			}
		    }
		    else
		    {
			yyerror("LHS is not variable");
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
		    if(!$1 || !$3)
		    {
			$$ = NULL;
		    }
		    else if(check_compatible_type($1->type, inttype) && check_compatible_type($3->type, inttype))
		    {
			$$ = $1;
		    }
		    else
		    {
			yyerror("not int type");
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
		    if(!$1 || !$3)
		    {
			$$ = NULL;
		    }
		    if(check_compatible_type($1->type, inttype) && check_compatible_type($3->type, inttype))
		    {
			$$ = $1;
		    }
		    else
		    {
			yyerror("not int type");
			$$ = NULL;
		    }
		}
		| binary
;
binary
		: binary RELOP binary {
		    if(!$1 || !$3)
		    {
			$$ = NULL;
		    }
		    else if(reloptype($1->type, $3->type))
		    {
			garbage_insert($$ = makeconstdecl(inttype));
		    }
		    else
		    {
			$$ = NULL;
		    }
		}
		| binary EQUOP binary {
		    if(!$1 || !$3)
		    {
			$$ = NULL;
		    }
		    else if(equoptype($1->type, $3->type))
		    {
			garbage_insert($$ = makeconstdecl(inttype));
		    }
		    else
		    {
			$$ = NULL;
		    }
		}
		| binary '+' binary {
		    if(!$1 || !$3)
		    {
			$$ = NULL;
		    }
		    else if(plustype($1->type, $3->type))
		    {
			$$ = $1;
		    }
		    else
		    {
			$$ = NULL;
		    }
		}
		| binary '-' binary {
		    if(!$1 || !$3)
		    {
			$$ = NULL;
		    }
		    else if(minustype($1->type, $3->type))
		    {
			$$ = $1;
		    }
		    else
		    { 
			$$ = NULL;
		    }
		}
		| unary %prec '=' {
		    if($1)
			$$ = $1;	//do not return decl->type
		    else 
			$$ = NULL;
		}
;
unary
		: '(' expr ')' {
		    if($2)  // it made by const decl!!
			$$ = deep_copy($2->type);
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
		    garbage_insert($$ = makenumconstdecl(inttype, $1));
		}
		| CHAR_CONST {
		    garbage_insert($$ = makecharconstdecl(chartype, $1));
		}
		| STRING {
		    garbage_insert($$ = makestringconstdecl(chartype, $1));
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
		    if($2 && check_compatible_type($2->type, inttype))
		    {
			$$ = $2;
		    }
		    else
		    {
			yyerror("not int type");
			$$ = NULL;
		    }
		}
		| '!' unary {
		    if($2 && check_compatible_type($2->type, inttype))
		    {
			$$ = $2;
		    }
		    else
		    {
			yyerror("not int type");
			$$ = NULL;
		    }
		}
		| unary INCOP {
		    if($1 && !INDECOPtype($1->type))
			$$ = NULL;
		    else
			$$ =$1;
		}
		| unary DECOP {
		    if($1 && !INDECOPtype($1->type))
			$$ = NULL;
		    else
			$$ = $1;
		}
		| INCOP unary {
		    if($2 && !INDECOPtype($2->type))
			$$ = NULL;
		    else
			$$ = $2;
		}
		| DECOP unary {
		    if($2 && !INDECOPtype($2->type))
			$$ = NULL;
		    else
			$$ = $2;
		}
		| '&' unary %prec '!' {
		    if(check_is_var_type($2))	//i must check this again! must deep copy
		    {	
			struct decl *temp;
			if(temp = deep_copy_pointer($2->type))
			{
			    garbage_insert($$ = makeconstdecl(temp));
			}
			else
			    $$ = NULL;
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
			struct decl *temp;
			if(temp = deep_copy_variable($2->type->ptrto))
			{
			    garbage_insert($$ = temp);
			}
			else
			    $$ = NULL;
		    }
		    else
		    {
			//error
			if($2 && !check_is_var_type($2))
			    yyerror("not variable");
			$$ = NULL;
		    }
		}
		| unary '[' expr ']' {
		    if(!$1 || !$3)
		    {
			$$ = NULL;
		    }
		    else if(check_is_const_type($1))
		    {
			$$ = arrayaccess($1, $3->type);
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
			if($1)
			    yyerror("not variable");
			$$ = NULL;
		    }
		}
		| unary '(' args ')'{
		    if(!$1 || !$3)
		    {
			$$ = NULL;
		    }
		    else if(check_is_proc($1))
		    {
			$$ = check_function_call($1, $3);
		    }
		    else
		    {	
			$$ = NULL;
		    }
		    
		    if($3)
		    {
			struct decl *temp = $3;
			while(temp)
			{
			    free(temp);
			    temp = temp->next;
			}
		    }	
		}
		| unary '(' ')' {
		    if($1 && check_is_proc($1))
		    {
			$$ = check_function_call($1, NULL);
		    }
		    else
		    {
			$$ = NULL;
		    }
		}
;
args    /* actual parameters(function arguments) transferred to function */
		: expr {
		    if($1)
		    {
			$$ = makevardecl($1->type);
			$$->next = NULL;
		    }
		    else
		    {
			$$ = NULL;
		    }
		}
		| expr ',' args {
		    if($1 && $3)
		    {
			$$ = makevardecl($1->type);
			$$->next = $3;
		    }
		    else
		    {
			$$ = NULL;
		    }
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
    SStack.TOP->garbage_top = NULL;
    StrStack = NULL;

    inttype = maketypedecl(Hash("int"));
    chartype = maketypedecl(Hash("char"));
    voidtype = maketypedecl(VOID);

    declare(enter(TYPE, "int", 3), inttype);
    declare(enter(TYPE, "char", 4), chartype);
    declare(enter(VOID, "void", 4), voidtype);
    returnid = enter(ID, "*return", 7);
}

struct ste *push_scope()	/* SStack.TOP에다가 새로히 ScopeNode를 만들고 연결 시킨다. */
{
    struct ScopeNode *temp = SStack.TOP;
    SStack.TOP = (struct ScopeNode*)malloc(sizeof(struct ScopeNode));
    SStack.TOP->prev = temp;
    SStack.TOP->top = temp->top;
    SStack.TOP->garbage_top = temp->garbage_top;
    return SStack.TOP->top;
}

struct decl *deep_copy(struct decl *declptr)
{
    struct decl *ftemp = declptr;
    if(ftemp)
    {
	 if(ftemp->typeclass == Hash("array"))
	{
	    if(ftemp->elementvar->type->typeclass == Hash("ptr"))
	    {
		return garbage_insert(makeconstdecl(makearraydecl(ftemp->intvalue, makevardecl(makeptrdecl(ftemp->elementvar->type->ptrto)))))->decl;
	    }
	    else
	    {
		return garbage_insert(makeconstdecl(makearraydecl(ftemp->intvalue, makevardecl(ftemp->elementvar->type))))->decl;
	    }
	}
	else if(ftemp->typeclass == Hash("ptr"))
	{
	    return garbage_insert(makeconstdecl(makeptrdecl(ftemp->ptrto)))->decl;
	}
	else
	{
	    return garbage_insert(makeconstdecl(ftemp))->decl;
	}	
    }
    return NULL;
}

struct decl *deep_copy_pointer(struct decl *declptr)
{
    struct decl *ftemp = declptr;
    if(ftemp)
    {
	 if(ftemp->typeclass == Hash("array"))
	{
	   /* if(ftemp->elementvar->type->typeclass == Hash("ptr"))
	    {
		return makeptrdecl(makearraydecl(ftemp->intvalue, makevardecl(makeptrdecl(ftemp->elementvar->type->ptrto))));
	    }
	    else
	    {
		return makeptrdecl(makearraydecl(ftemp->intvalue, makevardecl(ftemp->elementvar->type)));
	    }*/
	    yyerror("not & operator type");
	    return NULL;
	}
	else if(ftemp->typeclass == Hash("ptr"))
	{
	   // return makeptrdecl(makeptrdecl(ftemp->ptrto));
	    yyerror("not & operator type");
	    return NULL;
	}
	else
	{
	    return makeptrdecl(ftemp);
	}	
    }
    return NULL;
}

struct decl *deep_copy_variable(struct decl *declptr)
{
    struct decl *ftemp = declptr;
    if(ftemp)
    {
	 if(ftemp->typeclass == Hash("array"))
	{
	   /* if(ftemp->elementvar->type->typeclass == Hash("ptr"))
	    {
		return makevardecl(makearraydecl(ftemp->intvalue, makevardecl(makeptrdecl(ftemp->elementvar->type->ptrto))));
	    }
	    else
	    {
		return makevardecl(makearraydecl(ftemp->intvalue, makevardecl(ftemp->elementvar->type)));
	    }*/
	yyerror("not * operator type");
	return NULL;
	}
	else if(ftemp->typeclass == Hash("ptr"))
	{
	   // return makevardecl(makeptrdecl(ftemp->ptrto));
	    yyerror("not * operator type");
	    return NULL;
	}
	else
	{
	    return makevardecl(ftemp);
	}	
    }
    return NULL;
}


struct ste *push_ste_list(struct ste *formals)	//완벽한 deep copy를 해준다.
{
    struct ste *ftemp = formals;
    while(ftemp)
    {
	if(ftemp->decl->declclass == TYPE)  //returnid의 경우 decl이 바로 TYPE을 가리키므로 ftemp->decl을 바로 사용한다.
	{
	    if(ftemp->decl->typeclass == Hash("ptr"))
	    {
		declare(ftemp->name, makeptrdecl(ftemp->decl->ptrto));
	    }
	    else
	    {
		declare(ftemp->name, ftemp->decl);
	    }
	}
	else if(ftemp->decl->type->typeclass == Hash("array")) //array의 경우 pointer array일 경우와 그 외의 경우로 나눠서 deepcopy한다.
	{
	    if(ftemp->decl->type->elementvar->type->typeclass == Hash("ptr"))
	    {
		declare(ftemp->name, makeconstdecl(makearraydecl(ftemp->decl->type->intvalue, makevardecl(makeptrdecl(ftemp->decl->type->elementvar->type->ptrto)))));
	    }
	    else
	    {
		declare(ftemp->name, makeconstdecl(makearraydecl(ftemp->decl->type->intvalue, makevardecl(ftemp->decl->type->elementvar->type))));
	    }
	}
	else if(ftemp->decl->type->typeclass == Hash("ptr")) //pointer의 경우 ptrto를 사용해서 deepcopy한다.
	{
	    declare(ftemp->name, makevardecl(makeptrdecl(ftemp->decl->type->ptrto)));
	}
	else	//그 외의 경우 그냥 decl->type을 사용해서 deepcopy한다.
	{
	    declare(ftemp->name, makevardecl(ftemp->decl->type));
	}
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
	free(SStack.TOP);
	SStack.TOP = SStack.TOP->prev;
	return NULL;
    }

    while(temp != temp3)
    {
	struct ste *headtemp = Head;
	struct ste *stacktemp = temp->prev;
	Head = temp;
	Head->prev = headtemp;
	temp = stacktemp;
    }
    
    struct ste *garbage_temp = SStack.TOP->garbage_top;
    struct ste *garbage_temp3 = SStack.TOP->prev->garbage_top;
    while(garbage_temp != garbage_temp3)
    {
	free_ste(garbage_temp);
	garbage_temp = garbage_temp->prev;
    }
    
    free(SStack.TOP);
    SStack.TOP = SStack.TOP->prev;      /* SStack.TOP의 scope를 한단계 낮춘다. */

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
	free_ste(temp);
	temp = temp->prev;
    }

    struct ste *garbage_temp = SStack.TOP->garbage_top;
    struct ste *garbage_temp3 = SStack.TOP->prev->garbage_top;
    while(garbage_temp != garbage_temp3)
    {
	free_ste(garbage_temp);
	garbage_temp = garbage_temp->prev;
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
	free_ste(temp);
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

struct ste *garbage_insert( struct decl *declptr)
{
    struct ste *STE = (struct ste*)malloc(sizeof(struct ste));
    STE->decl = declptr;
    STE->prev = SStack.TOP->garbage_top;
    STE->name = NULL;
    SStack.TOP->garbage_top = STE;

    return SStack.TOP->garbage_top;
}

struct ste *free_ste(struct ste *steptr)
{
    free_decl(steptr->decl);	//ste를 해제하고 그 decl도 해제한다.
    free(steptr);
    steptr->decl = NULL;
    steptr->name = NULL;
    return NULL;
}

//when decl free make all pointer and value 0
struct decl *free_decl(struct decl *declptr)
{
    if(declptr->type)
    {
	if(declptr->type->typeclass == Hash("array"))
	{
	    if(declptr->type->elementvar->type->typeclass == Hash("ptr"))
	    {
		declptr->type->elementvar->type->ptrto = NULL;
		declptr->type->elementvar->type->typeclass = 0;
		declptr->type->elementvar->type->declclass = 0;
		free(declptr->type->elementvar->type);
		declptr->type->elementvar->typeclass = 0;
		declptr->type->elementvar->declclass = 0;
		declptr->type->elementvar->type = NULL;
		free(declptr->type->elementvar);
		declptr->type->typeclass = 0;
		declptr->type->declclass = 0;
		declptr->type->elementvar = NULL;
		free(declptr->type);
		declptr->typeclass = 0;
		declptr->declclass = 0;
		declptr->type = NULL;
		free(declptr);
	    }
	    else
	    {
		declptr->type->elementvar->typeclass = 0;
		declptr->type->elementvar->declclass = 0;
		declptr->type->elementvar->type = NULL;
		free(declptr->type->elementvar);
		declptr->type->typeclass = 0;
		declptr->type->declclass = 0;
		declptr->type->elementvar = NULL;
		free(declptr->type);
		declptr->typeclass = 0;
		declptr->declclass = 0;
		declptr->type = NULL;
		free(declptr);
	    }
	}
	else if(declptr->type->typeclass == Hash("ptr"))
	{
	    declptr->type->typeclass = 0;
	    declptr->type->declclass = 0;
	    declptr->type->ptrto = NULL;
	    free(declptr->type);
	    declptr->typeclass = 0;
	    declptr->declclass = 0;
	    declptr->type = NULL;
	    free(declptr);
	}
	else
	{
	    declptr->typeclass = 0;
	    declptr->declclass = 0;
	    declptr->type = NULL;
	    free(declptr);
	}
    }
    else if(declptr->ptrto)
    {
	declptr->typeclass = 0;
	declptr->declclass = 0;
	declptr->ptrto = NULL;
	free(declptr);
    }
    return NULL;
}

struct ste *sdestroy()
{
    while(SStack.TOP->top)
    {
	if(SStack.TOP->top->decl->declclass == Hash("FUNC"))
	{
	    free_ste(SStack.TOP->top->decl->formals);
	    free(SStack.TOP->top->decl);
	}
	if(SStack.TOP->top->decl->declclass == TYPE)
	    free(SStack.TOP->top->decl);
	free_ste(SStack.TOP->top);
	SStack.TOP->top = SStack.TOP->top->prev;
    }

    while(SStack.TOP->garbage_top)
    {
	free_ste(SStack.TOP->garbage_top);
	SStack.TOP->garbage_top = SStack.TOP->garbage_top->prev;
    }

    while(SStack.TOP)
    {
	free(SStack.TOP);
	SStack.TOP = SStack.TOP->prev;
    }

    while(StrStack)
    {
	if(StrStack->decl->fieldlist)
	    free_ste(StrStack->decl->fieldlist);
	free(StrStack->decl);
	free(StrStack);
	StrStack = StrStack->prev;
    }

    return NULL;
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






struct decl *finddecl(id *entry)    /* entry에 해당하는 name을 가진 ste가 있는지 찾는다.*/
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
//	yyerror("type is not suitable for plus operaton");
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
    else
    {
	yyerror("type is not suitable for plus operaton");
	return NULL;
    }
}

struct decl *minustype(struct decl *type1, struct decl *type2)
{
    if(type1 == NULL || type2 == NULL)
    {
//	yyerror("type is not suitable for minus operaton");
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
    else
    {
	yyerror("type is not suitable for minus operaton");
	return NULL;
    }
}

struct decl *reloptype(struct decl *type1, struct decl *type2)
{
    if(check_compatible_type(type1, type2))
    {
	if(type1->typeclass == Hash("struct") || type1->typeclass == Hash("array"))
	{
	    yyerror("type is not suitable for relop operaton");
	    return NULL;
	}
	else
	{
	    return inttype;
	}
    }
    else
    {
	yyerror("type is not suitable for relop operaton");
	return NULL;
    }
}
    
struct decl *equoptype(struct decl *type1, struct decl *type2)
{
    if(check_compatible_type(type1, type2))
    {
	if(type1->typeclass == Hash("struct") || type1->typeclass == Hash("array"))
	{
	    yyerror("type is not suitable for equop operaton");
	    return NULL;
	}
	else
	{
	    return inttype;
	}
    }
    else
    {
	yyerror("type is not suitable for equop operaton");
	return NULL;
    }
}

struct decl *INDECOPtype(struct decl *type)
{
    if(type == inttype || type == chartype)
    {
	return type;
    }
    else if(type == NULL)
    {
	return NULL;
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
	else if(formals->decl->type->typeclass == Hash("array") && actuals->type->typeclass == Hash("array"))
	{
	    if(check_compatible(formals->decl->type->elementvar->type, actuals->type->elementvar->type))
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

    return deep_copy(procptr->returntype);  /* for decl of the call */
}

struct decl *check_function_declare(struct decl *procptr, struct decl *procptr2)
{
    struct ste *formals = procptr->formals;
    struct ste *actuals = procptr2->formals;
    /* 1. compare number of formals and actuals */

    /* 2. check for type match			*/
    while(formals != NULL && actuals != NULL)
    {
	if(check_is_var_type(formals->decl))
	{
	    if(check_compatible(formals->decl->type, actuals->decl->type))
	    {
		if(formals->decl->type->typeclass == Hash("ptr") && actuals->decl->type->typeclass == Hash("array"))
		    break; 
		else
		{
		    formals = formals->prev;
		    actuals = actuals->prev;
		}
	    }
	    else
		break;
	}
	else if(formals->name == returnid)
	{
	    if(formals->decl == actuals->decl)
	    {
		formals = formals->prev;
		actuals = actuals->prev;
	    }
	    else if(formals->decl->typeclass == Hash("ptr") && formals->decl->ptrto == actuals->decl->ptrto)
	    {
		formals = formals->prev;
		actuals = actuals->prev;
	    }
	    else
		break;
	}
	else if(formals->decl->type->typeclass == Hash("array") && actuals->decl->type->typeclass == Hash("array"))
	{
	    if(check_compatible(formals->decl->type->elementvar->type, actuals->decl->type->elementvar->type))
	    {
		formals = formals->prev;
		actuals = actuals->prev;
	    }
	    else
		break;
	}
	else
	    break;
    }
    if(formals || actuals)
    {
	return NULL;
    }

    return (procptr->returntype);  /* for decl of the call */
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

struct decl *check_is_declared_for_else(struct id *entry) //variable을 선언하기 위해 동일한 entry를 name으로 가지는 ste가 있는지 찾는 함수 이다. struct scope와 현재 scope만 뒤진다. 
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
		    return inttype; //한번 정의 된적 있다는 신호이다.
		}
	    }
	    yyerror("redeclaration");
	    return temp->decl;
	}
	temp = temp->prev;
    }
    /*
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
    */
    return NULL; 
}

struct decl *check_is_declared_for_struct(struct id *entry) //struct를 선언하기 위해 동일한 entry를 name으로 가지는 ste가 있는지 찾는 함수 이다. 전체 scope를 다 뒤진다. 
{
    /*
    struct ste *temp = SStack.TOP->top;
    while(temp)
    {
	if(temp->name == entry)
	{
	    yyerror("redeclaration");
	    return temp->decl;
	}
	temp = temp->prev;
    }*/
    
    struct ste *temp = StrStack;
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
	if(top->name)
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
	REDUCE("look the type decl");
	tellmetype(temp->type);
    }
    if(temp->returntype)
    {
	REDUCE("look the returntype decl");
	tellmetype(temp->returntype);
    }
    if(temp->elementvar)
    {
	REDUCE("look the elmentvar decl");
	tellmetype(temp->elementvar);
    }
    if(temp->ptrto)
    {
	REDUCE("look the ptrto decl");
	tellmetype(temp->ptrto);
    }
    if(temp->fieldlist)
    {
	REDUCE("look the fieldlist");
	printStack(temp->fieldlist);
    }
    if(temp->formals)
    {
	REDUCE("look the formals");
	printStack(temp->formals);
    }
    
}

struct ste *pushStr(struct id *entry, struct decl *declptr) //struct stack의 push 함수
{
    struct ste *temp = StrStack;
    StrStack = (struct ste*)malloc(sizeof(struct ste));
    StrStack->name = entry;
    StrStack->decl = declptr;
    StrStack->prev = temp;
    return StrStack;
}
