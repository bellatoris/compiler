/******************************************************
 * File Name   : subc.h
 * Description
 *    This is a header file for the subc program.
 ******************************************************/

#ifndef __SUBC_H__
#define __SUBC_H__

#include <stdio.h>
#include <string.h>
#include <search.h>
#include <stdlib.h>

/* structure for ID */
typedef struct id {
      char *name;
      int lextype;
}id;

struct ste{
    struct id	*name;
    struct decl	*decl;
    struct ste	*prev;
}ste;

struct ScopeNode{
    struct ste *top;
    struct ScopeNode *prev;
}ScopeNode;

struct ScopeStack{
    struct ScopeNode *TOP;
}ScopeStack;

struct ste *push_scope();
struct ste *push_ste_list(struct ste *formals);
struct ste *pop_scope();
struct ste *insert(id *entry, struct decl *declptr);
void lookup();

struct decl{
    int		    declclass;  /* DECL Class: VAR, CONST, FUNC, TYPE	*/
    struct decl	    *type;  	/* VAR, CONST: pointer to its type decl	*/
    int		    value;	/* CONST: value of integer const	*/
//    float	    real_value;	/* CONST: value of float const		*/
    struct ste	    *formals;	/* FUNC: ptr to formals list		*/
    struct decl	    *returntype;/* FUNC: ptr to return TYPE decl	*/
    int		    typeclass;	/* TYPE: type class: int, array, ptr	*/
    struct decl	    *elementvar;/* TYPE(array): ptr to element VAR decl	*/
    int		    num_index;	/* TYPE(array): number of elements	*/
    struct ste	    *fieldlist;	/* TYPE(struct): ptr to field list	*/
    struct decl	    *ptrto;	/* TYPE(pointer): type of the pointer	*/
    int		    size;	/* ALL: size in bytes			*/
    struct ste	    **scope;	/* VAR: scope when VAR delcared		*/
    struct decl	    *next;	/* For list_of_variables declarations	*/
}decl;				/* Or parameter check of function call	*/
/* For hash table */

id* enter(int lextype, char *name, int length);
int read_line();

struct ste   *declare(id* entry, struct decl *declptr);

struct decl  *maketypedecl(int lextype);
struct decl  *makevardecl(struct decl *typeptr);
struct decl  *makeptrdecl(struct decl *typeptr);
struct decl  *makearraydecl(int numidx, struct decl *varptr);
struct decl  *makestructdecl(struct ste *fieldptr);
struct decl  *makeconstdecl(struct decl *typeptr);
struct decl  *makenumconstdecl(struct decl *typeptr, int intconst);
struct decl  *makeprocdecl();


struct decl  *finddecl(struct id* entry);   // entry를 가진 ste가 전체 stack scope에 있는지 확인 한다.해당하는 id가 존재하는지 확인 하려는 목적이다.
struct decl  *findstructdecl(struct id* entry);	// entry를 가진 ste가 struct scope에 있는지 확인 한다. 해당하는 struct가 존재하는지 확인 하려는 목적이다.
struct decl  *findcurrentdecl(struct id *fieldid, struct ste *fieldlist);


struct decl  *structaccess(struct decl *structptr, struct id *fieldid);
struct decl  *structPtraccess(struct decl *structptr, struct id *fiedlid);
struct decl  *arrayaccess(struct decl *arrayptr, struct decl *indexptr);


struct decl  *plustype(struct decl *type1, struct decl *type2);
struct decl  *minustype(struct decl *type1, struct decl *type2);
struct decl  *reloptype(struct decl *type1, struct decl *type2);
struct decl  *equoptype(struct decl *type1, struct decl *type2);


struct decl *check_is_var_type(struct decl *declptr);
struct decl *check_compatible(struct decl *declptr1, struct decl *declptr2);
struct decl *check_compatible_type(struct decl *type1, struct decl *type2);
struct decl *check_is_struct_type(struct decl *structptr);
struct decl *check_is_array_type(struct decl *arrayptr);
struct decl *check_same_type(struct decl *declptr1, struct decl *declptr2);
struct decl *check_is_type(struct decl *declptr);
struct decl *check_function_call(struct decl *procptr, struct decl *actuals);
struct decl *check_is_proc(struct decl *procptr);
struct decl *check_is_declared_for_else(struct id *entry);  //entry를 가진 ste가 현재 stack scope에 있는지 확인 한다. Declare 할 때 필요하다.
struct decl *check_is_declared_for_struct(struct id *entry);	//entry를 가진 ste가 전체 struct scope에 있는지 확인 한다. Struct를 Declare 할 때 필요하다.

void add_type_to_var(struct decl *declptr1, struct decl *declptr2);

struct ScopeStack SStack;
struct ste *StrStack;
struct decl *inttype;
struct decl *chartype;
struct decl *voidtype;
struct id* returnid;

unsigned int Hash(const char *key);
void printStack(struct ste *top);
void tellmetype(struct decl *declptr);
struct ste *pushStr(struct id *entry, struct decl *declptr);	//StrStack에 push한다.
#endif

