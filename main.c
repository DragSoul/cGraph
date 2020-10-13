#include "graph.h"
#include "queue.h"
#include "stack.h"


int main()
{
	Graph g = NULL;
	
	g = add_link(g, 25);
	g = add_link(g, 8);
	g = add_link(g, 5);
	g = add_link(g, 4);
	
	g = add_vectice(g, 5, 8);
	g = add_vectice(g, 5, 25);
	g = add_vectice(g, 8, 5);
	g = add_vectice(g, 25, 5);
	g = sups(g, 5);
	export_graph(g);

	Queue q = NULL;
	Graph g1 = g;
	while(g1 != NULL)
	{
		q = enqueue(q, *g1);
		g1 = g1->next;
	}

	display_queue(q);
	q = dequeue(q);
	display_queue(q);




	Stack p = NULL;
	Graph g2 = g;
	while(g2 != NULL)
	{
		p = push(p, *g2);
		g2 = g2->next;
	}
	display_stack(p);
	p = pop(p);
	display_stack(p);

	return 0;
}