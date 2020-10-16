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
void push_back_list(list* l, int value) {
	list_node* ln = (list_node*)(malloc(sizeof(list_node)));
	ln->value = value;
	ln->next = NULL;
	list_node* p = l->head;
	while (p != NULL && p->next != NULL)
		p = p->next;
	if (p == NULL)
		l->head = ln;
	else
		p->next = ln;
	l->size++;
}

int pop_back_list(list* l) {
	if (empty_list(l)) {
		printf("List is empty");
		return 0;
	}
	if (l->head->next == NULL) {
		int value = l->head->value;
		free(l->head);
		l->head = NULL;
		l->size--;
		return value;
	}
	list_node* ln = l->head;
	while (ln->next->next != NULL)
		ln = ln->next;
	int value = ln->next->value;
	free(ln->next);
	ln->next = 0;
	l->size--;
	return value;
}
//===================================================================================

//==============	DOUBLY LLIST	=================================================

struct doubly_list_node {
	int value;
	struct doubly_list_node* next;
	struct doubly_list_node* previous;

};
typedef struct doubly_list_node doubly_list_node;

struct doubly_list {
	doubly_list_node* head;
	doubly_list_node* tail;
	int size;
};
typedef struct doubly_list doubly_list;

doubly_list* doubly_create_list() {
	doubly_list* l = (doubly_list*)(malloc(sizeof(doubly_list)));
	l->head = l->tail = NULL;
	l->size = 0;
	return l;
}

bool doubly_empty_list(doubly_list* l) {
	return l->size == 0;
}

void doubly_push_front_list(doubly_list* l, int value) {
	doubly_list_node* ln = (doubly_list_node*)(malloc(sizeof(doubly_list_node)));
	ln->value = value;
	ln->next = ln->previous = NULL;
	if (doubly_empty_list(l)) {
		l->head = l->tail = ln;
		l->size++;
		return ;
	}

	ln->next = l->head;
	l->head->previous = ln;
	l->head = ln;
	l->size++;
}

void doubly_push_back_list(doubly_list* l, int value) {
	doubly_list_node* ln = (doubly_list_node*)(malloc(sizeof(doubly_list_node)));
	ln->value = value;
	ln->next = ln->previous = NULL;
	if (doubly_empty_list(l)) {
		l->head = l->tail = ln;
		l->size++;
		return;
	}
	ln->previous = l->tail;
	l->tail->next = ln;
	l->tail = ln;
	l->size++;
}

int doubly_pop_front_list(doubly_list* l) {
	if (doubly_empty_list(l))
	{
		printf("The list is empty");
		return 0;
	}
	int value = l->head->value;
	doubly_list_node* ln = l->head;
	if (l->size == 1) {
		l->size--;
		free(l->head);
		l->head = l->tail = NULL;
		return value;
	}
	l->head = l->head->next;
	l->head->previous = NULL;
	free(ln);
	l->size--;
	return value;
}

int doubly_pop_back_list(doubly_list* l) {
	if (empty_list(l)) {
		printf("List is empty");
		return 0;
	}
	int value = l->tail->value;
	if (l->size == 1) {
		free(l->tail);
		l->tail = l->head = NULL;
		l->size--;
		return value;
	}
	list_node* ln = l->tail;
	l->tail = l->tail->previous;
	l->tail->next = NULL;
	free(ln);
	l->size--;
	return value;
}
//===================================================================================

//==============	BINARY TREE	=====================================================
struct tree_node {
	struct tree_node* left_child;
	struct tree_node* right_child;
	int value;
};
typedef struct tree_node tree_node;

struct tree {
	tree_node* root;
	int size;
};
typedef struct tree tree;

tree* create_tree() {
	tree* t = (tree *)(malloc(sizeof(tree)));
	t->root = NULL;
	t->size = 0;
	return t;
}

bool empty_tree(tree* t) {
	return t->size == 0;
}

void insert_tree(tree* t, int value) {
	tree_node* tn = (tree_node*)(malloc(sizeof(tree_node)));
	tn->left_child = tn->right_child = NULL;
	tn->value = value;
	if (empty_tree(t)) {
		t->root = tn;
		t->size++;
		return t;
	}
	tree_node* root = t->root;
	while (true) {
		if (value < root->value) {
			if (root->left_child == NULL) {
				root->left_child = tn;
				t->size++;
				return;
			}
			else {
				root = root->left_child;
			}
		}
		else if (value > root->value) {
			if (root->right_child == NULL) {
				root->right_child = tn;
				t->size++;
				return;
			}
			else {
				root = root->right_child;
			}
		}
		else
			break;
	}
}

