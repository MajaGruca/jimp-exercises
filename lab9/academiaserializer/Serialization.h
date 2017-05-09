//
// Created by ktr on 09.05.2017.
//

#ifndef JIMP_EXERCISES_SERIALIZATION_H
#define JIMP_EXERCISES_SERIALIZATION_H

#include <iostream>
#include <string>
#include <vector>
#include <initializer_list>
#include <sstream>
#include <functional>

namespace academia
{

    class Serializable;


    class Serializer{
    public:
        Serializer(){}
        Serializer(std::ostream * out){out_=out;}
        virtual ~Serializer(){}

        virtual void IntegerField(const std::string &field_name, int value) =0;
        virtual void DoubleField(const std::string &field_name, double value) =0;
        virtual void StringField(const std::string &field_name, const std::string &value) =0;
        virtual void BooleanField(const std::string &field_name, bool value) =0;
        virtual void SerializableField(const std::string &field_name, const academia::Serializable &value) =0;
        virtual void ArrayField(const std::string &field_name, const std::vector<std::reference_wrapper<const academia::Serializable>> &value) =0;
        virtual void Header(const std::string &object_name) =0;
        virtual void Footer(const std::string &object_name) =0;
    protected:
        std::ostream *out_;
    };

    class Serializable{
    public:
        virtual void Serialize(Serializer* item) const =0;
    };

    class JsonSerializer : public Serializer{
    public:
        JsonSerializer(){}
        JsonSerializer(std::ostream * out):Serializer(out){}
        virtual ~JsonSerializer(){}

        virtual void IntegerField(const std::string &field_name, int value) override;
        virtual void DoubleField(const std::string &field_name, double value) override;
        virtual void StringField(const std::string &field_name, const std::string &value) override;
        virtual void BooleanField(const std::string &field_name, bool value) override;
        virtual void SerializableField(const std::string &field_name, const academia::Serializable &value) override;
        virtual void ArrayField(const std::string &field_name, const std::vector<std::reference_wrapper<const academia::Serializable>> &value) override;
        virtual void Header(const std::string &object_name) override;
        virtual void Footer(const std::string &object_name) override;

    };

    class XmlSerializer : public Serializer{
    public:
        XmlSerializer(){}
        XmlSerializer(std::ostream * out):Serializer(out){}
        virtual ~XmlSerializer(){}

        virtual void IntegerField(const std::string &field_name, int value) override;
        virtual void DoubleField(const std::string &field_name, double value) override;
        virtual void StringField(const std::string &field_name, const std::string &value) override;
        virtual void BooleanField(const std::string &field_name, bool value) override;
        virtual void SerializableField(const std::string &field_name, const academia::Serializable &value) override;
        virtual void ArrayField(const std::string &field_name, const std::vector<std::reference_wrapper<const academia::Serializable>> &value) override;
        virtual void Header(const std::string &object_name) override;
        virtual void Footer(const std::string &object_name) override;

    };



    class Building:public Serializable{
    public:
        Building(){}
        Building(int id, std::string nr, std::initializer_list<std::reference_wrapper<const Serializable>> room):
                id_(id), nr_(nr), room_(room){} ;
        virtual ~Building(){}

        void Serialize(Serializer* item) const override;

    private:
        int id_;
        std::string nr_;
        std::vector<std::reference_wrapper<const Serializable>> room_;
    };

    class Room : public Serializable {
    public:


        enum class Type {
            COMPUTER_LAB,
            LECTURE_HALL,
            CLASSROOM
        };

        Room(){}
        Room(int id, std::string nr, Type classroom) : id_(id), nr_(nr), classroom_(classroom) {};
        ~Room(){}




        void Serialize(Serializer * item) const override;

        std::string TypeToString(Type type) const;





    private:
        int id_;
        std::string nr_;
        Type classroom_;
    };

}




#endif //JIMP_EXERCISES_SERIALIZATION_H
