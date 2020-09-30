#include "graph.h"
#include "queue.h"
#include "stack.h"


int main()
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

	/*Queue q = NULL;
	for(int i = 0; i < 2; i++)
	{
		q = enqueue(q, *g);
		g = g->next;
	}

	display_queue(q);
	q = dequeue(q);
	display_queue(q);*/




	Stack p = NULL;
	for(int i = 0; i < 2; i++)
	{
		p = push(p, *g);
		g = g->next;
	}
	display_stack(p);
	p = pop(p);
	display_stack(p);

	return 0;
}