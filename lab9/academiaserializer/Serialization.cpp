//
// Created by ktr on 09.05.2017.
//

#include "Serialization.h"
namespace academia
{

    void BuildingRepository::StoreAll(Serializer *item) const {
        std::vector<std::reference_wrapper<const Serializable>> v(building_.begin(), building_.end());
        item->Header("building_repository");
        item->ArrayField("buildings", v);
        item->Footer("building_repository");
    }
    std::experimental::optional<Building> BuildingRepository::operator[](int i) const
    {
        for(auto n: building_)
        {
            if(n.Id()==i)
                return n;
        }
    }
    void BuildingRepository::Add(Building a)
    {
        building_.emplace_back(a);
    }

    void Building::Serialize(Serializer *item) const {
        std::vector<std::reference_wrapper<const Serializable>> v(room_.begin(), room_.end());
        item->Header("building");
        item->IntegerField("id", id_);
        item->StringField("name", nr_);
        item->ArrayField("rooms", v);
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
        wypisz_przecinek();
        *out_<<"\""<<field_name<<"\": "<<std::to_string(value);
    }

    void JsonSerializer::DoubleField(const std::string &field_name, double value) {
        wypisz_przecinek();
        *out_<<"\""<<field_name<<"\": "<<std::to_string(value);
    }

    void JsonSerializer::StringField(const std::string &field_name, const std::string &value) {
        wypisz_przecinek();
        *out_<<"\""<<field_name<<"\": \""<<value<<"\"";
    }

    void JsonSerializer::BooleanField(const std::string &field_name, bool value) {
        wypisz_przecinek();
        *out_<<"\""<<field_name<<"\": "<<std::to_string(value);
    }

    void JsonSerializer::SerializableField(const std::string &field_name, const academia::Serializable &value) {
        wypisz_przecinek();
        *out_<<field_name;
    }

    void JsonSerializer::ArrayField(const std::string &field_name,
                                    const std::vector<std::reference_wrapper<const academia::Serializable>> &value) {
        wypisz_przecinek();
        *out_<<"\""<<field_name<<"\": [";
        is_first=true;
        for(const Serializable &i: value)
        {
            i.Serialize(this);
        }
        *out_<<"]";
    }

    void JsonSerializer::Header(const std::string &object_name) {
        if (!is_first)
          *out_<<", ";
        is_first= true;
        *out_<<"{";
    }

    void JsonSerializer::Footer(const std::string &object_name) {
        *out_<<"}";
    }

    void JsonSerializer::wypisz_przecinek() {
            if(!is_first)
            {
                *out_<<", ";
            } else
                is_first=false;
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

        for(const Serializable &i: value)
        {
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