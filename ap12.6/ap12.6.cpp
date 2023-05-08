// ap12.6.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
using namespace std;

typedef int Info;
struct Elem
{
    Elem* link;
    Info info;
};

void enqueue(Elem*& first, Elem*& last, Info value);
bool isEmpty(Elem* first);
void printQueue(Elem* first);
bool contains(Elem* first, Info value);
void clearQueue(Elem*& first, Elem*& last);
void dequeue(Elem*& first, Elem*& last);

void enqueue(Elem*& first, Elem*& last, Info value)
{
    Elem* tmp = new Elem;
    tmp->info = value;
    tmp->link = NULL;
    if (last != NULL)
        last->link = tmp;
    last = tmp;
    if (first == NULL)
        first = tmp;
}

bool isEmpty(Elem* first)
{
    return first == NULL;
}

void printQueue(Elem* first)
{
    while (first != NULL)
    {
        cout << first->info << " ";
        first = first->link;
    }
    cout << endl;
}

bool contains(Elem* first, Info value)
{
    while (first != NULL)
    {
        if (first->info == value)
            return true;
        first = first->link;
    }
    return false;
}

void dequeue(Elem*& first, Elem*& last)
{
    if (isEmpty(first))
        return;

    Elem* tmp = first;
    first = first->link;

    if (first == NULL)
        last = NULL;

    delete tmp;
}

void clearQueue(Elem*& first, Elem*& last)
{
    while (first != NULL)
    {
        Elem* tmp = first->link;
        delete first;
        first = tmp;
    }
    last = NULL;
}

int main()
{
    Elem* first = NULL,
        * last = NULL;


    enqueue(first, last, 45);
    enqueue(first, last, 7);
    enqueue(first, last, 3);
    enqueue(first, last, 12);


    cout << "Queue: ";
    printQueue(first);


    cout << "Is queue empty? " << (isEmpty(first) ? "Yes" : "No") << endl;


    cout << "Adding 5 to queue: ";
    enqueue(first, last, 5);
    printQueue(first);


    int valueToFind = 3;
    cout << "Does the queue contain " << valueToFind << "? " << (contains(first, valueToFind) ? "Yes" : "No") << endl;


    cout << "Clearing first element of queue: ";
    dequeue(first, last);
    printQueue(first);


    cout << "Clearing the queue" << endl;
    clearQueue(first, last);


    cout << "Is queue empty? " << (isEmpty(first) ? "Yes" : "No") << endl;

    return 0;
}
