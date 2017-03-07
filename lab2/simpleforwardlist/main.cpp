//
// Created by ktr on 07.03.2017.
//


#include <iostream>
#include "ForwardList.h"
using namespace std;

int main()
{
    ForwardList *list = 0;
    list = PushFront(list,10);
    list = PushFront(list,15);
    list = PushFront(list,12);
    Append(list,CreateNode(99));
    PrintList(list);
    DestroyList(list);
    return 0;
}