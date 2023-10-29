#ifndef deque_h
#define deque_h

#include <stdlib.h>
#include "../action/action.h"

typedef struct Node
{
    Action data;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct Deque
{
    Node *front;
    Node *rear;
} Deque;

Deque *createDeque();
void pushFront(Deque *deque, Action data);
void popFront(Deque *deque);
void pushBack(Deque *deque, Action data);
void popBack(Deque *deque);
void freeDeque(Deque *deque);
Action getActionAt(Deque *deque, int index);

#endif
