/**
 * \file graph.c
 * \author Anthony BERTRAND
 * \brief contain algorithm for graph definition
 * \version 0.1
 * \date 27/09/20
 **/


#include "graph.h"

//ajoute un link en tete de graph
Graph add_link_head(Graph g, int x)
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

//ajoute le link en fonction de la valeur du sommet (ordre croissant)
Graph add_link(Graph g, int x)
{
	if (emptyg(g))
		return add_link_head(g, x);
	if(x < g->v)
		return add_link_head(g, x);
	if(x == g->v)
		return g;
	g->next = add_link(g->next, x);
	return g;
}

//ajoute l'arrete x->y (x et y doivent tous les 2 exister au préalable)
Graph add_vectice(Graph g, int x, int y)
{
	Graph aux;
	if (!is_edge(g, x) || !is_edge(g, y))
		return g;
	aux = g;
	while(aux->v != x)
		aux = aux->next;
	aux->l = insert(aux->l, y);
	return g;
}

//supprime l'arrete x->y
Graph sup_vectice(Graph g, int x, int y)
{
	Link_g *m;
	if(!is_vectice(g, x, y))
		return g;
	m = g;
	while(m->v != x)
		m = m->next;
	m->l = remove_l(m->l, y);
	return g;
}

//supprime le 1er link du graphe
Graph sup_head(Graph g)
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

//supprime le sommet x ainsi que toutes les arretes entrantes/sortantes
//(je crois, à verifier. Notamment le 2e if...)
//veut le transformer en une fct qui fait ce que je dis plus haut
Graph sups(Graph g, int x)
{
	if(!is_edge(g, x)) return g;
	if(n_vect_out(g, x) == 0 && n_vect_in(g, x) == 0) return g;
	if(x == g->v) return sup_head(g);

	if(is_vectice(g, g->v, x)) return sup_vectice(g, g->v, x);
	g->next = sups(g->next, x);
	return g;
}

//return true si le sommet existe
Booleen is_edge(Graph g, int x)
{
	if(emptyg(g))
		return false;
	if(x < g->v)
		return false;
	if(x == g->v)
		return true;
	return is_edge(g->next, x);
}


//return true si l'arrete x->y existe
Booleen is_vectice(Graph g, int x, int y)
{
	if(!is_edge(g, x) || !is_edge(g, y))
		return false;
	while(g->v != x)
		g = g->next;
	return appartient(g->l, y);
}

//return true si le graphe g est vide
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

//renvoie la liste des arretes partant de x
List list_vectice(Graph g, int x)
{
	if(!is_edge(g, x))
	{
		printf("ce sommet n'existe pas\n");
		return NULL;
	}
	while(g->v != x)
		g = g->next;
	return g->l;
}

//return le nombre d'arretes partant de x
int n_vect_in(Graph g, int x)
{
	if(!is_edge(g, x))
		return 0;
	while(g->v != x)
		g = g->next;
	return nbElt(g->l);
}

//return le nombre d'arretes entrant dans x
int n_vect_out(Graph g, int x)
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

//
void export_graph(Graph g)
{
	int y;
	FILE *flot;
	Graph aux;
	aux = g;
	List l1;
	flot = fopen("bin/graphe.dot", "w");
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
	system("dot -Tpng bin/graphe.dot -o bin/graphe.png");
}

void global(void)
{
	Graph g = NULL;
	g = add_link(g, 5);
	g = add_link(g, 8);
	g = add_link(g, 25);
	g = add_vectice(g, 5, 8);
	g = add_vectice(g, 5, 25);
	g = add_vectice(g, 8, 5);
	g = add_vectice(g, 25, 5);
	g = sups(g, 5);
	export_graph(g);
}