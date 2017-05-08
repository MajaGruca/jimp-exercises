//
// Created by ktr on 04.05.2017.
//

#ifndef JIMP_EXERCISES_MOVIESUBTITLES_H
#define JIMP_EXERCISES_MOVIESUBTITLES_H

#include <string>
#include <exception>
#include <memory>
#include <stdexcept>


namespace moviesubs
{
    class MovieSubtitles {

    public:
        MovieSubtitles();
        virtual ~MovieSubtitles();

        virtual void ShiftAllSubtitlesBy(int delay, int fps,std::stringstream *in, std::stringstream *out);

    };


    class MicroDvdSubtitles : public MovieSubtitles{

    public:
        MicroDvdSubtitles();
        virtual ~MicroDvdSubtitles();

        virtual void ShiftAllSubtitlesBy(int delay, int fps,std::stringstream *in, std::stringstream *out);
    };

    class SubRipSubtitles : public MovieSubtitles {

    public:
        SubRipSubtitles();
        virtual ~SubRipSubtitles();

        virtual void ShiftAllSubtitlesBy(int delay, int fps,std::stringstream *in, std::stringstream *out);
    };


    class MovieSubtitlesError : public std::runtime_error
    {
    public:
        MovieSubtitlesError(const std::string &str ) : std::runtime_error::runtime_error(str){

        }

       // MovieSubtitlesError(const std::string &__arg) : runtime_error(__arg) {};

    };
    class NegativeFrameAfterShift : public MovieSubtitlesError
    {
    public:
        NegativeFrameAfterShift();
    };
    class SubtitleEndBeforeStart : public MovieSubtitlesError
    {
    public:
        SubtitleEndBeforeStart();

    };
    class MissingTimeSpecification : public MovieSubtitlesError
    {
    public:
        MissingTimeSpecification();

    };
    class OutOfOrderFrames : public MovieSubtitlesError
    {
    public:
        OutOfOrderFrames();
    };
}


#endif //JIMP_EXERCISES_MOVIESUBTITLES_H
