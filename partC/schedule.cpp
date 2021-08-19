#include "schedule.h"
void mtm::Schedule::addEvents(mtm::EventContainer const & cont) {
    int i=0;
    while(vec[i]!= nullptr){
        i++;
    }

    EventContainer::EventIterator it_check=cont.begin();
    while(it_check.event){
        for(int j=0;j<vec.current;j++){
            if(*vec[j]==*it_check.event){
                throw mtm::EventAlreadyExists();
                return;
            }

        }
        ++it_check;
    }
    EventContainer::EventIterator it=cont.begin();
    while(it.event!= nullptr){
        vec[i]=it.event->clone();
        vec.updateArr();
        i++;
        ++it;
    }
    sort_vec();
}
void mtm::Schedule::registerToEvent(const DateWrap& date,std::string name,int student){
    BaseEvent baseEvent=BaseEvent(date,std::move(name));
    for(int i=0;i<vec.length;i++){
        if(vec[i]!= nullptr){
            if(baseEvent==(*vec[i])){
                vec[i]->registerParticipant(student);
                return;
            }
        }
    }
    throw EventDoesNotExist();


}

void mtm::Schedule::unregisterFromEvent(const DateWrap& dateWrap,std::string name, int student) {
    BaseEvent baseEvent=BaseEvent(dateWrap,std::move(name));
    for(int i=0;i<vec.length;i++){
        if(vec[i]!= nullptr){
            if(baseEvent==(*vec[i])){
                vec[i]->unregisterParticipant(student);
                return;
            }
        }
    }
    throw EventDoesNotExist();


}
void mtm::Schedule::printAllEvents() const {
    vec.print_all();
}
void mtm::Schedule::printMonthEvents(int month, int year) const{
    int i=0;
    while(vec[i]){
        if(vec[i]->get_date().month()==month&&vec[i]->get_date().year()==year){
            vec[i]->printShort(std::cout);

        }
        i++;
    }
}


void mtm::Schedule::printEventDetails(DateWrap const &date,std::string name) const{
    BaseEvent baseEvent=BaseEvent(date,std::move(name));
    for(int i=0;i<vec.length;i++){
        if(vec[i]!= nullptr){
            if(baseEvent==(*vec[i])){
                vec[i]->printLong(std::cout);
                return;
            }
        }
    }

}
