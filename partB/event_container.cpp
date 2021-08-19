#include "event_container.h"


mtm::EventContainer::EventContainer():vec(N) {

}

mtm::EventContainer::EventIterator mtm::EventContainer::begin() const{
    return EventIterator(this);
}
mtm::EventContainer::EventIterator mtm::EventContainer::end() const{
    int i=0;
    while(vec[i]!= nullptr){
        i++;
    }
  EventIterator it=  EventIterator(this);
    it.event=vec[i];
    return it;
}

