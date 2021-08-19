//
// Created by lamar on 1/9/2021.
//

#ifndef EX3_MTM_WINTER_FESTIVAL_H
#define EX3_MTM_WINTER_FESTIVAL_H


#include "date_wrap.h"
#include "base_event.h"
#include "event_container.h"
namespace mtm{




class Festival :public mtm::EventContainer {
public:
   explicit Festival(const DateWrap&);
   virtual ~Festival();
    virtual void add(BaseEvent const & );

private:
    DateWrap dateWrap;
};



}


#endif //EX3_MTM_WINTER_FESTIVAL_H
