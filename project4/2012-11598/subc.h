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
    struct ste *garbage_top;	//garbage ste
    struct ScopeNode *prev;
    int	   offset;		//scope offset
    int	   str_offset; 
}ScopeNode;

struct ScopeStack{
    struct ScopeNode *TOP;
}ScopeStack;


struct Property{
    int fetch;
    int offset;
    int size;
}Property;



struct ste *push_scope();
struct decl *deep_copy(struct decl *declptr);
struct decl *deep_copy_pointer(struct decl *declptr);
struct decl *deep_copy_variable(struct decl *declptr);
struct ste *push_ste_list(struct ste *formals);
struct ste *pop_scope();
struct ste *free_scope();
struct ste *free_ste_list(struct ste *steptr);
struct ste *insert(id *entry, struct decl *declptr);
struct ste *garbage_insert( struct decl *declptr);   //중간중간 생기는 garbage들을 모으는 함수
struct ste *free_ste(struct ste *steptr);
struct decl *free_decl(struct decl *declptr);
struct ste *sdestroy();

struct decl{
    int		    declclass;  /* DECL Class: VAR, CONST, FUNC, TYPE	*/
    struct decl	    *type;  	/* VAR, CONST: pointer to its type decl	*/
    int		    intvalue;	/* CONST: value of integer const	*/
    char	    *charvalue; /* CONST: value of char const		*/
    const char	    *stringvalue;/*CONST: value of string const		*/
//    float	    real_value;	/* CONST: value of float const		*/
    struct ste	    *formals;	/* FUNC: ptr to formals list		*/
    struct decl	    *returntype;/* FUNC: ptr to return TYPE decl	*/
    int		    isdeclared;	/* FUNC: isdeclared			*/
    int		    typeclass;	/* TYPE: type class: int, array, ptr	*/
    struct decl	    *elementvar;/* TYPE(array): ptr to element VAR decl	*/
    int		    num_index;	/* TYPE(array): number of elements	*/
    struct ste	    *fieldlist;	/* TYPE(struct): ptr to field list	*/
    struct decl	    *ptrto;	/* TYPE(pointer): type of the pointer	*/
    int		    size;	/* ALL: size in bytes			*/
//    struct ste	    **scope;	/* VAR: scope when VAR delcared		*/
    struct decl	    *next;	/* For list_of_variables declarations	*/

    //project4
    int		    fetch;
    int		    offset;
    int		    str_offset;
    struct ScopeNode *scope;   /* scope: when VAR declared	    */
}decl;				/* Or parameter check of function call	*/
/* For hash table */

id* enter(int lextype, char *name, int length);
int read_line();
void init_type();

struct ste   *declare(id* entry, struct decl *declptr);

struct decl  *maketypedecl(int lextype);
struct decl  *makevardecl(struct decl *typeptr);
struct decl  *makeptrdecl(struct decl *typeptr);
struct decl  *makearraydecl(int numidx, struct decl *varptr);
struct decl  *makestructdecl(struct ste *fieldptr);
struct decl  *makeconstdecl(struct decl *typeptr);
struct decl  *makenumconstdecl(struct decl *typeptr, int intconst);
struct decl  *makecharconstdecl(struct decl *typetpr, char *charconst);
struct decl  *makestringconstdecl(struct decl *typeptr, const char *stringconst); 
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
struct decl  *INDECOPtype(struct decl *type);



struct decl *check_is_var_type(struct decl *declptr);  //내가 var인지 체크
struct decl *check_is_const_type(struct decl *declptr);
struct decl *check_compatible(struct decl *declptr1, struct decl *declptr2);
struct decl *check_compatible_type(struct decl *declptr1, struct decl *declptr2);
struct decl *check_is_struct_type(struct decl *structptr);  //나의 typedecl이 맞는지 체크
struct decl *check_is_array_type(struct decl *arrayptr);
struct decl *check_is_ptr_type(struct decl *ptrptr);
struct decl *check_is_type(struct decl *declptr);
struct decl *check_function_call(struct decl *procptr, struct decl *actuals);
struct decl *check_function_declare(struct decl *procptr, struct decl *proptr2);
struct decl *check_is_proc(struct decl *procptr);
struct decl *check_is_declared_for_else(struct id *entry);  //entry를 가진 ste가 현재 stack scope에 있는지 확인 한다. Declare 할 때 필요하다.
struct decl *check_is_declared_for_struct(struct id *entry);	//entry를 가진 ste가 전체 struct scope에 있는지 확인 한다. Struct를 Declare 할 때 필요하다.


struct ScopeStack SStack;
struct ScopeNode *Global_Scope;
struct ste *StrStack;
struct decl *inttype;
struct decl *chartype;
struct decl *voidtype;
struct id* returnid;
char *filename;
FILE *file_out;

unsigned int Hash(const char *key);	//VAR ptr array struct CONST FUNC
void printStack(struct ste *top);
void tellmetype(struct decl *declptr);
struct ste *pushStr(struct id *entry, struct decl *declptr);	//StrStack에 push한다.



//project4
void Write_Instruction(char* instruction);
void Write_Label(char* instruction);
void Write_Else(char* instruction);

int  get_field_size(struct ste *steptr);
struct ste *find_func(struct decl *delcptr);
struct ste *find_func_closest();
int in_func;
int in_struct;
int label_no;
int string_no;
int loop_out_no;
int loop_continue_no;
int if_label_no;

#endif
