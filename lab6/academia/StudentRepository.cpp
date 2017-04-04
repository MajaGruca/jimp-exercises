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

    int StudyYear::GetY() const
    {
        return this->year;
    }
}

