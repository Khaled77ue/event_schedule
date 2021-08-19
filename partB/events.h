//
// Created by lamar on 1/4/2021.
//

#ifndef EX3_MTM_WINTER_EVENTS_H
#define EX3_MTM_WINTER_EVENTS_H


class DoubleDirectionNode {
public:
    explicit DoubleDirectionNode(int student) :student(student),
           next(nullptr), previous(nullptr){};
    ~DoubleDirectionNode() {//clear();
    }
    void clear(){

        next= nullptr;
        previous= nullptr;
    }
    int student;
    DoubleDirectionNode* next;
    DoubleDirectionNode* previous;


};

class StudentsCount {
public:
    explicit StudentsCount(int student) :start(nullptr), end(nullptr),nodesAmount(1) {
        auto* tmp =   new DoubleDirectionNode(student);
        end = tmp;
        start = tmp;
    }

    ~StudentsCount() {
        deleteCount(); }
    void deleteCount(){
        while (start != end) {
            DoubleDirectionNode* tmp = start;
            start = start->next;

            delete tmp;
        }
        if (start == end && start != nullptr && end != nullptr) {

            delete  end;
            start = nullptr;
            end = nullptr;
        }

    }
    void addStudent(int Student){
        if(start->student==-1){
            start->student=Student;
            return;
        }
        DoubleDirectionNode * current=start;
        while(current!= nullptr){
            if(Student<current->student){
                addNode(current,Student);
                return;
            }
            if(!current->next){
                current->next=new DoubleDirectionNode(Student);
                current->next->previous=current;
                current->next->next= nullptr;
                end=current->next;
                nodesAmount++;
                return;
            }
            current=current->next;

        }

    }
    void addNode(DoubleDirectionNode* current,int Student) {
        auto* tmp = new DoubleDirectionNode(Student);
        if (current->previous == nullptr) {
            tmp->next = current;
            tmp->previous = nullptr;
            current->previous = tmp;
            start = tmp;
        }
        else {
            DoubleDirectionNode* prev = current->previous;
            tmp->next = current;
            current->previous = tmp;
            prev->next = tmp;
            tmp->previous = prev;
        }
        nodesAmount++;
    }

    void addNode_copy(DoubleDirectionNode* current, DoubleDirectionNode* tmp2) {
        auto* tmp = new DoubleDirectionNode(tmp2->student);
        if (current->previous == nullptr) {
            tmp->next = current;
            tmp->previous = nullptr;
            current->previous = tmp;
            start = tmp;
        }
        else {
            DoubleDirectionNode* prev = current->previous;
            tmp->next = current;
            current->previous = tmp;
            prev->next = tmp;
            tmp->previous = prev;
        }
    }

    void removeNode(DoubleDirectionNode* current) {
        nodesAmount--;
        if (current->previous == nullptr && current->next == nullptr) {

            delete current;
            start= nullptr;
            end= nullptr;
            return;
        }
        if (current->previous == nullptr) {
            start = start->next;
            start->previous= nullptr;
            delete current;
            return;
        }
        if (current->next == nullptr) {
            end = current->previous;
            current->previous->next = nullptr;
            delete current;
            return;
        }
        current->next->previous = current->previous;
        current->previous->next = current->next;

        delete current;
    }

    DoubleDirectionNode* getStart() {
        return start;
    }
    DoubleDirectionNode* getEnd() {
        return end;
    }
    int getNodesAmount() {
        return nodesAmount;
    }
    StudentsCount copy_node() const {
        StudentsCount students =StudentsCount(-1);
        DoubleDirectionNode * current=this->start;

while(current!= nullptr){
    students.addStudent(current->student);
    current=current->next;
}
        return students;
    }
    bool find(int student){
        DoubleDirectionNode * current=start;
        while(current!= nullptr){
            if(current->student==student)return true;
            current=current->next;
        }
        return false;
    }
   void removeStudent(int student) {
       DoubleDirectionNode *current = start;
       while (current != nullptr) {
           if (current->student == student){
              removeNode(current);
               return;
           }
           current=current->next;
       }
   }
private:

    DoubleDirectionNode* start;
    DoubleDirectionNode* end;
    int nodesAmount;
};





#endif //EX3_MTM_WINTER_EVENTS_H
