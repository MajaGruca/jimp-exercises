//
// Created by maj3 on 27.03.17.
//

#ifndef JIMP_EXERCISES_SIMPLEJSON_H
#define JIMP_EXERCISES_SIMPLEJSON_H
#include <experimental/optional>
#include <string>
#include <iostream>
#include "vector"
#include "map"
namespace nets{

    enum SupportedType{
        INT,
        DOUBLE,
        BOOL
    };

    class JsonValue{
    public:

        JsonValue(int a);
        JsonValue(double a);
        JsonValue(std::string a);
        JsonValue(bool a);
        JsonValue(std::vector<JsonValue> a);
        JsonValue(std::map<std::string,JsonValue> a);
        ~JsonValue();
        std::string ToString() const;
        void GetBoo() const;
        std::experimental::optional<JsonValue> ValueByName(const std::string &name) const;
    private:
        int int_;
        double dou_;
        std::string str_;
        bool boo_;
        std::vector<JsonValue> vec_;
        std::map<std::string,JsonValue> map_;
        int constructor;
    };
}

#endif //JIMP_EXERCISES_SIMPLEJSON_H
