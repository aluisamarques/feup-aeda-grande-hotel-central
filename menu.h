//
// Created by aluis on 20/11/2020.
//

#ifndef GRANDE_HOTEL_CENTRAL_MENU_H
#define GRANDE_HOTEL_CENTRAL_MENU_H

#include "Login.h"
#include "UserInterface.h"
#include "InputValidation.h"
#include "Book.h"
#include "Product.h"
#include "DataBase.h"
#include "Files.h"

/**
    *  Bool Function
    *  Show the initial menu
*/
bool menu(){

    DataBase * dataBase = new DataBase();
    UserInterface ui;

    //employees
    Manager *employee1 = new Manager("Miguel", 123456789, 10, 1111);
    Reception *reception = new Reception("Luisa",987654321,2,9089);
    Responsible *responsible = new Responsible("Joaquim Mendes", 88888888, 3, 100);
    Responsible *responsible1 = new Responsible("Carlos Gomes", 121212121, 54, 2000);
    Cleaning *cleaning = new Cleaning("Margarida Raposo",999999999, 3, 900,"night");
    dataBase->addEmployeeElement(reception);
    dataBase->addEmployeeElement(responsible);
    dataBase->addEmployeeElement(responsible1);
    dataBase->addEmployeeElement(employee1);

    dataBase->addEmployeeElement(cleaning);

    updateEmployeesFile(employee1);
    updateEmployeesFile(reception);


    //rooms
    ViewRoom *vr = new ViewRoom(1,01,*dataBase);
    NoViewRoom *nvr = new NoViewRoom(1,02,*dataBase);
    SuiteRoom *sr = new SuiteRoom(2,01, *dataBase);
    ViewRoom *vr1 = new ViewRoom(2,03,*dataBase);
    SuiteRoom *sr1 = new SuiteRoom(2,04,*dataBase);


    dataBase->addRoomElement(vr);
    dataBase->addRoomElement(nvr);
    dataBase->addRoomElement(sr);
    dataBase->addRoomElement(vr1);
    dataBase->addRoomElement(sr1);

    //products
    Product * fairy = new Product("Cleaning",3,1);
    Product * product = new Product("Hygiene", 5, 2);
    Product * vanish = new Product("Cleaning", 2,1);
    addElement(*product, dataBase->getPointerProduct_to_buy());
    addElement(*vanish, dataBase->getPointerProduct_to_buy());
    addElement(*fairy, dataBase->getPointerProduct_to_buy());
    addElement(*fairy, dataBase->getPointerStock_products());
    std::cout << "stock: "<<dataBase->getStock_products().size();

    //books
    Client * pedro = new Client("Pedro",3,232323234);
    Book * book = new Book(pedro,*dataBase,02,02,2020,03,03,2020,todayDate());
    addElement(*book,dataBase->getPointerTemp_books());

    while(1){

    //if (dataBase->addEmployeeElement(employee1)) std::cout << "a";
    //updateClientsFile(c);
    loadFiles(dataBase);
/*
    for(int i = 0; i < dataBase->getClients().size(); i++){
        std::cout <<"nome: " << dataBase->getClients()[i]->getName() << " nif: "<< dataBase->getClients()[i]->getIntNIF()
        << " num pessoas: "<< dataBase->getClients()[i]->getGroupSize() ;
    }
    */
    int exit_flag;
    do{
        std::cout << "menu";
        ui.login(dataBase);
        ui.setDataBase(dataBase);
        if (ui.getUser()->employeeRole() == "Responsible") ui.responsible();
        else if (ui.getUser()->employeeRole() == "Cleaning") ui.cleaning();
        else if (ui.getUser()->employeeRole() == "Reception") ui.reception();
        else if (ui.getUser()->employeeRole() == "Manager") ui.manager();

        std::cout << "Turn off hotel system?\n[1] Yes [2] No\n";
        std::cin >> exit_flag;
    } while(exit_flag-1);


    return true;
}

#endif //GRANDE_HOTEL_CENTRAL_MENU_H

