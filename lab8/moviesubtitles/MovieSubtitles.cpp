//
// Created by ktr on 04.05.2017.
//

#include "MovieSubtitles.h"
#include <iostream>
#include <string>
#include <regex>
#include <stdexcept>
namespace moviesubs {


    MicroDvdSubtitles::MicroDvdSubtitles() {

    }

    MicroDvdSubtitles::~MicroDvdSubtitles() {

    }

    void MicroDvdSubtitles::ShiftAllSubtitlesBy(int delay, int fps, std::stringstream *in, std::stringstream *out) {

        if(fps<=0)
            throw std::invalid_argument("Invalid argument");
        std::string pom = in->str();
        double dodanie_o = ((double) delay / 1000) * fps;
        std::smatch mm;
        std::regex ee("[0-9]+");
        std::string linijka_pom;
        int tab_pom[2];
        int line_num = 0;



        while (pom.length() > 0) {
            std::size_t pos = pom.find("\n");
            line_num++;

            if (pos > pom.length()) {
                pos = pom.length();
            }
            std::string linijka = pom.substr(0, pos);
            pom = pom.erase(0, pos + 1);
            //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
            if (std::regex_match(linijka, std::regex("(\\{[0-9]+\\}\\{[0-9]+\\})(.*)"))) {
                linijka_pom = linijka;
                for (int j = 0; j < 2; j++) {
                    std::regex_search(linijka_pom, mm, ee);
                    for (auto x:mm) tab_pom[j] = stoi(x);
                    tab_pom[j] = tab_pom[j] + (int) dodanie_o;
                    if (tab_pom[j] < 0)
                        throw NegativeFrameAfterShift();
                    linijka_pom = mm.suffix().str();
                }
                if (tab_pom[0] > tab_pom[1])
                    throw SubtitleEndBeforeStart(line_num, linijka);
                *out << std::regex_replace(linijka, std::regex("\\{[0-9]+\\}\\{[0-9]+\\}"),
                                           "{" + std::to_string(tab_pom[0]) + "}{" + std::to_string(tab_pom[1]) + "}")
                     << '\n';
            } else {
                throw InvalidSubtitleLineFormat();
            }
        }


    }


    MovieSubtitles::MovieSubtitles() {

    }

    MovieSubtitles::~MovieSubtitles() {

    }

    void MovieSubtitles::ShiftAllSubtitlesBy(int delay, int fps, std::stringstream *in, std::stringstream *out) {
    }

    SubRipSubtitles::SubRipSubtitles() {

    }

    SubRipSubtitles::~SubRipSubtitles() {

    }

