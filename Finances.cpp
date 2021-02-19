//
// Created by marga on 21/11/2020.
//

#include "Finances.h"
#include "Book.h"

Finances::Finances(DataBase* dataBase, Date* begin, Date* end) {
    int days = *end - *begin;
    salaries_cost = 0;
    for (auto employee: dataBase->getEmployees())
        salaries_cost += employee->getSalary() / 30*days;

    booking_profit = 0; hygiene_cost = 0; cleaning_cost = 0;
    for (auto book: dataBase->getBooks())
        if(*begin > book->getBook_date() || *begin == book->getBook_date())
            if(book->getBook_date() > *end || *end == book->getBook_date())
            {
                hygiene_cost += book->hygieneProductsNeeded();
                booking_profit += book->getReservation_price();
            }

}