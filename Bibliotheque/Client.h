#pragma once
#ifndef CLIENT_H
#define CLIENT_H
#include <iostream>
#include "Book.h"
using namespace std;

class Client
{
private:
    string name;
    string password;
public:
    //default constructor
    Client();
    //constructeur
    Client(string, string);
    //destructeur
    virtual ~Client();
    //getters
    string getName();
    string getPassword();
    //setters
    void setName(string);
    void setPassword(string);
    //functions
    bool Login(string, string);
    void Logout();
    //void borrowBook(Book[], string);//
    //void returnBook(Book[], string);//

    //void displayClient();
};

#endif // CLIENT_H