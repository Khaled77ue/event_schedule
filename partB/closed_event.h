//
// Created by lamar on 1/5/2021.
//

#ifndef EX3_MTM_WINTER_CLOSED_EVENT_H
#define EX3_MTM_WINTER_CLOSED_EVENT_H

#include "base_event.h"
#include "date_wrap.h"

namespace mtm{


    class ClosedEvent: public BaseEvent{
    public:

      explicit  ClosedEvent(const DateWrap& dateWrap, std::string name );
 ~ClosedEvent()=default;
        virtual void addInvitee(int invitee);

    };




}


#endif //EX3_MTM_WINTER_CLOSED_EVENT_H
