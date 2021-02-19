//
// Created by migam on 11/17/2020.
//

#include "Files.h"

#define NAME 0
#define NIF 1
#define GROUP_SIZE 2
#define HISTORY 3
#define PRESENT 4
#define ROOM_NUMBER 5
#define SEPARATION 6


using namespace std;

Room* roomIdentifier(std::string room_type){
    if (room_type=="NoViewRoom") {
        NoViewRoom *room;
        return room;
    }
    else if (room_type=="ViewRoom") {
        ViewRoom *room;
        return room;
    }
    else {
        SuiteRoom *room;
        return room;
    }
}

template <class T>
void loadRoom(T *room, ifstream &rooms_file){
    stringstream ss;
    string line, st1;
    int num1 = 0 , num2 = 0;
    for (int i = 0; i < 4; i++)
    {
        getline(rooms_file, line);
        ss = std::stringstream(line);

        if ( i == 0){ //linha 2
            cout << "0\n";
            ss >> st1 >>num1 >>num2;
            cout << st1 << num1 << num2;
            room->setFloor(num1);
            room->setNumber(num2);
        }
        if ( i == 1 ){ // linha 3
            cout << "\n1\n";
            ss >> st1 >> num1;
            cout << st1 << num1;
            room->setAvailable(num1);
        }
        if ( i == 2){ //linha 4<<
            cout << "\n2\n";
            ss >> st1 >> num1;
            cout << st1 << num1 ;
            room->setCapacity(num1);
        }
        if( i == 3){continue;}
    }

}

void updateClientsFile(Client *client){
    std::ofstream outfile;
    std::ifstream infile;
    std::string line;

    outfile.open("Clients.txt", std::fstream::app);
    outfile << "Name: " << client -> getName() << std::endl;
    outfile << "NIF: " << to_string(client->getIntNIF()) << std::endl;
    outfile << "GroupSize: " << client -> getGroupSize() << std::endl;
    outfile << "OldClient: " << client -> getOld_Client() << std::endl;
    outfile << "Present: " << client -> getPresent() <<  std::endl;
    outfile << "RoomNumber: " << client -> getRoomNumber() <<  std::endl;
    outfile << "-----------------------------------------------------" << std::endl;
    outfile.close();
}

void updateEmployeesFile(Employee *employee){
    std::ofstream outfile;
    std::ifstream infile;
    std::string line;

    outfile.open("Employee.txt", std::fstream::app);
    outfile << "Name:" << employee -> getName() << std::endl;
    outfile << "NIF:" << std::to_string(employee -> getNIF()) << std::endl;
    outfile << "WorkYears: " << std::to_string(employee -> getWorkYears()) << std::endl;
    outfile << "Salary: " << std::to_string(employee -> getSalary()) <<  std::endl;
    outfile << "-----------------------------------------------------" << std::endl;
    outfile.close();
}

void updateRoomsFile(Room *room){
    std::ofstream outfile;
    std::ifstream infile;
    std::string line;

    outfile.open("Rooms.txt", std::fstream::app);
    outfile << "RoomType: " << room -> RoomType() << std::endl;
    outfile << "RoomID: " << std::to_string(room -> getFloor()) << "0" << room -> getNumber() <<std::endl;
    outfile << "Available: " << room -> getAvailable() << std::endl;
    outfile << "Capacity: " << std::to_string(room -> getCapacity()) << std::endl;
    outfile << "-----------------------------------------------------" << std::endl;
    outfile.close();
}

void updateProductStockFile(Product *product){
    std::ofstream outfile;
    std::ifstream infile;
    std::string line;
    std::vector<unsigned int> :: iterator clients;

    outfile.open("Products_on_stock.txt", std::fstream::app);
    outfile << "Type: " << product -> getType() << std::endl;
    outfile << "Quality: " << product -> getQuality() << std::endl;
    outfile << "Price: " << std::to_string(product -> getPrice()) << std::endl;
    outfile << "-----------------------------------------------------" << std::endl;
    outfile.close();
}


