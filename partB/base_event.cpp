
#include "base_event.h"

#include <utility>
/*
mtm::BaseEvent::BaseEvent(const mtm::BaseEvent &base):date(base.date),students(-1) {
    this->name=base.name;
   // this->date=base.date;
   base.invitees=copy_node( this->invitees);
   base.students.copy_node(this->students);
}*/
mtm::BaseEvent::BaseEvent(const DateWrap& dateWrap, std::string name):is_it_open(false),students(-1),invitees(-1),date(dateWrap),name(std::move(name)){
    // date.destroy_date();
}
mtm::BaseEvent::~BaseEvent() =default;//this->date.destroy_date();}

 //   this->students.deleteCount();
   // this->invitees.deleteCount();


void mtm::BaseEvent::registerParticipant(int student) {
    if(student>20000||student<=0)
        throw InvalidStudent();
    if(invitees.find(student)||is_it_open){
        if(students.find(student)){ throw AlreadyRegistered() ;}
       students.addStudent(student);
        return;
    }
    throw  RegistrationBlocked();
}



void mtm::BaseEvent::unregisterParticipant(int student) {
    if(student>20000||student<=0)
        throw InvalidStudent();
    if(this->students.find(student)){
        this->students.removeStudent(student);
        return;
    }
    throw NotRegistered();
}
mtm::BaseEvent* mtm::BaseEvent::clone() const{

  return (new BaseEvent(this->date,this->name,this->students,this->invitees,this->is_it_open));
}


std::ostream& mtm::BaseEvent::printShort(std::ostream &ostream) {

    return ostream<<this->name<<" "<< this->date<<"\n";

}


std::ostream& mtm::BaseEvent::printLong(std::ostream &ostream) {

    ostream<<this->name<<" "<<this->date<<"\n";
    DoubleDirectionNode * current=students.getStart();
while(current!= nullptr){
    if(current->student==-1){
        current=current->next;
        continue;
    }
    ostream<<current->student<<"\n";
    current=current->next;
}

    return ostream;

}

