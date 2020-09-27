/**
 * \file list.h
 * \author Anthony BERTRAND
 * \brief header for list algorithm
 * \version 0.1
 * \date 27/09/20
 **/

#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//----------------------------struct list------------------------------------

typedef struct link
{
    int v;
    struct link *next;
} Link, *List;

typedef enum{false, true}Booleen;

//-----------------------------fct liste----------------------------------------
List insert_head(List l, int x);
List insert(List l, int x);
List remove_head(List l);
List remove_l(List l, int x);
int nbElt(List l);
Booleen empty(List l);
int head(List l);
Booleen appartient(List l, int x);
List copie(List l);
void display_list(List l);

#endif
