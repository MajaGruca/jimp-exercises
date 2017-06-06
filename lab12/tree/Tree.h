//
// Created by ktr on 29.05.2017.
//

#ifndef JIMP_EXERCISES_TREE_H
#define JIMP_EXERCISES_TREE_H

#include <cstddef>
#include <initializer_list>
#include <algorithm>
#include <memory>
#include <vector>

namespace tree{

    template<typename Element>
    class InOrderTreeIterator;


    template <class Element>
    class Tree {
        public:

            Tree(const Element &cos):size_(1),value_(cos),root_(this){}
            Tree():size_(1),root_(this){}

            bool operator<(Element one);
            bool operator<(Tree one);

            void Insert(const Element &e);
            bool Find(const Element &e);
            Element Value(){ return value_;};
            size_t Depth(){
                if(L_dziecko && P_dziecko)
                    return 1+std::max(L_dziecko->Depth(),P_dziecko->Depth());
                else{
                    if(L_dziecko)
                        return 1+L_dziecko->Depth();
                    if(P_dziecko)
                        return 1+P_dziecko->Depth();
                    return 1;
                }
            };
            size_t Size(){ return size_;};
            Tree* L(){ return L_dziecko.get() ;}
            Tree* P(){ return P_dziecko.get() ;}
            Tree* Root(){ return root_;}
            operator Element(){ return value_;}

        private:

            Tree* root_;
            size_t size_;
            Element value_;

            std::unique_ptr<Tree> L_dziecko;
            std::unique_ptr<Tree> P_dziecko;
    };

    template <class Element>
    bool Tree<Element>::Find(const Element &e) {

        if(this->value_==e)
            return true;

        if(this->value_<e)
        {
            if(this->L_dziecko)
                this->L_dziecko->Find(e);
            else
                return false;

        } else
        {
            if(this->P_dziecko)
                this->P_dziecko->Find(e);
            else
                return false;
        }
        return false;
    }

    template <class Element>
    void Tree<Element>::Insert(const Element &e) {

        size_++;

        if(this->value_<e)
        {
            if(!this->L_dziecko) {

                this->L_dziecko = std::make_unique<Tree<Element>>(e);

            } else
            {this->L_dziecko->Insert(e);}

        } else
        {
            if(!this->P_dziecko) {

                this->P_dziecko = std::make_unique<Tree<Element>>(e);
            }
            else
            {this->P_dziecko->Insert(e);}
        }
    }
    template <class Element>
    bool Tree<Element>::operator<(Element one) {
        return this->value_<one;
    }

    template <class Element>
    bool Tree<Element>::operator<(Tree one) {
        return this->value_<one.value_;
    }

}



#endif //JIMP_EXERCISES_TREE_H