void updateProductToBuyFile(Product *product){
    std::ofstream outfile;
    std::ifstream infile;
    std::string line;
    std::vector<unsigned int> :: iterator clients;

    outfile.open("Products_to_buy.txt", std::fstream::app);
    outfile << "Type: " << product -> getType() << std::endl;
    outfile << "Quality: " << product -> getQuality() << std::endl;
    outfile << "Price: " << std::to_string(product -> getPrice()) << std::endl;
    outfile << "-----------------------------------------------------" << std::endl;
    outfile.close();
}

void updateBookFile(Book *book){
    std::ofstream outfile;
    std::ifstream infile;
    std::string line;

    outfile.open("Book.txt", std::fstream::app);
    outfile << "Name:" << book -> getClient() -> getName() << std::endl;
    outfile << "NIF: " << to_string(book->getClient()->getIntNIF()) << endl;
    outfile << "\nGroupSize: " << std::to_string(book -> getClient() -> getGroupSize())  << std::endl;
    outfile << "OldClient: " << book ->getClient() -> getOld_Client() << std::endl;
    outfile << "Present: " << book ->getClient() -> getPresent() <<  std::endl;
    outfile << "RoomType: " << book->getRoom() -> RoomType() << std::endl;
    outfile << "RoomID: " << std::to_string(book->getRoom() -> getFloor()) <<
    std::to_string(book->getRoom() -> getNumber()) <<std::endl;
    outfile << "Available: " << book->getRoom()-> getAvailable() << std::endl;
    outfile << "Capacity: " << book->getRoom()->getCapacity() << std::endl;
    outfile << "Check-in date: " << std::to_string(book->getCheckin_date().day) << "/"
    << std::to_string(book->getCheckin_date().month) << "/" << std::to_string(book->getCheckin_date().year) << std::endl;
    outfile << "Check-out date: " << std::to_string(book->getCheckout_date().day) << "/"
    << std::to_string(book->getCheckout_date().month) << "/" << std::to_string(book->getCheckout_date().year) << std::endl;
    outfile << "-----------------------------------------------------" << std::endl;
    outfile.close();
}

