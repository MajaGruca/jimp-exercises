//
// Created by ktr on 07.03.2017.
//
#include "ForwardList.h"
#include <iostream>
using namespace std;

struct ForwardList
{
    int value;
    ForwardList *next;
};

ForwardList *CreateNode(int value)
{
    ForwardList *node = new ForwardList;
    node->value = value;
    node->next = 0;
    return node;
}

ForwardList *PushFront(ForwardList *list, int value)
{
    ForwardList *node = CreateNode(value);
    if(list!=0)
    {
        node->next = list;
    }
    return node;
}

void Append(ForwardList *list, ForwardList *tail)
{
    ForwardList *wsk = list;
    while(wsk->next)
    {
        wsk = wsk->next;
    }
    wsk->next = tail;
    tail->next = 0;
}

void DestroyList(ForwardList *list)
{
    ForwardList *wsk = list;
    while(list)
    {
        wsk = list;
        list = list->next;
        delete wsk;
    }
}
void PrintList(ForwardList *list)
{
    ForwardList *wsk = list;
    while(wsk)
    {
        cout << wsk->value << '\t';
        wsk = wsk->next;
    }
}