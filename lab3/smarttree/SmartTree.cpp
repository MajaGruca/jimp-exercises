//
// Created by ktr on 18.03.2017.
//

#include "SmartTree.h"
#include <iostream>
#include <sstream>
#include <string>
#include <memory>

namespace datastructures{

    std::unique_ptr <SmartTree> CreateLeaf(int value)
    {
        std::unique_ptr<SmartTree> leaf = std::make_unique<SmartTree>();
        leaf->value=value;
        leaf->left= nullptr;
        leaf->right= nullptr;


        return leaf;
    }
    std::unique_ptr <SmartTree> InsertLeftChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> left_subtree)
    {
        if(tree!= nullptr)
        {
            if(tree->left== nullptr)
            {
                tree->left=std::move(left_subtree);

                return std::move(tree);
            }
        }
        return nullptr;
    }
    std::unique_ptr <SmartTree> InsertRightChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> right_subtree)
   {
       if(tree!= nullptr)
       {
           if(tree->right== nullptr)
           {
               tree->right=std::move(right_subtree);

               return std::move(tree);
           }
       }
       return nullptr;
    }
    void PrintTreeInOrder(const std::unique_ptr<SmartTree> &unique_ptr, std::ostream *out)
    {
        if(unique_ptr->left!= nullptr)
        {
            PrintTreeInOrder( unique_ptr->left,out);
        }
        *out << unique_ptr->value<<", ";
        if(unique_ptr->right!= nullptr)
        {
            PrintTreeInOrder( unique_ptr->right,out);
        }

    }
    void AddString(const std::unique_ptr<SmartTree> &tree, std::ostream *str)
    {
        *str << " [" << tree->value ;
        if(tree->left!= nullptr)
            AddString(tree->left,str);

        if(tree->right!= nullptr)
            AddString(tree->right,str);

        if(tree->left== nullptr)
            *str << " [none]";

        if(tree->right== nullptr)
            *str << " [none]";

        *str<<"]";
    }
    std::string DumpTree(const std::unique_ptr<SmartTree> &tree)
    {
        std::stringstream ss;
        AddString(tree, &ss);

        return  ss.str().erase(0,1);
    }
    std::unique_ptr <SmartTree> RestoreTree(const std::string &tree);

}