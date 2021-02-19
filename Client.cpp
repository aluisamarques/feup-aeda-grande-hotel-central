//
// Created by marga on 28/10/2020.
//

#include "Client.h"
#include "Exception.h"
#include "InputValidation.h"

#include <math.h>

Client::Client(){}

Client::Client(std::string name, int group_size, unsigned int int_nif)
{
    this -> name = name;
    this -> group_size = group_size;
    num_nif = int_nif;
    old_client = false;
    present = false;
    room_number = -1;
}

bool Client::operator==(const Client &client) const
{
    return client.num_nif == num_nif;
}

/*
 * Getters & Setters
 */

bool Client::getOld_Client() const {return old_client;}

void Client::setOld_Client(bool old_client) {this -> old_client = old_client;}

bool Client::getPresent() const {return present;}

void Client::setPresent(bool present) {this -> present = present;}

std::string Client::getName() const {return name;}

int Client::getGroupSize() const {return group_size;}

int Client::getRoomNumber() const {
    return room_number;
}

unsigned int Client::getIntNIF() const {
    return num_nif;
}

void Client:: setNIF(unsigned int int_nif){
    num_nif = int_nif;
}

void Client::setName(std::string name) {
    this -> name = name;
}

void Client::setGroupSize(int group_size) {
    this -> group_size = group_size;
}

void Client::setRoomNumber(int room_number) {
    this -> room_number= room_number;
}

