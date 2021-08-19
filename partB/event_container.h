//
// Created by lamar on 1/8/2021.
//


#ifndef EX3_MTM_WINTER_EVENT_CONTAINER_H
#define EX3_MTM_WINTER_EVENT_CONTAINER_H

#include "base_event.h"
#include <iostream>
#define N 1000
class  DynamicArray {

public:
    int length;
    int current;
    mtm::BaseEvent** vec;

    explicit DynamicArray(int size=N) : length(size), current(0) {
        vec = new mtm::BaseEvent*[size];
        for (int i = 0; i < size; i++) {
            vec[i] = nullptr;
        }
    }
    ~DynamicArray() {
        for (int i=0;i<length;i++){
            delete vec[i];
        }
        delete[] vec;
    }
    void clear(){
        for (int i=0;i<length;i++){
            delete vec[i];
        }
    }
    DynamicArray operator=(const DynamicArray& ar){
        DynamicArray new_ar (ar.length);
        for (int i = 0; i < length; i++) {
            new_ar[i]=ar[i];
        }
        return new_ar;
    }
    mtm::BaseEvent*& operator[](int index) const {
        return vec[index];
    }
    void add_to_vec(mtm::BaseEvent* ev){
        for(int i=0;i<length;i++){
            if(!vec[i]){
                vec[i]=ev;

                break;
            }
        }
        updateArr();

    }
    void updateArr() {
        current++;
        if (current == length) {
            auto** vec_new = new  mtm::BaseEvent*[2 * length];
            for (int i = 0; i < length; i++) {
                vec_new[i] = vec[i];
            }
            delete[] vec;
            vec = vec_new;
            length = 2 * length;
        }
    }
    void sort(){
        for(int i=0;i<length;i++){
            for(int j=0;j<length;j++){
                if(!vec[i]&&vec[i+1]){
                    vec[i]=vec[i+1];
                    vec[i+1]= nullptr;
                }
                if(vec[i]&&!vec[i+1]){
                    continue;
                }
                if(!vec[i]&&!vec[i+1]){
                    continue;
                }
                if(vec[i]&&vec[i+1]){
                    if(vec[i]>vec[i+1]){
                        mtm::BaseEvent* tmp=vec[i];
                        vec[i]=vec[i+1];
                        vec[i+1]=tmp;
                    }
                }
            }
        }
    }
    void print_all() const{

        for(int i=0;i<current;i++){
            std::cout<< vec[i]->get_name()<<" "<<vec[i]->get_date()<<"\n";
        }

    }
};


namespace mtm{

    class EventContainer{
    public:
        EventContainer();

   ~EventContainer()=default;


void destroy(){
vec.clear();
}



        friend    class EventIterator;

      //  virtual void add(const mtm::BaseEvent& event);
   class EventIterator{
public:
   ~EventIterator()=default;


    explicit EventIterator(const EventContainer* ev): event(ev->vec[0]), cont(const_cast<EventContainer *>(ev)){}

   EventIterator(EventIterator const & it){
      this->cont=it.cont;
      event=it.event->clone();
   }
   EventIterator operator=(const EventIterator& it){
       return EventIterator(it);
    }
BaseEvent&  operator*(){
   return *event;
   }
bool operator==(const EventIterator& it){
    return !it.event && !this->event;
}
bool operator!=(const EventIterator& it ){
    return !(this->operator==(it));
    }
EventIterator& operator++(){
    DateWrap date_event(this->event->get_date());
        for(int i=0;i<this->cont->vec.length;i++){
//DateWrap date_event=this->event->get_date();
//DateWrap date_vec=cont->vec[i]->get_date();

            if(this->event->get_name()==cont->vec[i]->get_name()&&cont->vec[i]->get_date()==date_event&&this->event!= nullptr){
                    if(cont->vec[i+1]){
                         this->event=cont->vec[i+1];
                return *this;
                    }
                    else{
                        this->event= nullptr;
                        return *this;
                    }

            }
        }



    return *this;
    }
    mtm::BaseEvent* event;
EventContainer* cont;

};
EventIterator begin() const;
EventIterator end() const;


        std::string name;
        DynamicArray vec;
        //DateWrap date;
    };



}


#endif //EX3_MTM_WINTER_EVENT_CONTAINER_H
