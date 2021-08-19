//
// Created by lamar on 1/9/2021.
//

#ifndef EX3_MTM_WINTER_ONE_TIME_EVENT_H
#define EX3_MTM_WINTER_ONE_TIME_EVENT_H


#include "event_container.h"



namespace mtm{

template <class EventType>
class OneTimeEvent:public EventContainer{
public:
    explicit OneTimeEvent(const DateWrap&,const std::string& name);

   virtual   ~OneTimeEvent()=default;







    virtual void add(const BaseEvent&);

private:
    DateWrap dateWrap;

};

}


template <class EventType>
void mtm::OneTimeEvent<EventType>::add(const mtm::BaseEvent &) {
    throw mtm::NotSupported();
}
template <class EventType>
mtm::OneTimeEvent<EventType>::OneTimeEvent(const DateWrap& dateWrap1, const std::string& name1):EventContainer(),dateWrap(dateWrap1){

    name=name1;
    vec[0]=new EventType(dateWrap1,name1);
vec.updateArr();
}
#endif //EX3_MTM_WINTER_ONE_TIME_EVENT_H
