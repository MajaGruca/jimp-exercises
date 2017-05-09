//
// Created by ktr on 09.05.2017.
//

#include "Serialization.h"
namespace academia
{

    void Building::Serialize(Serializer *item) const {
        item->Header("building");
        item->IntegerField("id", id_);
        item->StringField("name", number_);
        item->ArrayField("rooms", room_);
        item->Footer("building");

    }

    void Room::Serialize(Serializer *item) const {

        item->Header("room");
        item->IntegerField("id", id_);
        item->StringField("name", number_);
        item->StringField("type", TypeToString(classroom_));
        item->Footer("room");
    }

    std::string Room::TypeToString(Room::Type type) const {
        return std::string();
    }
}