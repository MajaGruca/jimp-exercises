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
        std::smatch mmm;
        std::regex ee ("[0-9]+");
        std::regex eee ("([0-9]{2}:){2}([0-9]{2},[0-9]{3})");
        std::string linijka_pom;
        std::string temp;
        int tab_pom[2];
        std::string tab_pom1[8];

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
                        tab_pom[j]=tab_pom[j]+(int)dodanie_o;
                        if(tab_pom[j]<0)
                            throw NegativeFrameAfterShift();
                        linijka_pom=mm.suffix().str();
                    }

                }
                *out<<std::regex_replace (linijka,std::regex("\\{[0-9]+\\}\\{[0-9]+\\}") ,"{"+std::to_string(tab_pom[0])+"}{"+std::to_string(tab_pom[1])+"}")<<'\n';
            }
            else
            {
                if(std::regex_match (linijka, std::regex("([0-9]{2}:){2}([0-9]{2},[0-9]{3})([[:space:]]-->[[:space:]])([0-9]{2}:){2}([0-9]{2},[0-9]{3})") ))
                {

                    linijka_pom=linijka;
                    for (int j=0;j<8;j++)
                    {
                        std::regex_search (linijka_pom,mm,ee);
                        for (auto x:mm) tab_pom1[j]=x;
                        linijka_pom=mm.suffix().str();
                    }
                    int t=3;
                    for(int a=0;a<2;a++)
                    {
                        if(a==1) t=7;
                        tab_pom1[t]=std::to_string(stoi(tab_pom1[t])+delay);
                        if(stoi(tab_pom1[t])/1000)
                        {
                            tab_pom1[t-1]=std::to_string(stoi(tab_pom1[t-1]) + stoi(tab_pom1[t]) / 1000);
                            tab_pom1[t]=std::to_string(stoi(tab_pom1[t])%1000);
                            if(stoi(tab_pom1[t - 1]) / 60)
                            {
                                tab_pom1[t-2]=std::to_string(stoi(tab_pom1[t-2]) + stoi(tab_pom1[t - 1]) / 60);
                                tab_pom1[t-1]=std::to_string(stoi(tab_pom1[t-1])%60);
                                if(stoi(tab_pom1[t - 2]) / 60)
                                {
                                    tab_pom1[t-3]=std::to_string(stoi(tab_pom1[t-3]) + stoi(tab_pom1[t - 2]) / 60);
                                    tab_pom1[t-2]=std::to_string(stoi(tab_pom1[t-2])%60);
                                }
                            }
                        }
                        while (tab_pom1[t].length()!=3)
                        {
                            tab_pom1[t]="0"+tab_pom1[t];
                        }
                        for(int j=0;j<3;j++)
                        {
                            if(tab_pom1[t-j-1].length()!=2)
                                tab_pom1[t-j-1]="0"+tab_pom1[t-j-1];
                        }
                    }
                    *out<<std::regex_replace (linijka,std::regex("([0-9]{2}:){2}([0-9]{2},[0-9]{3})([[:space:]]-->[[:space:]])([0-9]{2}:){2}([0-9]{2},[0-9]{3})") ,tab_pom1[0]+":"+tab_pom1[1]+":"+tab_pom1[2]+","+tab_pom1[3]+" --> "+tab_pom1[4]+":"+tab_pom1[5]+":"+tab_pom1[6]+","+tab_pom1[7])<<'\n';
                }
                else *out<<linijka<<'\n';
            }


        }

    }

    SubRipSubtitles::SubRipSubtitles() {

    }

    SubRipSubtitles::~SubRipSubtitles() {

    }

    void SubRipSubtitles::ShiftAllSubtitlesBy(int delay, int fps, std::stringstream *in, std::stringstream *out) {
        MovieSubtitles::ShiftAllSubtitlesBy(delay, fps, in, out);
    }

    NegativeFrameAfterShift::NegativeFrameAfterShift() : MovieSubtitlesError("NegativeFrameAfterShift"){
    }
    SubtitleEndBeforeStart::SubtitleEndBeforeStart() : MovieSubtitlesError("SubtitleEndBeforeStart"){
    }
    MissingTimeSpecification::MissingTimeSpecification() : MovieSubtitlesError("MissingTimeSpecification"){
    }
    OutOfOrderFrames::OutOfOrderFrames() : MovieSubtitlesError("OutOfOrderFrames"){
    }
}