//
// Created by aluis on 19/11/2020.
//

#include "UserInterface.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <sstream>

using namespace std;

    /**
    * Default Class constructor
    */
UserInterface::UserInterface(){};


void UserInterface::login(DataBase *dataBase) {
    cout << "\nWELCOME TO GRANDE HOTEL CENTRAL" << endl;
    Login login;
    string name;
    int nif;
    cout << "\n----Authentication----" << endl;
    do{ cout << "Name:";
        cin >> name;
        cout << "NIF:";
        cin >> nif;
    } while(!login.userLogin(dataBase, name, nif));
    user = login.getUser();
}


    /**
    * Show the action which one with index
    * Return the index that the user chose
    */
int UserInterface::chooseAction(std::vector<std::string> actions) {
    for(int i = 0; i < actions.size(); i++)
        std::cout << "\n[" << i+1 << "] " << actions[i];
    int action;

    cin >> action;
    return action;
}

/**
        * Print all the information about the user
    */
void UserInterface::printPersonalFolder() {
    cout << "\n---- Personal Folder - " << user->getName() << "----\n";
    cout << "Name:" << user -> getName() << endl;
    cout << "NIF:" << std::to_string(user -> getNIF()) << endl;
    cout << "WorkYears:" << std::to_string(user -> getWorkYears()) << endl;
    cout << "Salary: " << std::to_string(user -> getSalary()) <<  endl;
}

/**
        * Make the reservation
    */
void UserInterface::createReservation() {
    cout << "---- BOOKING ----";
    cout << "\nInsert Client information";

    string name;
    unsigned int nif, group_size;
    cout << "\nName:" ; cin >> name;
    cout << "NIF:" ; cin >> nif;
    cout << "Number of visitants:" ; cin >> group_size;

    try{ nifValidation(nif);
    } catch (InvalidNifException) {
        std::cout << "\nInvalid NIF.";
        return;
    }

    Client * client = new Client(name, group_size, nif);
    addElement(*client, (dataBase->getPointerClients())); //TODO return client if it already exists

    cout << "Insert Booking dates --";
    cout << "\nDate: dd mm yyyy";

    int day1, month1, year1;
    string in_date;

    cin.ignore(100,'\n');
    cout <<"\nCheck-in date:";
    getline(cin, in_date);
    cout << "data: "<<in_date<<endl;
    istringstream ss(in_date);
    ss >> day1 >> month1 >> year1;

    cin.clear();
    int day2, month2, year2;
    string out_date;
    cout << "Check-out date:";
    getline(cin, out_date);
    istringstream ss2(out_date);
    ss2 >> day2 >> month2 >> year2;

    Date * today = todayDate();

    try {
        try{
            Book* book = new Book(client, *dataBase, day1, month1, year1, day2, month2, year2, today);
            dataBase->getTemp_books().push_back(book);
            cout << "Reservation made with success.";
        }
        catch(NoRoomsAvailable){
            cout << "The system could not find available rooms.";};

    } catch (InvalidDate) {
        std::cout << "Invalid dates, keep in mind that check-out must be after check-in.";
    }
}

/**
        * Calculates the the price of the reservation
    */
void UserInterface::setPromotion(Book *book) {
    double total=0;
    double promotion=0;
    string answer;
    int book_days = book->getCheckout_date() - book->getCheckin_date() ;
    if (!(book->getClient()->getOld_Client())){
        cout<<"Manager you want to apply any promotion to this client?" <<endl;
        cin>>answer;  //input validation needed
        if(answer=="yes") {
            promotion = book->getRoom()->getPromotion();
            cout << "Would you like to apply a promotion (" << promotion << ") to this reservation?" << endl;
            while(true) {
                cin >> answer;
                if(answer == "yes" || answer == "no") break;
                cout << "Invalid answer, enter 'yes' or 'no'";
            }
            if (answer == "yes")
                    total += book->getRoom()->getBase_price() - book->getRoom()->getBase_price() * promotion;
            book->setReservation_price(total * book_days);
            return;
        }
    }
    book->setReservation_price(book->getRoom()->getBase_price()* book_days);
}

/**
        * Create the employee with the inputs
    */
void UserInterface::createEmployee() {
    cout << "\n---- Manager - Adding Employee ----";
    cout << "\nInsert Employee's information --";
    string name, role, shift;
    unsigned int nif, salary;
    cout << "\nName:" ; cin >> name;
    cout << "NIF:" ; cin >> nif;
    cout << "Role" ; cin >> role;
    cout << "Salary:" ; cin >> salary;

    if (role == "Cleaning"){
        cout << "\nShift"; cin >> shift;
        Cleaning* cleaning = new Cleaning(name, nif,0,salary,shift);
    }
    else if (role == "Responsible"){
        Responsible* responsible = new Responsible(name, nif, 0,salary);
    }
    else if (role == "Reception"){
        Reception* reception = new Reception(name,nif,0,salary);
    }
    else cout << "\nThere is no employee position for the given name.";
}

/**
        * Buy the products and see the cost of them
    */
