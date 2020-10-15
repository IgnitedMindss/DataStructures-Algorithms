#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>
#include<ctype.h>
#include <stddef.h>
#define NULL ((void*)0)
//=====================	FOR STACK =====================================================

struct stack_node {
	int value;
	struct stack_node* next;
};
typedef struct stack_node stack_node;

struct stack {
	stack_node* head;
	int size;
};
typedef struct stack stack;

stack* create_stack()
{
	stack* s = (stack*)malloc(sizeof(stack));
	s->head = NULL;
	s->size = 0;
	return s;
}

bool empty_stack(stack* s) {
	return s->size == 0;
}

void push_stack(stack* s, int value) {
	stack_node* n = (stack_node*)malloc(sizeof(stack_node));
	n->value = value;
	n->next = s->head;
	s->head = n;
	s->size++;
}

int pop_stack(stack* s) {
	int value = s->head->value;
	stack_node* sn = s->head;
	s->head = s->head->next;
	s->size--;
	free(sn);
	return value;
}

//======================================================================================

//=========================		FOR QUEUE	============================================

struct queue_node {
	int value;
	struct queue_node* next;
};

typedef struct queue_node queue_node;

struct queue {
	queue_node* front;
	queue_node* back;
	int size;
};

typedef struct queue queue;

queue* create_queue() {
	queue* q = (queue*)(malloc(sizeof(queue)));
	q->back = q->front = NULL;
	q->size = 0;
	return q;
}

bool empty_queue(queue* q) {
	return q->size == 0;
}

void push_queue(queue* q, int value) {
	queue_node* qn = (queue_node*)malloc(sizeof(queue_node));
	qn->next = NULL;
	qn->value = value;
	if (empty_queue(q))
		q->back = q->front = qn;
	else
		q->back->next = qn, q->back = qn;
	q->size++;
}

int pop_queue(queue* q) {
	if (empty_queue(q)) {
		printf("queue is empty!");
		return 0;
	}
	int value = q->front->value;
	queue_node* qn = q->front;
	q->front = q->front->next;
	free(qn);
	q->size--;
	return value;
}

//===================================================================================

//==============	FOR L-LIST	=====================================================
//--------------------------	FRONT OF L-LIST	-------------------------------------
struct list_node {
	int value;
	struct list_node* next;
};

typedef struct list_node list_node;

struct list {
	list_node* head;
	int size;
};

typedef struct list list;

list* create_list() {
	list* l = (list*)(malloc(sizeof(list)));
	l->head = NULL;
	l->size = 0;
	return l;
}

bool empty_list(list* l) {
	return l->size == 0;
}

void push_front_list(list* l, int value) {
	list_node* ln = (list_node*)(malloc(sizeof(list_node)));
	ln->value = value;
	ln->next = l->head;
	l->head = ln;
	l->size++;
}

int pop_front_list(list* l) {
	if (empty_list(l))
	{
		printf("The list is empty");
		return 0;
	}
	int value = l->head->value;
	list_node* ln = l->head;
	l->head = l->head->next;
	free(ln);
	l->size--;
	return value;
}

//--------------------------	BACK OF L-LIST	-------------------------------------

int main() {
	//==========	FOR STACK	=====================================================
	
	stack* s = create_stack();
	push_stack(s, 1);
	push_stack(s, 2);
	push_stack(s, 3);
	push_stack(s, 5);
	while(!empty_stack(s))
	printf("%d\t", pop_stack(s));

	//================================================================================
	printf("\n");
	//==========	FOR QUEUE	=====================================================

	queue* q = create_queue();
	push_queue(q, 1);
	push_queue(q, 3);
	push_queue(q, 6);
	push_queue(q, 2);
	while (!empty_queue(q)) {
		printf("%d\t", pop_queue(q));
	}
	//================================================================================
	printf("\n");
	//==========	FOR LLIST	=====================================================

	list* l = create_list();
	push_front_list(l, 8);
	push_front_list(l, 1);
	push_front_list(l, 9);
	push_front_list(l, 4);
	push_front_list(l, 5);
	while (!empty_list(l)) {
		printf("%d\t", pop_front_list(l));
	}
	//================================================================================
	return 0;
}