//
// Created by ktr on 04.04.2017.
//

#ifndef JIMP_EXERCISES_STUDYYEAR_H
#define JIMP_EXERCISES_STUDYYEAR_H

#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include <cmath>



using ::std::ostream;
using ::std::endl;
using ::std::pow;
using ::std::sqrt;
using ::std::cout;

using ::std::istream;
using ::std::ws;
namespace academia{
    class StudyYear
    {

    public:
        StudyYear();
        StudyYear(int a);
        operator int() const;
        /*std::string GetID()const;
        std::string GetFN()const;
        std::string GetLN()const;
        std::string GetP()const;*/
        int GetY() const ;
        void operator++();

        void operator--();
        bool operator<(StudyYear a) const ;
        bool operator<=(StudyYear a) const ;
        bool operator>(StudyYear a) const ;
        bool operator>=(StudyYear a) const ;
        bool operator==(StudyYear a) const ;
        bool operator!=(StudyYear a) const ;

    private:
        int year;
    };
    class Student  {
   /* public:
        std::string GetID()const;
        std::string GetFN()const;
        std::string GetLN()const;
        std::string GetP()const;
        int GetY() const ;*/
    private:
        std::string id;
        std::string first_name;
        std::string last_name;
        std::string program;
        StudyYear year;

    };

}



#endif //JIMP_EXERCISES_STUDYYEAR_H
