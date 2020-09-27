#include "graphe.h"

//-------------------------------------------fct list---------------------------------


/* ---------------------------------------------------------- */
/*                             head                           */

/*                                     						  */

/* in : l : List 											  */

/* out : value of the head of the list			              */
/* -----------------------------------------------------------*/
int head(List l)
{
	if(l == NULL){printf("opération interdite\n"); exit(1);}
	return l->v;
}

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

//--------------------------------------------fct graphe-----------------------------

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