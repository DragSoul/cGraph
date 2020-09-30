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

Link_g* create_link_g(int x);
Graph add_link_head(Graph g, int x);
Graph add_link(Graph g, int x);
Graph add_vectice(Graph g, int x, int y);
Graph sup_vectice(Graph g, int x, int y);
Graph sup_head(Graph g);
Graph sups(Graph g, int x);
//Booleen esg(Graph g, int x);
Booleen is_vectice(Graph g, int x, int y);
Booleen emptyg(Graph g);
Booleen is_edge(Graph g, int x);
List list_vectice(Graph g, int x);
int n_vect_in(Graph g, int x);
int n_vect_out(Graph g, int x);
void export_graph(Graph g);
void global(void);

#endif