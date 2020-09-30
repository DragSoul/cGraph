#ifndef STACK_H
#define STACK_H

#include "graph.h"

typedef struct link_s
{
	Link_g edge;
	struct link_s *next;
}Link_s, *Stack;


Stack push(Stack p, Link_g x);
Stack pop(Stack p);
Booleen empty_stack(Stack p);
void display_stack(Stack p);
int size_stack(Stack p);
Link_g head_stack(Stack p);

#endif