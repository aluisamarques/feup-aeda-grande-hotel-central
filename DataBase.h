//
// Created by marga on 28/10/2020.
//

#ifndef GRANDE_HOTEL_CENTRAL_DATABASE_H
#define GRANDE_HOTEL_CENTRAL_DATABASE_H

#include "Client.h"
#include "Employee.h"
#include "Room.h"
#include "Product.h"

#include <string>
#include <vector>

class Book;
struct Date;

/**
 * ## Template function
 * Inserts the element T in the vector of pointers of objects T
 * @param element an object T
 * @param vec a vector of pointers of objects T
*/
template<class T>
bool addElement(T element, std::vector<T*>* vec)
{
    for (auto & i : *vec)
        if (element == (*i)) return false;
    vec->push_back(&element);
    return true;
}

/**
 * Class DataBase
 * Class to create the database of the system
 * Where all the data is saved while the program is running
*/
class DataBase {
    std::vector<Client*> clients;                         ///< private vector to save all the information about the clients

    std::vector<Room*> rooms;                             ///< private vector to save all the information about the rooms

    std:: vector<NoViewRoom*> no_view_rooms;              ///< private vector to save all the information about the rooms that no have view

    std:: vector<ViewRoom*> view_rooms;                   ///< private vector to save all the information about the rooms that have view

    std:: vector<SuiteRoom*> suite_rooms;                 ///< private vector to save all the information about the suits

    std::vector<Employee*> employees;                     ///< private vector to save all the information about the employees

    std::vector<Product*> stock_products;                 ///< private vector to save all the information about the stock_products

    std::vector<Book*> books;                             ///< private vector to save all the information about the reservations

    std::vector<Book*> temporary_books;                   ///< private vector to save all the information about the temporary reservations

    std::vector<Product*> products_catalog;               ///< private vector to save all the information about the products_catalog

public:

    /**
     * Default DataBase construct
    */
    DataBase();

    /**
     * Class Function
     * returns vector with all the employees which have salary  == argument salary
     * @param salary argument to search
    */
    std::vector<Employee*> findEmployeeBySalary(double salary);

    /**
     * Class Function
     * returns vector with all the employees which have role  == argument role
     * @param role : argument to search
    */
    std::vector<Employee*> findEmployeeByRole(std::string role);

    /**
     * Class function
     * Calculates the total cost of the month
    */
    double totalCostMonth();

    /**
     * Class function
     * Calculates the total profit
    */
    double calculateProfit();


    unsigned int calculateBookDays(std::vector<unsigned int> out_date, std::vector<unsigned int> in_date);

    /**
     * Class function
     * Adds the employee in the employees' vector
     * @param employee : pointer to the employee to add
    */
    bool addEmployeeElement(Employee* employee);

    /**
     * Class function
     * Adds the room in the room's vector
     * @param room : pointer to the room to add
    */
    bool addRoomElement(Room *room);

    //Getters & Setters

    std::vector<Client*> getClients() const;               ///< Returns the private vector clients

    std::vector<Room*> getRooms() const;                   ///< Returns the private vector rooms

    std::vector<Employee*> getEmployees() const;           ///< Returns the private vector employees

    std::vector<Product*> getStock_products() const;       ///< Returns the private vector stock_products

    std::vector<Product*> getProduct_to_buy() const;       ///< Returns the private vector products_catalog

    std::vector<Book*> getBooks() const;                   ///< Returns the private vector books

    std::vector<Book*> getTemp_books() const;              ///< Returns the private vector temporary_books
};


#endif //GRANDE_HOTEL_CENTRAL_DATABASE_H
