#include "festival.h"



mtm::Festival::Festival(const DateWrap& dateWrap1):EventContainer(),dateWrap(dateWrap1){

}
mtm::Festival::~Festival()=default;






void mtm::Festival::add(BaseEvent const & ev) {
DateWrap ev_date=ev.get_date();
    if(this->dateWrap!=ev_date){
        throw mtm::DateMismatch();
    }
BaseEvent * copy_ev =new BaseEvent(ev.get_date(),ev.get_name(),ev.students,ev.invitees,ev.is_it_open);
    vec.add_to_vec(copy_ev);

}
