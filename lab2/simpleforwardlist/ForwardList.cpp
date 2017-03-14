//
// Created by ktr on 07.03.2017.
//
#include "ForwardList.h"
#include <iostream>
using namespace std;



ForwardList *CreateNode(int value)
{
    ForwardList *node = new ForwardList;
    node->value = value;
    node->next = nullptr;
    return node;
}

ForwardList *PushFront(ForwardList *list, int value)
{

    if(list!=nullptr)
    {
        ForwardList *node = CreateNode(value);
        node->next = list;
        return node;
    }
    else {
        return nullptr;
    }
}

void Append(ForwardList *list, ForwardList *tail)
{
    if(tail!=nullptr)
    {
        if(list!=nullptr)
        {
            ForwardList *wsk = list;
            while (wsk->next) {
                wsk = wsk->next;
            }
            wsk->next = tail;
            tail->next = nullptr;
        }
        else
        {
            list = tail;
        }
    }
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