/**
 * \file graph.h
 * \author Anthony BERTRAND
 * \brief header for graph algorithm
 * \version 0.1
 * \date 27/09/20
 **/

#ifndef GRAPH_H
#define GRAPH_H

#include "list.h"

//---------------------------struct graphe-------------------------------------

typedef struct link_g
{
	int v;
	List l;
	struct link_g *next;
}Link_g, *Graph;



//------------------------------fct graphe----------------------------------------

Graph adjst(Graph g, int x);
Graph adjs(Graph g, int x);
Graph adja(Graph g, int x, int y);
Graph supa(Graph g, int x, int y);
Graph supst(Graph g);
Graph sups(Graph g, int x);
//Booleen esg(Graph g, int x);
Booleen exa(Graph g, int x, int y);
Booleen emptyg(Graph g);
Booleen exs(Graph g, int x);
List esucc(Graph g, int x);
int de(Graph g, int x);
int di(Graph g, int x);
void export_graph(Graph g);
void global(void);

#endif