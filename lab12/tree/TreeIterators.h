//
// Created by ktr on 03.06.2017.
//

#ifndef JIMP_EXERCISES_TREEITERATORS_H
#define JIMP_EXERCISES_TREEITERATORS_H

#include <Tree.h>
#include <vector>
#include <iostream>
namespace tree
{
//////////////////////////////////////////////////////////////////////////////////////////////////
    template<class Element>
    void SetVectorInOrder(Tree<Element> *tree, std::vector<Tree<Element> *> &vec_in_or) {
        if (tree->L()) {
            SetVectorInOrder(tree->L(), vec_in_or);
        }
        vec_in_or.push_back(tree);
        if (tree->P()) {
            SetVectorInOrder(tree->P(), vec_in_or);
        }
    }

    template<class Element>
    class InOrderTreeView;

    template<class Element>
    InOrderTreeView<Element> InOrder(Tree<Element> *tree);

    template<class Element>
    InOrderTreeView<Element> InOrder(Tree<Element> *tree) {
        return InOrderTreeView<Element>(tree);
    }


    template<class Element>
    class InOrderTreeIterator {
    public:
        InOrderTreeIterator(Tree<Element> *tree) : iter_(0) {SetVectorInOrder<Element>(tree, vec_in_or);}
        InOrderTreeIterator<Element> &operator++() {++iter_; return *this;}
        Element operator*(){return vec_in_or[iter_]->Value();}
        bool operator!=(const InOrderTreeIterator<Element> &one) const{return iter_ != one.iter_;}
        friend class InOrderTreeView<Element>;

    private:
        void SetToEnd(){iter_ = vec_in_or.size();}
        std::vector<Tree<Element> *> vec_in_or;
        unsigned long iter_;
    };

    template<class Element>
    class InOrderTreeView {
    public:
        InOrderTreeView(Tree<Element> *tree) : tree_(tree) {};
        InOrderTreeIterator<Element> begin(){
            InOrderTreeIterator<Element> new_iterator(tree_->Root());
            return new_iterator;
        }
        InOrderTreeIterator<Element> end(){
            InOrderTreeIterator<Element> new_iterator(tree_->Root());
            new_iterator.SetToEnd();
            return new_iterator;
        }

    private:
        Tree<Element> *tree_;
    };

}



#endif //JIMP_EXERCISES_TREEITERATORS_H
