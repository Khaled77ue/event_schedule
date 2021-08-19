//
// Created by lamar on 1/9/2021.
//

#ifndef EX3_MTM_WINTER_RECURRING_EVENT_H
#define EX3_MTM_WINTER_RECURRING_EVENT_H

#include "event_container.h"
namespace mtm{
template <class EventType>

   class RecurringEvent:public EventContainer {
   public:
      RecurringEvent(DateWrap const& , const std::string& name, int num_occurrences, int interval_days);

     virtual  ~RecurringEvent()= default;
     //    this->date.destroy_date();



       void add( EventType const&);

   private:
       DateWrap date;
       int num_occurrences;
       int interval_days;
   };
}





template <class EventType>
void mtm::RecurringEvent<EventType>::add(const EventType &) {
    throw mtm::NotSupported();
}

template <class EventType>
mtm::RecurringEvent<EventType>::RecurringEvent(DateWrap const & dateWrap, const std::string& name, int num_occurrences, int interval_days):date(dateWrap),num_occurrences(num_occurrences),interval_days(interval_days){
    this->name=name;
  //  date.destroy_date();

for(int i=0;i<num_occurrences;i++){

    vec[i]=new EventType(dateWrap+i*interval_days,name);
    vec.updateArr();

}

}


#endif //EX3_MTM_WINTER_RECURRING_EVENT_H
