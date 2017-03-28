//
// Created by ktr on 27.03.2017.
//

#ifndef JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
#define JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H

#include <string>
#include <unordered_map>
namespace nets
{


    class View {
    public:
        View();
        View(std::string str);
        ~View();

        std::string Render(const std::unordered_map <std::string, std::string> &model)const;


        std::string GetStr() const;

    private:
        std::string str_;
    };
}



#endif //JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
