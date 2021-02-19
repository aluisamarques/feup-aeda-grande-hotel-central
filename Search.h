//
// Created by aluis on 17/11/2020.
//

#ifndef GRANDE_HOTEL_CENTRAL_SEARCH_H
#define GRANDE_HOTEL_CENTRAL_SEARCH_H

#include <vector>
#include <string>

class Employee;
class Book;
class Date;
class DataBase;
class Room;
class Product;

/**
 * Class Search
 * Class to create search
*/
class Search {
    std::vector<Employee*> search_employees;                                        ///< private vector search_employees

    std::vector<Book*> search_books;                                                ///< private vector search_books

    std::vector<Employee*> filter_employees_salary;                                 ///< private vector filter_employees_salary

    std::vector<Employee*> filter_employees_role;                                   ///< private vector filter_employees_role

    std::vector<Product*> stock_products;                                           ///< private vector stock_products

    std::vector<Product*> products_available_to_buy;                                ///< private vector products_available_to_buy

    double total_cost_salaries;                                                     ///< private double total_cost_salaries

    double total_cost_products;                                                     ///< private double total_cost_products
public:
    /**
        * Default Class constructor
    */
    Search();

    /**
        * Class constructor
        * @param database
    */
    Search(DataBase &dataBase);

    /**
        * Class Function
        * @param salary
        * Return vector with employees which salary equal to the argument salary
    */
    std::vector<Employee*> findEmployeeBySalary(double salary);

    /**
        * Class Function
        * @param role
        * Return vector with employees which role equal to the argument role
    */
    std::vector<Employee*> findEmployeeByRole(std::string role);

    /**
        * Class Function
        * @param date
        * Return vector with rooms which date equal to the argument date
    */
    std::vector<Book*> dayBooks(Date date);

    /**
        * Class Function
        * @param type
        * Return the number of products of type "type"
    */
    int checkProductsStock(std::string type);

    /**
        * Class Function
        * @param type
        * @param num_products
        * Return vector with products to buy
    */
    std::vector<Product*> buyProducts(std::string type, int num_products);

    /**
        * Class Function
        * @param month
        * Return total costs of the month "month"
    */
    double totalCostMonth(int month);

    /**
        * Class Function
        * @param book
        * Return the cost of products on this book
    */
    double productsCostPerBook(Book *book);

    /**
        * Class Function
        * @param month
        * Return the profit of the month "month"
    */
    double calculateProfit(int month);

    /**
        * Class Function
        * @param cost
        * Add cost to total_cost
    */
    void setTotal_cost_products(double cost);
};


#endif //GRANDE_HOTEL_CENTRAL_SEARCH_H
