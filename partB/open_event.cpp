#include "open_event.h"

#include <utility>
mtm::OpenEvent::OpenEvent(const DateWrap& dateWrap,std::string name) :BaseEvent(dateWrap,std::move(name)){
     is_it_open=true;

}

/*mtm::OpenEvent::~OpenEvent() {
    date.destroy_date();
    students.delete_vec();
    invitees.delete_vec();
}*/

void mtm::OpenEvent::registerParticipant(int student) {
    if(student>20000||student<=0)
        throw InvalidStudent();
    if(students.find(student)){
        throw AlreadyRegistered() ;
    }
    students.addStudent(student);
}

