//
// Created by ktr on 04.05.2017.
//
#include "MovieSubtitles.h"
#include <iostream>
#include <sstream>
using namespace moviesubs;
int main()
{

    moviesubs::SubRipSubtitles subs;
    //stringstream in {"1\n00:05:54,555 --> 00:05:56,722\nText\n\n2\n00:06:06,433 --> 00:06:07,801\nNEWLINE\n"};
    std::stringstream in {"1\n00:00:10,345 --> 00:00:12,678\nTEXT\n\n4\n00:19:14,141 --> 00:21:20,100\nTT\n"};
    std::stringstream out;
    subs.ShiftAllSubtitlesBy(1000, 24, &in, &out);
    //cout<<in.str()<<endl;
    std::cout<<out.str()<<std::endl;
    return 0;
}