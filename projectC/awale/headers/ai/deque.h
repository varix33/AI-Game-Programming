#ifndef deque_h
#define deque_h

#include <stdlib.h>
#include "../action/action.h"

// TODO
typedef struct Node
{
    Action data;
    struct Node *next;
    struct Node *prev;
} Node;

// TODO
typedef struct Deque
{
    Node *front;
    Node *rear;
} Deque;

// TODO
Deque *createDeque();
// TODO
void pushFront(Deque *deque, Action data);
// TODO
void popFront(Deque *deque);
// TODO
void pushBack(Deque *deque, Action data);
// TODO
void popBack(Deque *deque);
// TODO
void freeDeque(Deque *deque);
// TODO
Action getActionAt(Deque *deque, int index);

#endif
