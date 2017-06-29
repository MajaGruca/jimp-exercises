//
// Created by ktr on 29.05.2017.
//

#ifndef JIMP_EXERCISES_TEACHERHASH_H
#define JIMP_EXERCISES_TEACHERHASH_H

#include <string>

namespace academia
{

    class TeacherId {
        public:
            TeacherId(const int &value){ this->id_ = value; }

            operator int() const{ return this->id_; }

        private:
            int id_;
        };

    class Teacher
    {
    public:
        Teacher(const TeacherId &id, std::string name, std:: string department) : id_(id), name_(name),
                                                                                 department_(department) {}
        TeacherId  Id() const { return id_;}
        std::string Name() const { return name_;}
        std::string Department()const { return department_;}

        bool operator==(const Teacher& one) const { return id_==one.id_ && name_==one.name_ && department_==one.department_;}
        bool operator!=(const Teacher& one) const { return id_!=one.id_ || name_!=one.name_ || department_!=one.department_;}

    private:
        TeacherId id_;
        std::string name_;
        std::string department_;
    };

        class TeacherHash {
        public:
            TeacherHash() {}

            size_t operator()(const Teacher &teacher) const{
                return std::hash<int>{}(teacher.Id())^std::hash<std::string>{}(teacher.Name())^std::hash<std::string>{}(teacher.Department());
            }

        };
}



#endif //JIMP_EXERCISES_TEACHERHASH_H
