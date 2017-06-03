//
// Created by ktr on 29.05.2017.
//

#include <iostream>
#include "Tree.h"
using namespace tree;

int main()
{
    Tree<int> tree{5};
    tree.Insert(9);
   int a=9;

    std::cout << "PreOrder: ";
    /**for(const int &value_in_tree : PreOrder(tree)) {
        std::cout<<value_in_tree << " ";
    }*/
   /* std::cout << "InOrder: ";
    for(const int &value_in_tree : InOrder(tree)) {
        std::cout<<value_in_tree << " ";
    }
    std::cout << "PostOrder: ";
    for(const int &value_in_tree : PostOrder(tree)) {
        std::cout<<value_in_tree << " ";
    }*/
    return 0;
}