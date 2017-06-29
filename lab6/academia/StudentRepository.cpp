//
// Created by ktr on 04.04.2017.
//

#include "StudentRepository.h"
namespace academia {
    StudyYear::operator int() const
    {
        return year;
    }

    StudyYear::StudyYear() {
        this->year=1;
    }
    StudyYear::StudyYear(int a) {
        this->year=a;
    }
    void StudyYear::operator++() {
        ++(this->year);
    }

    void StudyYear::operator--() {
        --(this->year);
    }
    bool StudyYear::operator<(StudyYear a) const
    {
        return this->year < a.year;
    }
    bool StudyYear::operator<=(StudyYear a) const
    {
        return this->year <= a.year;
    }
    bool StudyYear::operator>(StudyYear a) const
    {
        return this->year > a.year;
    }
    bool StudyYear::operator>=(StudyYear a) const
    {
        return this->year >= a.year;
    }
    bool StudyYear::operator==(StudyYear a) const
    {
        return this->year == a.year;
    }
    bool StudyYear::operator!=(StudyYear a) const
    {
        return this->year != a.year;
    }
/*    std::string StudyYear::GetID()const
    {
        return this->
    }
    std::string StudyYear::GetFN()const;
    std::string StudyYear::GetLN()const;
    std::string StudyYear::GetP()const;*/
    int StudyYear::GetY() const
    {
        return this->year;
    }
}

