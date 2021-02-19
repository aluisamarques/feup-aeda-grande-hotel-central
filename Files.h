//
// Created by migam on 11/16/2020.
//

#ifndef GRANDE_HOTEL_CENTRAL_FILES_H
#define GRANDE_HOTEL_CENTRAL_FILES_H

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <vector>
#include "Client.h"
#include "Employee.h"
#include "Product.h"
#include "Room.h"
#include "Book.h"
#include "Date.h"


/**
 *  Function load
 *  @param database
 *  function to load all the information from the files
*/
void loadFiles(DataBase* database);

/**
 *  Function update clients file
 *  @param client
 *  @param update_type true to write , false to delete
 *  function to update
*/
void updateClientsFile(Client* client);

/**
 *  Function update employees file
 *  @param employee
 *  @param update_type true to write , false to delete
 *  function to update
*/
void updateEmployeesFile(Employee* employee);

/**
 *  Function update rooms file
 *  @param room
 *  @param update_type true to write , false to delete
 *  function to update
*/
void updateRoomsFile(Room* room);

/**
 *  Function update stock products file
 *  @param product
 *  @param update_type true to write , false to delete
 *  function to update
*/
void updateProductStockFile(Product* product);

/**
 *  Function update products to buy file
 *  @param product
 *  @param update_type true to write , false to delete
 *  function to update
*/
void updateProductToBuyFile(Product* product);


/**
 *  Function update books file
 *  @param book
 *  @param update_type true to write , false to delete
 *  function to update
*/
void updateBookFile(Book* book);

/**
 *  Function to create a room to type of argument
 *  @param room_type
*/
Room* roomIdentifier(std::string room_type);


#endif //GRANDE_HOTEL_CENTRAL_FILES_H