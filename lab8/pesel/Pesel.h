//
// Created by ktr on 25.04.2017.
//

#ifndef JIMP_EXERCISES_PESEL_H
#define JIMP_EXERCISES_PESEL_H

#include <string>
#include <exception>
#include <iostream>

namespace academia{
    class Pesel {

    public:
       // Pesel();
        Pesel(std::string pesel);
        virtual ~Pesel();

    private:
        std::string pesel;
    };


    class AcademiaDataValidationError : public std::runtime_error{

    public:
        AcademiaDataValidationError(const std::string &pesel ) : std::runtime_error::runtime_error(pesel){

        };
    };


    class InvalidPeselLength: public AcademiaDataValidationError{
    public:
        InvalidPeselLength(std::string pesel, int pesel_lenght);
    };

    class InvalidPeselCharacter: public AcademiaDataValidationError {
    public:
        InvalidPeselCharacter(std::string pesel);
    };

    class InvalidPeselChecksum: public AcademiaDataValidationError
    {
    public:
        InvalidPeselChecksum(std::string pesel, int check_sum);
    };
}


#endif //JIMP_EXERCISES_PESEL_H
