#include "date.hpp"

date::date():year_(0), month_(0), day_(0){}

date::date(const int& day, const int& month, const int& year):day_(day), month_(month), year_(year){}

int date::day() const { return day_;};
int date::month() const {return month_;};
int date::year() const {return year_;};

void date::set_day(const int& day){
    this->day_ = day;
}

void date::set_month(const int& month){
    this->month_ = month;
}

void date::set_year(const int& year){
    this->year_ = year;
}

bool date::valid() const{
    if (year_<0) return false;
    if (month_>12 || month_< 1) return false;
    if (day_>31 || day_<1) return false;

    if ((day_==31 && (month_ == 2 || month_ == 4 || month_ ==  6 || month_ == 9 || month_ == 11)))
        return false;
    if (day_ == 30 && month_ == 2) return false;

    return true;
}

bool operator==(const date& d1, const date& d2){
    if (!(d1.valid() && d2.valid())) return false;
    return (d1.day() == d2.day() && d1.month()==d2.month() && d1.year() == d2.year());
}

bool operator<(const date& d1, const date& d2){
    if (!(d1.valid() && d2.valid())) return false;
    if (d1.year() == d2.year()){
        if (d1.month() == d2.month()){
            return d1.day() == d2.day();
        }
        else
            return d1.month()<d2.month();
    }
    else
        return d1.year()<d2.year();
}

bool operator<=(const date& d1, const date& d2){
    if (d1 == d2) return true;
    return d1<d2;
}

bool operator>(const date& d1, const date& d2){ return d1<=d2;}
bool operator!=(const date& d1, const date& d2){ return !(d1==d2);}

date next_date(const date& d){
    if (!d.valid()) return date();
    date ndate=date((d.day()+1), d.month(), d.year());
    if (ndate.valid()) return ndate;
    ndate = date(1, d.month()+1, d.year());
    if (ndate.valid()) return ndate;
    ndate = date(1,1, d.year()+1);
    return ndate;
}

date previous_date(const date &d)
{
    if (!d.valid())
        return date();
    date pdate = date((d.day() -1), d.month(), d.year());
    if (pdate.valid())
        return pdate;
    pdate = date(31, d.month() -1, d.year());
    if (pdate.valid())
        return pdate;
    pdate = date(30, d.month() - 1, d.year());
    if (pdate.valid())
        return pdate;
    pdate = date(29, d.month() - 1, d.year());
    if (pdate.valid())
        return pdate;
    pdate = date(28, d.month() - 1, d.year());
    if (pdate.valid())
        return pdate;
    pdate = date(31, 12, d.year() - 1);
    return pdate;
}

date date::operator++(int){
    date d = *this;
    *this = next_date(d);
    return d;
}

date date::operator++()
{
    *this = next_date(*this);
    return *this;
}


date date::operator--(int)
{
    date d = *this;
    *this = previous_date(d);
    return d;
}

date date::operator++()
{
    *this = previous_date(*this);
    return *this;
}
