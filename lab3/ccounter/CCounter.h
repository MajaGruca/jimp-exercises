//
// Created by ktr on 14.03.2017.
//

#ifndef JIMP_EXERCISES_CCOUNTER_H
#define JIMP_EXERCISES_CCOUNTER_H


std::unique_ptr<Counter> Init();
void Inc(std::string key, std::unique_ptr<Counter> counter);
int Counts(const std::unique_ptr<Counter> &counter, std::string key);
void SetCountsTo(std::string key, int value, std::unique_ptr<Counter> *counter);

#endif //JIMP_EXERCISES_CCOUNTER_H
