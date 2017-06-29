//
// Created by ktr on 31.03.2017.
//

#include "TextPool.h"
#include <initializer_list>
#include <string>
#include <experimental/string_view>
#include <set>

namespace pool
{

    TextPool::TextPool(std::initializer_list<std::string> text)
    {
    for(auto &it : text)
        text_.insert(it);
    }

    TextPool::TextPool(TextPool &&textpool)
    {
        swap(text_,textpool.text_);
    }
    TextPool::~TextPool()
    {
        text_.clear();
    }
    TextPool & TextPool::operator=(TextPool &&textpool)
    {
        if (this == &textpool)
        {
            return textpool;
        }
        text_.clear();
        swap(text_, textpool.text_);
    }


    std::experimental::string_view TextPool::Intern(const std::string &str)
    {
        auto temp=text_.insert(str);
        return *temp.first;
    }
    size_t TextPool::StoredStringCount() const
    {
        return text_.size();
    }
}