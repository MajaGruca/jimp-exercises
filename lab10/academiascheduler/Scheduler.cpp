//
// Created by ktr on 22.05.2017.
//

#include "Scheduler.h"


#include <vector>
#include <algorithm>
#include <set>
#include <map>

namespace academia
{


    SchedulingItem::SchedulingItem(int new_course_id, int new_teacher_id, int new_room_id, int new_time_slot, int new_year) {

        course_id=new_course_id;
        teacher_id=new_teacher_id;
        room_id=new_room_id;
        time_slot=new_time_slot;
        year=new_year;

    }

    Schedule Schedule::OfTeacher(int teacher_id) const {
        Schedule temp;
        std::copy_if (cos.begin(), cos.end(), std::back_inserter(temp.cos), [teacher_id](SchedulingItem it ){return teacher_id==it.TeacherId();} );
        return temp;
    }

    Schedule Schedule::OfRoom(int room_id) const {
        Schedule temp;
        std::copy_if (cos.begin(), cos.end(), std::back_inserter(temp.cos), [room_id](SchedulingItem it ){return room_id==it.RoomId();} );
        return temp;
    }

    Schedule Schedule::OfYear(int year) const {
        Schedule temp;
        std::copy_if (this->cos.begin(), this->cos.end(), std::back_inserter(temp.cos), [year](SchedulingItem it ){return (year==it.Year());} );
        return temp;
    }

    std::vector<int> Schedule::AvailableTimeSlots(int n_time_slots) const {
        return std::vector<int>();
    }

    void Schedule::InsertScheduleItem(const SchedulingItem &item) {
        cos.push_back(item);
    }

    std::size_t Schedule::Size() const {
        return cos.size();
    }

    SchedulingItem Schedule::operator[](int it) const {
        return cos[it];
    }

    Schedule Scheduler::PrepareNewSchedule(const std::vector<int> &rooms,
                                           const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                           const std::map<int, std::set<int>> &courses_of_year, int n_time_slots) {
        return Schedule();
    }
}