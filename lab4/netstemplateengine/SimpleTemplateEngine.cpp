//
// Created by ktr on 27.03.2017.
//

#include "SimpleTemplateEngine.h"
#include <iostream>
#include <regex>

namespace nets
{
    View::View():str_(""){
    }

    View::View(std::string str){
        str_=str;
    }

    View::~View(){
    }
    std::string View::GetStr() const
    {
        return str_;
    }

    std::string View::Render(const std::unordered_map <std::string, std::string> &model) const
    {
        std::string str=GetStr();
        std::string temp=str;
        std::smatch matching_substring;
        std::string key,regex_key,result;
        while (std::regex_search (temp,matching_substring,std::regex("\\{\\{[A-Za-z0-9_]+\\}\\}")))

        {
            for (auto x:matching_substring) {key=x;}
            key.erase (0,2);
            key.erase (key.length()-2,2);
            auto it = model.find(key);
            regex_key="\\{\\{"+key+"\\}\\}";
            if (it != model.end())
            {
                str=std::regex_replace(temp,std::regex(regex_key),it->second);
                result=result+str;
                temp =matching_substring.suffix().str();
                temp=std::regex_replace(temp,std::regex(regex_key),it->second);

            }
            else
            {
                str=std::regex_replace(temp,std::regex(regex_key),"");
                result=result+str;
                temp =matching_substring.suffix().str();

            }

            if(result.length())
                result=result.erase(result.length()-temp.length(),temp.length());

        }
        result=result+temp;
        return result;
    }
}