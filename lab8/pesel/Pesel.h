//
// Created by ktr on 25.04.2017.
//

#ifndef JIMP_EXERCISES_PESEL_H
#define JIMP_EXERCISES_PESEL_H

#include <string>
#include <exception>
#include <stdexcept>
namespace academia{
    class Pesel {

    public:
       // Pesel();
        Pesel(const char *str);
        ~Pesel();
    };
    class AcademiaDataValidationError : public std::runtime_error{

    public:
        AcademiaDataValidationError(const std::string &m) : std::runtime_error::runtime_error(m){
            //std::cerr <<
        }
    };
    class InvalidPeselLength : public AcademiaDataValidationError{
    public:
        InvalidPeselLength();
    };
    class InvalidPeselCharacter: public AcademiaDataValidationError{
    public:
        InvalidPeselChecksum();
    };
    class InvalidPeselChecksum : public AcademiaDataValidationError{
    public:
        InvalidPeselChecksum(const char  aa, int a);
    };

    //validatePESEL(const char* a);
}


#endif //JIMP_EXERCISES_PESEL_H
