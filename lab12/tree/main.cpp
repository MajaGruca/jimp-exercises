//
// Created by ktr on 29.05.2017.
//

#include <iostream>
#include "Tree.h"
#include <TreeIterators.h>
using namespace tree;
void Print(Tree<int>* a)
{
    if(a->L())
    {
        Print(a->L());
    }
    std::cout<<a->Value()<<std::endl;
    if(a->P())
    {
        Print(a->P());
    }
}
int main()
{

Tree<int> simple_tree(0);
    simple_tree.Insert(-20);
    simple_tree.Insert(80);
    simple_tree.Insert(10078);
    simple_tree.Insert(98341);
    simple_tree.Insert(198341);
    simple_tree.Insert(-90);
    simple_tree.Insert(-10);
    if(simple_tree.Find(-10))
    {std::cout<<simple_tree.Value()<<" jest"<<std::endl;}
std::cout<<"//////////////////////////////////////////////////////"<<std::endl;
    Print(&simple_tree);
    return 0;
}