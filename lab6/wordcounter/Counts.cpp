//
// Created by ktr on 10.04.2017.
//

#include "Counts.h"
namespace datastructures {
    Counts::Counts(int count) {
        wordcount = count;
    }

    Counts::Counts() {
        wordcount = 0;
    }

    int Counts::GetCounts() const {
        return wordcount;
    }

    bool operator==(int a, Counts b) {
        return a == b.GetCounts();
    }

    int Counts::operator+(Counts a) const {
        return this->wordcount + a.wordcount;
    }

    int Counts::operator+(int a) const {
        return this->wordcount + a;
    }

    void Counts::operator++() {
        ++(this->wordcount);
    }

    void Counts::operator--() {
        --(this->wordcount);
    }

    bool Counts::operator==(Counts a) const {
        return this->wordcount == a.wordcount;
    }

    bool Counts::operator!=(Counts a) const {
        return this->wordcount != a.wordcount;
    }

    bool Counts::operator!=(int a) const {
        return this->wordcount != a;
    }

    bool Counts::operator==(int a) const {
        return this->wordcount == a;
    }

    bool Counts::operator<=(Counts a) const {
        return this->GetCounts() <= a.GetCounts();
    }

    bool Counts::operator<(Counts a) const {
        return this->GetCounts() < a.GetCounts();
    }

    bool Counts::operator>=(Counts a) const {
        return this->GetCounts() >= a.GetCounts();
    }

    bool Counts::operator>(Counts a) const {
        return this->GetCounts() > a.GetCounts();
    }
}