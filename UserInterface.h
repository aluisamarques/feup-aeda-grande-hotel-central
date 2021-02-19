//
// Created by aluis on 19/11/2020.
//

#ifndef GRANDE_HOTEL_CENTRAL_USERINTERFACE_H
#define GRANDE_HOTEL_CENTRAL_USERINTERFACE_H

#include "Login.h"
#include "Book.h"
#include "Search.h"
#include "Exception.h"
#include "InputValidation.h"
#include <string>

#define PERSONAL_FOLDER "Visualize personal folder."
#define LOG_OUT "Log-out.\n"
#define BOOK "Make reservation (temporary)."
#define EXPENSES "View expenses."
#define ADD_PRODUCTS "Buy products"
#define ADD_EMPLOYEES "Add employees."
#define FINISH_BOOK "Finish book."
#define PROFIT "View profit."

/**
 * Class Search
 * Class to create search
*/
class UserInterface {
    DataBase* dataBase;                                                             ///< private member dataBase

    Employee* user;                                                                 ///< private member user

    std::vector<std::string> cleaning_actions { PERSONAL_FOLDER, LOG_OUT };         ///< private vector cleaning actions

    std::vector<std::string> responsible_actions {PERSONAL_FOLDER, LOG_OUT};        ///< private vector responsible actions

    std::vector<std::string> reception_actions {PERSONAL_FOLDER, BOOK ,LOG_OUT};    ///< private vector reception actions

    std::vector<std::string> manager_actions {PERSONAL_FOLDER, FINISH_BOOK ,        ///< private vector manager actions
                                              EXPENSES, PROFIT,
                                              ADD_PRODUCTS, ADD_EMPLOYEES, LOG_OUT};

public:
    /**
        * Default Class constructor
    */
    UserInterface();

    /**
        * Class function
        * Manage the login

    */
    void login(DataBase *dataBase);

    /**
        * Class function
        * Interface of manager
    */
    void manager();

    /**
        * Class function
        * Interface of reception
    */
    void reception();

    /**
        * Class function
        * Interface of responsible
    */
    void responsible();

    /**
        * Class function
        * Interface of cleaning
    */
    void cleaning();


    /**
        * Class function
        * @param actions vector with the actions that user can do
        * Show the action which one with index
        * Return the index that the user chose
    */
    int chooseAction(std::vector<std::string> actions);

    /**
        * Class function
        * Print all the information about the user
    */
    void printPersonalFolder();

    /**
        * Class function
        * Receive all the inputs to make the reservation
        * Make the reservation
    */
    void createReservation();

    /**
        * Class function
        * @param search
        * See the product to buy
        * Buy the products and see the cost of them
        * Save this information
    */
    void buyProducts(Search *search);

    /**
        * Class function
        * @param book the reservation
        * See if the client is a new client or not
        * Set the promotion
        * Calculates the the price of the reservation
    */
    void setPromotion(Book *book);

    /**
        * Class function
        * Create the employee with the inputs
    */
    void createEmployee();

    /**
        * Class function
        * Return the user
    */
    Employee* getUser() const;

    /**
        * Class function
        * Set the database of this UserInterface
    */
    void setDataBase(DataBase* dataBase);

};



#endif //GRANDE_HOTEL_CENTRAL_USERINTERFACE_H
