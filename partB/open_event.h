//
// Created by lamar on 1/5/2021.
//

#ifndef EX3_MTM_WINTER_OPEN_EVENT_H
#define EX3_MTM_WINTER_OPEN_EVENT_H

#include "base_event.h"

#include "events.h"
namespace mtm{

    class OpenEvent:public BaseEvent{
    public:
       //     ~OpenEvent() override;
       explicit  OpenEvent(const DateWrap& dateWrap, std::string name );
        void registerParticipant(int student) override ;

    };
}


#endif //EX3_MTM_WINTER_OPEN_EVENT_H