void loadFiles(DataBase * database){
    std::ifstream clients_file("Clients.txt");
    std::ifstream rooms_file("Rooms.txt");
    std::ifstream product_on_stock_file("Products_on_stock.txt");
    std::ifstream product_to_buy_file("Products_to_buy.txt");
    std::ifstream book_file("Book.txt");
    std::ifstream employees_file("Employees.txt");
    std::string line, st1, st2, st3 = "0";
    int st4;
    std::stringstream ss;
    unsigned int d,m,y = 0;
    std::string dummy = "";
    while(!clients_file.eof())
    {
        Client* client = new Client();
        for (int i = 0; i < 7; i++) {
            getline(clients_file, line);
            ss = std::stringstream(line);
            if (i == NAME) {
                ss >> st2 >> st1;
                cout << st2 << " " << st1;
                if ((st1) == "-1") break;
                client->setName(st1);
            } else {
                ss >> st2 >> st4;
                if (i == NIF) {
                    client->setNIF(st4);
                }
                if (i == GROUP_SIZE) {
                    client->setGroupSize(st4);
                }
                if (i == HISTORY) {
                    client->setOld_Client(st4);
                }
                if (i == PRESENT) {
                    client->setPresent(st4);
                }
                if (i == ROOM_NUMBER) {
                    client->setRoomNumber(st4);
                }
                if (i == SEPARATION) {
                    //continue;
                }
            }
        }
        addElement(*client, database->getClients());
    }
/*
    while(!rooms_file.eof())
    {
        string room_type;
        getline(rooms_file, line);
        ss = std::stringstream(line);
        ss >> st1 >>room_type;

        if (room_type=="NoViewRoom") {
            NoViewRoom *room;
            loadRoom(room, rooms_file);
            database->addRoomElement(room);
        }
        else if (room_type=="ViewRoom") {
            ViewRoom *room;
            loadRoom(room, rooms_file);
            database->addRoomElement(room);
        }
        else {
            SuiteRoom *room;
            loadRoom(room, rooms_file);
            database->addRoomElement(room);
        }
        cout << database->getRooms().size();

    }

    while(!employees_file.eof())
    {
        Employee * employee;
        for (int i= 0;i!=5;i++)
        {
            getline(employees_file, line);
            ss = std::stringstream(line);
            ss >> st2 >> st1;
            switch (i)
            {
                case 0:
                    employee -> setName(st1);
                case 1:
                    employee -> setNIF(stoi(st1));
                case 2:
                    employee -> setWorkYears(stoi(st1));
                case 3:
                    employee -> setSalary(stoi(st1));
            }
        }
        database->addEmployeeElement(employee);
    }
    while(!product_on_stock_file.eof())
    {
        Product * product;
        for (int i= 0;i!=4;i++)
        {
            getline(product_on_stock_file, line);
            ss = std::stringstream(line);
            ss >> st2 >> st1;
            switch (i)
            {
                case 0:
                    product -> setType(st1);
                case 1:
                    product -> setQuality(stoi(st1));
                case 2:
                    product -> setPrice(stoi(st1));
            }

        }
        addElement(*product,database->getPointerStock_products());
    }
    while(!product_to_buy_file.eof())
    {
        Product * product;
        for (int i= 0;i!=4;i++)
        {
            getline(product_to_buy_file, line);
            ss = std::stringstream(line);
            ss >> st2 >> st1;
            switch (i)
            {
                case 0:
                    product -> setType(st1);
                case 1:
                    product -> setQuality(stoi(st1));
                case 2:
                    product -> setPrice(stoi(st1));
            }

        }
        addElement(*product,database->getPointerProduct_to_buy());
    }
    while(!book_file.eof()) {
        Book *book;
        for (int i = 0; i !=8; i++) {
            getline(book_file, line);
            ss = std::stringstream(line);
            switch (i) {
                case 0:
                    ss >> st2 >> st1;
                    book->getClient()->setName(st1);
                case 1:
                    ss >> st2 >> st1;
                    book->getClient()->setNIF(stoi(st1));
                case 2:
                    ss >> st2 >> st1;
                    book->getClient()->setGroupSize(stoi(st1));
                case 3:
                    ss >> st2 >> st1;
                    book->getClient()->setOld_Client(stoi(st1));
                case 4:
                    ss >> st2 >> st1;
                    book->getClient()->setPresent(stoi(st1));
                case 5:
                    ss >> st2 >> st1;
                    for (int i = 0; i < stoi(st1); i++) {
                        getline(rooms_file, line);
                        ss = std::stringstream(line);
                        ss >> st1 >>st2;
                        Room * room = roomIdentifier(st2);
                        getline(book_file, line);
                        ss = std::stringstream(line);
                        ss >> st1 >>st2 >>st3;
                        room -> setFloor(stoi(st2));
                        room -> setNumber(stoi(st3));
                        getline(book_file, line);
                        ss >> st1 >> st2;
                        room -> setAvailable(stoi(st2));
                        getline(book_file, line);
                        ss >> st1 >> st2;
                        room -> setCapacity(stoi(st2));
                        database->addRoomElement(room);
                    }
                case 6:
                    ss >> st2 >> d >> dummy >> m >> dummy >> y;
                    Date * date = new Date(d,m,y);
                    book->getCheckin_date() = *date;
                    getline(book_file, line);
                    ss = std::stringstream(line);
                    ss >> st2 >> d >> dummy >> m >> dummy >> y;
                    Date * dat = new Date(d,m,y);
                    book->getCheckout_date() = *dat;

            }
        }
        addElement(*book,database->getPointerBooks());
    }
}