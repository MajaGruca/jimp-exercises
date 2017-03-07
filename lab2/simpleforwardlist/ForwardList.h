//
// Created by ktr on 07.03.2017.
//

#ifndef JIMP_EXERCISES_FORWARDLIST_H
#define JIMP_EXERCISES_FORWARDLIST_H

struct ForwardList
{
    int value;
    ForwardList *next;
};

ForwardList *CreateNode(int value);
void DestroyList(ForwardList *list);
void PrintList(ForwardList *list);
void Append(ForwardList *list, ForwardList *tail);
ForwardList *PushFront(ForwardList *list, int value);


#endif //JIMP_EXERCISES_FORWARDLIST_H
