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

//---------------------------struct graphe-------------------------------------

typedef struct link_g
{
	int v;
	List l;
	struct link_g *next;
}Link_g, *Graph;

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
