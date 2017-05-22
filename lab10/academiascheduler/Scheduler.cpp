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

        std::vector<int>temp;
        for(int i=0;i<n_time_slots;i++)
            temp.push_back(i+1);

        for(auto& n :cos)
        {
            auto tmp=std::find(temp.begin(),temp.end(),n.TimeSlot());
            if(tmp!=temp.end())
                temp.erase(tmp);
        }
        return temp;
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
                                           const std::map<int, std::set<int>> &courses_of_year, int n_time_slots)
    {
        Schedule schedule;
        int all_time_slots=n_time_slots;
        int rooms_it=0;
        bool flag= false;
        int c_id=0,t_id=0,r_id=0,t_s=0,y=0;
        for (auto it : teacher_courses_assignment)
        {
            t_id=it.first;
            for(auto a : it.second) {
                c_id=a;
                if(all_time_slots<=0)
                {
                    all_time_slots=n_time_slots;
                    rooms_it++;
                }
                if(rooms.size()<rooms_it+1)
                    throw NoViableSolutionFound();
                r_id=rooms[rooms_it];
                for (auto b : courses_of_year) {
                    for(auto c : b.second)
                    {
                        if(c==a)
                        {
                            y=b.first;

                            flag=true;
                            break;
                        }
                    }
                    if(flag)
                    {
                        break;
                    }
                }
                if(!flag)
                    throw NoViableSolutionFound();
                else
                    flag= false;
                schedule.InsertScheduleItem(SchedulingItem{c_id, t_id, r_id,all_time_slots , y});
                all_time_slots--;
            }
        }
        return schedule;
    }
}