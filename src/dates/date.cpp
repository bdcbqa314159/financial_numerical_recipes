#include "date.hpp"

date::date():year_(0), month_(0), day_(0){}

date::date(const int& day, const int& month, const int& year):day_(day), month_(month), year_(year){}

int date::day() const { return day_;};
int date::month() const {return month_;};
int date::year() const {return year_;};
