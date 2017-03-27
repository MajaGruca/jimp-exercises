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
        std::string regex_str="";
        std::string str=GetStr();
        std::string temp;
        std::smatch matching_substring;
        for (auto n : model)
        {
            regex_str= "\\{\\{"+n.first +"\\}\\}";
            temp=str;
            while (std::regex_search (temp,matching_substring,std::regex(regex_str)))
            {
                temp = matching_substring.suffix().str();
                str=std::regex_replace(str,std::regex(regex_str),n.second);
            }
        }
        temp=str;
        regex_str="\\{\\{[A-Za-z0-9_]+\\}\\}";
        while (std::regex_search (temp,matching_substring,std::regex(regex_str)))
        {
            temp = matching_substring.suffix().str();
            str=std::regex_replace(str,std::regex(regex_str),"");
        }
        return str;
    }
}