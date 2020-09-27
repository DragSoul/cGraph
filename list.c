/**
 * \file list.c
 * \author Anthony BERTRAND
 * \brief contain algorithm for list definition
 * \version 0.1
 * \date 27/09/20
 **/


#include "list.h"

/* --------------------------------------------------------------------------*/
/*  int head(List l)                                                         */
/** return the value of the first link in the list
 *
 * @param  l list
 * @return value of the head of the list
 **/
/*---------------------------------------------------------------------------*/
int head(List l)
{
	if(l == NULL){printf("opération interdite\n"); exit(1);}
	return l->v;
}


/* ---------------------------------------------------------- */
/*                            empty                           */

/*                                     						  */

/* in : l : List 											  */

/* out : value of the head of the list			              */
/* -----------------------------------------------------------*/
Booleen empty(List l)
{
	if(l == NULL)
		return true;
	return false;
}

List insert_head(List l, int x)
{
	Link *m;
	m = (Link*)malloc(sizeof(Link));
	if (m == NULL)
	{
		printf("pb malloc\n");
		exit(1);
	}
	m->v = x;
	m->next = l;
	return m;
}

List insert(List l, int x)
{
	if(empty(l) == true)
		return insert_head(l,x);
	if(x < head(l))
		return insert_head(l,x);
	if(x == head(l))
		return l;
	l->next = insert(l->next, x);
	return l;
}

List remove_head(List l)
{
	Link *m;
	if(empty(l) == true)
	{
		printf("opération interdite\n");
		exit(1);
	}
	m = l;
	l = l->next;
	free(m);
	return l;
}

List remove_l(List l, int x)
{
	if(empty(l) == true)
		return l;
	if(x < head(l))
		return l;
	if(x == head(l))
		return remove_head(l);
	l->next = remove_l(l->next, x);
	return l;
}

int nbElt(List l)
{
	int cpt = 0;
	while(l != NULL)
	{
		cpt = cpt + 1;
		l = l->next;
	}
	return cpt;
}

Booleen appartient(List l, int x)
{
	if(l == NULL)
		return false;
	if(l->v == x)
		return true;
	return appartient(l->next, x);
}


List copie(List l)
{
	List l1;
	l1 = NULL;
	Link *m;
	m = (Link*)malloc(sizeof(Link));
	if (m == NULL)
	{
		printf("pb malloc copie\n");
		exit(1);
	}

	m->v = l->v;
	l1 = m;
	List aux = l1;
	l = l->next;
	while(!empty(l))
	{
		Link *m;
		m = (Link*)malloc(sizeof(Link));
		if (m == NULL)
		{
			printf("pb malloc copie\n");
			exit(1);
		}
		m->v = l->v;
		aux->next = m;
		aux = aux->next;
		l = l->next;
	}
	return l1;
}

void display_list(List l)
{
	while(l != NULL)
	{
		printf("%d ", l->v);
		l = l->next;
	}
}