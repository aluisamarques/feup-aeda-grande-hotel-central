//
// Created by marga on 21/11/2020.
//

#ifndef GRANDE_HOTEL_CENTRAL_FINANCES_H
#define GRANDE_HOTEL_CENTRAL_FINANCES_H
#include "DataBase.h"
#include "Date.h"

class Finances {
    double cleaning_cost;
    double hygiene_cost;
    double salaries_cost;
    double booking_profit;
public:
    Finances(DataBase* dataBase, Date* begin, Date* end);
    double getCleaning_cost() const {return cleaning_cost;}
    double getHygiene_cost() const {return hygiene_cost;}
    double getSalaries_cost() const {return salaries_cost;}
    double getBooking_profit() const {return booking_profit;}
    /*
    void setCleaning_cost(double c) {c = cleaning_cost;}
    void setHygiene_cost(double h) {h = hygiene_cost;}
    void setSalaries_cost(double s) {s = salaries_cost;}
    void setBooking_profit(double p) {p = booking_profit;}
     */
};


#endif //GRANDE_HOTEL_CENTRAL_FINANCES_H
