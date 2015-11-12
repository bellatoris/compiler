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

struct decl{
    int		    declclass;  /* DECL Class: VAR, CONST, FUNC, TYPE	*/
    struct decl	    *type;  	/* VAR, CONST: pointer to its type decl	*/
    int		    value;	/* CONST: value of integer const	*/
    float	    real_value;	/* CONST: value of float const		*/
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

#endif

