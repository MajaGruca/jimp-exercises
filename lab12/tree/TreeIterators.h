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

    /*template<class Element>
    InOrderTreeView<Element> InOrder(Tree<Element> *tree) {
        return InOrderTreeView<Element>(tree);
    }
*/

    template <class Element>
    class InOrderTreeIterator
    {
    public:
        InOrderTreeIterator(){}
        InOrderTreeIterator(tree::Tree<Element>* a){}
        InOrderTreeIterator &operator++();
        Element operator*();
        bool operator !=(const InOrderTreeIterator & one) const { return false;}
        operator Element();

    private:

        std::vector<Element> cos;

    };


    template <class Element>
    class InOrderTreeView
    {
    public:
        InOrderTreeView(tree::Tree<int>*);
        InOrderTreeIterator<Element> begin();
        InOrderTreeIterator<Element> end();

    };


   /* template<class Element>
    InOrderTreeView<Element> InOrder(Tree<Element> *tree) ;*/
}



#endif //JIMP_EXERCISES_TREEITERATORS_H
