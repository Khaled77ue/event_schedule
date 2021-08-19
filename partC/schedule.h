//
// Created by lamar on 1/9/2021.
//

#ifndef EX3_MTM_WINTER_SCHEDULE_H
#define EX3_MTM_WINTER_SCHEDULE_H
#include <utility>

#include "date_wrap.h"
#include "event_container.h"
namespace mtm{
    typedef bool(*Predicate)(mtm::BaseEvent const &);
    class Schedule{
    public:
Schedule():vec(DynamicArray(1000)){};
~Schedule()= default;

void sort_vec(){
    if(vec.current==1){
        return;
    }
for(int i=0;i<vec.current;i++){
    for(int j=0;j<vec.current-1;j++){
        if(vec[j]->get_date()>vec[j+1]->get_date()){
            BaseEvent* tmp=vec[j];
            vec[j]=vec[j+1];
            vec[j+1]=tmp;
        }
        if(vec[j]->get_date()==vec[j+1]->get_date()&&vec[j]->get_name()>vec[j+1]->get_name()){
            BaseEvent* tmp=vec[j];
            vec[j]=vec[j+1];
            vec[j+1]=tmp;
        }
    }
}
}
void addEvents(mtm::EventContainer const &);
void registerToEvent(const DateWrap&,std::string,int);
void unregisterFromEvent(const DateWrap&,std::string,int);

        void   printAllEvents() const ;
      void  printMonthEvents(int,int) const;
        void  printEventDetails(const DateWrap&,std::string) const;

       // template <class Predicate>

        template<class Predicate>
        void printSomeEvents(Predicate predicate, bool verbose= false) const{
         for(int i=0;i<vec.current;i++){
        if(vec[i]){
            if(predicate(*vec[i])){
                if(verbose){
                    vec[i]->printLong(std::cout);

                }
                else{
                    vec[i]->printShort(std::cout);
                }
            }
        }
    }}
    private:
        DynamicArray vec;



    };

}


#endif //EX3_MTM_WINTER_SCHEDULE_H