void print_tree(tree_node* root) {
	if (root == NULL) {
		return;
	}
	print_tree(root->left_child);
	printf("%d\t", root->value);
	print_tree(root->right_child);
}
//===================================================================================

//==============	GRAPHS		=====================================================

struct edge_node {
	int v;
	int weight;
	struct edge_node* next;
};
typedef struct edge_node edge_node;

struct graph {
	edge_node** edges;
	int nb_nodes;
	int nb_edges;
	bool is_directed;
};
typedef struct graph graph;

graph* create_graph(int nb_nodes, bool is_directed) {
	graph* g = (graph*)(malloc(sizeof(graph)));
	g->nb_nodes = nb_nodes;
	g->nb_edges = 0;
	g->is_directed = is_directed;
	g->edges = (graph**)(malloc(sizeof(graph*) * nb_nodes));

	int u;
	for (u = 0; u < g->nb_nodes; u++)
		g->edges[u] = NULL;
	return g;
}

void print_graph(graph* g) {
	int u;
	for (u = 0; u < g->nb_nodes; u++) {
		printf("%d-->", u);
		
		edge_node* e = g->edges[u];
		while (e != NULL) {
			printf("%d\t", e->v);
			e = e->next;
		}
		printf("\n");
	}
}

//function that will connect u to v with the weight weight
void graph_add_edge(graph* g, int u, int v, int weight) {
	edge_node* e = (edge_node*)(malloc(sizeof(edge_node)));
	e->v = v;
	e->weight = weight;
	e->next = g->edges[u];
	g->edges[u] = e;
	if (!g->is_directed)		//In non-directed graph it should connect both the ways u<->v
	{
		e = (edge_node*)(malloc(sizeof(edge_node)));
		e->v = u;
		e->weight = weight;
		e->next = g->edges[v];
		g->edges[v] = e;
	}
	g->nb_edges++;
}
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

	//----------	ACTING AS STACK	-------------------------------------------------
	list* l1 = create_list();
	push_front_list(l1, 8);
	push_front_list(l1, 1);
	push_front_list(l1, 9);
	push_front_list(l1, 4);
	push_front_list(l1, 5);
	while (!empty_list(l1)) {
		printf("%d\t", pop_front_list(l1));
	}

	printf("\n");

	//----------	ACTING AS QUEUE	--------------------------------------------------
	list* l2 = create_list();
	push_back_list(l2, 8);
	push_back_list(l2, 1);
	push_back_list(l2, 9);
	push_back_list(l2, 4);
	push_back_list(l2, 5);
	while (!empty_list(l2)) {
		printf("%d\t", pop_front_list(l2));
	}

	printf("\n");

	//----------	ACTING AS STACK	-------------------------------------------------
	list* l3 = create_list();
	push_back_list(l3, 8);
	push_back_list(l3, 1);
	push_back_list(l3, 9);
	push_back_list(l3, 4);
	push_back_list(l3, 5);
	while (!empty_list(l3)) {
		printf("%d\t", pop_back_list(l3));
	}
	//================================================================================
	printf("\n");
	//================	FOR DOUBLY LLIST	==========================================

	//----------------	ACTING AS STACK		------------------------------------------
	doubly_list* dl1 = doubly_create_list();
	doubly_push_front_list(dl1, 8);
	doubly_push_front_list(dl1, 2);
	doubly_push_front_list(dl1, 5);
	doubly_push_front_list(dl1, 3);
	doubly_push_front_list(dl1, 1);
	while (!doubly_empty_list(dl1)) {
		printf("%d\t", doubly_pop_front_list(dl1));
	}

	printf("\n");

	//-----------------	ACTING AS QUEUE		-------------------------------------------
	doubly_list* dl = doubly_create_list();
	doubly_push_front_list(dl, 8);
	doubly_push_front_list(dl, 2);
	doubly_push_front_list(dl, 5);
	doubly_push_front_list(dl, 3);
	doubly_push_front_list(dl, 1);
	while (!doubly_empty_list(dl)) {
		printf("%d\t", doubly_pop_back_list(dl));
	}
	//=================================================================================
	printf("\n");
	//==================	BINARY TREE		===========================================
	tree* t = create_tree();
	insert_tree(t, 3);
	insert_tree(t, 1);
	insert_tree(t, 2);
	insert_tree(t, 5);
	insert_tree(t, 4);
	print_tree(t->root);

	//=================================================================================
	printf("\n");
	//==================	FOR GRAPH		===========================================
	graph* g = create_graph(6, false);
	graph_add_edge(g, 2, 4, 1);
	graph_add_edge(g, 2, 5, 1);
	print_graph(g);
	return 0;
}