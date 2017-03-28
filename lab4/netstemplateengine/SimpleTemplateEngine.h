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
        //void ToString(std::ostream *out) const;
        //double Distance(const Point &other) const;

        std::string Render(const std::unordered_map <std::string, std::string> &model)const;
        //metody akcesorów są publiczne i tylko w przy ich pomocy
        //można się dostać z zewnątrz do pól klasy
        //double GetX() const;
        //double GetY() const;

        std::string GetStr() const;
        //std::unordered_map <std::string, std::string> GetMap() const;



        //metody seterów pozwalające zmienić stan obiektu
        //po jego zainicjalizowaniu
        //void SetX(double x);
        //void SetY(double y);
    private:
        std::string str_;
    };
}



#endif //JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
