#include "queue.h"

Queue enqueue(Queue q, Link_g x) 
{	
	Link_q *m; 
	m=(Link_q*)malloc(sizeof(Link_q));
	if (m == NULL) 
	{
		printf("pb malloc ");
		exit(1) ;
	}
	m->edge=x;
	if (empty_queue(q))
	{
		m->next= m ;
		return m;
	}
	m->next=q->next;
	q->next=m;
	return m ; 
}

Queue dequeue (Queue q) 
{
	Link_q *m ;
	if (empty_queue(q))
	{
		printf("liste empty_queue ") ;
		exit(1);
	}
	if (q->next==q)
	{
		free(q);
		return NULL;
	}
	m=q->next;
	q->next=q->next->next;
	free(m);
	return q ;
}

Booleen empty_queue(Queue q)
{
	if(q == NULL)
		return true;
	return false;
}


void display_queue(Queue q)
{
	if(empty_queue(q))
	{
		printf("la liste est empty_queue\n");
		exit(1);
	}
	Queue m = q;
	while(q->next != m)
	{
		printf("%d, ", q->edge.v);
		q=q->next;
	}
	printf("%d\n", q->edge.v);
}

Link_g head_queue(Queue q)
{
	return q->edge;
}

int size_queue(Queue q)
{
	int i=0;
	if(empty_queue(q))
	{
		return i;
	}
	Queue m = q;
	while(q->next != m)
	{
		i=i+1;
		q=q->next;
	}
	i = i+1;
	return i;
}

