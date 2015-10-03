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

/* For hash table */

id* enter(int lextype, char *name, int length);

int read_line();

#endif

