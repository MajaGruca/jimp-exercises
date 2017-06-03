//
// Created by ktr on 03.06.2017.
//

#ifndef JIMP_EXERCISES_TREEITERATORS_H
#define JIMP_EXERCISES_TREEITERATORS_H

#include <Tree.h>
#include <vector>
namespace tree
{


    template<class Element>
    class InOrderTreeView;

    template<class Element>
    InOrderTreeView<Element> InOrder(Tree<Element> *tree);

    template<class Element>
    InOrderTreeView<Element> InOrder(Tree<Element> *tree) {
        return InOrderTreeView<Element>(tree);
    }

    template <class Element>
    void InOrderVector(std::vector<Element> &v_,Tree<Element>* tree)
    {
        if(tree->L())
        {
            InOrderVector(v_,tree->L().get());
        }
        v_.emplace_back(tree->Value());
        if(tree->P())
        {
            InOrderVector(v_,tree->P().get());
        }
    }
    template <class Element>
    class InOrderTreeIterator
    {
    public:
        InOrderTreeIterator(){}
        InOrderTreeIterator(Tree<Element>* tree) : v_(std::vector<Element>()){
            InOrderVector<Element>(v_,tree);
            iter=v_.begin();
        }
        InOrderTreeIterator &operator++(){ ++iter; return *this;}
        Element operator*(){ return *iter;}
        bool operator !=(const InOrderTreeIterator & one) const { return iter!=one.iter;}

        friend class InOrderTreeView<Element>;

    private:
        void SetToEnd(void){iter = v_.end();};
        std::vector<Element> v_;
        typename std::vector<Element>::iterator iter;

    };


    template <class Element>
    class InOrderTreeView
    {
    public:
        InOrderTreeView(Tree<int>* cos):tree_(cos){}
        InOrderTreeIterator<Element> begin(){ return tree_->Root();}
        InOrderTreeIterator<Element> end(){
            InOrderTreeIterator<Element> new_iterator(this->tree_->Root());
            new_iterator.SetToEnd();
            return new_iterator;

        }

    private:
        Tree<Element> *tree_;
    };


}



#endif //JIMP_EXERCISES_TREEITERATORS_H
