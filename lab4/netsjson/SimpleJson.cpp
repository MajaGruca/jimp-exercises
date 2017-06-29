//
// Created by maj3 on 27.03.17.
//
#include "SimpleJson.h"
#include <regex>
namespace nets {

    std::string AddBackslash(std::string str)
    {
        std::string temp = "";
        for(int i = 0;i<str.length();i++)
        {
            if(str[i]=='\\' || str[i] == '\"')
                temp+='\\';
            temp+=str[i];
        }
        return temp;
    }

    JsonValue::JsonValue(int a) {
        int_ = a;
        constructor = 1;
    }

    JsonValue::JsonValue(double a) {
        dou_ = a;
        constructor = 2;
    }

    JsonValue::JsonValue(bool a) {
        boo_ = a;
        constructor = 3;
    }

    JsonValue::~JsonValue(){
        map_.clear();
    }

    JsonValue::JsonValue(std::string a){
        str_=a;
        constructor = 4;
    }

    JsonValue::JsonValue(std::vector<JsonValue> a) {
        vec_ = a;
        constructor = 5;
    }

    JsonValue::JsonValue(std::map<std::string, JsonValue> a) {
        map_ = a;
        constructor = 6;
    }

    std::string JsonValue::ToString() const {
        switch (this->constructor) {
            case 1:
                return std::to_string(int_);
            case 2: {
                std::string temp = std::to_string(dou_);
                int i = temp.size()-1;
                while (temp[i] == '0') {
                    temp.pop_back();
                    i--;
                }
                return temp;
            }
            case 3:
                if (boo_ )
                    return "true";
                else
                    return "false";
            case 4: {
                std::string temp = "\"";
                temp+=AddBackslash(str_);
                temp+='\"';
                return temp;
                }
            case 5: {
                std::string temp="[";
                for (auto n=0;n<vec_.size(); n++) {
                    temp.append(vec_[n].ToString());
                    if(n!=vec_.size()-1)
                        temp.append(", ");
                    else
                        temp.append("]");
                }
                return temp;
            }
            case 6: {
               std::string data = "{\"";
                for (auto &n : map_) {
                    data += AddBackslash(n.first);
                    data += "\": "+n.second.ToString()+", \"";
                }
                data[data.size()-3]='}';
                data.pop_back();
                data.pop_back();
                return data;
            }
            default:
                break;
            }
        }

    std::experimental::optional<JsonValue> JsonValue::ValueByName(const std::string &name) const{
        for (auto &n: map_) {
            if (n.first == name)
                return n.second;
        }
    }
}