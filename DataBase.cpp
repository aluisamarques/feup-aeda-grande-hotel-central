//
// Created by marga on 28/10/2020.
//

#include "DataBase.h"
#include "Employee.h"
#include "Book.h"
#include "InputValidation.h"

#include <vector>
#include <math.h>
#include <string>

struct Date;
using namespace std;

DataBase::DataBase()
{
    clients.resize(0);
    employees.resize(0);
    rooms.resize(0);
    products_catalog.resize(0);
    stock_products.resize(0);
    books.resize(0);
    temporary_books.resize(0);
}

bool DataBase::addRoomElement(Room *room) {
    for (auto & i : rooms)
        if (*room == (*i)) return false;
    rooms.push_back(room);
    return true;
}

bool DataBase::addEmployeeElement(Employee* employee) {
    for (auto & i : employees)
        if (*employee == (*i)) return false;
    employees.push_back(employee);
    return true;
}

/*
 * Getters & Setters
 */

std::vector<Room*> DataBase::getRooms() const {return rooms;}

std::vector<Employee*> DataBase::getEmployees()const {return employees;}

std::vector<Client*>* DataBase::getPointerClients() {return &clients;}

std::vector<Product *>* DataBase::getPointerStock_products(){return &stock_products;}

std::vector<Product*>* DataBase::getPointerProduct_to_buy() {return &products_catalog;}

std::vector<Book *>* DataBase::getPointerBooks() {return &books;}

std::vector<Book *>* DataBase::getPointerTemp_books() {return &temporary_books;}

std::vector<Book *> DataBase::getBooks() const {
    return books;
}

vector<Product *> DataBase::getStock_products() const {
    return stock_products;
}

std::vector<Client *> DataBase::getClients() const {
    return clients;
}

std::vector<Product *> DataBase::getProduct_to_buy() const {
    return products_catalog;
}

std::vector<Book *> DataBase::getTemp_books() const {
    return temporary_books;
}




