//
// Created by aluis on 17/11/2020.
//

#include "Search.h"
#include "DataBase.h"
#include "Book.h"

using namespace std;

/**
        * Default Class constructor
    */
Search::Search(){}

/**
        * Class constructor
    */
Search::Search(DataBase &database){
    search_employees = database.getEmployees();
    search_books = database.getBooks();
    stock_products = database.getStock_products();
    products_available_to_buy = database.getProduct_to_buy();
}

/**
        * Return vector with employees which salary equal to the argument salary
    */
std::vector<Employee *> Search::findEmployeeBySalary(double salary) {
    for(auto i: search_employees){
        if (salary == i->getSalary())
            filter_employees_salary.push_back(i);
    }
    return filter_employees_salary;
}

/**
        * Return vector with employees which role equal to the argument role
    */
std::vector<Employee *> Search::findEmployeeByRole(string role) {
    for(auto i: search_employees){
        if(role == i->employeeRole())
            filter_employees_role.push_back(i);
    }
    return filter_employees_role;
}

/**
        * Return the number of products of type "type"
    */
int Search::checkProductsStock(string type){
    int product_type_stock = 0;
    for(auto p:stock_products){
        if(p->getType() == type)
            product_type_stock++;
    }
    return product_type_stock;
}

/**
        * Return vector with products to buy
    */
std::vector<Product*> Search::buyProducts(string type, int num_products_to_shop) {
    std::vector<Product*> purchased_products;

    std::vector<Product*>::iterator it ;

    while (num_products_to_shop){
        for(it = products_available_to_buy.begin(); it != products_available_to_buy.end(); it++){
            if((*it)->getType() == type){
                purchased_products.push_back(*it);
                products_available_to_buy.erase(it);
                num_products_to_shop --;
            }
        }
    }

    return purchased_products;
}

/**
        * Return the cost of products on this book
    */
double Search::productsCostPerBook(Book *b) {
    double products_cost = 0;
    int cleaning_shop = 0, hygiene_shop = 0;

    //checks if stock has enough products
    checkProductsStock("Cleaning")-b->cleaningProductsNeeded() >= 0 ? (cleaning_shop = (checkProductsStock("Cleaning")-b->cleaningProductsNeeded())) : cleaning_shop = 0 ;
    checkProductsStock("Hygiene")-b->hygieneProductsNeeded() >= 0 ? (hygiene_shop = (checkProductsStock("Hygiene")-b->hygieneProductsNeeded())) : hygiene_shop = 0;

    //if there are not enough products, buys from vector products to buy
    std::vector<Product*> cleaning_purchased = buyProducts("Cleaning", cleaning_shop);
    std::vector<Product*> hygiene_purchased = buyProducts("Hygiene", hygiene_shop);

    //calculate costs of purchased products
    for (auto c: cleaning_purchased){
        products_cost += c->getPrice();
    }

    for (auto h: hygiene_purchased){
        products_cost += h->getPrice();
    }

    return products_cost;
}

/**
        * Return total costs of the month "month"
    */
double Search::totalCostMonth(int month) { //testar função ! NECESSITO files
    total_cost_products = 0;
    total_cost_salaries = 0;

    for (auto e: search_employees) {
        total_cost_salaries += e->getSalary();
    }

    for(auto b: search_books){
        if (b->getCheckin_date().month == month){
            total_cost_products += productsCostPerBook(b);
        }
    }

    return (total_cost_products + total_cost_salaries);
}

/**
        * Return the profit of the month "month"
    */
double Search::calculateProfit(int month) {
    double clients_payment = 0.0;

    for (auto b: search_books){
        if (b->getCheckin_date().month == month)
        clients_payment += b->getReservation_price();
    }

    return clients_payment - totalCostMonth(month);
}

/**
        * Return vector with rooms which date equal to the argument date
    */
std::vector<Book *> Search::dayBooks(Date date) {
    vector<Book *> books_of_the_day;
    for (auto b: search_books){
        if (b->getCheckin_date() == date){
            books_of_the_day.push_back(b);
        }
    }
    return books_of_the_day;
}

/**
        * Add cost to total_cost
    */
void Search::setTotal_cost_products(double cost) {
    total_cost_products += cost;
}