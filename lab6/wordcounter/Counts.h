//
// Created by ktr on 10.04.2017.
//

#ifndef JIMP_EXERCISES_COUNTS_H
#define JIMP_EXERCISES_COUNTS_H

namespace datastructures {
    class Counts {
    public:


        Counts();

        Counts(int count);


        void operator++();

        void operator--();

        bool operator<(Counts a) const;

        bool operator<=(Counts a) const;

        bool operator>(Counts a) const;

        bool operator>=(Counts a) const;

        bool operator==(Counts a) const;

        bool operator==(int a) const;

        bool operator!=(Counts a) const;

        bool operator!=(int a) const;

        int operator+(Counts a) const;

        int operator+(int a) const;


        int GetCounts() const;

    private:

        int wordcount;
    };
}


#endif //JIMP_EXERCISES_COUNTS_H
