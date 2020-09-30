#ifndef QUEUE_H
#define QUEUE_H

#include "graph.h" 


typedef struct link_q
{ 
  Link_g edge;
  struct link_q *next;
}Link_q , *Queue ; 

Queue enqueue (Queue q, Link_g edge);
Queue dequeue (Queue q);
Booleen empty_queue(Queue q);
void display_queue(Queue q);
Link_g head_queue(Queue q);
int size_queue(Queue q);

#endif