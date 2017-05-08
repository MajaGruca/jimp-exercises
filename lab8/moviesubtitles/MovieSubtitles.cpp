//
// Created by ktr on 04.05.2017.
//

#include "MovieSubtitles.h"
#include <iostream>
#include <string>
#include <regex>
namespace moviesubs {


    MicroDvdSubtitles::MicroDvdSubtitles() {}

    MicroDvdSubtitles::~MicroDvdSubtitles() {}

    void MicroDvdSubtitles::ShiftAllSubtitlesBy(int delay, int fps, std::stringstream *in, std::stringstream *out) {

        if(fps<=0)
            throw MovieSubtitlesError("Invalid Framerate");
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

    MovieSubtitles::MovieSubtitles() {}

    MovieSubtitles::~MovieSubtitles() {}

    void MovieSubtitles::ShiftAllSubtitlesBy(int delay, int fps, std::stringstream *in, std::stringstream *out) {}

    SubRipSubtitles::SubRipSubtitles() {}

    SubRipSubtitles::~SubRipSubtitles() {}

    void SubRipSubtitles::ShiftAllSubtitlesBy(int delay, int fps, std::stringstream *in, std::stringstream *out) {

        int flag=1;
        std::string pom = in->str();
        if(pom[pom.length()-2]=='\n')
            flag=0;
        std::smatch mm;
        std::smatch mmm;
        std::regex ee("[0-9]+");
        std::string linijka_pom;
        std::string tab_pom1[8];
        int line_num = 0;
        int line_numb=0;
        std::vector<int> order;
        if(fps<=0)
            throw MovieSubtitlesError("Invalid Framerate");
        while (pom.length() > 0) {
            std::size_t pos = pom.find("\n");
            line_num++;
            if (pos > pom.length()) {
                pos = pom.length();
            }
            std::string linijka = pom.substr(0, pos);
            pom = pom.erase(0, pos + 1);
            //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

            if (std::regex_match(linijka, std::regex("([0-9]{2}:){2}([0-9]{2},[0-9]{3})([[:space:]]-->[[:space:]])([0-9]{2}:){2}([0-9]{2},[0-9]{3})"))) {
                line_numb++;
                linijka_pom = linijka;
                double time1=0,time2=0;
                for (int j = 0; j < 8; j++) {
                    std::regex_search(linijka_pom, mm, ee);
                    for (auto x:mm) tab_pom1[j] = x;
                    linijka_pom = mm.suffix().str();
                }
                time1=stoi(tab_pom1[0])*3600+stoi(tab_pom1[1])*60+stoi(tab_pom1[2])+stoi(tab_pom1[3])*0.001;
                time2=stoi(tab_pom1[4])*3600+stoi(tab_pom1[5])*60+stoi(tab_pom1[6])+stoi(tab_pom1[7])*0.001;
                if (time1 + delay*0.001< 0)
                    throw NegativeFrameAfterShift();
                if (time1 > time2)
                    throw SubtitleEndBeforeStart(line_numb, linijka);
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
                    if(tab_pom1[t].length() != 3) {
                        tab_pom1[t] = "0" + tab_pom1[t];
                    }
                    for (int j = 0; j < 3; j++) {
                        if (tab_pom1[t - j - 1].length() != 2)
                            tab_pom1[t - j - 1] = "0" + tab_pom1[t - j - 1];
                    }
                }
                *out << std::regex_replace(linijka, std::regex("([0-9]{2}:){2}([0-9]{2},[0-9]{3})([[:space:]]-->[[:space:]])([0-9]{2}:){2}([0-9]{2},[0-9]{3})"),
                                           tab_pom1[0] + ":" + tab_pom1[1] + ":" + tab_pom1[2] + "," + tab_pom1[3] +
                                               " --> " + tab_pom1[4] + ":" + tab_pom1[5] + ":" + tab_pom1[6] + "," +
                                               tab_pom1[7]) << '\n';
            } else
            {

                if (std::regex_search(linijka, std::regex("([0-9]{2}:)")))
                    throw  InvalidSubtitleLineFormat();
                else
                {
                    if (std::regex_search(linijka, std::regex("([0-9])")))
                        order.push_back(stoi(linijka));
                }
                for(int k=0;k<order.size()-1;k++)
                {
                    if(order[k]+1!=order[k+1])
                        throw OutOfOrderFrames();
                }
                *out << linijka << '\n';
                if(pom.length()==0 && flag)
                    *out << '\n';
            }
        }
    }

    NegativeFrameAfterShift::NegativeFrameAfterShift() : MovieSubtitlesError("NegativeFrameAfterShift") {}

    SubtitleEndBeforeStart::SubtitleEndBeforeStart(int line_num, std::string line) : MovieSubtitlesError(
            "At line " + std::to_string(line_num) + ": " + line) {
        this->line_number=line_num;
    }

    int SubtitleEndBeforeStart::LineAt() const {
        return this->line_number;
    }

    MissingTimeSpecification::MissingTimeSpecification() : MovieSubtitlesError("MissingTimeSpecification") {}

    OutOfOrderFrames::OutOfOrderFrames() : MovieSubtitlesError("OutOfOrderFrames") {    }

    InvalidSubtitleLineFormat::InvalidSubtitleLineFormat() : MovieSubtitlesError("InvalidSubtitleLineFormat") {}

}