//
// Created by ktr on 22.05.2017.
//

#ifndef JIMP_EXERCISES_SCHEDULER_H
#define JIMP_EXERCISES_SCHEDULER_H

#include <vector>
#include <set>
#include <map>

namespace academia
{  class SchedulingItem{
        /*course_id - identyfikator kursu
        teacher_id - identyfikator nauczyciela akademickiego prowadzącego te zajęcia o tej godzinie
        room_id - identyfikator pomieszczenia w którym odbywają się zajęcia
        time_slot - okno czasowe, w którym odbywają się zajęcia, dla uproszczenia cały tydzień jest podzielony na N okien czasowych nie zachodzących na siebie (np. dla 20: 1 ⇒ pon 8:00-10:00, 2 ⇒ pon 10:00-12:00, … 20 ⇒ pią 14:00-16:00). Zajęcia wymagają zawsze pojedynczego okna czasowego i zawsze są z nim wyrównane tzn. nie mogą zajmować połowę 12ego i połowę 13ego
        year - rok studiów na którym obowiązuje przedmiot
         */

    public:

        SchedulingItem(int course_id,int teacher_id,int room_id,int time_slot,int year);
        ~SchedulingItem(){};
        int CourseId() const { return course_id;};
        int TeacherId() const { return teacher_id;};
        int RoomId() const { return room_id;};
        int TimeSlot() const { return time_slot;};
        int Year() const { return year;};

    private:
        int course_id;
        int teacher_id;
        int room_id;
        int time_slot;
        int year;

    };
    class Schedule
    {
        /*Schedule OfTeacher(int teacher_id) const - wylicza fragment harmonogramu związany z danym nauczycielem akademickim (może się przydać copy_if…)
Schedule OfRoom(int room_id) const - j.w. tylko związany z danym pomieszczeniem
Schedule OfYear(int year) const - j.w. dla danego roku studiów
std::vector<int> AvailableTimeSlots(int n_time_slots) const - wylicza wektor jeszcze nie zajętych okien czasowych, gdzie n_time_slots jest maksymalną wartością okna czasowego
void InsertScheduleItem(const SchedulingItem &item) - wstawia nowy element planu
size_t Size() const - zwaraca rozmiar planu*/
    public:

        Schedule(){};
        ~Schedule(){};
        Schedule OfTeacher(int teacher_id) const;
        Schedule OfRoom(int room_id) const;
        Schedule OfYear(int year) const;
        std::vector<int> AvailableTimeSlots(int n_time_slots) const;
        void InsertScheduleItem(const SchedulingItem &item);
        std::size_t Size() const;

        SchedulingItem operator[](int it) const;

    private:
        std::vector<SchedulingItem> cos;
    };
    class Scheduler {
    public:
        Scheduler(){};
        ~Scheduler(){};
        Schedule PrepareNewSchedule(const std::vector<int> &rooms, const std::map<int, std::vector<int>> &teacher_courses_assignment, const std::map<int, std::set<int>> &courses_of_year, int n_time_slots);
    };


    class GreedyScheduler{
        GreedyScheduler(){};
        ~GreedyScheduler(){};

    };
    class NoViableSolutionFound{

    };





}


#endif //JIMP_EXERCISES_SCHEDULER_H