void UserInterface::buyProducts(Search * search) {
    int max_hygiene = 100, max_cleaning = 70, count_hygiene = 0, count_cleaning = 0;
    cout << "\nStock Products";
    vector<Product*> stock = dataBase->getStock_products();

    for (int i = 0; i < stock.size(); i++){
        cout << "\n[" << i+1 << "]" << "Type:" << stock[i]->getType() << " Quality:" << stock[i]->getQuality() <<
             " Price:" << stock[i]->getPrice();
        if (stock[i]->getType() == "Hygiene") count_hygiene++;
        else count_cleaning++;
    }

    cout << "\nCatalog Products";
    vector<Product*> catalog = dataBase->getProduct_to_buy();

    for (int i = 0; i < catalog.size(); i++){
        cout << "\n[" << i+1 << "]" << "Type:" << catalog[i]->getType() << " Quality:" << catalog[i]->getQuality() <<
        " Price:" << catalog[i]->getPrice();
    }

    int answer;
    cout << "\nChoose the product you want to buy. If you do not want to buy, enter 0.";
    cin >> answer;
    if (answer == 0) return;
    else addElement(*catalog[answer-1],dataBase->getPointerStock_products());
    cout << "\nProduct " << answer << " was added to the stock with success.";

    search->setTotal_cost_products(search->totalCostMonth(11) + (max_hygiene - count_hygiene)*1 +
    (max_cleaning - count_cleaning)*2);

}

void UserInterface::cleaning() {
    int exit_flag = false;
    do{
        cout << "\n----Cleaning - " << user->getName() << " ----";
        cout << "\nInsert what you want to do:";
        switch (chooseAction(cleaning_actions)) {
            case 1: //personal folder
                printPersonalFolder();
                break;
            case 2: // logout
                return;
            default:
                cout << "\nInvalid action, choose a number from 1 to " << cleaning_actions.size() << endl;
        }
    } while(!exit_flag);
}

void UserInterface::responsible() {
    int exit_flag = 1;
    do{
    cout << "\n----Responsible - "<< user->getName() << " ----";
    cout << "\nInsert what you want to do:";

    switch(chooseAction(responsible_actions)){
        case 1: //personal folder
            printPersonalFolder();
            break;
        case 2: //logout
            return;
        default:
            cout << "\nInvalid action, choose a number from 1 to " << cleaning_actions.size() << endl;
    }
        cout << "\n\nWould you like to do anything else before leaving? \n[1] Yes [2] No\n";
        cin >> exit_flag;
    } while(!(exit_flag-1));
}

void UserInterface::reception(){
    int exit_flag = 1;
    do{
        cout << "\n---- Reception - "<< user->getName() << " ----";
        cout << "\nInsert what you want to do:";
        switch(chooseAction(reception_actions)){
            case 1: //personal folder
                printPersonalFolder();
                break;
            case 2: // make reservations;
                createReservation();
                break;
            case 3: // logout
                return;
            default:
                cout << "\nInvalid action, choose a number from 1 to " << cleaning_actions.size() << endl;
        }

        cout << "\n\nWould you like to do anything else before leaving? \n[1] Yes [2] No\n";
        cin >> exit_flag;
    } while(!(exit_flag-1));
}

void UserInterface::manager() {
    bool exit_flag = 1;
    do{
        Search *search = new Search(*dataBase);
        cout << "\n---- Manager - "<< user->getName() << " ----";
        cout << "\nInsert what you want to do:";
        switch(chooseAction(manager_actions)){
            case 1: //personal folder
                printPersonalFolder();
                break;
            case 2: // terminate reservations
                if (dataBase->getTemp_books().size()==0){
                    cout << "\nThere are no unfinished books.";
                    break;
                }
                for(int i = 0; i<dataBase->getTemp_books().size(); i++)
                    setPromotion(dataBase->getTemp_books()[i]);
                break;
            case 3: // view expenses
                unsigned int month;
                while(true) {
                    cout << "\nInsert a month:";
                    cin >> month;
                    if (month > 0 && month <= 12) break;
                    cout << "Invalid month, choose a number from 1 to 12";
                }
                search->totalCostMonth(month);
                break;
            case 4: //view profit
                unsigned int month_p;
                cout << "\nInsert a month:";
                cin >> month_p;
                search->calculateProfit(month_p);
                break;
            case 5: //add products to stock
                buyProducts(search);
                break;
            case 6: //add employees
                createEmployee();
                break;
            case 7: //logout
                return;
            default:
                cout << "\nInvalid action, choose a number from 1 to " << cleaning_actions.size() << endl;
        }

        cout << "\n\nWould you like to do anything else before leaving? \n[1] Yes [2] No\n";
        cin >> exit_flag;
    } while(!(exit_flag-1));
}

/**
        * Return the user
    */
Employee *UserInterface::getUser() const {
    return user;
}

/**
    * Set the database of this UserInterface
    */
void UserInterface::setDataBase(DataBase *dataBase) {
    this -> dataBase = dataBase;
}
