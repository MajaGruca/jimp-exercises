//
// Created by ktr on 29.05.2017.
//

#ifndef JIMP_EXERCISES_SEQUENTIALGENERATOR_H
#define JIMP_EXERCISES_SEQUENTIALGENERATOR_H

template <class TID,class C>
class SequentialIdGenerator {
public:
    SequentialIdGenerator():iffirst(true),counter(0){}
    SequentialIdGenerator(C cos):iffirst(true),counter(cos){}
    TID NextValue(){
        if(!iffirst){++counter;}
        iffirst=false;
        return TID (counter);}
private:
    bool iffirst;
    C counter;
};


#endif //JIMP_EXERCISES_SEQUENTIALGENERATOR_H
