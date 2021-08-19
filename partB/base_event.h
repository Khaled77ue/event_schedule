//
// Created by lamar on 1/5/2021.
//
#include "date_wrap.h"
#include "events.h"
#include <cstring>
#include <utility>
#ifndef EX3_MTM_WINTER_BASE_EVENT_H
#define EX3_MTM_WINTER_BASE_EVENT_H
namespace mtm{
class BaseEvent{
public:

  explicit   BaseEvent(const DateWrap& dateWrap, std::string name,const StudentsCount& students,const StudentsCount& invtees):is_it_open(false)
   , students((students.copy_node())),invitees((invtees.copy_node())),date(dateWrap),name(std::move(name)){
//date=dateWrap;
// date.destroy_date();

    }
 explicit      BaseEvent(const DateWrap& dateWrap, std::string name,const StudentsCount& students,const StudentsCount& invtees,bool is_it_open):is_it_open(is_it_open),

                                        students((students.copy_node())),invitees((invtees.copy_node())),date(dateWrap),name(std::move(name)){
                                            // date.destroy_date();

    }
  explicit  BaseEvent(const DateWrap& dateWrap, std::string name );
  // BaseEvent( const BaseEvent &base);
    virtual  ~BaseEvent();

    virtual void registerParticipant(int student);
    void unregisterParticipant(int student);
   bool operator>(const BaseEvent& base){
       return this->date>base.date;
   }
    bool operator==(const BaseEvent& b){
        return this->date == b.date && this->name == b.name;
    }
    std::string  get_name() const{
        return name;
    }
    std::ostream& printShort(std::ostream &);
    std::ostream& printLong(std::ostream &);

    virtual BaseEvent* clone() const ;
DateWrap get_date() const{
    return date;
}
bool is_it_open;
 StudentsCount students;
    StudentsCount invitees;
protected:
    DateWrap date;
  std::string  name;


};
}





#endif //EX3_MTM_WINTER_BASE_EVENT_H
