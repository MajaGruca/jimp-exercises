//
// Created by ktr on 14.03.2017.
//

#include "MinimalTimeDifference.h"
#include <sstream>
#include <regex>
#include <cmath>


namespace minimaltimedifference {
    unsigned int ToMinutes(std::string time_HH_MM) {
        std::regex tominute{R"((\d{1,2}):(\d{2}))"};
        std::smatch matches;
        if(std::regex_match(time_HH_MM, matches, tominute))
        {
            return stoi(matches[1])*60+stoi(matches[2]);

        } else return 0;
    }

    unsigned int MinimalTimeDifference(std::vector<std::string> times)
    {
        unsigned int min_differenc=1441;
        unsigned int diff;

        for(int i=0;i<times.size()-1;i++)
        {
            for(int j=i+1;j<times.size();j++)

            {

                diff=abs(ToMinutes(times[i])-ToMinutes(times[j]));
                if (std::min(diff,1440-diff)<min_differenc)
                {
                    min_differenc=std::min(diff,1440-diff);
                }
            }
        }
        return min_differenc;
    }
}
