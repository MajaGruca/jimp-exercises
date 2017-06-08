//
// Created by ktr on 06.06.2017.
//
#include <map>
#include <string>
#include <iostream>

#include "ArabicRoman.h"

int RomanToArabic(std::string wejscie) {
    std::map<std::string,int> arab ={{"I",1},{"V",5},{"X",10},{"L",50},{"C",100},{"D",500},{"M",1000}};
    std::string tab[7]={"M","D","C","L","X","V","I"};
    std::string przod,tyl;
    int wynik=0;
    int znalezione;
    int literka;
    if(!wejscie.length())
        return 0;
    bool ifoklitera= true;
    //std::cout<<wejscie;
    for(int i=0;i<7;i++)
    {
        znalezione = wejscie.find(tab[i]);
        if(znalezione!=std::string::npos)
        {
            literka=i;
            ifoklitera= false;
            //std::cout<<arab[tab[literka]]<<" znalezione "<<znalezione<<std::endl;
            break;
        }
    }


    if(wejscie.length()==1)
        return arab[tab[literka]];
    if(znalezione>0 && znalezione<wejscie.length())
    {
        wynik=wynik+arab[tab[literka]]-RomanToArabic(wejscie.substr(0,znalezione))+RomanToArabic(wejscie.substr(znalezione+1,wejscie.length()-znalezione+1));
    }
    if(znalezione==0)
        wynik=wynik+arab[tab[literka]]+RomanToArabic(wejscie.substr(1,wejscie.length()-1));
    if(znalezione==wejscie.length())
        wynik=wynik+arab[tab[literka]]-RomanToArabic(wejscie.substr(0,wejscie.length()-1));



    return wynik;
}

std::string ArabicToRoman(int a) {

    return "nic";
}
