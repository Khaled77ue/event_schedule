//
// Created by lamar on 12/31/2020.
//
#include <ostream>
#include <iostream>

#include "exceptions.h"
#ifndef EX3_MTM_WINTER_DATE_WRAP_H
#define EX3_MTM_WINTER_DATE_WRAP_H

extern "C"{
#include "date.h"
}
namespace mtm{
    class DateWrap{
    public:
        DateWrap(int day,int month,int year);

          ~DateWrap(){
            dateDestroy(date);
          };
           DateWrap(const DateWrap& datew){
               this->date=dateCreate(datew.day(),datew.month(),datew.year());
          }
          DateWrap& operator=(const DateWrap& datew){
          this->date=dateCreate(datew.day(),datew.month(),datew.year());
          return *this;
          }
        int day() const;
        int month() const;
        int year() const;
        void destroy_date(){
            dateDestroy(this->date);
        }
        std::ostream& print(std::ostream&  os) const{
            int day=0;
            int month=0;
            int year=0;
            dateGet(date,&day,&month,&year);
            return os<<day<<'/'<<month<<'/'<<year;
        }

        friend std::ostream &operator <<(std::ostream &os,const DateWrap& dateWrap){
            return dateWrap.print(os);
        }
        bool operator <( DateWrap const&);
        bool operator==(DateWrap const &);
        bool operator >(DateWrap const &);
        bool operator !=( DateWrap const &);
        bool operator <=(DateWrap  const &);
        bool operator >=(DateWrap const &);
        DateWrap& operator++(int);
        void operator+=(int days);
        friend DateWrap operator+(int days,const DateWrap& dateWrap){
            if (days < 0) throw mtm::NegativeDays();
            mtm::DateWrap date1 = mtm::DateWrap(dateWrap.day(), dateWrap.month(), dateWrap.year());
            for (int i = 0; i < days; i++) {
                date1++;
            }
            return date1;

        }

        friend    DateWrap operator+(DateWrap const &  date1,int days){
            if (days < 0) throw mtm::NegativeDays();
            mtm::DateWrap date11 = mtm::DateWrap(date1.day(), date1.month(),date1.year());
            for (int i = 0; i < days; i++) {
                date11++;
            }
            return date11;}
    private:
        Date date;



    };

}







#endif //EX3_MTM_WINTER_DATE_WRAP_H
