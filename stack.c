#include "stack.h"

Stack push(Stack p, Link_g x)
{
	Link_s *m;
	m = (Link_s*)malloc(sizeof(Link_s));
	if(m == NULL)
	{
		printf("pb malloc\n");
		exit(1);
	}
	m->edge = x;
	m->next = p;
	return m;
}

Stack pop(Stack p)
{
	Link_s *m;
	if(empty_stack(p))
	{
		printf("op interdite\n");
		exit(1);
	}
	m=p;
	p = p->next;
	free(m);
	return p;
}

Booleen empty_stack(Stack p)
{
	if(p == NULL)
		return true;
	return false;
}

void display_stack(Stack p)
{
	while(!empty_stack(p))
	{
		printf("%d, ", p->edge.v);
		p=p->next;
	}
	printf("\n");
}

Link_g head_stack(Stack p)
{
	return p->edge;
}

int size_stack(Stack p)
{
	int i=0; 
	while (!empty_stack(p))
	{
		i = i+1;
		p = p->next;
	}
	return i;
}








