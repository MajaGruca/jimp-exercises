//
// Created by ktr on 25.04.2017.
//

#include "Pesel.h"
#include <string>
namespace academia
{


    Pesel::Pesel(std::string pesel) {
        if (pesel.length()!=11) throw InvalidPeselLength(pesel,pesel.length());

        for (int i=0; i<11;i++)
        {
            if (!isdigit(pesel[i])) throw InvalidPeselCharacter(pesel);
        }

        int sum=0;
        int temp_tab[11]={9,7,3,1,9,7,3,1,9,7};

        for(int i=0;i<10;i++)
        {
            sum=sum+(pesel[i]-'0')*temp_tab[i];
        }
        if (pesel[10]-'0'!=sum%10) throw InvalidPeselChecksum(pesel,sum);

    }

    Pesel::~Pesel() {

    }

    InvalidPeselLength::InvalidPeselLength(std::string pesel, int pesel_lenght) : AcademiaDataValidationError("Invalid PESEL("+pesel+") length: "+std::to_string(pesel_lenght) ){

    }

    InvalidPeselCharacter::InvalidPeselCharacter(std::string pesel) : AcademiaDataValidationError("Invalid PESEL("+pesel+") character set"){

    }

    InvalidPeselChecksum::InvalidPeselChecksum(std::string pesel, int check_sum) : AcademiaDataValidationError("Invalid PESEL("+pesel+") checksum: "+std::to_string(check_sum)){

    }
}