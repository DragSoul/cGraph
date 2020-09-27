/**
 * \file graph.c
 * \author Anthony BERTRAND
 * \brief contain algorithm for graph definition
 * \version 0.1
 * \date 27/09/20
 **/


#include "graph.h"


Graph adjst(Graph g, int x)
{
	Link_g *m;
	m = (Link_g*)malloc(sizeof(Link_g));
	if (m == NULL)
	{
		printf("pb malloc\n");
		exit(1);
	}
	m->v = x;
	m->l = NULL;
	m->next = g;
	return m;
}

Graph adjs(Graph g, int x)
{
	if (emptyg(g))
		return adjst(g, x);
	if(x < g->v)
		return adjst(g, x);
	if(x == g->v)
		return g;
	g->next = adjs(g->next, x);
	return g;
}

Graph adja(Graph g, int x, int y)
{
	Graph aux;
	if (!exs(g, x) || !exs(g, y))
		return g;
	aux = g;
	while(aux->v != x)
		aux = aux->next;
	aux->l = insert(aux->l, y);
	return g;
}

Graph supa(Graph g, int x, int y)
{
	Link_g *m;
	if(!exa(g, x, y))
		return g;
	m = g;
	while(m->v != x)
		m = m->next;
	m->l = remove_l(m->l, y);
	return g;
}

Graph supst(Graph g)
{
	Link_g *m;
	if (emptyg(g))
	{
		printf("le graphe est déjà empty\n");
		exit(1);
 	}
 	m = g;
 	g = g->next;
 	free(m);
 	return g;
}

Graph sups(Graph g, int x)
{
	if(!exs(g, x)) return g;
	if(di(g, x) != 0 || de(g, x) != 0) return g;
	if(x == g->v) return supst(g);
	g->next = sups(g->next, x);
	return g;
}

Booleen exs(Graph g, int x)
{
	if(emptyg(g))
		return false;
	if(x < g->v)
		return false;
	if(x == g->v)
		return true;
	return exs(g->next, x);
}

Booleen exa(Graph g, int x, int y)
{
	if(!exs(g, x) || exs(g, y))
		return false;
	while(g->v != x)
		g = g->next;
	return appartient(g->l, x);
}

Booleen emptyg(Graph g)
{
	if(g == NULL)
		return true;
	return false;
}
//------------------------------------------------------pb-----------------------------
/*Booleen esg(Graph g, int x)
{
	return appartient(esg(g, x), x);
}*/

List esucc(Graph g, int x)
{
	if(!exs(g, x))
	{
		printf("ce sommet n'existe pas\n");
		return NULL;
	}
	while(g->v != x)
		g = g->next;
	return g->l;
}

int de(Graph g, int x)
{
	if(!exs(g, x))
		return 0;
	while(g->v != x)
		g = g->next;
	return nbElt(g->l);
}

int di(Graph g, int x)
{
	int cpt = 0;
	while(!emptyg(g))
	{
		if(appartient(g->l, x))
			cpt++;
		g = g->next;
	}
	return cpt;
}

void export_graph(Graph g)
{
	int y;
	FILE *flot;
	Graph aux;
	aux = g;
	List l1;
	flot = fopen("graphe.dot", "w");
	if (flot == NULL)
	{
		printf("pb ouverture fichier\n");
		exit(1);
	}
	fprintf(flot, "digraph family\n{\n");
	while(!emptyg(g))
	{
		fprintf(flot, "%d[label=\"%d\"]\n", g->v, g->v);
		g = g->next;
	}
	while(!emptyg(aux))
	{
		if(!empty(aux->l))
			l1 = copie(aux->l);
		while(!empty(l1))
		{
			y = head(l1);
			l1 = remove_head(l1);
			fprintf(flot, "%d->%d\n", aux->v, y);
		}
		aux = aux->next;
	}
	fprintf(flot, "}\n");
	fclose(flot);
	system("dot -Tpng graphe.dot -o graphe.png");
}

void global(void)
{
	Graph g = NULL;
	g = adjs(g, 5);
	g = adjs(g, 8);
	g = adjs(g, 25);
	g = adja(g, 5, 8);
	g = adja(g, 5, 25);
	g = adja(g, 8, 5);
	g = adja(g, 25, 5);
	export_graph(g);
}