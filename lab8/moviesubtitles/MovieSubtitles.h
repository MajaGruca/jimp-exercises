//
// Created by ktr on 04.05.2017.
//

#ifndef JIMP_EXERCISES_MOVIESUBTITLES_H
#define JIMP_EXERCISES_MOVIESUBTITLES_H

#include <string>
#include <exception>


namespace moviesubs
{
    class MicroDvdSubtitles {

    public:
        std::string ShiftAllSubtitlesBy(int delay, int fps,const char* in, const char* out);

    };

    class SubRipSubtitles {



    };
    class MovieSubtitles {



    };
    class NegativeFrameAfterShift
    {

    };
    class SubtitleEndBeforeStart
    {

    };
    class InvalidSubtitleLineFormat
    {

    };
    class MissingTimeSpecification
    {

    };
    class OutOfOrderFrames
    {

    };
}


#endif //JIMP_EXERCISES_MOVIESUBTITLES_H
