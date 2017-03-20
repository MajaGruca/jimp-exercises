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
    std::string DumpTree(const std::unique_ptr<SmartTree> &tree)
    {
        std::string str;

        str += "["+std::to_string(tree->value)+" ";
        if(tree->left!= nullptr)
            str+=DumpTree(tree->left);
        else
            str+= "[none]";

        str+=" ";

        if(tree->right!= nullptr)
            str+=DumpTree(tree->right);
        else
            str+= "[none]";
        str+="]";
        return str;
    }
    std::unique_ptr <SmartTree> RestoreTree(const std::string &tree);

}