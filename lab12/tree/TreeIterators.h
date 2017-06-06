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
    ////////////////////////////////////////////////////////////////////////////////////////////////
   template<class Element>
    void SetVectorPreOrder(Tree<Element> *tree, std::vector<Tree<Element> *> &vec_in_or) {

        vec_in_or.push_back(tree);
        if (tree->L()) {
            SetVectorPreOrder(tree->L(), vec_in_or);
        }
        if (tree->P()) {
            SetVectorPreOrder(tree->P(), vec_in_or);
        }
    }

    template<class Element>
    class PreOrderTreeView;

    template<class Element>
    PreOrderTreeView<Element> PreOrder(Tree<Element> *tree);

    template<class Element>
    PreOrderTreeView<Element> PreOrder(Tree<Element> *tree) {
        return PreOrderTreeView<Element>(tree);
    }

    template<class Element>
    class PreOrderTreeIterator {
    public:
        PreOrderTreeIterator(Tree<Element> *tree) : iter_(0) {SetVectorPreOrder<Element>(tree, vec_in_or);}
        PreOrderTreeIterator<Element> &operator++() {++iter_; return *this;}
        Element operator*(){return vec_in_or[iter_]->Value();}
        bool operator!=(const PreOrderTreeIterator<Element> &one) const{return iter_ != one.iter_;}
        friend class PreOrderTreeView<Element>;

    private:
        void SetToEnd(){iter_ = vec_in_or.size();}
        std::vector<Tree<Element> *> vec_in_or;
        unsigned long iter_;
    };

    template<class Element>
    class PreOrderTreeView {
    public:
        PreOrderTreeView(Tree<Element> *tree) : tree_(tree) {};
        PreOrderTreeIterator<Element> begin(){
            PreOrderTreeIterator<Element> new_iterator(tree_->Root());
            return new_iterator;
        }
        PreOrderTreeIterator<Element> end(){
            PreOrderTreeIterator<Element> new_iterator(tree_->Root());
            new_iterator.SetToEnd();
            return new_iterator;
        }

    private:
        Tree<Element> *tree_;
    };
//////////////////////////////////////////////////////////////////////////////////////////////////
    template<class Element>
    void SetVectorPostOrder(Tree<Element> *tree, std::vector<Tree<Element> *> &vec_in_or) {
        if (tree->L()) {
            SetVectorPostOrder(tree->L(), vec_in_or);
        }
        if (tree->P()) {
            SetVectorPostOrder(tree->P(), vec_in_or);
        }
        vec_in_or.push_back(tree);
    }

    template<class Element>
    class PostOrderTreeView;

    template<class Element>
    PostOrderTreeView<Element> PostOrder(Tree<Element> *tree);

    template<class Element>
    PostOrderTreeView<Element> PostOrder(Tree<Element> *tree) {
        return PostOrderTreeView<Element>(tree);
    }

    template<class Element>
    class PostOrderTreeIterator {
    public:
        PostOrderTreeIterator(Tree<Element> *tree) : iter_(0) {SetVectorPostOrder<Element>(tree, vec_in_or);}
        PostOrderTreeIterator<Element> &operator++() {++iter_; return *this;}
        Element operator*(){return vec_in_or[iter_]->Value();}
        bool operator!=(const PostOrderTreeIterator<Element> &one) const{return iter_ != one.iter_;}
        friend class PostOrderTreeView<Element>;

    private:
        void SetToEnd(){iter_ = vec_in_or.size();}
        std::vector<Tree<Element> *> vec_in_or;
        unsigned long iter_;
    };

    template<class Element>
    class PostOrderTreeView {
    public:
        PostOrderTreeView(Tree<Element> *tree) : tree_(tree) {};
        PostOrderTreeIterator<Element> begin(){
            PostOrderTreeIterator<Element> new_iterator(tree_->Root());
            return new_iterator;
        }
        PostOrderTreeIterator<Element> end(){
            PostOrderTreeIterator<Element> new_iterator(tree_->Root());
            new_iterator.SetToEnd();
            return new_iterator;
        }

    private:
        Tree<Element> *tree_;
    };



}



#endif //JIMP_EXERCISES_TREEITERATORS_H
