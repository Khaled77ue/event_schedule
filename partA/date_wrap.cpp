#include "date_wrap.h"





mtm::DateWrap::DateWrap(int day, int month, int year) {
    if(day<0)   throw mtm::NegativeDays();
    if (month<0) throw mtm::NegativeDays();

    this->date=dateCreate(day,month,year);

}



int mtm::DateWrap::day() const{
    int day=0;
    int month=0;
    int year=0;
    dateGet(this->date,&day,&month,&year);
    return day;
}

int mtm::DateWrap::month() const{
    int day=0;
    int month=0;
    int year=0;
    dateGet(this->date,&day,&month,&year);
    return month;
}

int mtm::DateWrap::year() const{
    int day=0;
    int month=0;
    int year=0;
    dateGet(this->date,&day,&month,&year);
    return year;
}

bool mtm::DateWrap::operator<(DateWrap const& date2) {
   // Date date1=dateCreate(date2.day(),date2.month(),date2.year());
    int val=  dateCompare(this->date,date2.date);
    return val < 0;
}

bool mtm::DateWrap::operator==(DateWrap const& date2) {
    int val=  dateCompare(this->date,date2.date);
    return val == 0;

}
bool mtm::DateWrap::operator!=(const DateWrap& date2) {

    return !(this->operator==(date2));

}

bool mtm::DateWrap::operator>(DateWrap const& date2) {

  //  Date date1=dateCreate(date2.day(),date2.month(),date2.year());
    int val=  dateCompare(this->date,date2.date);
    return val > 0;


}

bool mtm::DateWrap::operator>=(DateWrap const& date2) {

  //  Date date1=dateCreate(date2.day(),date2.month(),date2.year());
    int val=  dateCompare(this->date,date2.date);
    return val > 0||val==0;


}

bool mtm::DateWrap::operator<=(DateWrap const& date2) {

    //Date date1=dateCreate(date2.day(),date2.month(),date2.year());
    int val=  dateCompare(this->date,date2.date);
    return val < 0||val==0;


}
mtm::DateWrap&  mtm::DateWrap::operator++(int) {
    dateTick(this->date);
    return *this;
}


void mtm::DateWrap::operator+=(int days) {
    if (days<0)throw mtm::NegativeDays();
    for (int i = 0; i < days; i++) {
        dateTick(this->date);
    }

}



mtm::DateWrap operator+(int days,const mtm::DateWrap& dateWrap) {
    if (days < 0) throw mtm::NegativeDays();
    mtm::DateWrap date1 = mtm::DateWrap(dateWrap.day(), dateWrap.month(), dateWrap.year());
    for (int i = 0; i < days; i++) {
        date1++;
    }
    return date1;

}

