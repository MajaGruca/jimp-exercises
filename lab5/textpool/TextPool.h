//
// Created by ktr on 31.03.2017.
//

#ifndef JIMP_EXERCISES_TEXTPOOL_H
#define JIMP_EXERCISES_TEXTPOOL_H

#include <initializer_list>
#include <string>
#include <experimental/string_view>
#include <set>
namespace pool
{
    class TextPool {
    public:
        TextPool()= default;
        TextPool(std::initializer_list<std::string> text);
        TextPool(TextPool &&pooltext);
        TextPool &operator=(TextPool &&pooltext);
        ~TextPool();

        std::experimental::string_view Intern(const std::string &str);
        size_t StoredStringCount() const;

    private:
        std::set<std::string> text_;

    };

}



#endif //JIMP_EXERCISES_TEXTPOOL_H
