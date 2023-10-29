#include "../../headers/ai/deque.h"

Deque *createDeque()
{
    Deque *deque = (Deque *)malloc(sizeof(Deque));
    deque->front = NULL;
    deque->rear = NULL;

    return deque;
}

void pushFront(Deque *deque, Action data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = deque->front;
    newNode->prev = NULL;

    if (deque->front != NULL)
    {
        deque->front->prev = newNode;
    }

    deque->front = newNode;

    if (deque->rear == NULL)
    {
        deque->rear = newNode;
    }
}

void popFront(Deque *deque)
{
    if (deque->front == NULL)
    {
        return;
    }

    Node *temp = deque->front;
    deque->front = deque->front->next;

    if (deque->front == NULL)
    {
        deque->rear = NULL;
    }
    else
    {
        deque->front->prev = NULL;
    }

    free(temp);
}

void pushBack(Deque *deque, Action data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = deque->rear;

    if (deque->rear != NULL)
    {
        deque->rear->next = newNode;
    }

    deque->rear = newNode;

    if (deque->front == NULL)
    {
        deque->front = newNode;
    }
}

void popBack(Deque *deque)
{
    if (deque->rear == NULL)
    {
        return;
    }

    Node *temp = deque->rear;

    deque->rear = deque->rear->prev;

    if (deque->rear == NULL)
    {
        deque->front = NULL;
    }
    else
    {
        deque->rear->next = NULL;
    }

    free(temp);
}

void freeDeque(Deque *deque)
{
    while (deque->front != NULL)
    {
        popFront(deque);
    }

    free(deque);
}

Action getActionAt(Deque *deque, int index)
{
    Node *current = deque->front;
    int i = 0;

    while (current != NULL && i < index)
    {
        current = current->next;
        i++;
    }

    if (current != NULL)
    {
        return current->data;
    }
    else
    {
        // TODO error
    }
}
