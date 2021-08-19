#include "closed_event.h"

#include <utility>

using mtm::InvalidStudent;


mtm::ClosedEvent::ClosedEvent( DateWrap const & dateWrap, std::string name):BaseEvent(dateWrap,std::move(name)) {
     this->is_it_open= false;
}
void mtm::ClosedEvent::addInvitee(int invitee) {
    if(invitee>20000||invitee<=0)
        throw InvalidStudent();
    if(invitees.find(invitee))throw AlreadyInvited();
    invitees.addStudent(invitee);
}
