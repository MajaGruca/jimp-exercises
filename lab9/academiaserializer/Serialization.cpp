//
// Created by ktr on 09.05.2017.
//

#include "Serialization.h"
namespace academia
{

    void Building::Serialize(Serializer *item) const {
        item->Header("building");
        item->IntegerField("id", id_);
        item->StringField("name", nr_);
        item->ArrayField("rooms", room_);
        item->Footer("building");

    }

    void Room::Serialize(Serializer *item) const {

        item->Header("room");
        item->IntegerField("id", id_);
        item->StringField("name", nr_);
        item->StringField("type", TypeToString(classroom_));
        item->Footer("room");
    }

    std::string Room::TypeToString(Room::Type type) const {
        switch(type){
            case Type::CLASSROOM:
                return "CLASSROOM";
            case Type::COMPUTER_LAB:
                return "COMPUTER_LAB";
            case Type::LECTURE_HALL:
                return "LECTURE_HALL";
        }
    }

    void JsonSerializer::IntegerField(const std::string &field_name, int value) {
        *out_<<"\""<<field_name<<"\": "<<std::to_string(value)<<", ";
    }

    void JsonSerializer::DoubleField(const std::string &field_name, double value) {
        *out_<<"\""<<field_name<<"\": "<<std::to_string(value)<<", ";
    }

    void JsonSerializer::StringField(const std::string &field_name, const std::string &value) {
        *out_<<"\""<<field_name<<"\": \""<<value<<"\"";
        if (field_name!="type")
            *out_<<", ";
    }

    void JsonSerializer::BooleanField(const std::string &field_name, bool value) {
        *out_<<"\""<<field_name<<"\": "<<std::to_string(value)<<", ";
    }

    void JsonSerializer::SerializableField(const std::string &field_name, const academia::Serializable &value) {
        *out_<<field_name;
    }

    void JsonSerializer::ArrayField(const std::string &field_name,
                                    const std::vector<std::reference_wrapper<const academia::Serializable>> &value) {
        *out_<<"\""<<field_name<<"\": [";
        for (auto &i: value)
        { break;}

            //*out_ << i << ' ';




        *out_<<"]";
    }

    void JsonSerializer::Header(const std::string &object_name) {
        *out_<<"{";
    }

    void JsonSerializer::Footer(const std::string &object_name) {
        *out_<<"}";
    }
}