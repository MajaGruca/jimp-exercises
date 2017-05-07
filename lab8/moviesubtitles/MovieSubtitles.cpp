//
// Created by ktr on 04.05.2017.
//

#include "MovieSubtitles.h"
#include <iostream>
#include <string>
#include <regex>
namespace moviesubs
{


    MicroDvdSubtitles::MicroDvdSubtitles() {


    }

    MicroDvdSubtitles::~MicroDvdSubtitles() {

    }

    void MicroDvdSubtitles::ShiftAllSubtitlesBy(int delay, int fps, std::stringstream *in, std::stringstream *out) {
        MovieSubtitles::ShiftAllSubtitlesBy(delay, fps, in, out);
    }


    MovieSubtitles::MovieSubtitles() {

    }

    MovieSubtitles::~MovieSubtitles() {

    }

    void MovieSubtitles::ShiftAllSubtitlesBy(int delay, int fps, std::stringstream *in, std::stringstream *out) {
        std::string pom=in->str();
        double dodanie_o =((double)delay/1000)*fps;
        std::smatch mm;
        std::regex ee ("[0-9]+");
        std::string linijka_pom;
        int tab_pom[2];

        while(pom.length()>0)
        {std::size_t pos = pom.find("\n");
            if(pos>pom.length())
            {
                pos=pom.length();
            }
            std::string linijka = pom.substr (0,pos);
            pom=pom.erase(0,pos+1);
            //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

            if (std::regex_match (linijka, std::regex("(\\{[0-9]+\\}\\{[0-9]+\\})(.*)") ))
            {


                for (int i=0;i<2;i++)
                {
                    linijka_pom=linijka;
                    for (int j=0;j<2;j++)
                    {
                        std::regex_search (linijka_pom,mm,ee);
                        for (auto x:mm) tab_pom[j]=stoi(x);//std::cout<<x<<" ";
                        linijka_pom=mm.suffix().str();
                    }

                }
                *out<<std::regex_replace (linijka,std::regex("\\{[0-9]+\\}\\{[0-9]+\\}") ,"{"+std::to_string(tab_pom[0]+(int)dodanie_o)+"}{"+std::to_string(tab_pom[1]+(int)dodanie_o)+"}")<<'\n';
            }


        }

    }
}