    void SubRipSubtitles::ShiftAllSubtitlesBy(int delay, int fps, std::stringstream *in, std::stringstream *out) {

        if(fps<=0) {
            throw std::invalid_argument("Ivalid argument");
        }
        std::string pom = in->str();
        std::smatch mm;
        std::smatch mmm;
        std::regex ee("[0-9]+");
        std::string linijka_pom;
        std::string tab_pom1[8];
        int line_num = 0;
        int zmienna=0;
        int stara_zmienna=0;

        while (pom.length() > 0) {
            std::size_t pos = pom.find("\n\n");
            line_num++;

            if (pos > pom.length()) {
                pos = pom.length();
            }
            std::string linijka = pom.substr(0, pos+1);
            pom = pom.erase(0, pos + 2);
            //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

            if (std::regex_match(linijka, std::regex("([0-9]+\n)([0-9]{2}:){2}([0-9]{2},[0-9]{3})([[:space:]]-->[[:space:]])([0-9]{2}:){2}([0-9]{2},[0-9]{3})((\n.*)+[\n]{1,2})"))) {
                linijka_pom = linijka;
                for (int j = -1; j < 8; j++) {

                    std::regex_search(linijka_pom, mm, ee);
                    if(j>=0)
                    {
                        for (auto x:mm) tab_pom1[j] = x;
                    }
                    if(j==-1)
                    {
                        for (auto x:mm) zmienna = stoi(x);
                        if(zmienna-stara_zmienna!=1)
                            throw OutOfOrderFrames();
                        stara_zmienna=zmienna;
                    }
                    linijka_pom = mm.suffix().str();
                }
                int t = 3;
                for (int a = 0; a < 2; a++) {
                    if (a == 1) t = 7;
                    tab_pom1[t] = std::to_string(stoi(tab_pom1[t]) + delay);
                    if (stoi(tab_pom1[t]) / 1000) {
                        tab_pom1[t - 1] = std::to_string(stoi(tab_pom1[t - 1]) + stoi(tab_pom1[t]) / 1000);
                        tab_pom1[t] = std::to_string(stoi(tab_pom1[t]) % 1000);
                        if (stoi(tab_pom1[t - 1]) / 60) {
                            tab_pom1[t - 2] = std::to_string(stoi(tab_pom1[t - 2]) + stoi(tab_pom1[t - 1]) / 60);
                            tab_pom1[t - 1] = std::to_string(stoi(tab_pom1[t - 1]) % 60);
                            if (stoi(tab_pom1[t - 2]) / 60) {
                                tab_pom1[t - 3] = std::to_string(
                                        stoi(tab_pom1[t - 3]) + stoi(tab_pom1[t - 2]) / 60);
                                tab_pom1[t - 2] = std::to_string(stoi(tab_pom1[t - 2]) % 60);
                            }
                        }
                    }

                    for(int z=0;z<4;z++)
                    {
                        if(stoi(tab_pom1[z])<0)
                        {
                            throw NegativeFrameAfterShift();
                        }
                    }

                    while (tab_pom1[t].length() != 3) {
                        tab_pom1[t] = "0" + tab_pom1[t];
                    }
                    for (int j = 0; j < 3; j++) {
                        if (tab_pom1[t - j - 1].length() != 2)
                            tab_pom1[t - j - 1] = "0" + tab_pom1[t - j - 1];
                    }
                }
                for (int z = 0; z < 4; z++) {
                    if (tab_pom1[z] > tab_pom1[z + 4])
                        //std::cout<<"subtitles end before strat";
                    { throw SubtitleEndBeforeStart(line_num, linijka.substr(2, linijka.length() - 6)); }
                    if (tab_pom1[z] < tab_pom1[z + 4])
                        break;
                }
                //f(line_num!=1)
                //    *out<<"\n";
                *out << std::regex_replace(linijka, std::regex("([0-9]{2}:){2}([0-9]{2},[0-9]{3})([[:space:]]-->[[:space:]])([0-9]{2}:){2}([0-9]{2},[0-9]{3})"),
                                           tab_pom1[0] + ":" + tab_pom1[1] + ":" + tab_pom1[2] + "," + tab_pom1[3] +
                                           " --> " + tab_pom1[4] + ":" + tab_pom1[5] + ":" + tab_pom1[6] + "," +
                                           tab_pom1[7]) << '\n';
            } else throw InvalidSubtitleLineFormat();


        }



    }

    NegativeFrameAfterShift::NegativeFrameAfterShift() : MovieSubtitlesError("NegativeFrameAfterShift") {
    }

    SubtitleEndBeforeStart::SubtitleEndBeforeStart(int line_num, std::string line) : MovieSubtitlesError(
            "At line " + std::to_string(line_num) + ": " + line) {

        this->line_number=line_num;
    }

    int SubtitleEndBeforeStart::LineAt() const {
        return this->line_number;
    }

    MissingTimeSpecification::MissingTimeSpecification() : MovieSubtitlesError("MissingTimeSpecification") {
    }

    OutOfOrderFrames::OutOfOrderFrames() : MovieSubtitlesError("OutOfOrderFrames") {
    }

    InvalidSubtitleLineFormat::InvalidSubtitleLineFormat() : MovieSubtitlesError("InvalidSubtitleLineFormat") {

    }

}