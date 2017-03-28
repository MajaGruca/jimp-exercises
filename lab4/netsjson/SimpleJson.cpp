//
// Created by maj3 on 27.03.17.
//
#include "SimpleJson.h"
namespace nets {


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

    JsonValue::JsonValue(std::string a){
       /* for(int i=0;i<a.size();i++)
        {
            str_.push_back(a[i]);
        }*/
        std::string cos = a;
        for (int i=0; i < cos.length(); i++){
            if (cos[i]=='\"' || cos[i]=='\\'){
                cos.insert(i, 1,'\\');
                i++;
            }
        }
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
                std::string temp1 = std::to_string(dou_);
                std::string temp2;
                int i = 0;
                while (temp1[i] != '0') {
                    temp2.push_back(temp1[i]);
                    i++;
                }
                return temp2;
            }

            case 3:
                if (boo_ )//== true)
                    return "true";
                else
                    return "false";
            case 4: {
                std::string temp;
                //for (auto n: str_) {
                 //   temp.push_back(n);
                 //   }

                return "\"" + str_ + "\"";
                //return temp;
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
                /*std::string temp;
                for (auto &n: this->map_) {
                    temp.append(n.second.ToString());
                }
                return temp;*/
                std::string data = "{";
                for (auto &n : this->map_) {
                    std::string cos = n.first;
                    for (int i=0;i<cos.length();i++){
                        if (cos[i]=='\"' || cos[i]=='\\'){
                            cos.insert(i, 1,'\\');
                            i++;
                        }
                    }
                    data = data+"\""+cos+"\": "+n.second.ToString()+", ";
                }
                data[data.size()-2]='}';
                data.pop_back();
                return data;
            }
            default:
                break;
            }

        }
    std::experimental::optional<JsonValue> JsonValue::ValueByName(const std::string &name) const {

            for (auto &n: map_) {
                if (n.first == name)
                    return n.second;//std::experimental::make_optional(map_.at(name));
                //else
                  //  return {};
            }

            //if(map_.at(name)) {
            // std::experimental::optional<JsonValue> temp = map_.at(name).ToString();
            // return temp;
            //}
    }
}