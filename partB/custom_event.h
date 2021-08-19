//
// Created by lamar on 1/5/2021.
//

#ifndef EX3_MTM_WINTER_CUSTOM_EVENT_H
#define EX3_MTM_WINTER_CUSTOM_EVENT_H

#include "base_event.h"

namespace mtm{


    template <class CanRegister>
    class CustomEvent:public BaseEvent{
    public:
        explicit  CustomEvent(const DateWrap& dateWrap, const std::string&  name,CanRegister);
        void registerParticipant(int student) override;
virtual ~CustomEvent()=default;
    private:
        CanRegister canRegister;
    };

}
#include "custom_event.h"

template<class CanRegister>
mtm::CustomEvent<CanRegister>::CustomEvent(const DateWrap& dateWrap, const std::string& name,CanRegister can):BaseEvent(dateWrap,name),canRegister(can) {

}

template<class CanRegister>
void mtm::CustomEvent<CanRegister>::registerParticipant(int student) {
    if(student>20000||student<=0)
        throw InvalidStudent();

    if(!canRegister(student))throw RegistrationBlocked();
    if(students.find(student))throw AlreadyRegistered();
    students.addStudent(student);
}
#endif //EX3_MTM_WINTER_CUSTOM_EVENT_H
