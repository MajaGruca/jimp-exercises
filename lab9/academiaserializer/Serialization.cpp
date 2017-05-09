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
        for(const Serializable &i: value)
        {
            i.Serialize(this);
        }




        *out_<<"]";
    }

    void JsonSerializer::Header(const std::string &object_name) {
        *out_<<"{";
    }

    void JsonSerializer::Footer(const std::string &object_name) {
        *out_<<"}";
    }

    void XmlSerializer::IntegerField(const std::string &field_name, int value) {
        *out_<<"<"<<field_name<<">"<<std::to_string(value)<<"<\\"<<field_name<<">";
    }

    void XmlSerializer::DoubleField(const std::string &field_name, double value) {
        *out_<<"<"<<field_name<<">"<<std::to_string(value)<<"<\\"<<field_name<<">";
    }

    void XmlSerializer::StringField(const std::string &field_name, const std::string &value) {
        *out_<<"<"<<field_name<<">"<<value<<"<\\"<<field_name<<">";
    }

    void XmlSerializer::BooleanField(const std::string &field_name, bool value) {
        *out_<<"<"<<field_name<<">"<<std::to_string(value)<<"<\\"<<field_name<<">";
    }

    void XmlSerializer::SerializableField(const std::string &field_name, const academia::Serializable &value) {
        *out_<<"<"<<field_name<<">"<<"<\\"<<field_name<<">";
    }

    void XmlSerializer::ArrayField(const std::string &field_name,
                                   const std::vector<std::reference_wrapper<const academia::Serializable>> &value) {
        *out_<<"<"<<field_name<<">";
        int flag=0;
        for(const Serializable &i: value)
        {
            if(flag)
            {
                *out_<<", ";
            } else
               flag=1;
            i.Serialize(this);
        }

        *out_<<"<\\"<<field_name<<">";
    }

    void XmlSerializer::Header(const std::string &object_name) {
        *out_<<"<"<<object_name<<">";
    }

    void XmlSerializer::Footer(const std::string &object_name) {
        *out_<<"<\\"<<object_name<<">";

    }
}